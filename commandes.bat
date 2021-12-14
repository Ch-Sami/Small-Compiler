flex lexical.l
bison -d synt.y
gcc lex.yy.c synt.tab.c  -o comp_isil_2021.exe