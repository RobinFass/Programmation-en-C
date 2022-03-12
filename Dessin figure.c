#include <stdio.h>
#include <stdlib.h>

int verif_h(int h,char choix);
int verif_c(int h,char choix);
int verif_t(int h);

void instru(){
    printf("Instructions:\n   Afficher sapin droite (a)\n   Afficher sapin gauche (b)\n   Afficher sapin complet (c)\n   Afficher carre (d)\n   Afficher losange (e)\n   Afficher cinq (f)\n   Afficher instructions (h)\n   Quitter (q)\n\n");
    printf("Votre choix ?\n");
}

void demi_sap(int h,char c){
    int l=0;
    if (c=='a'){
        for (;h>0;h--){
            l++;
            for (int compte=0;compte<l;compte++){printf("*");}
            printf("\n");
        }
        printf("\n");
    } else {
        for (;h>0;h--){
            l++;
            for (int compte=-h+1;compte<0;compte++){printf(" ");}
            for (int compte=0;compte<l;compte++){printf("*");}
            printf("\n");
        }
        printf("\n");
    }
}

void sapin(int h){
    int l=0;
    for (;h>0;h--){
        l++;
        for (int compte=-h+1;compte<0;compte++){printf(" ");}
        for (int compte=0;compte<2*l-1;compte++){printf("*");}
        printf("\n");
    }
    for (int compte=0;compte<l-1;compte++){printf(" ");}
    printf("*\n\n");
}

int cas_hauteur(char choix){
    int hauteur;
    printf("Hauteur ?\n");
    scanf("%d",&hauteur);

    if (!verif_h(hauteur,choix)){return cas_hauteur(choix);};

    if (choix=='a'){demi_sap(hauteur,'a');}
    else if (choix=='b'){demi_sap(hauteur,'b');}
    else {sapin(hauteur);}
    return 0;
}

void carre(int c){
    if (c==1){printf("*\n\n");}
    else{
        for (int compte=1;compte<c;compte++){printf("*");}
        printf("*\n");
        for (int compte=c-2;compte>0;compte--){
            printf("*");
            for (int compte=c-2;compte>0;compte--){printf(" ");}
            printf("*\n");
        }
        for (int compte=1;compte<c;compte++){printf("*");}
        printf("*\n\n");
    }
}

void losange(int c){
    int c_bis=c,l=0,esp=0;
    for (;c>0;c--){
        for (int compte=-c+1;compte<0;compte++){printf(" ");}
        printf("/");
        for (int compte=0;compte<esp;compte++){printf(" ");}
        printf("\\\n");
        esp+=2;
    }
    esp-=2;
    for (;c_bis>0;c_bis--){
        l++;
        for (int compte=0;compte<l-1;compte++){printf(" ");}
        printf("\\");
        for (int compte=0;compte<esp;compte++){printf(" ");}
        printf("/\n");
        esp-=2;
    }
    printf("\n");
}

int cas_cote(char choix){
    int cote;
    printf("Cote ?\n");
    scanf("%d",&cote);

    if (!verif_c(cote,choix)){return cas_cote(choix);}

    if (choix=='d'){carre(cote);}
    else {losange(cote);}
    return 0;
}

int cinq(){
    int taille;
    printf("Taille ?\n");
    scanf("%d",&taille);

    if (!verif_t(taille)){return cinq();}
    for (int compte=1;compte<taille;compte++){printf("*");}
    printf("*\n");

    for (int compte=taille-2;compte>0;compte--){printf("*\n");}

    for (int compte=1;compte<taille;compte++){printf("*");}
    printf("*\n");

    for (int compte=taille-2;compte>0;compte--){
        for (int compte=taille-1;compte>0;compte--){printf(" ");}
        printf("*\n");
    }

    for (int compte=0;compte<taille;compte++){printf("*");}
    printf("\n\n");
    return 0;
}

int verif_h(int h,char choix){
    if (h<=0){printf("Erreur de saisie. ");return 0;}
    return 1;
}

int verif_c(int h,char choix){
    if (h<=0){printf("Erreur de saisie. ");return 0;}
    return 1;
}

int verif_t(int h){
    if (h<3){printf("Erreur de saisie. ");return 0;}
    return 1;
}

int main(){
    char choix='z';
    int test=0;
    instru();

    while (choix!='q'){
        scanf(" %c",&choix);

        if (choix=='a'||choix=='b'||
            choix=='c'||choix=='d'||
            choix=='e'||choix=='f'||
            choix=='h'){
                if(choix=='a'||choix=='b'||choix=='c'){cas_hauteur(choix);}
                else if(choix=='d'||choix=='e'){cas_cote(choix);}
                else if (choix=='f'){cinq();}
                else {instru();}

        } else if (choix=='q'){return 0;}
        else {printf("Erreur de saisie. ");choix='h';test=1;}

        if (choix!='h'){printf("Autre choix ?\n");}
        else if (choix!='h'||test==1){printf("Votre choix ?\n");}
    }
    return 0;
}

