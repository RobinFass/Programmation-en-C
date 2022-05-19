#include <stdio.h>
char flush_space(){
    char c;
    scanf("%c", &c);
    while(c == ' '){
        scanf("%c", &c);
    }
    return c;
}
void shift(int tab[], int taille_tab, int taille_nb){
    int i;
    for (i = 0; i<taille_nb; i++){
        tab[taille_tab-i-1] = tab[taille_nb-i-1];
        tab[taille_nb-i-1]=0;
    }
}
int is_num(char c){
    return c>= '0' && c<= '9';
}
int convert(char c){
    return c-'0';
}
char lire_nombre(int tab[], int taille){
    char cur = 0; int minus = 0; int i = 0;
    cur = flush_space();
    if (cur == '-'){
        minus = 1;
        cur = flush_space();
    }
    tab[0] = minus?-convert(cur) : convert(cur);
    scanf("%c", &cur);
    for(i = 1; is_num(cur); ++i){
        tab[i] = convert(cur);
        scanf("%c", &cur);
    }
    shift(tab, taille, i);
    if (cur == ' '){
        return flush_space();
    }
    else{
        return cur;
    }
}
void display(int tab[], int taille){
    int i = 0;
    for (i = 0; i<taille && tab[i]==0; i++){;}
	if (i==taille){
        printf("0");
	}
    for (; i<taille; i++){
        printf("%d", tab[i]);
    }
    printf("\n");
}
int plus_fort(int tab[], int tab2[], int taille){
    int t1,t2,val1,val2;
    for (int i=0;i<taille;i++){
        if (tab[i]!=tab2[i]){
            return tab[i]>tab2[i] ? 0:1;
        }
    }
}
void add_num(int res[], int nb1[], int nb2[], int taille, int signe1, int signe2){
    int i = 0; int dizaine=0;
    int ret = 0; int unite=0;
    int cur = 0;
    int wait;
    if(signe1 && signe2){
        for(i=0; i<taille; i++){
            cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
            dizaine=cur/10;
            unite=cur%10;
            res[taille-i-1]=unite;
            ret=dizaine;
        }
    }
    else if (!signe1 && !signe2){
        for(i=0; i<taille; i++){
            cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
            dizaine=cur/10;
            unite=cur%10;
            res[taille-i-1]=unite;
            ret=dizaine;
        }
        for (i=0;i<taille && res[i]==0;i++){;}
        res[i]=-res[i];
    }
    else {
        int force=plus_fort(nb1,nb2,taille);
        for(i=0; i<taille; i++){
            if (force){
                wait=nb1[taille-i-1];
                nb1[taille-i-1]=nb2[taille-i-1];
                nb2[taille-i-1]=wait;
            }
            if ((nb1[taille-i-1]-ret)<nb2[taille-i-1]){
                cur=10-nb2[taille-i-1]+nb1[taille-i-1]-ret;
                ret=1;
                res[taille-i-1]=cur;
            }
            else {
                cur=(nb1[taille-i-1]-ret)-nb2[taille-i-1];
                ret=0;
                res[taille-i-1]=cur;
            }

        }

        for (i=0;i<taille && res[i]==0;i++){;}
        if (force){
            if (!signe2){
                res[i]=-res[i];
            }
        }
        else {
            if (!signe1){
                res[i]=-res[i];
            }
        }
    }
}
int positif(int tab[], int taille){
    for (int i=0;i<taille;i++){
        if (tab[taille-i-1]<0){
            tab[taille-i-1]=-tab[taille-i-1];
            return 0;
        }
    }
    return 1;
}
void copy(int nb[], int res[], int taille){
    for (int i=0;i<taille;i++){
        res[i]=nb[i];
    }
}
int calcul_long(int tab[], int taille){
    int i;
    for (i=0; i<taille && tab[i]==0;i++){;}
    return taille-i;
}
int add_multi(int res[], int nb1[], int nb2[], int taille){
    int cur, ret=0;
    for(int i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        ret=cur/10;
        res[taille-i-1]=cur%10;
    }
}
void multi(int res[], int nb1[], int nb2[], int taille, int signe1, int signe2){
    int cur, ret=0, puiss=0, i, wait[1000] = {0};
    int t1=calcul_long(nb1, taille), t2=calcul_long(nb2, taille);
    for (int x=0; x<t1; x++){
        for (int y=0; y<t2+1; y++){
            cur=nb1[taille-x-1]*nb2[taille-y-1]+ret;
            ret=cur/10;
            wait[taille-y-1-puiss]=cur%10;
        }
        add_multi(res, res, wait, taille);
        ret=0;
        wait[taille-1-puiss]=0;
        puiss++;
    }
    if (signe1 != signe2){
        for (i=0;i<taille && res[i]==0;i++){;}
        res[i]=-res[i];
    }
}
int sub_div(int res[], int nb1[], int nb2[], int taille){
    int cur, ret=0;
    for(int i=0; i<taille; i++){
        if ((nb1[taille-i-1]-ret)<nb2[taille-i-1]){
            cur=10-nb2[taille-i-1]+nb1[taille-i-1]-ret;
            ret=1;
            res[taille-i-1]=cur;
        }
        else {
            cur=(nb1[taille-i-1]-ret)-nb2[taille-i-1];
            ret=0;
            res[taille-i-1]=cur;
        }
    }
    if (res[1]==9){
        return 0;
    }
    return 1;
}
int compare(int nb1[], int nb2[], int taille){
    for (int i=0;i<taille;i++){
        if (nb1[i]>nb2[i]){return 1;}
        else if (nb1[i]!=nb2[i]){return 0;}
    }
    return 2;
}
void append(int tab[], int var, int taille){
    int i;
    for (i=1; i<taille-1; i++){
        tab[i]=tab[i+1];
    }
    tab[i]=var;
}
void div(int res[], int nb1[], int nb2[], int taille, int signe1, int signe2, int modulo){
    int i=calcul_long(nb1, taille),compte=0;
    int inutile[1000]={0}, x[1000]={0};
    int comp=compare(nb1,nb2,taille);
    if (comp==1){
        for (int y=0; y<i;y++){
            append(x,nb1[taille-i+y],taille);

            while (sub_div(inutile, x, nb2, taille)){
                compte++;
                sub_div(x, x, nb2, taille);
            }
            append(res,compte,taille);
            compte=0;
        }
    }
    else if (comp==2){append(res,1,taille);}
    else if (modulo){
        copy(nb1, x, taille);
    }
    if (modulo){
        if (!signe1 && signe2){copy(x, res,taille);}
        else{
            copy(x, res,taille);
            compte=1;
        }
    }
    if (((signe1 != signe2) && !compte) || (((!signe1 && !signe2) || (!signe1 && signe2)) && compte)){
        for (i=0;i<taille && res[i]==0;i++){;}
        res[i]=-res[i];
    }
}
int main(){
    int nb1[1000] = {0}; int res1[1000]={0};
    int nb2[1000] = {0}; int res2[1000]={0};
    int nb3[1000] = {0};
    int signe1, signe2, signe3, signeres1, signeres2;
    char op1, op2;
    op1 = lire_nombre (nb1, 1000);
    op2 = lire_nombre (nb2, 1000);
    lire_nombre(nb3, 1000);
	signe1 = positif (nb1, 1000);
    signe2 = positif (nb2, 1000);
    signe3 = positif (nb3, 1000);
    if (op2=='*' || op2=='/' || op2=='%'){
        if (op1=='+' || op1=='-'){
            if (op2=='*'){multi(res1,nb2,nb3,1000,signe2,signe3);}
            else if (op2=='/'){div(res1,nb2,nb3,1000,signe2,signe3,0);}
            else if (op2=='%'){div(res1,nb2,nb3,1000,signe2,signe3,1);}
            signeres1=positif(res1,1000);
            if (op1=='+'){add_num(res2,nb1,res1,1000,signe1,signeres1);}
            else if (op1=='-'){add_num(res2,nb1,res1,1000,signe1,!signeres1);}
        }
        else {
            if (op1=='*'){multi(res1,nb1,nb2,1000,signe1,signe2);}
            else if (op1=='/'){div(res1,nb1,nb2,1000,signe1,signe2,0);}
            else if (op1=='%'){div(res1,nb1,nb2,1000,signe1,signe2,1);}
            signeres1=positif(res1,1000);
            if (op2=='*'){multi(res2,res1,nb3,1000,signeres1,signe3);}
            else if (op2=='/'){div(res2,res1,nb3,1000,signeres1,signe3,0);}
            else if (op2=='%'){div(res2,res1,nb3,1000,signeres1,signe3,1);}
        }
        display(res2,1000);
    }
    else {
        if (op1=='*'){multi(res1,nb1,nb2,1000,signe1,signe2);}
        else if (op1=='/'){div(res1,nb1,nb2,1000,signe1,signe2,0);}
        else if (op1=='%'){div(res1,nb1,nb2,1000,signe1,signe2,1);}
        else if (op1=='+'){add_num(res1,nb1,nb2,1000,signe1,signe2);}
        else if (op1=='-'){add_num(res1,nb1,nb2,1000,signe1,!signe2);}
        signeres1=positif(res1,1000);
        if (op2=='*'){multi(res2,res1,nb3,1000,signeres1,signe3);}
        else if (op2=='/'){div(res2,res1,nb3,1000,signeres1,signe3,0);}
        else if (op2=='%'){div(res2,res1,nb3,1000,signeres1,signe3,1);}
        else if (op2=='+'){add_num(res2,res1,nb3,1000,signeres1,signe3);}
        else if (op2=='-'){add_num(res2,res1,nb3,1000,signeres1,!signe3);}
        display(res2,1000);
    }
    return 0;
}