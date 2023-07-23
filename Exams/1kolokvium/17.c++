/*
  Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:

OperativenSistem
Во класата OperativenSistem треба да се чуваат следниве податоци:

име на оперативниот систем (динамички алоцирана низа од знаци)
верзија (float)
тип (енумерација со можни вредности LINUX, UNIX, WINDOWS)
големина (во GB) (float)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктори со и без параметри
copy constructor
destructor
преоптоварување на операторот =
метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - bool ednakviSe(const OperativenSistem &os)
метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат исто име и се од ист тип. bool istaFamilija(const OperativenSistem &sporedba)
Repozitorium
Во класата Repozitorium треба да се чуваат следниве податоци:

име на репозиториумот (низа од 20 знака)
динамички алоцирана низа од OperativenSistem
број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктор Repozitorium(const char *ime)
деструктор
метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент, доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.
*/
#include <iostream>
#include <cstring>

using namespace std;

enum Tip{
    LINUX,UNIX,WINDOWSG
};

class OperativenSistem{
private:
    char *ime;
    float verzija;
    Tip tip;
    float golemina;

    void copy(const OperativenSistem &os){
        this->ime=new char[strlen(os.ime)+1];
        strcpy(this->ime,os.ime);
        this->verzija=os.verzija;
        this->tip=os.tip;
        this->golemina=os.golemina;
    }
public:
    OperativenSistem(char *ime=" ",float verzija=0.0,Tip tip=LINUX,float golemina=0.0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->verzija=verzija;
        this->tip=tip;
        this->golemina=golemina;
    }

    OperativenSistem(const OperativenSistem &os){
        copy(os);
    }

    OperativenSistem &operator=(const OperativenSistem &os){
        if(this!=&os){
            delete[]ime;
            copy(os);
        }
        return *this;
    }

    ~OperativenSistem(){
        delete[]ime;
    }

    void pecati(){
        cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<tip<<" Golemina:"<<golemina<<"GB"<<endl;
    }

    bool ednakviSe(const OperativenSistem &os){
        if((strcmp(ime, os.ime)==0) && (this->verzija==os.verzija) && (this->tip==os.tip) && (this->golemina==os.golemina)){
            return true;
        }
        else {
            return false;
        }
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija) {
            return 0;
        }
        if(os.verzija>verzija) {
            return -1;
        }
        return 1;
    }

    bool istaFamilija(const OperativenSistem &sporedba){
        if((strcmp(this->ime, sporedba.ime)) && (tip==sporedba.tip)){
            return true;
        }
        return false;
    }

};

class Repozitorium{

private:
    char ime[20];
    OperativenSistem *niza;
    int brojOperativniSistemi;
    
    void copy(const Repozitorium &r){
        strcpy(this->ime, r.ime);
        this->brojOperativniSistemi=r.brojOperativniSistemi;
        this->niza=new OperativenSistem[brojOperativniSistemi];
        for(int i=0;i<brojOperativniSistemi;i++){
            this->niza[i]=r.niza[i];
        }
    }

public:
    Repozitorium(const char *ime){
        strcpy(this->ime, ime);
        this->brojOperativniSistemi=brojOperativniSistemi;
        this->niza=new OperativenSistem[brojOperativniSistemi];
        for(int i=0;i<brojOperativniSistemi;i++){
            this->niza[i]=niza[i];
        }
    }

    Repozitorium(const Repozitorium &r){
        copy(r);
    }

    Repozitorium &operator =(const Repozitorium &r){
        if(this!=&r) {
            delete [] niza;
            copy(r);
        }
        return *this;
    }

    ~Repozitorium(){
        delete [] niza;
    }

    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: FINKICloud"<<endl;
        for(int i=0;i<brojOperativniSistemi;i++){
            niza[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem){
        int flag=0;
        for(int i=0;i<brojOperativniSistemi;i++) {
            if (this->niza[i].ednakviSe(operativenSistem)){
                flag=1;
                // break;
            }
        }
        if(flag==0){
            return;
        }

        OperativenSistem *tmp = new OperativenSistem[brojOperativniSistemi-1];
        for(int i=0, j=0;i<brojOperativniSistemi;i++) {
            if (!this->niza[i].ednakviSe(operativenSistem)) {
                tmp[j] = niza[i];
                j++;
            }
        }
        brojOperativniSistemi--;
        delete [] niza;
        niza=tmp;
    }

    void dodadi(const OperativenSistem &nov){
        int flag=0;
        for(int i=0;i<brojOperativniSistemi;i++){
            if(niza[i].istaFamilija(nov)){
                if(niza[i].sporediVerzija(nov)==1){ //-1 доколку верзијата на оперативниот систем од аргументот е поголема
                    niza[i]=nov;
                }
                // return;
            }
        }

        OperativenSistem *tmp = new OperativenSistem[brojOperativniSistemi+1];
        for(int i=0;i<brojOperativniSistemi;i++){
            tmp[i]=niza[i];
        }
        tmp[brojOperativniSistemi++]=nov;
        delete [] niza;
        niza=tmp;
    }

}

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
