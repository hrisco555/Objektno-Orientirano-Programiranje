/*
Во програмскиот јазик C да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

Фирма која го произведува ( низа од 100 знаци)
Големина на монитор во инчи (реален број)
Дали е со touch или не (булова променлива)
Цена (цел број)
Да се креира структура ITStore, што содржи: (5 поени)

Име на продавницата (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)

[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
Да се креира функција najeftina_ponuda, што прима низа од променливи од типот ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*

Да се дополни функцијата main (10 поени).

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда
  */

#include <stdio.h>

typedef struct {
    char firma[100];
    float golemina_monitor;
    int touch;
    int cena;
}Laptop;

struct ITStore{

    char ime_prodavnica[100];
    char lokacija[100];
    Laptop l[100];
    int n;

};

typedef struct ITStore ITStore;

void print(ITStore it){

    int i;
    printf("%s %s\n",it.ime_prodavnica,it.lokacija);
    for(i=0;i<it.n;i++){
        printf("%s %g %d\n", it.l[i].firma, it.l[i].golemina_monitor, it.l[i].cena);
    }
}

void najeftina_ponuda(ITStore *it, int n){

    int i,j,min=99999, min_i=0;
    for(i=0;i<n;i++){
        for(j=0;j<it[i].n;j++){
            if((it[i].l[j].cena<min) && it[i].l[j].touch==1){
                min=it[i].l[j].cena;
                min_i=i;
            }
        }
    }

    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n",it[min_i].ime_prodavnica, it[min_i].lokacija);
    printf("Najniskata cena iznesuva: %d", min);
}

int main(){

    ITStore it[50];

    int n,i,j;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%s", it[i].ime_prodavnica);
        scanf("%s", it[i].lokacija);
        scanf("%d", &it[i].n);
        for(j=0;j<it[i].n;j++){
            scanf("%s", it[i].l[j].firma);
            scanf("%f", &it[i].l[j].golemina_monitor);
            scanf("%d", &it[i].l[j].touch);
            scanf("%d", &it[i].l[j].cena);
        }
    }
    
    for(i=0;i<n;i++){
        print(it[i]);
    }

    najeftina_ponuda(it,n);

    return 0;
}
