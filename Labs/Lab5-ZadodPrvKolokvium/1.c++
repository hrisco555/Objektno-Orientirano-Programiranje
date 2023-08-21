/*
Во програмскиот јазик C да се креира структура Movie за опишување на филм во рамките на една стриминг платформа. Структурата за филм треба да ги содржи следниве полиња: (5 поени)

Име (низа од 100 знаци)

Рејтинг (реален број)

Жанр (низа од 40 знаци)

Да се креира структура StreamingService, што ги содржи следниве полиња: (5 поени)

Име на стриминг платформата (низа од 50 знаци)

Низа од достапни филмови (низа од максимум 30 елементи од структурата Movie)

Број на елементи во низата (цел број)

Да се креира глобална функција print за печатење на информациите за дадена стриминг платформа во следниот формат: (10 поени)

[Ime na streaming platformata]

[ImeFilm1] [Rejting1]

[ImeFilm2] [Rejting2]

[ImeFilm3] [Rejting3]

...

Да се креира функција showBestStreamningService, што прима низа од променливи од типот StreamingService, и променлива genre. Оваа функција треба да го испечати името на стриминг платформата која нуди најмногу филмови кои се од даден жанр (во зависност од пратената променлива genre). Ако има повеќе такви стриминг платформи со максимален број на филмови од пратениот жанр, се печати првата.(15 поени)

Да се дополни функцијата main (5 поени).

*/

#include <stdio.h>
#include <string.h>
struct Movie{
    char imef[100];
    float rating;
    char zhanr[40];
};
typedef struct Movie Movie;
void readM(Movie *m){
    scanf("%s %f %s",m->imef,&m->rating,m->zhanr);
}
void printM(Movie m){
    printf("%s %.1f\n",m.imef,m.rating);
}

struct StreamingService{
    char imeS[50];
    Movie filmovi[30];
    int br;
};
typedef struct StreamingService StreamingService;
void readS(StreamingService *s){
    scanf("%s %d",s->imeS,&s->br);
    int i=0;
    for (i = 0; i < s->br ; ++i) {
        readM(&s->filmovi[i]);
    }
}
void printS(StreamingService s){
    printf("%s\n",s.imeS);
    int i=0;
    for (i = 0; i < s.br; ++i) {
        printM(s.filmovi[i]);
    }
}
void showBestStreamingService(StreamingService *services,int num_services,char *zanr){
    int maks=0,i=0,j=0,indeks=-1;
    for (i = 0; i < num_services; ++i) {
        int br=0;
        for (j = 0; j < services[i].br ; ++j) {
            if(strcmp(services[i].filmovi[j].zhanr,zanr)==0)
                br++;
        }
        if(br>maks){
            maks=br;
            indeks=i;
        }
    }
    if(indeks>=0)
        printf("Best streaming service is: %s",services[indeks].imeS);
    else printf("No service has movies of the given genre.");
}

int main(){
    int num_services;
    scanf("%d", &num_services);
    StreamingService services[num_services];
    int i=0;
    for (i = 0; i < num_services; ++i) {
        readS(&services[i]);

    }
    for (i = 0; i < num_services; ++i) {
      printS(services[i]);
    }
    char genre[40];
    scanf("%s", genre);
    showBestStreamingService(services, num_services, genre);
    return 0;
}
