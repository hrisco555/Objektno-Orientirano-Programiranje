/*
Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++
  */

#include<iostream>
#include <cstring>
using namespace std;

struct Voz{

    char relacija[50];
    float km;
    int broj_patnici;

};

typedef struct Voz Voz;

typedef struct {
char grad[20];
Voz vozovi[30];
int broj_vozovi;
}ZeleznickaStanica;


// void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){

//     int min=99999, min_i=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if((zs[i].vozovi[j].km<min) && (strcmp(grad,zs[i].grad)==0)){
//                 min=zs[i].vozovi[j].km;
//                 min_i=i;
        
//             }
//         }
//     }
//         cout<<"Najkratka relacija: "<<zs[min_i].vozovi[min_i].relacija<<" "<<"("<<min<<" km)"<<endl;
// }


void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){

    int min=99999, min_i=0,i=0,j=0;
    char najmalaRelacija[25];
    for(i=0;i<n;i++){
            if(strcmp(grad,zs[i].grad)==0)
            {
                for (int j = 0; j < zs[i].broj_vozovi; j++)
                {
                    if(zs[i].vozovi[j].km<min){
                        min=zs[i].vozovi[j].km;
                        min_i=i;
                        strcpy(najmalaRelacija, zs[i].vozovi[j].relacija);
                    }
                }
            }
    }
    cout<<"Najkratka relacija: "<<najmalaRelacija<<" "<<"("<<min<<" km)"<<endl;
}



int main(){

    int n;
    cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];

        for(int i=0;i<n;i++)
        {
            cin>>zStanica[i].grad;
            cin>>zStanica[i].broj_vozovi;

            for(int j=0;j<zStanica[i].broj_vozovi;j++)
            {
                cin>>zStanica[i].vozovi[j].relacija;
                cin>>zStanica[i].vozovi[j].km;
                cin>>zStanica[i].vozovi[j].broj_patnici;
            }
        }

    char grad[25];
    cin>>grad;

    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
