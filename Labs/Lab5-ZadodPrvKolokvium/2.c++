/*
За да се овозможи прецизна контрола и евиденција во еден аеродромски сервис, потребно е да се имплементира модул со следниве класи и функционалности:

Да се имплементира класа Airplane во која ќе се чуваат информации за:

Регистарска ознака (низа од најмногу 12 знаци)
Име на авиокомпанија која го поседува авионот (динамички алоцирана низа од знаци)
Матичен аеродром на авиокомпанијата (низа од најмногу 20 знаци)
Состојба (авионот може да се најде во состојба НЕИСПРАВЕН, СЕ_ПОПРАВА или ИСПРАВЕН)
Вкупен број на часови налет (цел број)
За класата да се имплементираат потребните конструктори, оператор = и методи за да функционира решението. (10 поени). Дополнително за класата да се имплементира метод void print() за печатење на информациите за авионот (според тест примерите). (5 поени)

Да се имплементира класа AirportService во која ќе се чуваат информации за:

Име на аеродромот каде се наоѓа сервисот (низа од најмногу 20 знаци)
Листа на авиони кои моментално се наоѓаат во сервисот (динимички алоцирана низа од објекти од класата Airplane, иницијално без елементи)
Број на авиони во сервисот (број на елементи во низата со авиони - цел број, иницијално е 0)
За класата да се имплементираат потребните конструктори и методи со цел да функционира решението. (5 поени) Дополнително во класата да се имплементираат:

метод void addAirplane (Airplane plane) - за додавање нoв авион во сервисот (5 поени). Еден авион може да се додаде во сервисот само ако се наоѓа во состојба НЕИСПРАВЕН. Дополнително, ако веќе во сервисот има авион од иста авиокомпанија како авионот кој сакаме да го додадеме, потребно е во сервисот да остане авионот со поголем број на часови налет. Кога авион се додава во сервисот неговата состојба преминува во состојба СЕ_ПОПРАВА (10 поени).
метод Airplane serviceOldestAirplane() - за сервисирање на најстариот авион. За најстар авион се смета оној авион од листата кој има најмногу часови налет. Сервисирањето на еден авион претствува:

Потребно е авионот да биде избришан од листата со авиони во сервисот
Авионот треба да премине од состојба СЕ_ПОПРАВА во состојба ИСПРАВЕН
Доколку има повеќе авиони со ист број на часови налет при одредувањето на најстар авион, тогаш потребно е да се избрише авионот чиј што матичен аеродром на авиокомпанијата на авионот е аеродромот каде што се наоѓа сервисот. Во ваква ситуација, секогаш само еден од авионите ќе има ист матичен аеродром со аеродромот на сервисот.  (15 поени)
метод void print() - за печатење на информации за сите авиони кои моментално се наоѓаат на поправка во сервисот (формат во тест примери) (10 поени)
*/

#include <iostream>
#include <cstring>

using namespace std;

class Airplane{

private:
    char regoz[12];
    char *ime;
    char imeaerodrom[20];
    int sostojba;
    int brojcasovi;

public:
    Airplane(char *ro="",char *ia="",char *aer="", int brc=0,int s=0)
    {
        strcpy(regoz, ro);
        ime=new char [strlen(ia) + 1];
        strcpy(ime, ia);
        strcpy(imeaerodrom, aer);
        sostojba=s;
        brojcasovi=brc;
    }
    Airplane(const Airplane &A)
    {
        strcpy(regoz, A.regoz);
        ime=new char [strlen(A.ime) + 1];
        strcpy(ime, A.ime);
        strcpy(imeaerodrom, A.imeaerodrom);
        sostojba=A.sostojba;
        brojcasovi=A.brojcasovi;

    }
    Airplane &operator=(const Airplane &A)
    {
        if(this!=&A)
        {
            delete[]ime;
            strcpy(regoz, A.regoz);
            ime=new char [strlen(A.ime) + 1];
            strcpy(ime, A.ime);
            strcpy(imeaerodrom, A.imeaerodrom);
            sostojba=A.sostojba;
            brojcasovi=A.brojcasovi;
        }
        return *this;

    }
    ~Airplane()
    {
        delete[]ime;
    }
    void print()
    {
        cout << "ID: " << regoz << " - ";
        if(sostojba==1)
        {
            cout<<"REPAIRING ";

        }
        else if(sostojba==0)
        {
            cout<<"NOT_WORKING ";

        }
        else
        {
            cout<<"WORKING ";
        }
        cout << ime << ", " << brojcasovi << ", " << imeaerodrom << endl;
    }

    int getSostojba() const {
        return sostojba;
    }

    void setSostojba(int sostojba) {
        Airplane::sostojba = sostojba;
    }

    char *getImeAviokompanija() const {
        return ime;
    }

    int getBrojCasovi() const {
        return brojcasovi;
    }

    const char *getAerodrom() const {
        return imeaerodrom;
    }


};

class AirportService {
private:
    char ime[20];
    Airplane *avioni;
    int broj;

public:
    AirportService(char *im = "") {
        strcpy(ime, im);
        avioni = 0;
        broj = 0;

    }

    AirportService(const AirportService &AS) {
        strcpy(ime, AS.ime);
        broj = AS.broj;
        avioni = new Airplane[broj];
        for (int i = 0; i < broj; i++) {
            avioni[i] = AS.avioni[i];
        }
    }

    AirportService &operator=(const AirportService &AS) {
        if (this != &AS) {
            delete[]avioni;
            strcpy(ime, AS.ime);
            broj = AS.broj;
            avioni = new Airplane[broj];
            for (int i = 0; i < broj; i++) {
                avioni[i] = AS.avioni[i];
            }
        }
        return *this;
    }

    ~AirportService() {
        delete[]avioni;
    }

    void addAirplane(Airplane plane) {
        if (plane.getSostojba() == 0) {
            int m = 0, index = 0;
            for (int i = 0; i < broj; ++i) {
                if (strcmp(avioni[i].getImeAviokompanija(), plane.getImeAviokompanija()) == 0) {
                    if (plane.getBrojCasovi() > avioni[i].getBrojCasovi()) {
                        m = 1;
                        index = i;
                    } else m = 2;
                }
            }
            Airplane *temp;
            if (m == 1) {
                temp = new Airplane[broj];
                for (int j = 0; j < broj; ++j) {
                    if (j != index) {
                        temp[j] = avioni[j];
                    } else {
                        temp[j] = plane;
                        temp[j].setSostojba(1);
                    }
                }
            } else if (m == 0) {
                temp = new Airplane[broj + 1];
                for (int j = 0; j < broj; ++j) {
                    temp[j] = avioni[j];
                }
                temp[broj] = plane;
                temp[broj].setSostojba(1);
                broj++;
            }
            delete[] avioni;
            avioni = temp;
        }

    }

    Airplane serviceOldestAirplane() {
        int chasovi = 0, index = -1;
        for (int i = 0; i < broj; ++i) {
            if (avioni[i].getBrojCasovi() > chasovi) {
                chasovi = avioni[i].getBrojCasovi();
                index = i;
            } else if (avioni[i].getBrojCasovi() == chasovi) {
                if (strcmp(avioni[i].getAerodrom(), this->ime) == 0)
                    index = i;
            }
        }
        avioni[index].setSostojba(2);
        Airplane plane;
        plane = avioni[index];
        Airplane *tmp;
        tmp = new Airplane[broj - 1];
        int c = 0;
        for (int j = 0; j < broj; ++j) {
            if (j != index) {
                tmp[c] = avioni[j];
                c++;
            }
        }
        broj--;
        delete[] avioni;
        avioni = tmp;
        return plane;
    }


    void print()
    {
        cout<<ime<<endl;
        for(int i=0; i < broj; i++)
        {
            if(avioni[i].getSostojba() == 1)
            {
                avioni[i].print();
            }
        }
    }

};

int main() {
    int testCase;
    cin >> testCase;
    char ID[12];
    char company_name[20];
    char company_airport[20];
    int flight_hours;
    int state;
    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR AIRPLANE" << endl;
        Airplane a;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Airplane a2("ZHN-96-TA", "FINKI1-Airline", "TMF", 13, 0);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR AIRPLANE" << endl;
        Airplane p("ZHN-96-TA", "FINKI-Airline", "TMF", 13, 0);
        Airplane p1(p);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Airplane p2;
        p2 = p;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING PRINT() FOR AIRPLANE" << endl;
        cin>>ID>>company_name>>company_airport>>flight_hours>>state;
        Airplane p(ID, company_name, company_airport, flight_hours, state);
        p.print();
    } else if (testCase == 4) {
        cout << "TESTING CONSTRUCTOR FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING ADD() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        as.print();
    } else if (testCase == 6) {
        cout << "TESTING serviceOldestAirplane() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        Airplane p = as.serviceOldestAirplane();
        cout<<"Removed plane:"<<endl;
        p.print();
        cout<<"-----------------"<<endl;
        as.print();
    }  else if (testCase == 7) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        as.addAirplane(a1);

        AirportService s1 = as; //copy constructor
        AirportService s2;
        s2 = s1; //operator =
        s1.print();
        s2.print();
    }
    return 0;
}
