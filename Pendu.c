#include <stdio.h>
#include <stdlib.h>

///declaration



///declaration

int main(){
    int taille=5;
    int vie=10, test=0,tvie=0;
    char lettre;
    char motsec[5]={'s','a','l','u','t'};
    char mot[5]={'-','-','-','-','-'};
    while(vie){
            printf("\nVotre vie:%d\n",vie);
        printf("Voici le mot:\n");
        for (int i=0; i<5;i++){
            printf("%c",mot[i]);
        }
        printf("\nQuelle est votre lettre ?: ");
        scanf(" %c",&lettre);
        for (int i=0; i<5;i++){
            if(motsec[i]==lettre){
                mot[i]=lettre;
                tvie=1;
            }
        }
        if (tvie==0){vie--;}
        tvie=0;
        for (int i=0; i<5;i++){
            if (motsec[i]!=mot[i]){
                test=1;
            }
        }
        if (!test){
            printf("\nGG vous avez gagne !<3");
            return 0;
        } else {
            test=0;
        }
    }
    printf("Plus d'essaie vous etes pendu !");
    return 0;
}
