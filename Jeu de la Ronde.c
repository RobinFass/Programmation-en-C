#include <stdio.h>
#include <stdlib.h>

typedef struct Ronde Ronde;
struct Ronde{
    char nom;
    Ronde *next;
};

typedef struct Liste Liste;
struct Liste{
    Ronde *first;
};

Liste *init_liste(){
    Ronde *ronde=malloc(sizeof(*ronde));
    Liste *liste=malloc(sizeof(*liste));

    printf("Nom de l'enfant 1:\n");
    scanf(" %c",&ronde->nom);
    ronde->next=NULL;
    liste->first=ronde;
    return liste;
}

void setliste(Liste *liste, int n){
    for(int i=2;i<n+1;i++){
        Ronde *ronde=malloc(sizeof(*ronde));
        printf("Nom de l'enfant %d:\n",i);
        scanf(" %c",&ronde->nom);

        ronde->next=NULL;

        Ronde *actu=liste->first;
        Ronde *dernier;
        while(actu!=NULL){
            dernier=actu;
            actu=actu->next;
        }
        dernier->next=ronde;
    }
}

void affiche(Liste *liste, int *n, int k){
    Ronde *actu=liste->first;
    Ronde *der;
    int stop=0;
    while (actu!=NULL && stop<n){
        der=actu;
        printf("%c -> ",actu->nom);
        actu=actu->next;
        stop++;
    }
    if (k==-1){printf("Le vainqueur est %c\n",der->nom);}
    else{printf("fin\n");}
}

void setvalue(int *n, int *k){
    printf("Le nombre N:\n");
    scanf("%d",n);
    printf("Le nombre K:\n");
    scanf("%d",k);
}

void setrond(Liste *liste){
    Ronde *actu=liste->first;
    Ronde *dernier;
    while(actu!=NULL){
        dernier=actu;
        actu=actu->next;
    }
    dernier->next=liste->first;
}

void suppr(Ronde *ronde){
    Ronde *kill=ronde->next;
    ronde->next=kill->next;
    kill->next=NULL;
}

void game(Liste *liste, int n, int k){
    Ronde *dernier;
    Ronde *actu=liste->first;
    char* dead = (char*) malloc(sizeof(char) * (n-1));
    int tokill=1, dc=0;
    if(k==1){affiche(liste,n,-1);}
    else{
        while(actu!=NULL){
            if (tokill%k==0){
                dead[dc]=actu->nom;
                actu=actu->next;
                suppr(dernier);
                dc++;
            }
            dernier=actu;
            if (tokill%k!=0){
                actu=actu->next;
            }
            tokill++;
        }

        for (int i=0;i<n-1;i++){
            printf("%c -> ",dead[i]);
        }
        printf("Le vainqueur est %c\n\n",dernier->nom);
    }
}

Liste *setname(int *n){
    Liste *liste=init_liste();
    setliste(liste,n);
    return liste;
}

int main(){
    int *n=0,*k=0;
    setvalue(&n,&k);
    Liste *liste=setname(n);
    setrond(liste);
    affiche(liste,n,k);
    game(liste,n,k);

    int rep=0;
    while(rep<6){
        printf("\nValeurs N et K: 1\nDonner les noms: 2\nFaire des noms une ronde: 3\nAfficher la ronde: 4\nLancer la partie: 5\nQuitter: 6+\n");
        printf("Donnez un nombre entre 1 et 5 pour appeler une des fonctions:\n");
        scanf(" %d",&rep);
        if(rep==1){setvalue(&n,&k);}
        else if(rep==2){setname(n);}
        else if(rep==3){setrond(liste);}
        else if(rep==4){affiche(liste,n,k);}
        else if(rep==5){game(liste,n,k);}
    }
    return 0;
}
