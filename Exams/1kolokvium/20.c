/*
  Во програмскиот јазик C да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)
*/


#include <stdio.h>
#include <string.h>


struct Pacient{
    char ime[100];
    int zdravstveno;
    int pregledi;
};

typedef struct Pacient Pacient;

struct MaticenDoktor{

    char ime_doktor[100];
    Pacient niza[200];
    int br_pac;
    float cena;
};

typedef struct MaticenDoktor doktor;

void najuspesen_doktor(doktor *md,int n){
    float max=0.0;
    int max_i;
    int najmnoguPregledani;
    for (int i = 0; i < n; ++i) {
        int br_pregledani=0;
        float zbir=0.0;
        for (int j = 0; j < md[i].br_pac; ++j) {
            if(md[i].niza[j].zdravstveno==0){ //ne se osigurani zdravstveno
                zbir+=md[i].cena*md[i].niza[j].pregledi; //cenata se zgolemuva za tie sto nemaat zdravstveno
            }
            br_pregledani+= md[i].niza[j].pregledi; //se sobiraat br na pregeldani
        }
        if((zbir>max)||((max==zbir) && (br_pregledani>najmnoguPregledani))){
            max=zbir;
            max_i=i;
            najmnoguPregledani = br_pregledani; 
        }
    }
    printf("%s %.2f %d", md[max_i].ime_doktor, max, najmnoguPregledani);
}

int main()
{
    int i, j, n;
    doktor md[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        //ime na doktor
        scanf("%s", &md[i].ime_doktor);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++){
            scanf("%s", &md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdravstveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}
