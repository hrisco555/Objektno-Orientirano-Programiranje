/*
Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра. За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци), број на ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).

Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци), низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)

Треба да се направи функција со потпис (15 поени)

void najdobarIgrac(KompjuterskaIgra *lista, int n)
Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY". (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)

(Забелешка: секогаш ќе има точно еден најдобар играч)

Функционалност на задачата и дополнување на main функцијата (10 поени)

Забелешка: Задачата да се реши во програмскиот јазик C+
  */

#include <iostream>
#include <cstring>

using namespace std;
struct Igrac{

    char korisnicko_ime[15];
    int nivo;
    int poeni;

};

typedef struct Igrac Igrac;

typedef struct {
    char ime_igra[20];
    Igrac igraci[30];
    int br_igraci;
}KompjuterskaIgra;

void najdobarIgrac(KompjuterskaIgra *lista, int n){

    int max_i=0,max=0;
    for(int i=0;i<n;i++){ //ja barame igrata so ima najgolem broj igraci
        if (lista[i].br_igraci > max) {
            max=lista[i].br_igraci;
            max_i = i;
        }
    }
    int indeksigrac=0,maxpoeni=0;
    //najdobar igrac
    for (int i = 0; i < lista[max_i].br_igraci; ++i) {
        if((lista[max_i].igraci[i].poeni>maxpoeni) || ((lista[max_i].igraci[i].poeni==maxpoeni))){
            indeksigrac=i;
        }
    }

    cout << "Najdobar igrac e igracot so korisnicko ime " << lista[max_i].igraci[max_i].korisnicko_ime << " koj ja igra igrata " << lista[max_i].ime_igra << endl;

}

int main() {
    KompjuterskaIgra igra[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>igra[i].ime_igra;
        cin>>igra[i].br_igraci;
        for (int j = 0; j < igra[i].br_igraci; ++j) {
            cin>>igra[i].igraci[j].korisnicko_ime;
            cin>>igra[i].igraci[j].nivo;
            cin>>igra[i].igraci[j].poeni;
        }

    }

    najdobarIgrac(igra,n);
    return 0;
}
