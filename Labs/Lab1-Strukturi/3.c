/*
За програмски јазик да се употреби C.

Да се креира структура Employee во која се чуваат податоци за еден вработен. За вработениот се чуваат информации за името на вработениот (низа од карактери), матичен број (ЕМБГ) на вработениот(низа од карактери), име на одделот во кој што работи (низа од карактери), плата (цел број).

Потоа, да се креира структура Company во која се чуваат податоци за името на компанијата (низа од карактери), низа од вработени во компанијата и број на вработени.

Да се направи функција:

void printEmployeesBelowAverageSalary(Company *comp, int numCompanies)

која што за секоја компанија, ќе ги испечати сите вработени чија што плата е пониска од просекот на платите на сите вработени во таа компанија.

Да се направи функција: 

void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department) 

кoja што за секоја компанија ќе го испечати вработениот со највисока плата во дадениот оддел.

Напомена: Прво од тастатура се чита бројот на компании, потоа компаниите (името и бројот на вработени), а потоа податоците за нивните вработени соодветно, a на крај се чита одделот кој што ќе биде искористен во printHighestSalaryEmployee функцијата.
  */

#include <stdio.h>
#include <string.h>

struct Employee{
    char ime_vraboten[20];
    char EMBG[12];
    char oddel[20];
    int plata;

};

typedef struct Employee Employee;

struct Company {
    char ime_kompanija[20];
    Employee vraboteni[20];
    int br_vraboteni;

};

typedef struct Company Company;

void printEmployeesBelowAverageSalary(Company *comp, int num_Companies){

    int i,j;

    printf("Employees with salaries below the average:\n");
    for(i=0;i<num_Companies;i++){
        float prosek=0;
        float suma=0;
        for(j=0;j<comp[i].br_vraboteni;j++) {
          suma += comp[i].vraboteni[j].plata; //site plati se sobiraat vo firmata.
        }
        prosek = suma/comp[i].br_vraboteni; //se bara prosek
        for(j=0;j<comp[i].br_vraboteni;j++){
            if(comp[i].vraboteni[j].plata<prosek){
                printf("%s %s %s %d\n", comp[i].vraboteni[j].ime_vraboten, comp[i].vraboteni[j].EMBG, comp[i].vraboteni[j].oddel, comp[i].vraboteni[j].plata);
            }
        }
    }

}

void printHighestSalaryEmployee(Company *comp, int num_Companies, char *department){

    int i,j;
    printf("Employees with highest salaries for given department:\n");
    for(i=0;i<num_Companies;i++){
         int max=0, indeks_j=0;
        for(j=0;j<comp[i].br_vraboteni;j++) {       //sporeduva department so oddelot bidejki dva pati gi vnesuvame ako se isti dava 0.Treba da dade 0 za uslovot da e tocen
            if(comp[i].vraboteni[j].plata>max && strcmp(department, comp[i].vraboteni[j].oddel)==0){
                max=comp[i].vraboteni[j].plata;
                indeks_j=j;
            }
        }
        printf("%s %s %s %d\n", comp[i].vraboteni[indeks_j].ime_vraboten, comp[i].vraboteni[indeks_j].EMBG, comp[i].vraboteni[indeks_j].oddel, comp[i].vraboteni[indeks_j].plata);
    }
}

int main() {

    Company comp[50];
    int num_companies, i, j;
    char department[20];
    scanf("%d", &num_companies);

    //prviot ciklus za komp i vrabotenite 
    for (i = 0; i < num_companies; i++) {
        scanf("%s", comp[i].ime_kompanija);
        scanf("%d", &comp[i].br_vraboteni);

        //vtoriot ciklus za ednata kompanija site informacii za vrabotenite
        for (j = 0; j < comp[i].br_vraboteni; j++) {
            
        scanf("%s", comp[i].vraboteni[j].ime_vraboten);
        scanf("%s", comp[i].vraboteni[j].EMBG);
        scanf("%s", comp[i].vraboteni[j].oddel);
        scanf("%d", &comp[i].vraboteni[j].plata);
    }
}

    scanf("%s", department);

    printEmployeesBelowAverageSalary(comp,num_companies);
    printHighestSalaryEmployee(comp,num_companies,department);

    return 0;
}
