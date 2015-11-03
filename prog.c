#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *VERSION = "0.0.02";

void treset(char x[])
{
    int i;
    for (i=0;i<999;i++)
        x[i] = 0;
}

/*
 
 Fonction : stroperateur(char chaine1[], char chaine2[],char chaineOP[], int ic)
 
 Note : Il sert a découper une chaine d'opération, chaine1 est l'operation complete, chaine2 sort une valeur comprise entre un signe, chaineOP sort le signe, ic est la valeur de positionnement dans chaine1
 
 Exemple :
 
 printf("\n\n\n\n\n\n\n\n\n\ndebut .. \n");
 
 int longeurdelachaine;
 char chaine[sizeof("1+100*4,3/2+(1,23/3)")] = "1+100*4,3/2+(1,23/3)";
 
 longeurdelachaine = strilen(chaine);
 
 printf("L equation est :\t %s chaine de %d long",chaine,longeurdelachaine);
 
 int parcourtDeLaChaine;
 char chaineOperant[100];
 char chaineSigne[2];
 
 parcourtDeLaChaine = 0;
 
 char suite[100];
 
 while (parcourtDeLaChaine < longeurdelachaine)
 {
 printf("parcourt de la chaine : %d\n",parcourtDeLaChaine);
 strcpy(chaineOperant,"");
 strcpy(chaineSigne,"");
 parcourtDeLaChaine = stroperateur(chaine,chaineOperant,chaineSigne,parcourtDeLaChaine);
 printf("\nnous sommes %d\tde la chaine\tla fonction renvoie :\t%s\tsigne : %s\n",parcourtDeLaChaine,chaineOperant,chaineSigne);
 sprintf(suite,"%s%s%s",suite,chaineSigne,chaineOperant);
 printf("SUITE OPERATOIRE : %s\n",suite);
 }
 
 
 */


int stroperateur(char chaine1[], char chaine2[],char chaineOP[], int ic)
{
    char signe[2];
    char c[2];
    char strret[100];
    int ifunc;
    
    strcpy(strret,"");
    
    c[0] = chaine1[ic];
    if ( (c[0] == '0') || (c[0] == '1') || (c[0] == '2') || (c[0] == '3') || (c[0] == '4') || (c[0] == '5') || (c[0] == '6') || (c[0] == '7') || (c[0] == '8') || (c[0] == '9') )
    {
        signe[0] = '\0';
        ifunc = 0;
    } else if ( (c[0] == '*') || (c[0] == '/') || (c[0] == '+') || (c[0] == '-') || (c[0] == '(') || (c[0] == ')') ) {
        signe[0] = c[0];
        ifunc = 1;
    } else {
        signe[0] = 0;
        ifunc = 0;
    }
    
    signe[1] = '\0';
    
    //printf("[FUNC stroperateur] ic = %d\t et le signe est : %s\tet ifunc : %d\n",ic,signe,ifunc);
    
    c[0] = 1;
    
    c[1] = 0;
    while (c[0] != 0)
    {
        c[0] = chaine1[ic+ifunc];
        //printf("caractere etudie : %s\t",c);
        if ( (c[0] == '*') || (c[0] == '/') || (c[0] == '+') || (c[0] == '-') || (c[0] == '(') || (c[0] == ')'))
        {
            c[0] = 0;
            //printf("C'est un signe\tla chaine est : .%s.\n",strret);
        } else {
            strcat(strret,c);
            //printf("Ce n'est pas un signe\tla chaine est : .%s.\n",strret);
            ifunc++;
        }
        
        
    }
    
    ifunc += ic;
    strcpy(chaine2,strret);
    strcpy(chaineOP,signe);
    //printf("ifunc == %d\n\n",ifunc);
    return ifunc;
}



/*
 
 FONCTION : isNomber(char chaine[])
 
 Retourne : 1 ou 0
 renvoie 1 si le contenue chaine[] est un nombre entier
 renvoie 0 si le contenue contient autre chose que des chiffres
 
 exemple :
 
 r = isNomber("1234")
 
 r == 1
 
 r = isNomber("123p");
 
 r == 0
 
 */
int isNomber(char chaine[])
{
    int i;
    char c;
    int ir;
    c = chaine[0]; ir = 1;
    while (c != 0)
    {
        if ( (c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') )
        {
            
            
        } else {
            ir = 0;
            break;
        }
        i++;
        c = chaine[i];
    }
    return ir;
}


/*
 
 FONCTION : strilen(char chaine[])
 
 retourne : retourne le nombre de char dans la chaine
 
 exemple :
 
 r = strilen("abcde")
 
 r == 5
 
 */
int strilen(char chaine[])
{
    int i;
    char c;
    c = 1;
    while (c!=0)
    {
        c = chaine[i];
        i++;
    }
    return (i-1);
}


/*
 
 FONCTION : strcmparray(char chaine1[100][100], char chaine2[], int *ic)
 
 retourne : 0 ou 1
 0 si aucune occurence trouvé
 1 si une occurence trouvé
 
 Note : chaine1 est une liste de chaine, chaine2 la chaine que l'on recherche dans chaine1 et ic le pointeur qui retourne la ligne du tableau ou l'occurence à été trouvé
 
 exemple :
 
 listedeschaines[0] = les chaussures
 listedeschaines[1] = des livres
 listedeschaines[2] = un poulet
 
 r = strcmparray(listedeschaines,"un poulet",i)
 
 r == 1
 
 i == 2
 
 */
int strcmparray(char chaine1[100][100], char chaine2[], int *ic)
{
    int i,ir;
    char c;
    char rc[1000];
    c = chaine1[0][0]; i = 0, ir = 0;
    while (c != 0)
    {
        //printf("strcmparray: .%s.==.%s.\n",chaine1[i],chaine2);
        if (strcmp(chaine1[i],chaine2) == 0) {
            ir = 1;
            break;
        }
        i++;
        c = chaine1[i][0];
    }
    
    *ic = i;
    return ir;
}

/*
 
 FONCTION : strretic(char chaine[], int ic, char chaineR[])
 
 retourne : void
 
 note : copie chaine dans chaineR de 0 à ic
 
 example :
 
 strretic("abcdefge",3,chainederetour)
 
 chainederetour == abc
 
 */
void strretic(char chaine[], int ic, char chaineR[])
{
    int i;
    char c;
    char rc[1000];
    c = 1;
    for (i=0;i<ic;i++)
        rc[i] = chaine[i];
    rc[i] = '\0';
    strcpy(chaineR,rc);
}

/*
 
 FONCTION : strsrchic(char chaine[],char srch)
 
 retourne : i
 
 note : renvoie la ligne de la chaine ou se trouve le caractère srch (le premier trouvé) retourne 0 si non trouvé
 
 exemple :
 
 r = strsrchic("le chat miaule",'a')
 
 r == 6
 
 */
int strsrchic(char chaine[],char srch)
{
    int i,x;
    char c;
    c = 1;
    x = 0;
    i = 0;
    while (chaine[i] != 0)
    {
        c = chaine[i];
        //printf("(str srch ic) .%c. == .%c.\n",c,srch);
        if (c == srch)
        {
            x = 1;
            break;
        }
        i++;
    }
    if (x) return i;
    return -1;
}

/*
 
 FONCTION : strcopy(char chaine1[],char chaine2[])
 
 retourne : rien
 
 note : semblable à strcpy
 
 */
void strcopy(char chaine1[],char chaine2[])
{
    int i;
    char c;
    
    i = 0; chaine2[0] = 'a';
    
    while (chaine1[i] != 0)
    {
        chaine2[i] = chaine1[i];
        i++;
    }
}

/*
 
 FONCTION : strremplaceSpace(char chaine[],char chaineR[])
 
 retourne : rien
 
 note : supprime tout les espaces de chaine et replace la nouvelle chaine dans chaineR
 
 exemple :
 
 strremplaceSpace("Je ne veux plus d'espace",chaineNouvelle)
 
 chaineNouvelle == Jeneveuxplusd'espace
 
 */

void strremplaceSpace(char chaine[],char chaineR[])
{
    int i, iz;
    char rc[1000];
    treset(rc);
    char c;
    i = 0, c = 'a', iz = 0;
    
    while (c != 0)
    {
        c = chaine[i];
        if (c != ' ')
        {
            rc[iz] = c;
            iz++;
        }
        i++;
    }
    
    strcpy(chaineR,rc);
}

/*
 
 FONCTION : strcremplace(char chaine[],char srch, char rep,char chaineR[])
 
 retourne : rien
 
 note : cherche dans la chaine[] les carractere srch et les remplaces par le carractere rep et renvoie la nouvelle chaine dans chaineR
 
 exemple :
 
 strcremplace("Le gateau est au chocolat",' ','_',chaineNouvelle)
 
 chaineNouvelle == Le_gateau_est_au_chocolat
 
 */

void strcremplace(char chaine[],char srch, char rep,char chaineR[])
{
    int i;
    char rc[1000];
    char c;
    treset(rc);
    i=0,c='a';
    while (c != '\0')
    {
        c = chaine[i];
        if (c == srch)
        {
            rc[i] = rep;
        } else {
            rc[i] = c;
        }        i++;
    }
    strcpy(chaineR,rc);
}

/*
 
 FONCTION : strbetween(char chaine[],char deb,char fi, char chaineR[])
 
 retourne : 1 ou 0
 1 si un résultat est trouvé
 0 si un résultat n'a pas été trouvé
 
 exemple :
 
 r = strbetween("le message est ici(non ici)",'(',')',chaineNouvelle)
 
 r == 1
 
 chaineNouvelle == non ici
 
 r = strbetween("je ne commence pas",'(',')',chaineNouvelle)
 
 r == 0
 
 chaineNouvelle ==
 
 */

int strbetween(char chaine[],char deb,char fi, char chaineR[])
{
    int i;
    int ic;
    int iz;
    int ix;
    char c;
    char rc[1000];
    
    int ireset;
    treset(rc);
    
    i = 0; iz = 0; ic = 0;
    c = 'a';
    ix = 1;
    
    if (deb == '\0') ic = 1;
    
    while (c != '\0')
    {
        c = chaine[i];
        if (c == fi) {
            ic = 0;
            ix = 0;
        }
        if (ic) {
            rc[iz] = c;
            iz++;
        }
        if (c == deb && c != '\0') ic = 1;
        i++;
    }
    rc[i]='\0';
    strcpy(chaineR,rc);
    if (strcmp(rc,"") != 0 && ix == 0) return 1;
    return 0;
}

/*
 
 FONCTION MAIN
 
 */

int main(int argc, char *argv[])
{
    printf("version: %s\n",VERSION);
    
    FILE *fpsource;
    FILE *fpdest;
    
    char chaine[100];
    char chaine2[2000];
    char chaine3[1000][100];
    char chainePourComm[1000][100];
    char chaineTradC[2000];
    char variable[100][100];
    char variabletype[100];
    char *c_ticket_var;
    char *string_variable_ligne;
    int i_variable;
    int nbligne;
    int ti_variable;
    int tvar;
    
    
    char fonctiontype[100];
    char fonction[1000][1000];
    int i_fonction;
    int fonction_now;
    char fonctiontemp[100];
    char *fonctionarguments;
    char *fonctionechar;
    int fonctionvirgu;
    
    int istric;
    char valeur_variable[1000];
    int ti_valeurvariable;
    
    
    int str_op;
    
    int ti_checkop;
    int len_op,pos_op;
    
    char DEC_VAR_TYPE[10][10];
    strcpy(DEC_VAR_TYPE[1],"int");
    strcpy(DEC_VAR_TYPE[2],"char");
    strcpy(DEC_VAR_TYPE[3],"char*");
    strcpy(DEC_VAR_TYPE[4],"void");
    
    int const DEC_VAR_INT = 1, DEC_VAR_CHAR = 2, DEC_VAR_ECHAR = 3, DEC_VAR_VOID = 4;
    
    
    // SCanf pour recuperer les nom des fichiers
    
    if (argc > 2)
    {
        fpsource = fopen(argv[1],"r"); // OUVRE LE FICHIER OU CE TROUVE LE SCRIPT
        if (fpsource == NULL)
        {
            fprintf(stdout,"Le fichier n'a pas pu etre lu\n");
        }
        
        fpdest = fopen(argv[2],"w"); // OUVRE LE FICHIER OU LE CODE C SERA PLACE
        if (fpdest == NULL)
        {
            fprintf(stdout,"Le fichier n'a pas pu etre creer ou ouvert\n");
        }
    } else
    {
        printf("\033[31;01mErreur, il faut mettre les arguments pendant le lancement du programme !\n %s repertoireScript repertoireCodeC [-read/-compile]\nExtinction\033[00m\n",argv[0]);
        
        exit(1);
    }
    
    nbligne = 0;
    
    while (fgets(chaine, 1000, fpsource) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        strcat(chaine3[nbligne],chaine); // CHAINE DE CARACTERE OU IL SERA TRAVAILLE LIGNE PAR LIGNE
        nbligne++;                       // INCREMENTE NBLIGNE
        strcat(chaine2,chaine);         // AJOUTE LA NOUVELLE LIGNE DANS LA CHAINE2
        strcat(chainePourComm[nbligne],chaine); // AJOUTE LA CHAINE DANS LA LIGNE DANS LE TABLEAU CHAINEPOURCOMM
        
    }
    
    int ifor;
    char t[100];
    char t2[100];
    char t3[100];
    char t4[100];
    char t5[100];
    char t6[100];
    char t7[100];
    
    i_variable = 0; i_fonction = 0;
    
    
    
    printf("\n\n");
    for (ifor = 0;ifor < (nbligne);ifor++)
    {
        strremplaceSpace(chaine3[ifor],chaine3[ifor]); // SUPPRIME DANS LA CHAINE3[IFOR] TOUT LES ESPACES
        strcremplace(chaine3[ifor],'\n','\0',chaine3[ifor]); // SUPPRIME DANS LA CHAINE3[IFOR] TOUT LES RETOUR A LA LIGNE
        printf("[%d]\t\t%s\n",ifor,chaine3[ifor]);
        
        /*
         * ICI C EST LES VARIABLES
         */
        
        if (strncmp(chaine3[ifor],"#",1) == 0) // SI DANS LA LIGNE LE PREMIER CARACTERE EST UN # ALORS SA VEUT DIRE QUE C'EST UNE DECLARATION DE VARIABLE
        {
            printf(" // ici une déclaration de variable\n");
            strcpy(t,"");
            if (strbetween(chaine3[ifor],'#','(',t)){ // PLACE DANS t LA CHAINE DE CARACTERE ENTRE # ET (
                strcopy(t,variable[i_variable]);      // PLACE DANS variable[i_variable] LA CHAINE DE CARACTERE t
                strcpy(t,"");
                if (strbetween(chaine3[ifor],'(',')',t)){ // PLACE DANS t LA CHAINE DE CARACTERE ENTRE ( et ) SOIT LE TYPE DE LA VARIABLE
                    
                    
                    
                    if ((strcmp(t,"n") == 0) || (strcmp(t,"nombre") == 0)) // SI t EST N OU NOMBRE
                    {
                        variabletype[i_variable] = DEC_VAR_INT;
                    } else if ((strcmp(t,"l") == 0) || (strcmp(t,"lettre") == 0)) // SI t EST L OU LETTRE
                    {
                        variabletype[i_variable] = DEC_VAR_CHAR;
                    } else if ((strcmp(t,"c") == 0) || (strcmp(t,"chaine") == 0)) // SI t EST C OU CHAINE
                    {
                        variabletype[i_variable] = DEC_VAR_ECHAR;
                    } else {                                                      // SI CE N EST AUCUN DES TROIS
                        puts("\033[31;01merreur lors de la déclaration de la variable1");
                    }
                } else {                                                          // Si il n y a pas de  ')' dans la chaine cela veut dire qu'il n'y a pas de type c'est donc une erreur
                    puts("\033[31;01merreur lors de la déclaration de la variable2\033[00m");
                }
                
                
            } else {        // Si il n y a pas les '(' et ')' alors il n'y a pas de type lors de la déclaration
                puts("\033[31;01merreur lors de la déclaration de la variable3\033[00m");
            }
            
            if (fonction_now) // Si c'est la déclaration se fait dans une fonction alors il prends en plus le nom de la fonction nomdelavariable_nomdelafonction
            {
                sprintf(variable[i_variable],"%s_%s",variable[i_variable],fonction[i_fonction]);
            }
            //printf("[CODE C]\t%s %s;\n",DEC_VAR_TYPE[variabletype[i_variable]],variable[i_variable]);
            
            fprintf(fpdest,"%s %s;\n",DEC_VAR_TYPE[variabletype[i_variable]],variable[i_variable]);
            
            i_variable++; // Passe a la variable suivante
            
        }
        
        /*
         * ICI C EST LA FIN DES VARIABLES
         *
         *
         *
         * ICI C EST LES FONCTIONS
         *
         */
        
        if (strncmp(chaine3[ifor],"_",1) == 0) // Si la chaine commence par un _ alors c'est une déclaration de fonction
        {
            
            strcpy(t,"");
            if (strbetween(chaine3[ifor],'.','(',t)) // Met la chaine qui se trouve entre . et ( dans t
            {
                if (strcmp(t,"debut") == 0) // Si t == debut , soit le début de la déclaration
                {
                    fonction_now = 1;   // On rentre alors dans une fonction
                    strcpy(t,"");
                    strbetween(chaine3[ifor],'_','.',t); // Met la chaine qui se trouve entre _ et . dans t
                    strcpy(fonction[i_fonction],t);      // Met le nom de la fonction dans la variable dans la ligne de sa propre fonction
                    strbetween(chaine3[ifor],'(',')',t); // Met la chaine qui se trouve entre ( et ) soit le type de la fonction
                    sprintf(t,"%c",t[0]);                // Prends le premier caractere
                    
                    if ((strcmp(t,"n") == 0) || (strcmp(t,"nombre") == 0))
                    {
                        fonctiontype[i_fonction] = DEC_VAR_INT;
                    } else if ((strcmp(t,"l") == 0) || (strcmp(t,"lettre") == 0))
                    {
                        fonctiontype[i_fonction] = DEC_VAR_CHAR;
                    } else if ((strcmp(t,"c") == 0) || (strcmp(t,"chaine") == 0))
                    {
                        fonctiontype[i_fonction] = DEC_VAR_ECHAR;
                    } else if ((strcmp(t,"v") == 0) || (strcmp(t,"vide") == 0) || (strcmp(t,"") == 0))
                    {
                        fonctiontype[i_fonction] = DEC_VAR_VOID;
                    } else {
                        puts("erreur lors de la déclaration de la fonction");
                    }
                    
                    fprintf(fpdest,"%s %s(",DEC_VAR_TYPE[fonctiontype[i_fonction]],fonction[i_fonction]); // Ajoute dans le fichier C le type puis le nom de la fonction
                    strcpy(t,"");
                    
                    strcpy(t3,"");
                    
                    fonctionvirgu = 0;
                    
                    if (strbetween(chaine3[ifor],'[',']',t)) // Cherche la chaine qui ce trouve entre [ et ], soit les arguments
                    {
                        fonctionechar = strdup(t); // Duplique la chaine [] en *
                        while ((fonctionarguments = strsep(&fonctionechar,","))) // étape par étape il décompose la chaine par rapport à la virgule
                        {
                            if (fonctionvirgu != 0) strcat(t3,","); // Si c'est la premiere fois il ne met pas la virgule
                            fonctionvirgu++;
                            
                            printf("%s\n",fonctionarguments);
                            strcpy(t2,"");
                            if (strbetween(fonctionarguments,'(',')',t2)) // Recherche dans la chaine le type de l argument
                            {
                                if ((strcmp(t2,"n") == 0) || (strcmp(t2,"nombre") == 0))
                                {
                                    strcat(t3,DEC_VAR_TYPE[DEC_VAR_INT]);
                                    strcat(t3," ");
                                    variabletype[i_variable] = DEC_VAR_INT;
                                } else if ((strcmp(t2,"l") == 0) || (strcmp(t2,"lettre") == 0))
                                {
                                    strcat(t3,DEC_VAR_TYPE[DEC_VAR_CHAR]);
                                    strcat(t3," ");
                                    variabletype[i_variable] = DEC_VAR_CHAR;
                                } else if ((strcmp(t2,"c") == 0) || (strcmp(t2,"chaine") == 0))
                                {
                                    strcat(t3,DEC_VAR_TYPE[DEC_VAR_ECHAR]);
                                    strcat(t3," ");
                                    variabletype[i_variable] = DEC_VAR_ECHAR;
                                } else {
                                    puts("\033[31;01merreur lors de la déclaration de la fonction\033[00m");
                                }
                            } else {
                                printf("\033[31;01mla variable lors de la déclaration de fonction n'a pas de type, c'est obligatoire !\n\033[00m");
                            }
                            strcpy(t4,"");
                            strcpy(t5,"");
                            sprintf(t5,"%s",fonctionarguments); // Transfert * en []
                            strbetween(t5,'\0','(',t4);         // Met le nom de l'argument dans t4
                            strcat(t4,"_");
                            strcat(t4,fonction[i_fonction]);
                            strcat(t3,t4);                      // met t4 à la suite de t3 (t3 est la chaine continue des arguments
                            
                            strcpy(variable[i_variable],t4);
                            i_variable++;
                            printf("here\n");
                        }
                        fprintf(fpdest,"%s)\n{\n",t3); // Ajoute dans le code C la chaine des arguments et l ouverture de la fonction
                    } else {
                        fprintf(fpdest,")\n{\n"); // Si il n'y a pas d'arguments alors il ferme la ) et ouvre la fonction
                    }
                    
                    
                }
            } else
            {
                
                
                /** FIN FONCTION **/
                strcpy(t,"");
                if (strbetween(chaine3[ifor],'.','\0',t))
                {
                    //                if (strcmp(t,"debut") == 0)
                    //                {
                    //                    printf("DEBUT FONC");
                    //
                    //                    fonction_now = 1;
                    //                    strcpy(t,"");
                    //                    strbetween(chaine3[ifor],'_','.',t);
                    //                    strcpy(fonction[i_fonction],t);
                    //                    fonctiontype[i_fonction] = 4;
                    //                    fprintf(fpdest,"%s %s()\n{\n",DEC_VAR_TYPE[fonctiontype[i_fonction]],fonction[i_fonction]);
                    //
                    //                } else
                    if (strcmp(t,"fin") == 0) // FIN DE FONCTION
                    {
                        printf("FIN FONC \n");
                        
                        strcpy(t,"");
                        strbetween(chaine3[ifor],'_','.',t); // Met le nom de la fonction dans la variable t
                        if (strcmp(fonction[i_fonction],t) == 0) // Compare si la terminaisons de la fonction est celle de départ
                        {
                            fprintf(fpdest,"} // fin de la fonction %s\n\n\n",fonction[i_fonction]); // Ajoute dans le fichier C la fin de fonction
                            i_fonction++; // On passe à la fonction suivante
                            fonction_now = 0; // Sort de la fonction
                        } else{
                            puts("\033[31;01mERREUR DANS LA FONCTION\033[00m"); // Si le nom de la fonction.fin n'est pas la meme que celle de .debut
                        }
                    }
                    
                    
                }
                
            }
        }
        
        /*
         * FIN FONCTION
         */
        
        
        /*
         * ATTRIBUTION DES VALEURS
         */
        strcpy(t,"");
        if (strbetween(chaine3[ifor],'=','\0',t) == 1) // Recherche de la du premier = à la fin de la chaine
        {
            strcpy(valeur_variable,t); // Introduit le résultat dans valeur_variable
            istric = strsrchic(chaine3[ifor],'='); // Recherche cb de lettre avant le =
            strcpy(t,"");
            strretic(chaine3[ifor],istric,t); // Nom de la variable
            
            if (fonction_now) { // si on est dans une fonction
                sprintf(t,"%s_%s",t,fonction[i_fonction]); // on ajoute _nomdelafonction au nom de la variable
            }
            
            if (strcmparray(variable,t,&ti_variable)) // Recherche la variable dans la liste déclaré
            {
                printf("variable trouve\n");
                printf("%s = %s\t%d\n",variable[ti_variable],t,ti_variable);
                
                /*
                 Regarde si la valeur est elle meme une variable
                 */
                
                if (fonction_now)
                {
                    strcpy(t2,"");
                    sprintf(t2,"%s_%s",valeur_variable,fonction[i_fonction]);
                } else
                {
                    strcpy(t2,valeur_variable);
                }
                
                if (strcmparray(variable,t2,&ti_valeurvariable)) // Si la valeur est une variable declaré dans la fonction
                {
                    if (variabletype[ti_valeurvariable] == variabletype[ti_variable]) // Si les deux types sont identiiques
                    {
                        fprintf(fpdest,"%s = %s;\n",t,variable[ti_valeurvariable]);
                    } else
                    {
                        printf("\033[31;01mla valeur valeur n'est pas du même type que ce attribue\n\033[00m");
                    }
                } else
                { // SI la valeur n'est pas une variable
                    printf("valeur = %s\n",valeur_variable);
                    //if ( strcmparray(tcr_op,valeur_variable,&ti_checkop) ) // Si c'est une chaine opératoire
                    
                    if ((strsrchic(valeur_variable,'+') > -1) || (strsrchic(valeur_variable,'-') > -1) || (strsrchic(valeur_variable,'*') > -1) || (strsrchic(valeur_variable,'/') > -1) || (strsrchic(valeur_variable,'(') > -1) || (strsrchic(valeur_variable,')') > -1))
                    {
                        //printf("CHAINE OP \n");
                        strcpy(t2,valeur_variable);
                        len_op = 0;
                        len_op = strilen(t2);
                        strcpy(t4,"");
                        strcpy(t5,"");
                        strcpy(t6,"");
                        strcpy(t7,"");
                        pos_op = 0;
                        
                        //printf("(operatoire) la longeur de la chaine operatoire est de : %d",len_op);
                        
                        while (pos_op < len_op)
                        {
                            strcpy(t4,"");
                            strcpy(t5,"");
                            strcpy(t6,"");
                            pos_op = stroperateur(valeur_variable,t4,t5,pos_op);
                            
                            //t4 = valeur
                            //t5 = signe
                            
                            if (fonction_now)
                            {
                                sprintf(t6,"%s_%s",t4,fonction[i_fonction]);
                            } else
                            {
                                strcpy(t6,t4);
                            }
                            
                            //printf("(operatoire) variable t6 = %s\n",t6);
                            
                            if (strcmparray(variable,t6,&ti_checkop)) // Si la valeur est une variable
                            {
                                //printf("c'est une variable\n");
                                sprintf(t7,"%s%s%s",t7,t5,t6);
                            } else //Si ce n'est pas une variable mais une valeur
                            {
                                switch (variabletype[ti_variable]) // En fonction du type il existe différent moyen de la traité
                                {
                                    case 1:                  // Si la variable est un nombre
                                        if (isNomber(t4)) // Verifie que c'est bien un nombre
                                        {
                                            sprintf(t7,"%s%s%s",t7,t5,t4); // Ajoute a la suite de la chaine operatoir
                                        } else {
                                            printf("\033[31;01mattribution de valeur invalide, il ne faut que des chiffres dans un entier !\033[00m");
                                        }
                                        break;
                                    case 2:                // Si la variable est un char
                                        
                                        tvar = strilen(t4);
                                        
                                        switch (tvar) { // En fonction de la taille de la valeur
                                            case 1: // Si c'est seulement 1 caractere
                                                sprintf(t7,"%s%s'%s'",t7,t5,t4); // Ajoute a la suite operatoire
                                                break;
                                            case 2: // Si c'est en deux caractere
                                                if (t4[0] == '\\') // Il faut que le premier soit un "\"
                                                {
                                                    sprintf(t7,"%s%s'%s'",t7,t5,t4); // Ajoute a la suite operatoire// Ajoute dans le fichier C
                                                } else {
                                                    if (isNomber(t4))
                                                    {
                                                        sprintf(t7,"%s%s%s",t7,t5,t4);
                                                    } else
                                                    {
                                                        printf("\033[31;01mattribution valeur non conforme\033[00m");
                                                    }
                                                }
                                                break;
                                            default:
                                                printf("\033[31;01mattribution valeur non conforme\033[00m");
                                                break;
                                        }
                                        break;
                                    default:
                                        printf("\033[31;01mla valeur %s n'a pas un type correct pour une attribution de valeur\033[00m",t4);
                                        break;
                                        
                                }
                            }
                            
                        }
                        
                        //printf("la Suite opératoire est %s",t7);
                        fprintf(fpdest,"%s=%s;\n",variable[ti_variable],t7);
                        
                    } else { //
                        
                        switch (variabletype[ti_variable]) // En fonction du type il existe différent moyen de la traité
                        {
                            case 1:                  // Si la variable est un nombre
                                if (isNomber(valeur_variable)) // Verifie que c'est bien un nombre
                                {
                                    fprintf(fpdest,"%s = %s;\n",t,valeur_variable); // Ajoute au fichier C
                                } else {
                                    printf("\033[31;01mattribution de variable invalide, il ne faut que des chiffres dans un entier ! et sans virgule ou point\033[00m");
                                }
                                break;
                            case 2:                // Si la variable est un char
                                printf("CHAR   %d \n",strilen(valeur_variable));
                                
                                tvar = strilen(valeur_variable);
                                
                                switch (tvar) { // En fonction de la taille de la valeur
                                    case 1: // Si c'est seulement 1 caractere
                                        fprintf(fpdest,"%s = '%s';\n",t,valeur_variable); // Ajoute dans le fichier C
                                        break;
                                    case 2: // Si c'est en deux caractere
                                        if (valeur_variable[0] == '\\') // Il faut que le premier soit un "\"
                                        {
                                            fprintf(fpdest,"%s = '%s';\n",t,valeur_variable); // Ajoute dans le fichier C
                                        } else {
                                            printf("\033[31;01mattribution variable non conforme");
                                        }
                                        break;
                                    default:
                                        printf("\033[31;01mattribution variable non conforme\033[00m");
                                        break;
                                }
                                break;
                            default:
                                printf("\033[31;01mla variable %s n'a pas un type correct pour une attribution de valeur\033[00m",t);
                                break;
                                
                        }
                    } //
                }
                
            } else {
                printf("\033[31;01mla variable %s n'est pas déclaré\n\033[00m",t);
            }
            
        }
        
        /*
         * FIN DES ATTRIBUTION VALEURS
         */
        
        /*
         * INSERTION COMM
         */
        
        if (strncmp(chaine3[ifor],"-",1) == 0) // Si dans la chaine le premier caractere est un '-'
        {
            fprintf(fpdest,"// %s\n",chainePourComm[ifor+1]); // Ajoute dans le fichier C le commentaire
        }
        
        /*
         * FIN INSERTION COMM
         */
        
        /*
         * RETOUR FONCTION
         */
        
        if (strncmp(chaine3[ifor],"@",1) == 0) // Si le premier caractere est un @
        {
            if (fonction_now) // Si c'est dans une fonction (en même temps il ne peut pas y avoir de retour sans que cela soit dans une fonction
            {
                strcpy(t,"");
                if (strbetween(chaine3[ifor],'@','\0',t)) // Met dans t de @ jusquà la fin de la chaine soit la valeur de retour
                {
                    strcat(t,"_");
                    strcat(t,fonction[i_fonction]); // Ajoute à t _nomdelafonction
                    if (strcmparray(variable,t,&ti_variable)) // Verifie si la valeur de retour est une variable deja declare
                    {
                        if (variabletype[ti_variable] == fonctiontype[i_fonction]) // Si c'est bien le cas, et que la variable est déclaré alors il vérifie si le type de fonction est égale avec le type de variable
                        {
                            printf("GOOD IS TOO TYPE\n");
                            fprintf(fpdest,"return %s;\n",variable[ti_variable]); // Ajoute dans le fichier C le retour avec le nom de la variable
                        } else {
                            printf("\033[31;01mNOT GOOD DOSNT TOO TYPE\n\033[00m"); // Pas le bon type de fonction par rapport au type de la variable
                        }
                    } else // Si ce n'est pas une variable en retour
                    {
                        strcpy(t,"");
                        strbetween(chaine3[ifor],'@','\0',t);
                        if (isNomber(t)) // Recheche si c'est un nombre
                        {
                            if (fonctiontype[i_fonction] == DEC_VAR_INT) //Si la fonction est de type int
                            {
                                printf("GOOD IS INT TYPE");
                                fprintf(fpdest,"return %s;\n",t); // Ajoute dans le fichier C
                            } else // Si la fonction n'est pas int
                            {
                                printf("\033[31;01mNOT GOOD IS NOT INT TYPE\033[00m");
                            }
                        } else
                        {
                            if (fonctiontype[i_fonction] == DEC_VAR_CHAR) // Si la fonction est de type char
                            {
                                tvar = strilen(t);
                                
                                switch (tvar) // En fonction de la taille de la valeur
                                {
                                    case 1:             // Si elle est de taille une
                                        printf("1 CHAR");
                                        fprintf(fpdest,"return '%s';\n",t); // Ajoute dans le fichier C le retour d un char
                                        break;
                                    case 2:            // Si elle est de taille deux
                                        if (t[0] == '\\') // il faut que le premier caractere soit un "\"
                                        {
                                            fprintf(fpdest,"return '%s';\n",t); // Ajoute dans le fichier C le retour d un char
                                        } else {    // Si le premier caractere n'est pas un "\"
                                            printf("\033[31;01mattribution retour non conforme\033[00m");
                                        }
                                        break;
                                    default:
                                        printf("\033[31;01mattribution retour non conforme\033[00m"); // si c'est plus de deux de taille
                                        break;
                                }
                            }
                            
                            
                        }
                    }
                } else
                { // retour inconnu par le code
                    printf("\033[31;01mNOT GOOD INCONNU RETURN\033[00m");
                }
                
                
                
                printf("retourne %s\n",t);
            }
        }
        
        printf("[.%s.]",fonction[i_fonction]);
    }
    printf("\n\n");
    
    fclose(fpsource);
    fclose(fpdest);
    
    
    if (argc > 3)
    {
        int iOption;
        
        for (iOption=3;iOption<argc;iOption++)
        {
            if (strcmp(argv[iOption],"-r") == 0 || strcmp(argv[iOption],"-read") == 0)
            {
                printf("\n\nLECTURE DU FICHIER %s :\n\n",argv[2]);
                char printfcat[100];
                sprintf(printfcat,"cat %s",argv[2]);
                system(printfcat);
            }
            if (strcmp(argv[iOption],"-c") == 0 || strcmp(argv[iOption],"-compile") == 0)
            {
                printf("\n\n\t[Compilation du programme]\n\n");
                char printfgcc[100];
                int gcc;
                sprintf(printfgcc,"gcc %s",argv[2]);
                gcc = system(printfgcc);
                if (gcc != 0)
                {
                    printf("\n\n\n\t\033[31;01mLa compilation a echoue\n\033[00m");
                } else
                {
                    printf("\n\n\t Compilation reussi\n");
                }
            }
        }
    }
    
    exit(0);
}
