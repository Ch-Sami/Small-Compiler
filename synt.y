%{
  //bibliothèques
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  //définitions des variables
  typedef struct Entite{
      char nom[20];
      char code[10];
      char type[20];
      int taille;
      char estConstante[10];
      char valeur[100];
      struct Entite *suivant;
  }Entite;

  int nbr_ligne = 1;
  int bib_io_included = 0;
  int bib_lang_included = 0;
  int bib_io_manquante_detecte = 0;
  int bib_lang_manquante_detecte = 0;
  char sauvType[20];
  char var_idf_sauv[20];
  bool idf_var_prblm = false;
  bool exp_erreur = false;

  float arithmetic_expression_result = 0;
  typedef struct Arithmetic_expression{
    float valeur;
    char mot[20];
    char type[20];
    int numPar;
    int priorite;
    struct Arithmetic_expression *suivant;
  }arithmetic_expression;

  typedef struct Var_idf_list{
    char idf[30];
    struct Var_idf_list *suivant;
  }Var_idf_list;

  typedef struct Non_declare_list{
    char idf[30];
    int nbr_ligne;
    struct Non_declare_list *suivant;
  }Non_declare_list;

  typedef struct Signes_formatage{
    char signe[3];
    struct Signes_formatage *suivant;
  }Signes_formatage;

  typedef struct Liste_elements{
    char element[255];
    char type[30];
    struct Liste_elements *suivant;
  }Liste_elements;

  //prototypes des fonctions
  Entite* recherche(char nom[]);
  void inserer(char nom[], char code[]);
  void insererType(char nom[], char type[]);
  bool estDeclare(char nom[]);
  void afficher();
  void constante(char nom[]);
  bool estConstante(char nom[]);
  void definirTailleTableau(char nom[], int taille);
  int getTailleTableau(char nom[]);
  bool estDepasseTaille(char nom[], int i);
  void ajouter_operand_expression_arithmetique(char idf[], float valeur);
  void ajouter_parenthese_expression_arithmetique(char par[]);
  void ajouter_operation_expression_arithmetique(char operation[]);
  bool estNombre(char nom[]);
  char* getValue(char nom[]);
  char* getType(char nom[]);
  void reinitialiser_var_idf_list_head();
  void inserer_var_idf(char idf[]);
  void afficherIDFs(); // used just for tests
  Var_idf_list * get_var_idf_list_head();
  void inserer_non_declare(char idf[], int nbr_ligne);
  bool non_declare_deja_detecte(char idf[], int nbr_ligne);
  void afficher_non_declare_list(); // used just for tests
  void creerCellules(char nomTab[], int taille);
  float calculer_expression_arithmetique(int nbr_ligne);
  void affecter(char nom[], char valeur[]);
  void initialiser_expression_arithmetique();
  void afficherAX(); // used just for tests
  void afficherSignes(); // used just for tests
  void reinitialiser_signes_formatage_head();
  void inserer_signe_formatage(char signe[]);
  Signes_formatage * get_signes_formatage_head();
  int var_idf_list_length();
  int signes_formatage_length();
  int liste_elements_length();
  void reinitialiser_liste_elements_head();
  void inserer_element(char element[], char type[]);
  Liste_elements * get_liste_elements_head();
  void afficher_liste_elements(); // used just for tests

  int yylex();
  void yyerror(const char *s);
%}
%union{
	int entier;
  float reel;
	char* chaine;
}
%token mc_import bib_io bib_lang pvg err <chaine>idf mc_private mc_public mc_protected mc_class aco_ov aco_fr 
       mc_entier mc_reel mc_chaine nom_tableau taille_tab mc_const cr_ov cr_fr <entier>cst vrg mc_main pr_ov
       pr_fr aff add sus mult dv <entier>entier <reel>reel <chaine>chaine mc_for equals not_equals inf inf_or_equals sup sup_or_equals
       mc_in mc_out quotation_mark
%start S

%%

S: bib_importation_liste class_header_syntax aco_ov corps aco_fr {printf("syntaxe correct");}
;
bib_importation_liste: bib_importation bib_importation_liste
                       |
;
bib_importation: mc_import nom_bib pvg
;
nom_bib: bib_io {
                  if(bib_io_included == 1){
                    printf("erreur semantique a la ligne %d : double inclusion de la bibliotheque ISIL.io.\n", nbr_ligne);
                  }else{
                    bib_io_included = 1;
                  }
                }
        |bib_lang{
                   if(bib_lang_included == 1){
                    printf("erreur semantique a la ligne %d : double inclusion de la bibliotheque ISIL.lang.\n", nbr_ligne);
                  }else{
                    bib_lang_included = 1;
                  }
                 }
;
class_header_syntax: access_modifier mc_class idf
;
access_modifier: mc_private
                 |mc_public
                 |mc_protected
;
corps: variable_declaration_liste mc_main pr_ov pr_fr aco_ov liste_instruction aco_fr
;
variable_declaration_liste: variable_declaration variable_declaration_liste
                            |
;
variable_declaration: simple_variable_declaration {reinitialiser_var_idf_list_head();}
                      |table_declaration {reinitialiser_var_idf_list_head();  reinitialiser_liste_elements_head();}
                      |const_declaration {reinitialiser_var_idf_list_head();}
;

simple_variable_declaration: variable_type liste_idf_variable_simple pvg
                             |variable_type liste_idf_variable_simple aff {
                              //verifier si bib.lang inclue
                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                bib_lang_manquante_detecte = 1;
                              }
                               //initialiser l'expression arithmetique
                               initialiser_expression_arithmetique();
                               exp_erreur = false;
                              } arithmetic_expression pvg{
                                if(!exp_erreur && !bib_lang_manquante_detecte){
                                  //calculer le resultat de l'expression arithmetique
                                  float resultat = calculer_expression_arithmetique(nbr_ligne);
                                  // printf("RESULT :  %f \n", resultat);

                                  char result_string[100];
                                  sprintf(result_string, "%f", resultat);
                                  //verifier la compatibilite des types
                                  char resultat_type[10];
                                  int partie_entiere = (int)resultat;
                                  float partie_decimal = resultat - partie_entiere;
                                  if(partie_decimal == 0){
                                    strcpy(resultat_type, "entier");
                                    strcpy(result_string, strtok(result_string, "."));
                                  }else{
                                    strcpy(resultat_type, "reel");
                                  }
                                  Var_idf_list * courant = get_var_idf_list_head();
                                  while(courant != NULL){
                                      if(strcmp(getType(courant->idf), "chaine") == 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est de type %s.\n", nbr_ligne, courant->idf, result_string, resultat_type);
                                      }else if(strcmp(getType(courant->idf), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, courant->idf, result_string);
                                      }else{
                                        //affecter
                                        affecter(courant->idf, result_string);
                                      }
                                      courant = courant->suivant;
                                  }

                                  //affichage exp arithmetique
                                  // afficherAX();
                                }
                              }
                              |variable_type liste_idf_variable_simple aff chaine pvg {
                                //verifier si bib.lang inclue
                                if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                  printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                  bib_lang_manquante_detecte = 1;
                                }
                                if(!bib_lang_manquante_detecte){
                                  Var_idf_list * courant = get_var_idf_list_head();
                                  while(courant != NULL){
                                    char type[30];
                                    strcpy(type, getType(courant->idf));
                                    if(strcmp(type, "chaine") != 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, courant->idf, type, $4);
                                      }else{
                                        //affecter
                                        affecter(courant->idf, $4);
                                      }
                                      courant = courant->suivant;
                                  }
                                }
                              }
;
liste_idf_variable_simple: idf {
                               // verifier si double declaration
                               if(estDeclare($1)){
                                 printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, $1);
                               }else{
                                 //inserer le type
                                 insererType($1, sauvType);
                                 //sauv idf
                                 inserer_var_idf($1);
                                 
                               }
                            }vrg liste_idf_variable_simple
                           |idf{
                               // verifier si double declaration
                               if(estDeclare($1)){
                                 printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, $1);
                               }else{
                                 //inserer le type
                                 insererType($1, sauvType);
                                 //sauv idf
                                 inserer_var_idf($1);
                               }
                            }
;
table_declaration: variable_type liste_idf_tab_dec pvg
                  |variable_type liste_idf_tab_dec aff {
                        //verifier si bib.lang inclue
                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                          bib_lang_manquante_detecte = 1;
                        }
                      } cr_ov liste_elements cr_fr pvg {
                        if(!bib_lang_manquante_detecte){
                          Var_idf_list * courant = get_var_idf_list_head();
                          while(courant != NULL){
                            //verification de taille
                            if(getTailleTableau(courant->idf) < liste_elements_length()){
                              printf("erreur semantique a la ligne %d : depassement de la taille du tableau %s.\n", nbr_ligne, courant->idf);
                            }else{
                              //verification des types
                              bool estCompatible = true;
                              Liste_elements *elt_courant = get_liste_elements_head();
                              while(elt_courant != NULL){
                                if(strcmp(elt_courant->type, getType(courant->idf)) != 0){
                                  printf("erreur semantique a la ligne %d : incompatibilite de type, le tableau %s est de type %s mais l'element %s est de type %s.\n", nbr_ligne, courant->idf, getType(courant->idf), elt_courant->element, elt_courant->type);
                                  estCompatible = false;
                                }
                                elt_courant = elt_courant->suivant;
                              }
                              if(estCompatible){
                                //remplissement des cellules
                                int i = 0;
                                char str[10];
                                elt_courant = get_liste_elements_head();
                                while(elt_courant != NULL){
                                char cellule[30];
                                strcpy(cellule, courant->idf);
                                strcat(cellule, "[");
                                sprintf(str, "%d", i);
                                strcat(cellule, str);
                                strcat(cellule, "]");
                                affecter(cellule, elt_courant->element);
                                i++;
                                elt_courant = elt_courant->suivant;
                              }
                              }
                            }
                            courant = courant->suivant;
                          }
                        }
                      }
;


liste_elements: element vrg liste_elements
               |element
;

element: cst {
                  char element[255];
                  sprintf(element, "%d", $1);
                  inserer_element(element, "entier");
                }
         |entier {
                  char element[255];
                  sprintf(element, "%d", $1);
                  inserer_element(element, "entier");
                }
         |reel{
                char element[255];
                sprintf(element, "%f", $1);
                inserer_element(element, "reel");
              }
         |chaine{
                  inserer_element($1, "chaine");
                }
;

liste_idf_tab_dec: nom_tableau cr_ov cst cr_fr {
                  // verifier si double declaration
                  if(estDeclare($1)){
                    printf("erreur semantique a la ligne %d : double declaration du tableau %s.\n", nbr_ligne, $1);
                  }else{
                    //inserer le type
                    insererType($1, sauvType);
                    //definir la taille du tableau
                    definirTailleTableau($1, $3);
                    //allouer les cellules
                    creerCellules($1, $3);
                    //sauv idf
                    inserer_var_idf($1);
                  }
                }vrg liste_idf_tab_dec
               |nom_tableau cr_ov cst cr_fr{
                  // verifier si double declaration
                  if(estDeclare($1)){
                    printf("erreur semantique a la ligne %d : double declaration du tableau %s.\n", nbr_ligne, $1);
                  }else{
                    //inserer le type
                    insererType($1, sauvType);
                    //definir la taille du tableau
                    definirTailleTableau($1, $3);
                    //allouer les cellules
                    creerCellules($1, $3);
                    //sauv idf
                    inserer_var_idf($1);
                  }
                }
;
const_declaration: mc_const variable_type liste_idf_const pvg
                   |mc_const variable_type liste_idf_const aff { 
                     //verifier si bib.lang inclue
                     if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                       printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                       bib_lang_manquante_detecte = 1;
                     }
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    } arithmetic_expression pvg {
                      if(!exp_erreur && !bib_lang_manquante_detecte){
                        //calculer le resultat de l'expression arithmetique
                        float resultat = calculer_expression_arithmetique(nbr_ligne);
                        // printf("RESULT :  %f \n", resultat);

                        char result_string[100];
                        sprintf(result_string, "%f", resultat);
                        //verifier la compatibilite des types
                        char resultat_type[10];
                        int partie_entiere = (int)resultat;
                        float partie_decimal = resultat - partie_entiere;
                        if(partie_decimal == 0){
                          strcpy(resultat_type, "entier");
                          strcpy(result_string, strtok(result_string, "."));
                        }else{
                          strcpy(resultat_type, "reel");
                        }
                        Var_idf_list * courant = get_var_idf_list_head();
                        while(courant != NULL){
                            if(strcmp(getType(courant->idf), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                              printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, courant->idf, result_string);
                            }else{
                              //affecter
                              affecter(courant->idf, result_string);
                            }
                            courant = courant->suivant;
                        }
                        //affichage exp arithmetique
                        // afficherAX();
                      }
                    }
                    |mc_const variable_type liste_idf_const aff chaine pvg {
                      //verifier si bib.lang inclue
                      if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                        printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                        bib_lang_manquante_detecte = 1;
                      }
                      if(!bib_lang_manquante_detecte){
                        Var_idf_list * courant = get_var_idf_list_head();
                        while(courant != NULL){
                          char type[30];
                          strcpy(type, getType(courant->idf));
                          if(strcmp(type, "chaine") != 0){
                              printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, courant->idf, type, $4);
                            }else{
                              //affecter
                              affecter(courant->idf, $5);
                            }
                            courant = courant->suivant;
                        }
                      }
                    }
;

liste_idf_const: idf vrg liste_idf_const{
                    // verifier si double declaration
                    if(estDeclare($1)){
                      printf("erreur semantique a la ligne %d : double declaration de la constante %s.\n", nbr_ligne, $1);
                    }else{
                      //inserer le type
                      insererType($1, sauvType);
                      //est constante
                      constante($1);
                      //sauv idf
                      inserer_var_idf($1);
                    }
                  }
                 |idf{
                    // verifier si double declaration
                    if(estDeclare($1)){
                      printf("erreur semantique a la ligne %d : double declaration de la constante %s.\n", nbr_ligne, $1);
                    }else{
                      //inserer le type
                      insererType($1, sauvType);
                      //est constante
                      constante($1);
                      //sauv idf
                      inserer_var_idf($1);
                    }
                  }
;
variable_type: mc_entier { strcpy(sauvType, $1); }
               |mc_reel { strcpy(sauvType, $1); }
               |mc_chaine { strcpy(sauvType, $1); }
;
liste_instruction: instruction liste_instruction
                   |
;
instruction: affectation {reinitialiser_var_idf_list_head(); reinitialiser_liste_elements_head();}
             |loop
             |lecture {
               if(bib_io_included == 0 && bib_io_manquante_detecte == 0){
                 printf("erreur semantique : la bibliotheque ISIL.io est manquante.\n");
                 bib_io_manquante_detecte = 1;
               }
               reinitialiser_var_idf_list_head();
               reinitialiser_signes_formatage_head();
              }
             |ecriture {
               if(bib_io_included == 0 && bib_io_manquante_detecte == 0){
                 printf("erreur semantique : la bibliotheque ISIL.io est manquante.\n");
                 bib_io_manquante_detecte = 1;
               }
               reinitialiser_var_idf_list_head();
               reinitialiser_signes_formatage_head();
              }
;
affectation: variable_idf aff { 
            //verifier si bib.lang inclue
             if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
               printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
               bib_lang_manquante_detecte = 1;
             }
             //initialiser l'expression arithmetique
             initialiser_expression_arithmetique();
             exp_erreur = false;
            } arithmetic_expression pvg {
                                      if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                                         //calculer le resultat de l'expression arithmetique
                                         float resultat = calculer_expression_arithmetique(nbr_ligne);
                                         // printf("RESULT :  %f \n", resultat);

                                         char result_string[100];
                                         sprintf(result_string, "%f", resultat);
                                         //verifier la compatibilite des types
                                         char resultat_type[10];
                                         int partie_entiere = (int)resultat;
                                         float partie_decimal = resultat - partie_entiere;
                                         if(partie_decimal == 0){
                                           strcpy(resultat_type, "entier");
                                           strcpy(result_string, strtok(result_string, "."));
                                         }else{
                                           strcpy(resultat_type, "reel");
                                         }
                                         if(strcmp(getType(var_idf_sauv), "chaine") == 0){
                                            printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est un %s.\n", nbr_ligne, var_idf_sauv, result_string, resultat_type);
                                          }else if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                            printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                                          }else{
                                            //affecter
                                            affecter(var_idf_sauv, result_string);
                                          }
  
                                          //affichage exp arithmetique
                                          // afficherAX();
                                      }
                                    }
            |variable_idf aff chaine pvg {
              //verifier si bib.lang inclue
              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                bib_lang_manquante_detecte = 1;
              }
              if(!idf_var_prblm && !bib_lang_manquante_detecte){
                char type[30];
                strcpy(type, getType(var_idf_sauv));
                if(strcmp(type, "chaine") != 0){
                  printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, var_idf_sauv, type, $3);
                }else{
                  //affecter
                  affecter(var_idf_sauv, $3);
                }
              }
            }
            |variable_idf add add pvg {
                                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                          bib_lang_manquante_detecte = 1;
                                        }
                                        if(!idf_var_prblm && !bib_lang_manquante_detecte){
                                          if(estNombre(var_idf_sauv)){
                                            //affecter
                                            char ans_valeur[100];
                                            char nvl_valeur[100];
                                            strcpy(ans_valeur, getValue(var_idf_sauv));
                                            if(strcmp(getType(var_idf_sauv), "reel") == 0){
                                              float val_reel = atof(ans_valeur);
                                              val_reel ++;
                                              sprintf(nvl_valeur, "%f", val_reel);
                                            }else if(strcmp(getType(var_idf_sauv), "entier") == 0){
                                              int val_entier = atoi(ans_valeur);
                                              val_entier ++;
                                              sprintf(nvl_valeur, "%d", val_entier);
                                            }
                                            affecter(var_idf_sauv, nvl_valeur);
                                          }else{
                                            printf("erreur semantique a la ligne %d : la variable %s est de type chaine, elle ne peut pas etre augmenter par 1.\n", nbr_ligne, var_idf_sauv);
                                          }
                                        }
                                      }
            |variable_idf sus sus pvg {
                                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                          bib_lang_manquante_detecte = 1;
                                        }
                                        if(!idf_var_prblm && !bib_lang_manquante_detecte){
                                          if(estNombre(var_idf_sauv)){
                                            //affecter
                                            char ans_valeur[100];
                                            char nvl_valeur[100];
                                            strcpy(ans_valeur, getValue(var_idf_sauv));
                                            if(strcmp(getType(var_idf_sauv), "reel") == 0){
                                              float val_reel = atof(ans_valeur);
                                              val_reel --;
                                              sprintf(nvl_valeur, "%f", val_reel);
                                            }else if(strcmp(getType(var_idf_sauv), "entier") == 0){
                                              int val_entier = atoi(ans_valeur);
                                              val_entier --;
                                              sprintf(nvl_valeur, "%d", val_entier);
                                            }
                                            affecter(var_idf_sauv, nvl_valeur);
                                          }else{
                                            printf("erreur semantique a la ligne %d : la variable %s est de type chaine, elle ne peut pas etre augmenter par 1.\n", nbr_ligne, var_idf_sauv);
                                          }
                                        }
                                      }
              |nom_tableau cr_ov cr_fr aff {
                        //verifier si bib.lang inclue
                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                          bib_lang_manquante_detecte = 1;
                        }
                      } cr_ov liste_elements cr_fr pvg {
                        if(!bib_lang_manquante_detecte){
                          //verification de taille
                          if(getTailleTableau($1) < liste_elements_length()){
                            printf("erreur semantique a la ligne %d : depassement de la taille du tableau %s.\n", nbr_ligne, $1);
                          }else{
                            //verification des types
                            bool estCompatible = true;
                            Liste_elements *elt_courant = get_liste_elements_head();
                            while(elt_courant != NULL){
                              if(strcmp(elt_courant->type, getType($1)) != 0){
                                printf("erreur semantique a la ligne %d : incompatibilite de type, le tableau %s est de type %s mais l'element %s est de type %s.\n", nbr_ligne, $1, getType($1), elt_courant->element, elt_courant->type);
                                estCompatible = false;
                              }
                              elt_courant = elt_courant->suivant;
                            }
                            if(estCompatible){
                              //remplissement des cellules
                              int i = 0;
                              char str[10];
                              elt_courant = get_liste_elements_head();
                              while(elt_courant != NULL){
                              char cellule[30];
                              strcpy(cellule, $1);
                              strcat(cellule, "[");
                              sprintf(str, "%d", i);
                              strcat(cellule, str);
                              strcat(cellule, "]");
                              affecter(cellule, elt_courant->element);
                              i++;
                              elt_courant = elt_courant->suivant;
                            }
                            }
                          }
                        }
                      }
;


variable_idf: idf{
                if(!estDeclare($1)){
                  if(!non_declare_deja_detecte($1, nbr_ligne)){
                    printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, $1);
                    inserer_non_declare($1, nbr_ligne);
                  }
                  idf_var_prblm = true;
                }else if(strcmp(getValue($1), "") != 0 && estConstante($1)){
                  printf("erreur semantique a la ligne %d : la constante %s est deja definie.\n", nbr_ligne, $1);
                  idf_var_prblm = true;
                }else{
                  strcpy(var_idf_sauv, $1);
                  idf_var_prblm = false;
                }
              }
              |nom_tableau cr_ov cst cr_fr{
                //nom de cellule
                char nom_cellule[30];
                char num_cellule[10];
                strcpy(nom_cellule, "");
                strcpy(num_cellule, "");
                sprintf(num_cellule, "%d", $3);
                strcat(nom_cellule, $1);
                strcat(nom_cellule, "[");
                strcat(nom_cellule, num_cellule);
                strcat(nom_cellule, "]");
                if(!estDeclare($1)){
                  if(!non_declare_deja_detecte($1, nbr_ligne)){
                    printf("erreur semantique a la ligne %d : le tableau %s est non declare.\n", nbr_ligne, $1);
                    inserer_non_declare($1, nbr_ligne);
                  }
                  idf_var_prblm = true;
                }else if(estDepasseTaille($1, $3)){
                  printf("erreur semantique a la ligne %d : depassement de la taille, la cellule %s n'existe pas.\n", nbr_ligne, nom_cellule); 
                  idf_var_prblm = true;
                }else{
                  idf_var_prblm = false;
                  strcpy(var_idf_sauv, nom_cellule);
                }
              }
;
arithmetic_expression: entre_parentheses arithmetic_expression_rest
                       |operand arithmetic_expression_rest
;
entre_parentheses: pr_ov {
                           ajouter_parenthese_expression_arithmetique("pr_ov");
                         } arithmetic_expression pr_fr{
                           ajouter_parenthese_expression_arithmetique("pr_fr");
                         }
;
arithmetic_expression_rest: operation arithmetic_expression
                            |
;
operand: idf{
            if(!estDeclare($1)){
              if(!non_declare_deja_detecte($1, nbr_ligne)){
                printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, $1);
                inserer_non_declare($1, nbr_ligne);
              }
            }else if(!estNombre($1)){
              exp_erreur = true;
              printf("erreur semantique a la ligne %d : la variable %s n'est pas un nombre, elle ne peut pas etre un operand dans une expression arithmetique.\n", nbr_ligne, $1);
            }else if(strcmp(getValue($1), "") == 0){
              printf("erreur semantique a la ligne %d : la variable %s est non definie.\n", nbr_ligne, $1);
              exp_erreur = true;
            }else{
              if(strcmp(getType($1), "entier") == 0){
                ajouter_operand_expression_arithmetique($1, atoi(getValue($1)));
              }else if(strcmp(getType($1), "reel") == 0){
                ajouter_operand_expression_arithmetique($1, atof(getValue($1)));
              }
            }
         }
         |nom_tableau cr_ov cst cr_fr{
            //nom de cellule
            char nom_cellule[30];
            char num_cellule[10];
            strcpy(nom_cellule, "");
            strcpy(num_cellule, "");
            sprintf(num_cellule, "%d", $3);
            strcat(nom_cellule, $1);
            strcat(nom_cellule, "[");
            strcat(nom_cellule, num_cellule);
            strcat(nom_cellule, "]");
            if(!estDeclare(nom_cellule)){
              if(!non_declare_deja_detecte(nom_cellule, nbr_ligne)){
                printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, nom_cellule);
                inserer_non_declare(nom_cellule, nbr_ligne);
              }
            }else if(estDepasseTaille($1, $3)){
              printf("erreur semantique a la ligne %d : depassement de la taille, la cellule %s n'existe pas.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else if(!estNombre(nom_cellule)){
              printf("erreur semantique a la ligne %d : la variable %s n'est pas un nombre, elle ne peut pas etre un operand dans une expression arithmetique.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else if(strcmp(getValue(nom_cellule), "") == 0){
              printf("erreur semantique a la ligne %d : la variable %s est non definie.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else{
              if(strcmp(getType(nom_cellule), "entier") == 0){
                ajouter_operand_expression_arithmetique(nom_cellule, atoi(getValue(nom_cellule)));
              }else if(strcmp(getType(nom_cellule), "reel") == 0){
                ajouter_operand_expression_arithmetique(nom_cellule, atof(getValue(nom_cellule)));
              }
            }
         }
         |cst {
                char str[255];
                sprintf(str, "%d", $1);
                ajouter_operand_expression_arithmetique(str, (float)$1);
              }
         |entier{
                  char str[255];
                  sprintf(str, "%d", $1);
                  ajouter_operand_expression_arithmetique(str, (float)$1);
                }
         |reel{
                char str[255];
                sprintf(str, "%f", $1);
                ajouter_operand_expression_arithmetique(str, $1);
              }
;
operation: add {
                 ajouter_operation_expression_arithmetique("add");
               }
           |sus{
                 ajouter_operation_expression_arithmetique("sus");
               }
           |mult{
                 ajouter_operation_expression_arithmetique("mult");
                }
           |dv{
                ajouter_operation_expression_arithmetique("dv");
              }
;
loop: loop_header aco_ov liste_instruction aco_fr
;
loop_header: mc_for pr_ov loop_initialisation pvg loop_condition pvg loop_incrementation pr_fr
;
loop_initialisation: variable_idf aff {
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    } arithmetic_expression {
                                              //verifier si bib.lang inclue
                                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                                bib_lang_manquante_detecte = 1;
                                              }
                                              if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                                                //calculer le resultat de l'expression arithmetique
                                                float resultat = calculer_expression_arithmetique(nbr_ligne);
                                                // printf("RESULT :  %f \n", resultat);

                                                char result_string[100];
                                                sprintf(result_string, "%f", resultat);
                                                //verifier la compatibilite des types
                                                char resultat_type[10];
                                                int partie_entiere = (int)resultat;
                                                float partie_decimal = resultat - partie_entiere;
                                                if(partie_decimal == 0){
                                                  strcpy(resultat_type, "entier");
                                                  strcpy(result_string, strtok(result_string, "."));
                                                }else{
                                                  strcpy(resultat_type, "reel");
                                                }
                                                if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                                  printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                                                }else{
                                                  //affecter
                                                  affecter(var_idf_sauv, result_string);
                                                }

                                                //affichage exp arithmetique
                                                // afficherAX();
                                              }
                                            }
                    |variable_type idf aff { 
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    } arithmetic_expression {
                                              //verifier si bib.lang inclue
                                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                                bib_lang_manquante_detecte = 1;
                                              }
                                              if(!bib_lang_manquante_detecte){
                                                // verifier si double declaration
                                                if(estDeclare($2)){
                                                  printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, $2);
                                                }else{
                                                  //inserer le type
                                                  insererType($2, sauvType);
                                                  if(!exp_erreur){
                                                      //calculer le resultat de l'expression arithmetique
                                                      float resultat = calculer_expression_arithmetique(nbr_ligne);
                                                      // printf("RESULT :  %f \n", resultat);

                                                      char result_string[100];
                                                      sprintf(result_string, "%f", resultat);
                                                      //verifier la compatibilite des types
                                                      char resultat_type[10];
                                                      int partie_entiere = (int)resultat;
                                                      float partie_decimal = resultat - partie_entiere;
                                                      if(partie_decimal == 0){
                                                        strcpy(resultat_type, "entier");
                                                        strcpy(result_string, strtok(result_string, "."));
                                                      }else{
                                                        strcpy(resultat_type, "reel");
                                                      }
                                                      if(strcmp(getType($2), "chaine") == 0){
                                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est un %s.\n", nbr_ligne, $2, result_string, resultat_type);
                                                      }else if(strcmp(getType($2), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, $2, result_string);
                                                      }else{
                                                        //affecter
                                                        affecter($2, result_string);
                                                      }

                                                      //affichage exp arithmetique
                                                      // afficherAX();
                                                  }
                                                }
                                              }
                                            }
;
loop_condition: arithmetic_expression comparaison arithmetic_expression
;
comparaison: equals
             |not_equals
             |inf
             |inf_or_equals
             |sup
             |sup_or_equals
;
loop_incrementation: variable_idf add add {
                          //verifier si bib.lang inclue
                          if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                            printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                            bib_lang_manquante_detecte = 1;
                          }
                        }
                     |variable_idf sus sus{
                        //verifier si bib.lang inclue
                          if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                            printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                            bib_lang_manquante_detecte = 1;
                          }
                        }
                     |variable_idf aff { 
                       //verifier si bib.lang inclue
                       if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                         printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                         bib_lang_manquante_detecte = 1;
                       }
                       //initialiser l'expression arithmetique
                       initialiser_expression_arithmetique();
                       exp_erreur = false;
                      } arithmetic_expression {
                        if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                          //calculer le resultat de l'expression arithmetique
                           float resultat = calculer_expression_arithmetique(nbr_ligne);
                           // printf("RESULT :  %f \n", resultat);
                           char result_string[100];
                           sprintf(result_string, "%f", resultat);
                           //verifier la compatibilite des types
                           char resultat_type[10];
                           int partie_entiere = (int)resultat;
                           float partie_decimal = resultat - partie_entiere;
                           if(partie_decimal == 0){
                             strcpy(resultat_type, "entier");
                             strcpy(result_string, strtok(result_string, "."));
                           }else{
                             strcpy(resultat_type, "reel");
                           }
                           if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                             printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                           }else{
                             //ne pas affecter
                             //affecter(var_idf_sauv, result_string);
                           }

                           //affichage exp arithmetique
                           // afficherAX();
                        }
                      }   
;

lecture: mc_in pr_ov chaine vrg variable_idf pr_fr pvg {
  if(!idf_var_prblm){
    int len = strlen($3);
    for(int i = 1 ; i < len-2 ; i++){
      if($3[i] == '%' && $3[i-1] != '\\' && ($3[i+1] == 'd' || $3[i+1] == 'f' || $3[i+1] == 's') ){
        char signe[3];
        signe[0] = $3[i];
        signe[1] = $3[i+1];
        inserer_signe_formatage(signe);
      }
    }
    if(signes_formatage_length() > 1){
      printf("erreur semantique a la ligne %d : trop de signes de formatage.\n", nbr_ligne);
    }else if(signes_formatage_length() == 0){
      printf("erreur semantique a la ligne %d : aucun signe de formatage.\n", nbr_ligne);
    }else{
      char temp[len-2];
      strcpy(temp, get_signes_formatage_head()->signe);
      char type[30];
      strcpy(type, getType(var_idf_sauv));
      if(strcmp(temp, "%d") == 0){
        if(strcmp("entier", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type entier mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else if(strcmp(temp, "%f") == 0){
        if(strcmp("reel", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type reel mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else if(strcmp(temp, "%s") == 0){
        if(strcmp("chaine", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type chaine mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else{
        printf("erreur semantique a la ligne %d : le signe de formatage %s est inconnu.\n", nbr_ligne, $3);
      }
    }
  }
}
;

ecriture: mc_out pr_ov chaine liste_sorties pr_fr pvg {
  if(!idf_var_prblm){
    int len = strlen($3);
    for(int i = 1 ; i < len-2 ; i++){
      if($3[i] == '%' && $3[i-1] != '\\' && ($3[i+1] == 'd' || $3[i+1] == 'f' || $3[i+1] == 's') ){
        char signe[3];
        signe[0] = $3[i];
        signe[1] = $3[i+1];
        inserer_signe_formatage(signe);
      }
    }
    int signes_formatage_length_con = signes_formatage_length();
    int var_idf_list_length_con = var_idf_list_length();
    if(signes_formatage_length_con > var_idf_list_length_con){
      printf("erreur semantique a la ligne %d : le nombre des signes de formatage est superieur au nombre des sorties.\n", nbr_ligne);
    }else if(signes_formatage_length_con < var_idf_list_length_con){
      printf("erreur semantique a la ligne %d : le nombre des signes de formatage est inferieur au nombre des sorties.\n", nbr_ligne);
    }else if(signes_formatage_length_con == var_idf_list_length_con){
      Signes_formatage *sf_courant = get_signes_formatage_head();
      Var_idf_list *idf_courant = get_var_idf_list_head();
      int num_sortie = signes_formatage_length_con;
      while(sf_courant != NULL && idf_courant != NULL){
        char type[30];
        strcpy(type, getType(idf_courant->idf));
        if(strcmp(sf_courant->signe, "%d") == 0){
          if(strcmp("entier", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type entier mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else if(strcmp(sf_courant->signe, "%f") == 0){
          if(strcmp("reel", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type reel mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else if(strcmp(sf_courant->signe, "%s") == 0){
          if(strcmp("chaine", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type chaine mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else{
          printf("erreur semantique a la ligne %d : le signe de formatage %s est inconnu.\n", nbr_ligne, $3);
        }
        num_sortie--;
        sf_courant = sf_courant->suivant;
        idf_courant = idf_courant->suivant;
      }
    }
  }
}
;

liste_sorties: vrg variable_idf {inserer_var_idf(var_idf_sauv);} liste_sorties
              |variable_idf {inserer_var_idf(var_idf_sauv);}
              |
;

%%
void yyerror (const char *s) {
  printf("erreur syntaxique !! a la ligne %d \n", nbr_ligne);
}
int main()
{
  yyparse();
  afficher();
}
int yywrap() {}