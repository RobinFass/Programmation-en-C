#include <stdio.h>
#include <stdlib.h>

enum couleur {Pique, Coeur, Trefle, Carreau};
enum valeur {Sept, Huit, Neuf, Dix, Valet, Dame, Roi, As};
typedef struct Carte C;
typedef enum couleur c;
typedef enum valeur v;

struct Carte{
    v valeur;
    c couleur;
};

void show(C carte);

void show(C carte){
    char cou[4]={'Pique','Coeur','Trefle','Carreau'};
    char val[8]={'Sept', 'Huit', 'Neuf', 'Dix', 'Valet', 'Dame', 'Roi', 'As'};
    printf("(%c,%c)", val[carte.valeur],cou[carte.couleur]);
}

int main(){
    C carte;
    carte.valeur=Dix;
    carte.couleur=Pique;
    show(carte);
    return 0;
}
