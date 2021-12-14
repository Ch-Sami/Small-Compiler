%{
    extern int var_bib_io;
    extern int var_bib_lang;
    extern int nbr_ligne;
    #include "synt.tab.h"
    #include "functions.h"
    extern YYSTYPE yylval;
%}
idf \$[a-zA-Z]([a-zA-Z]|[0-9]|_)*
nom_tableau \@[a-zA-Z]([a-zA-Z]|[0-9]|_)*
cst 0|[1-9][0-9]*
entier (\-|\+)?(0|[1-9][0-9]*)
reel (\-|\+)?(0|[1-9][0-9]*)\.([0-9]*[1-9]|0)
chaine \"[^"]*\"
commentaire ##[^#]*##

%%
ISIL.io return bib_io;
ISIL.lang return bib_lang;
import return mc_import;
private return mc_private;
public return mc_public;
protected return mc_protected;
class return mc_class;
\{ return aco_ov;
\} return aco_fr;
entier {
    yylval.chaine=strdup(yytext);
    return mc_entier;
    }
reel {
    yylval.chaine=strdup(yytext);
    return mc_reel;
    }
chaine {
    yylval.chaine=strdup(yytext);
    return mc_chaine;
    }
CONST {
    yylval.chaine=strdup(yytext);
    return mc_const;
    }
; return pvg;
, return vrg;
\[ return cr_ov;
\] return cr_fr;
\" return quotation_mark;
main return mc_main;
\( return pr_ov;
\) return pr_fr;
:= return aff;
\+ return add;
\- return sus;
\* return mult;
\/ return dv;
\= return equals;
\!\= return not_equals;
\< return inf;
\<\= return inf_or_equals;
\> return sup;
\>\= return sup_or_equals;
for return mc_for;
in return mc_in;
out return mc_out;

{idf} {
        if(yyleng<=20){
            yylval.chaine=strdup(yytext);
            inserer(yytext,"idf");
            return idf;
        }
    }
{nom_tableau} {
        if(yyleng<=20){
            yylval.chaine=strdup(yytext);
            inserer(yytext,"nom_tableau");
            return nom_tableau;
        }
    }
{cst} {
    yylval.entier = atoi(yytext);
    return cst;
    }
{entier} {
    yylval.entier = atoi(yytext);
    return entier;
    }
{reel} {
    yylval.reel = atof(yytext);
    return reel;
    }
{chaine} {
    yylval.chaine=strdup(yytext);
    return chaine;
}

[ \t]
\n nbr_ligne++;

{commentaire}

. {printf("Erreur lexical a la ligne %d sur l'entite %s \n", nbr_ligne, yytext);
   return err;}

%%