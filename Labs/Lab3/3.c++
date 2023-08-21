/*
Да се дефинира класа Employee во која ќе се чуваат информации за:

name(низа од максимум 100 карактери) -име на вработениот

surname(низа од максимум 100 карактери) - презиме

salary(цел број) - колку му е платата

методи кои што класата треба да ги има:

print() 

-Принта во формат:
Employee name: 

Employee surname: 

Employee salary: 

Да се дефинира класа TechCompany во која ќе се чуваат информации за:

name(низа од максимум 100 карактери) -име на фирмата

employees(низа од вработени) 

numOfEmployees(цел број) - колку вработени има во фирмата 

методи кои што класата треба да ги има:

print() 

-Принта во формат:
Tech company name: 

Number of employees: 

 double getAverageOfEmployeeсSalary()

-Враќа средна врендност од платите на секој вработен во таа фирма


Сите променливи внатре во класите треба да бидат приватни. Соодветно во рамките на класите да се дефинираат:

конструктор (без и со параметри)

деструктор

set методи

get методи

copy constructor

Функции надвор од класата:

printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies)

-Го враќа TechCompany објектот што има најголема средна вредност за плати на неговите вработени
printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies)

-Го враќа TechCompany објектот што има најголема стандардна девијација за плати на неговите вработени
𝑉𝐴𝑅=∑𝑓𝑜𝑟 𝑒𝑎𝑐ℎ 𝐸𝑚𝑝𝑙𝑜𝑦𝑒𝑒 𝑒[(𝑒.𝑠𝑎𝑙𝑎𝑟𝑦−𝐴𝑉𝐺)2]𝑛−1𝑆𝑇𝐷=(√𝑉𝐴𝑅)

-Помош: AVG е средната вредност на платите на сите вработен во таа фирма, STD е стандардна девијација, VAR  е помошна променлива. И прво квадрирајте го изразот па потоа додадете го во сумата!
isSameCompany(TechCompany company1, TechCompany company2)

-Враќа boolean вредност: две фирми се исти ако имаат исто име. Треба само да се првери дали им е исто името!
ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Employee{

private:
    char name[100];
    char surname[100];
    int salary;

public:
    Employee(){
        strcpy(name,"John");
        strcpy(surname,"Doe");
        salary=0;
    }
    Employee(const char *i, const char *p, int s){

            strcpy(name,i);
            strcpy(surname,p);
            salary=s;

//            strcpy(this->name,name);
//            strcpy(this->surname,surname);
//            this->salary=salary;

    }
    Employee(const Employee &e)
    {
        strcpy(name,e.name);
        strcpy(surname,e.surname);
        salary=e.salary;
    }

    ~Employee(){}

//    void setName(const char *i)
//    {
//        strcpy(name,i);
//    }
//    void setSurname(char *p)
//    {
//        strcpy(surname,p);
//    }
//    void setSalary(int s)
//    {
//        salary=s;
//    }

    char *getName(){
        return name;
    }

    char *getSurname(){
        return surname;
    }

    int getSalary()const{
        return salary;
    }

    void printEmployee()
    {
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee surname: "<<surname<<endl;
        cout<<"Employee salary: "<<salary<<endl;
    }
};

class TechCompany {
private:
    char name[100];
    Employee employees[20];
    int numofEmployees;
public:

    TechCompany() {
        strcpy(name,"david");
        numofEmployees=0;
        for(int i=0;i<numofEmployees;i++){
            employees[i]=Employee();
        }
    }

    TechCompany(char *ime) {
        strcpy(name, ime);
        numofEmployees = 0;
    }

    TechCompany(const TechCompany &comp) //copy konstruktor
    {
        strcpy(name, comp.name);
        numofEmployees = comp.numofEmployees;
        for (int i = 0; i < numofEmployees; ++i) { //for ciklus za niza
            employees[i] = comp.employees[i];
        }
    }

    ~TechCompany() {}


    void setName(const char *ime) {
        strcpy(name, ime);
    }

    void setNumofEmployees(int noe) {
        numofEmployees = noe;
    }

    char *getName() {
        return name;
    }

    const Employee &getEmployee(int index)const{
        return employees[index];
    }

    int getNumEmployees() {
        return numofEmployees;
    }

    void print() {
        cout << "Tech company name: " << name << endl;
        cout << "Number of employees: " << numofEmployees << endl;
    }

    double getAverageOfEmployeesSalary() {
        double suma = 0.0;
        for (int i = 0; i < numofEmployees; ++i) {
            suma += employees[i].getSalary(); //so get deka sme vo druga klasa
        }
        return suma / numofEmployees; //sredna vrednost
    }

    void addEmployee(Employee e)
    {
        if(numofEmployees<20)
        {
            employees[numofEmployees]=e;
            numofEmployees++;
        }
    }


};

TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies){

    int i,max_i=0;
    float max=0;
    for(i=0;i<numCompanies;i++) {

        if(companies[i].getAverageOfEmployeesSalary()>max){

            max=companies[i].getAverageOfEmployeesSalary();
            max_i=i;
        }
    }
    return companies[max_i];
}


TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies) {
    int max_i;
    double najgolema_plata = 0;

    for (int i = 0; i < numCompanies; i++) {
        int broj_vraboteni = companies[i].getNumEmployees();
        double srp= companies[i].getAverageOfEmployeesSalary();
        double var = 0;

        for (int j = 0; j < broj_vraboteni; j++) {
            double razlika_plata = companies[i].getEmployee(j).getSalary() - srp;
            //var += diff * diff;
            var+=(razlika_plata*razlika_plata);
        }

        double standardSalary = sqrt(var / (broj_vraboteni-1));

        if (standardSalary > najgolema_plata) {
            najgolema_plata = standardSalary;
            max_i = i;
        }
    }

    return companies[max_i];
}

bool isSameCompany(TechCompany comp1, TechCompany comp2){
    return strcmp(comp1.getName(), comp2.getName())==0;
}



int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout<<"-->Testing get and set methods for one object and copy constructor"<<std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout<<"-->Testing addEmployee function"<<std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout<<"-->Testing copy of first employee"<<std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout<<"-->Testing methods"<<std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " <<t1.getName() << std::endl;

    if (isSameCompany(t, t1)){
        std::cout<<"The tech company: "<<t.getName()<<" has the highest standard deviation and highest average salary"<<std::endl;
    }
    return 0;
}
