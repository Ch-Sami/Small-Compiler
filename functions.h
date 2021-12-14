//bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//définitions des variables
typedef struct Entite{
    char nom[20];
    char code[30];
    char type[20];
    int taille;
    char estConstante[10];
    char valeur[30];
    struct Entite *suivant;
}Entite;
Entite *head = NULL;

typedef struct Arithmetic_expression{
    float valeur;
    char mot[20];
    char type[20];
    int numPar;
    int priorite;
    struct Arithmetic_expression *suivant;
}Arithmetic_expression;
Arithmetic_expression *arithmetic_expression_head = NULL;

typedef struct Var_idf_list{
  char idf[30];
  struct Var_idf_list *suivant;
}Var_idf_list;
struct Var_idf_list *var_idf_list_head = NULL;

typedef struct Non_declare_list{
  char idf[30];
  int nbr_ligne;
  struct Non_declare_list *suivant;
}Non_declare_list;
Non_declare_list *non_declare_list_head = NULL;

typedef struct Signes_formatage{
  char signe[3];
  struct Signes_formatage *suivant;
}Signes_formatage;
Signes_formatage *signes_formatage_head = NULL;

typedef struct Liste_elements{
  char element[255];
  char type[30];
  struct Liste_elements *suivant;
}Liste_elements;
Liste_elements *liste_elements_head = NULL;


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
void creerCellules(char nomTab[], int taille);
void gererParentheses();
bool ilYaPar();
float calculer_expression_arithmetique();
void augmenterPrioriteEntre(Arithmetic_expression *courant_ov, Arithmetic_expression *courant_fr);
void supprimerParentheses(Arithmetic_expression *courant_ov, Arithmetic_expression *courant_fr);
float calculer_expression_arithmetique(int nbr_ligne);
int getMaxPriorite();
int getMinPriorite();
void calculer_sub_expression_arithmetique(Arithmetic_expression *courant1, Arithmetic_expression *courant2, int nbr_ligne);
Arithmetic_expression* chercherOperation(Arithmetic_expression *courant1, char operation[]);
void affecter(char nom[], char valeur[]);
void initialiser_expression_arithmetique();
void reinitialiser_var_idf_list_head();
void inserer_var_idf(char idf[]);
void afficherIDFs(); // used just for tests
Var_idf_list * get_var_idf_list_head();
int var_idf_list_length();
void inserer_non_declare(char idf[], int nbr_ligne);
bool non_declare_deja_detecte(char idf[], int nbr_ligne);
void afficher_non_declare_list();
int signes_formatage_length();
void reinitialiser_signes_formatage_head();
void inserer_signe_formatage(char signe[]);
Signes_formatage * get_signes_formatage_head();
void afficherSignes(); // used just for tests
int liste_elements_length();
void reinitialiser_liste_elements_head();
void inserer_element(char element[], char type[]);
Liste_elements * get_liste_elements_head();
void afficher_liste_elements(); // used just for tests
void afficherAX(); // used just for tests

//fonctions
Entite* recherche(char nom[]){
    //si liste vide
    if(head == NULL) {
      return NULL;
    }
    //sinon
    Entite *courant = head;
    while(courant != NULL){
        if(strcmp(courant->nom, nom) == 0){
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

void inserer(char nom[], char code[]){
    //verifier que l'entite n'existe pas
    if(recherche(nom) == NULL){
        //créer une nouvelle Entite
        Entite *entite = (Entite*) malloc(sizeof(Entite));
        //remplire l'entité
        strcpy(entite->nom, nom);
        strcpy(entite->code, code);
        strcpy(entite->type, "");
        entite->taille = 1;
        strcpy(entite->estConstante, "non");
        strcpy(entite->valeur, "");
        //insérer dans la liste
        entite->suivant = head;
        head = entite;
    }
}

void insererType(char nom[], char type[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        strcpy(entite->type, type);
    }
}

bool estDeclare(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        //verifier si declaré
        return (strcmp(entite->type, "") != 0);
    }
    return true;
}

void constante(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        strcpy(entite->estConstante, "oui");
    }
}

bool estConstante(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        return strcmp(entite->estConstante, "oui") == 0;
    }
}

bool estNombre(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        //verifier si nombre
        return (strcmp( entite->type , "entier" ) == 0 || strcmp( entite->type , "reel" ) == 0);
    }
}

char* getValue(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        return entite->valeur;
    }
}

char* getType(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        return entite->type;
    }
}

void definirTailleTableau(char nom[], int taille){
    Entite *tab = recherche(nom);
    //verifier que le tableau existe
    if(tab != NULL){
        //definir taille
        tab->taille = taille;
    }
}

int liste_elements_length(){
    int i = 0;
    Liste_elements * courant = liste_elements_head;
    while(courant != NULL){
        i++;
        courant = courant->suivant;
    }
    return i;
}

void reinitialiser_liste_elements_head(){
    liste_elements_head = NULL;
}

void inserer_element(char element[], char type[]){
    Liste_elements *entite = (Liste_elements*) malloc(sizeof(Liste_elements));
    strcpy(entite->element, element);
    strcpy(entite->type, type);
    if(liste_elements_head == NULL){
        entite->suivant = NULL;
        liste_elements_head = entite;
    }else{
        entite->suivant = liste_elements_head;
        liste_elements_head = entite;
    }
}

Liste_elements * get_liste_elements_head(){
    return liste_elements_head;
}
void afficher_liste_elements(){
    Liste_elements * courant = liste_elements_head;
    while(courant != NULL){
        printf("elt: %s , type: %s\n", courant->element, courant->type);
        courant = courant->suivant;
    }
}

int getTailleTableau(char nom[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        return entite->taille;
    }
}

bool estDepasseTaille(char nom[], int i){
    Entite *tab = recherche(nom);
    //verifier que le tableau existe
    if(tab != NULL){
        return (tab->taille <= i);
    }
}

Var_idf_list * get_var_idf_list_head(){
    return var_idf_list_head;
}

void reinitialiser_var_idf_list_head(){
    var_idf_list_head = NULL;
}

void inserer_var_idf(char idf[]){
    Var_idf_list *entite = (Var_idf_list*) malloc(sizeof(Var_idf_list));
    strcpy(entite->idf, idf);
    if(var_idf_list_head == NULL){
        entite->suivant = NULL;
        var_idf_list_head = entite;
    }else{
        entite->suivant = var_idf_list_head;
        var_idf_list_head = entite;
    }
}

void afficherIDFs(){
    Var_idf_list * courant = var_idf_list_head;
    while(courant != NULL){
        printf("%s\n", courant->idf);
        courant = courant->suivant;
    }
}

int var_idf_list_length(){
    int i = 0;
    Var_idf_list * courant = var_idf_list_head;
    while(courant != NULL){
        i++;
        courant = courant->suivant;
    }
    return i;
}

void inserer_non_declare(char idf[], int nbr_ligne){
    Non_declare_list *entite = (Non_declare_list*) malloc(sizeof(Non_declare_list));
    strcpy(entite->idf, idf);
    entite->nbr_ligne = nbr_ligne;
    if(non_declare_list_head == NULL){
        entite->suivant = NULL;
        non_declare_list_head = entite;
    }else{
        entite->suivant = non_declare_list_head;
        non_declare_list_head = entite;
    }
}

bool non_declare_deja_detecte(char idf[], int nbr_ligne){
    Non_declare_list * courant = non_declare_list_head;
    while(courant != NULL){
        if(strcmp(courant->idf, idf) == 0 && courant->nbr_ligne == nbr_ligne){
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

void afficher_non_declare_list(){
    Non_declare_list * courant = non_declare_list_head;
    while(courant != NULL){
        printf("idf: %s  , ligne: %d\n", courant->idf, courant->nbr_ligne);
        courant = courant->suivant;
    }
}

int signes_formatage_length(){
    int i = 0;
    Signes_formatage * courant = signes_formatage_head;
    while(courant != NULL){
        i++;
        courant = courant->suivant;
    }
    return i;
}

void reinitialiser_signes_formatage_head(){
    signes_formatage_head = NULL;
}

Signes_formatage * get_signes_formatage_head(){
    return signes_formatage_head;
}

void inserer_signe_formatage(char signe[]){
    Signes_formatage *entite = (Signes_formatage*) malloc(sizeof(Signes_formatage));
    strcpy(entite->signe, signe);
    if(signes_formatage_head == NULL){
        entite->suivant = NULL;
        signes_formatage_head = entite;
    }else{
        entite->suivant = signes_formatage_head;
        signes_formatage_head = entite;
    }
}

void afficherSignes(){
    Signes_formatage * courant = signes_formatage_head;
    while(courant != NULL){
        printf("%s\n", courant->signe);
        courant = courant->suivant;
    }
}

void creerCellules(char nomTab[], int taille){
    for(int i = 0; i < taille; i++){
        //nom de cellule
        char nom_cellule[30];
        char num_cellule[10];
        strcpy(nom_cellule, "");
        strcpy(num_cellule, "");
        sprintf(num_cellule, "%d", i);
        strcat(nom_cellule, nomTab);
        strcat(nom_cellule, "[");
        strcat(nom_cellule, num_cellule);
        strcat(nom_cellule, "]");
        //verifier que l'entite n'existe pas
        if(recherche(nom_cellule) == NULL){
            //créer une nouvelle entite
            Entite *entite = (Entite*) malloc(sizeof(Entite));
            //remplire l'entite
            strcpy(entite->nom, nom_cellule);
            strcpy(entite->code, "cellule");
            strcpy(entite->type, getType(nomTab));
            entite->taille = 1;
            strcpy(entite->estConstante, "non");
            strcpy(entite->valeur, "");
            //insérer dans la liste
            entite->suivant = head;
            head = entite;
        }
    }
}

void initialiser_expression_arithmetique(){
    arithmetic_expression_head = NULL;
}

void ajouter_operand_expression_arithmetique(char idf[], float valeur){
    //créer un nouvel element
    Arithmetic_expression *element = (Arithmetic_expression*) malloc(sizeof(Arithmetic_expression));
    //remplir l'element
    element->valeur = valeur;
    strcpy(element->mot, idf);
    strcpy(element->type, "operand");
    element->numPar = 0;
    element->priorite = 0;
    element->suivant = NULL;
    //premiere element
    if(arithmetic_expression_head == NULL){
        arithmetic_expression_head = element;
    }else{
        //le reste FIFO
        Arithmetic_expression * courant = arithmetic_expression_head;
        // Arithmetic_expression * courant = precedent->suivant;
        while(courant->suivant != NULL){
            courant = courant->suivant;
        }
        courant->suivant = element;
    }
}

void ajouter_parenthese_expression_arithmetique(char par[]){
    //créer un nouvel element
    Arithmetic_expression *element = (Arithmetic_expression*) malloc(sizeof(Arithmetic_expression));
    //remplir l'element
    element->valeur = 0;
    strcpy(element->mot, par);
    strcpy(element->type, "parenthese");
    element->numPar = 0;
    element->priorite = 0;
    element->suivant = NULL;
    //premiere element
    if(arithmetic_expression_head == NULL){
        arithmetic_expression_head = element;
    }else{
        //le reste FIFO
        Arithmetic_expression * courant = arithmetic_expression_head;
        // Arithmetic_expression * courant = precedent->suivant;
        while(courant->suivant != NULL){
            courant = courant->suivant;
        }
        courant->suivant = element;
    }
}

void ajouter_operation_expression_arithmetique(char operation[]){
    //créer un nouvel element
    Arithmetic_expression *element = (Arithmetic_expression*) malloc(sizeof(Arithmetic_expression));
    //remplir l'element
    element->valeur = 0;
    strcpy(element->mot, operation);
    strcpy(element->type, "operation");
    element->numPar = 0;
    element->priorite = 0;
    element->suivant = NULL;
    //premiere element
    if(arithmetic_expression_head == NULL){
        arithmetic_expression_head = element;
    }else{
        //le reste FIFO
        Arithmetic_expression * courant = arithmetic_expression_head;
        // Arithmetic_expression * courant = precedent->suivant;
        while(courant->suivant != NULL){
            courant = courant->suivant;
        }
        courant->suivant = element;
    }
}

void gererParentheses(){
    //do this while there is a par_ov
    while(ilYaPar()){
        Arithmetic_expression *courant_ov = arithmetic_expression_head;
        bool isCut = false;
        while (courant_ov->suivant != NULL){
            Arithmetic_expression *courant_fr = courant_ov->suivant;
            if(strcmp(courant_ov->mot, "pr_ov") == 0){
                isCut = false;
                while(courant_fr != NULL && !isCut){
                    if(strcmp(courant_fr->mot, "pr_fr") == 0){
                        //si il ya un seul nombre entre parentheses  alors n'augment pas sa priorite
                        if(courant_ov->suivant->suivant != courant_fr){
                            //augmenter priorite
                            augmenterPrioriteEntre(courant_ov, courant_fr);
                        }
                        //supprimer parentheses
                        supprimerParentheses(courant_ov, courant_fr);
                        break;
                    }else if(strcmp(courant_fr->mot, "pr_ov") == 0){
                        isCut = true;
                    }else{
                        courant_fr = courant_fr->suivant;
                    }
                }
            }
            if(isCut){
                courant_ov = courant_fr;
            }else{
                courant_ov = courant_ov->suivant;
            }
        }
    }
}

bool ilYaPar(){
    Arithmetic_expression *courant_trv = arithmetic_expression_head;
    while(courant_trv != NULL){
        if(strcmp(courant_trv->mot, "pr_ov") == 0){
            return true;
        }
        courant_trv = courant_trv->suivant;
    }
    return false;
}

void augmenterPrioriteEntre(Arithmetic_expression *courant_ov, Arithmetic_expression *courant_fr){
    Arithmetic_expression *courant = courant_ov->suivant;
    while(courant != courant_fr && courant != NULL){
        courant->priorite++;
        courant = courant->suivant;
    }
}

void supprimerParentheses(Arithmetic_expression *courant_ov, Arithmetic_expression *courant_fr){
    Arithmetic_expression *courant_supp = arithmetic_expression_head;
    if(courant_supp == courant_ov){
        arithmetic_expression_head = courant_supp->suivant;
        courant_supp = courant_supp->suivant;
    }
    while (courant_supp != NULL){
        if(courant_supp->suivant == courant_ov){
            courant_supp->suivant = courant_ov->suivant;
        }else if(courant_supp->suivant == courant_fr){
            courant_supp->suivant = courant_fr->suivant;
        }
        courant_supp = courant_supp->suivant;
    }
}

float calculer_expression_arithmetique(int nbr_ligne){
    gererParentheses();
    //si l'expression arithmetique est compose d'un seul nombre  alors retourner cet nombre.
    if(arithmetic_expression_head->suivant == NULL){
        return arithmetic_expression_head->valeur;
    }
    //sinon  calculer le resultat de l'expression arithmetique
    int maxPriotite = getMaxPriorite();
    int minPriorite = getMinPriorite();
    while(maxPriotite >= minPriorite){
        Arithmetic_expression *courant1 = arithmetic_expression_head;
        while(courant1->suivant != NULL){
            if(courant1->priorite == maxPriotite){
                Arithmetic_expression *courant2 = courant1->suivant;
                while(courant2->suivant != NULL && courant2->suivant->priorite == maxPriotite){
                    courant2 = courant2->suivant;
                }
                if(courant1->suivant != courant2){
                    //calculer sub expression arithmetique.
                    // printf("calculer......  --------------------------------------------- \n");////////////////
                    calculer_sub_expression_arithmetique(courant1, courant2, nbr_ligne);
                    // printf("calcule termine --------------------------------------------- \n");///////////////
                }
                //sortir de la boucle.
                break;
            }
            courant1 = courant1->suivant;
        }
        maxPriotite = getMaxPriorite();
    }
    // printf("%f\n", arithmetic_expression_head->valeur);
    return arithmetic_expression_head->valeur;
}

int getMaxPriorite(){
    Arithmetic_expression *courant = arithmetic_expression_head;
    int currMax = courant->priorite;
    while(courant != NULL){
        if(courant->priorite > currMax){
            currMax = courant->priorite;
        }
        courant = courant->suivant;
    }
    return currMax;
}

int getMinPriorite(){
    Arithmetic_expression *courant = arithmetic_expression_head;
    int currMin = courant->priorite;
    while(courant != NULL){
        if(courant->priorite < currMin){
            currMin = courant->priorite;
        }
        courant = courant->suivant;
    }
    return currMin;
}

void calculer_sub_expression_arithmetique(Arithmetic_expression *courant1, Arithmetic_expression *courant2, int nbr_ligne){
    Arithmetic_expression *reste_expression = courant2->suivant;
    courant2->suivant = NULL;
    Arithmetic_expression *courant = courant1;
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // while(courant != NULL){
    //     if(strcmp(courant->type, "operation") == 0){
    //         printf("-%s\n", courant->mot);
    //     }else{
    //         printf("-%f\n", courant->valeur);
    //     }
    //     courant = courant->suivant;
    // }
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //calculer tout les divisions
    courant = chercherOperation(courant1, "dv");
    while(courant != NULL){
        //calculer valeur
        if(courant->suivant->suivant->valeur == 0){
            printf("erreur semantique a la ligne %d : division par 0 detecte.\n", nbr_ligne);
            afficher();
            exit(1);
        }else{
            courant->valeur = courant->valeur / courant->suivant->suivant->valeur;
            // printf("----- div_result = %f\n", courant->valeur);//////////////////////////////////////////
            //garder que le resultat
            if(courant->suivant->suivant->suivant != NULL){
                courant->suivant = courant->suivant->suivant->suivant;
            }else{
                courant->suivant = NULL;
            }
        }
        courant = chercherOperation(courant1, "dv");
    }
    
    //calculer tout les multiplications
    courant = chercherOperation(courant1, "mult");
    while(courant != NULL){
        //calculer valeur
        courant->valeur = courant->valeur * courant->suivant->suivant->valeur;
        // printf("----- mult_result = %f\n", courant->valeur);/////////////////////////////////////////
        //garder que le resultat
        if(courant->suivant->suivant->suivant != NULL){
            courant->suivant = courant->suivant->suivant->suivant;
        }else{
            courant->suivant = NULL;
        }
        courant = chercherOperation(courant1, "mult");
    }
    
    //calculer tout les soustractions
    courant = chercherOperation(courant1, "sus");
    while(courant != NULL){
        //calculer valeur
        courant->valeur = courant->valeur - courant->suivant->suivant->valeur;
        // printf("----- sus_result = %f\n", courant->valeur);/////////////////////////////////////////////
        //garder que le resultat
        if(courant->suivant->suivant->suivant != NULL){
            courant->suivant = courant->suivant->suivant->suivant;
        }else{
            courant->suivant = NULL;
        }
        courant = chercherOperation(courant1, "sus");
    }
    
    //calculer tout les additions
    courant = chercherOperation(courant1, "add");
    while(courant != NULL){
        //calculer valeur
        courant->valeur = courant->valeur + courant->suivant->suivant->valeur;
        // printf("----- add_result = %f\n", courant->valeur);/////////////////////////////////////////////
        //garder que le resultat
        if(courant->suivant->suivant->suivant != NULL){
            courant->suivant = courant->suivant->suivant->suivant;
        }else{
            courant->suivant = NULL;
        }
        courant = chercherOperation(courant1, "add");
    }
    //diminuer priorite
    courant1->priorite --;
    //re-attacher le reste de l'expression
    courant1->suivant = reste_expression;
}

Arithmetic_expression* chercherOperation(Arithmetic_expression *courant1, char operation[]){
    Arithmetic_expression *courant = courant1;
    if(courant->suivant != NULL){
        while(courant->suivant->suivant != NULL){
            if(strcmp(courant->suivant->mot, operation) == 0){
                return courant;
            }
            courant = courant->suivant;
        }
    }
    
    return NULL;
}

void affecter(char nom[], char valeur[]){
    Entite *entite = recherche(nom);
    //verifier que l'entite existe
    if(entite != NULL){
        strcpy(entite->valeur, valeur);
    }
}

void afficherAX(){
    Arithmetic_expression * courant = arithmetic_expression_head;
    printf(" _______________________________________________________________________\n");
    printf("|  valeur     |  mot         |  type        |  numPar    |  priorite    |\n");
    printf("|_____________|______________|______________|____________|______________|\n");
    while(courant != NULL){
        printf("|%12f |%12s  |%12s  |%11d |%13d |\n", courant->valeur, courant->mot, courant->type, courant->numPar, courant->priorite);
        courant = courant->suivant;
    }
    printf("|_____________|______________|______________|____________|______________|\n");
}

void afficher(){
    printf("\n/*************** Table des symboles ******************/\n");
    printf(" ______________________________________________________________________________________\n");
    printf("|  NomEntite  |  CodeEntite  |  TypeEntite  |  taille  |  estConstante  |    valeur    |\n");
    printf("|_____________|______________|______________|__________|________________|______________|\n");
    Entite *courant = head;
    while(courant != NULL){
        printf("|%12s |%12s  |%12s  |%8d  |%15s |%13s |\n", courant->nom, courant->code, courant->type, courant->taille, courant->estConstante, courant->valeur);
        courant = courant->suivant;
    }
    printf("|_____________|______________|______________|__________|________________|______________|\n");
}