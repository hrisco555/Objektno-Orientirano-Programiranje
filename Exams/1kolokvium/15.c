/*
Да се дефинира структура RabotnaNedela во која се чуваат бројот на работни часови за секој работен ден во неделата (5 дена) и број на неделата. Потоа да се дефинира структура Rabotnik за кој се чува име (низа од 50 знаци) и низа од работни недели (макс 4).

Да се имплементираат следните функции:

int maxNedela(Rabotnik *r) која за проследениот работник ќе го врати бројот на неделата со најмногу работни часови
void table(Rabotnik *r, int n) која за низата од работници ќе отпечати приказ во следниот формат:
Пример

Rab     1   2   3   4   Vkupno
Brianna 192 238 226 225 881
Ava     236 231 184 212 863
Matthew 236 235 219 243 933
Alyssa  240 254 217 228 939
Emma    247 205 204 242 898 
каде во секој ред се печати името на работникот и вкупниот број на работни часови за секоја работна недела, како и вкупниот број на часови за сите недели. Во рамките на редот податоците се разделени со знак за табулатор \t.
  */

#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5


struct RabotnaNedela{
    
    int casovi[DENOVI];
    int nedeli;
    
};

typedef struct RabotnaNedela RabotnaNedela;

struct Rabotnik{
    
    char ime[50];
    RabotnaNedela nedeli[NEDELI];
};

typedef struct Rabotnik R;

 int maxNedela(R *r){
    
    int i,j,max=0,max_i,zbir;
    for(i=0;i<NEDELI;i++){
        zbir=0;
        for(j=0;j<DENOVI;j++){
            zbir+=r->nedeli[i].casovi[j];
        }
        if(zbir>max){
            max=zbir;
            max_i=i;
        }
        //zbir=0;
    }
    return max_i+1;
}



//sobira casovite vo edna nedela od site denovi
int cas_vo_nedeli(R r, int indeks){
    
    int zbir=0;
    int i;
    for(i=0;i<DENOVI;i++){
        //zbir=0;
        zbir+=r.nedeli[indeks].casovi[i]; //fiksiran e indeksot kaj nedeli
    }
    
    return zbir;

}

void table(R *r, int n){
    
    int vkupno=0;
    int i,j;
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(i=0;i<n;i++){
        vkupno=0;
        printf("%s\t", r[i].ime);
        for(j=0;j<NEDELI;j++){
            printf("%d\t",cas_vo_nedeli(r[i], j));
            vkupno+=cas_vo_nedeli(r[i], j);
        }
        printf("%d\n", vkupno);
    }
    
    
}

//daden e main-ot
int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
