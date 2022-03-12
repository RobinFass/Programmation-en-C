#include <stdio.h>
#include <stdlib.h>

char cesar(tab,taille);
char asterix(tab,taille);
int main(){
    char tab[6]={'c','o','u','c','o','u'};
    for (int i=0;i<6;i++){
        printf("%c",tab[i]);
    }
    printf("\n");
    cesar(tab,6);
    for (int i=0;i<6;i++){
        printf("%c",tab[i]);
    }
    printf("\n");
    asterix(tab,6);
    for (int i=0;i<6;i++){
        printf("%c",tab[i]);
    }
    printf("\n");
    return 0;
}

char cesar(char tab[], int taille){
    int i;
    for (i=0;i<taille;i++){
        tab[i]=(tab[i]-97+3)%26+97;
    }
}

char asterix(char tab[], int taille){
    int i;
    for (i=0;i<taille;i++){
        tab[i]=(tab[i]-97-3)%26+97;
    }
}
