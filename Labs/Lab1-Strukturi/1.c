#include <stdio.h>
#include <string.h>

/*
 1 LABS
Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen
*/


#include <stdio.h>

struct Transaction
{
int ibroj;
int suma;
int provizija;
int tip;
};

typedef struct Transaction Transaction;

int main(){

    Transaction t[20];
    int n,i;
    int brojac=0;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &t[i].ibroj);
        scanf("%d", &t[i].suma);
        scanf("%d", &t[i].provizija);
        scanf("%d", &t[i].tip);
    }
    for (i=0; i<n; i++) {
        if(t[i].tip==1){
            brojac++;
            printf("%d %d\n", t[i].ibroj, t[i].suma+t[i].provizija);
            }
    }
    
    
    if(brojac==0){
        printf("No credit card transaction");
    }
    return 0;
}
