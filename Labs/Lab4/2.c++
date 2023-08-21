/*
Да се дефинира класа Product за која се чува информација за:

име на продукт (низа од карактери)
набавна цена (цел број)
продажна цена (цел број)
За класата да се дефинираат следните методи: 

default конструктор
конструктор со аргументи
copy конструктор
int profit() метод што ја враќа добивката (продажна - набавна цена)
void display() метод за печатење на производ во формат ИМЕ - ПРОФИТ
Потоа дефинирајте класа Company за која се чува информација за:

име (низа од карактери)
низа од продукти (динамички алоцирана низа од објекти од класата Product)
број на елементи во низата (цел број)
За класата да се дефинираат следните методи:

default конструктор
конструктор со аргументи
copy конструктор
деструктор
оператор =
int totalProfit() метод за пресметување на профит
void display() метод за печатење на информации за компанијата во формат 
 ИМЕ
 производ1
 .
 .
производN
профит
void addNewProduct(Product p) метод за додавање на нов производ
void deleteProduct(Product p) метод за бришење на производот р 
Да не се менува main функцијата, по потреба може да се дефинираат и дополнителни методи.
*/

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

class Product{
private:
    char name[20];
    int originalCost;
    int sellingPrice;

public:
    Product(char *name=" ", int originalCost=0, int sellingPrice=0){
        strcpy(this->name,name);
        this->originalCost=originalCost;
        this->sellingPrice=sellingPrice;
    }

    Product(const Product &p){
        strcpy(this->name,p.name);
        this->originalCost=p.originalCost;
        this->sellingPrice=p.sellingPrice;
    }

    void setOriginalCost(int originalCost) {
        this->originalCost = originalCost;
    }

    int profit(){

       return sellingPrice-originalCost;
    }

    void display(){
        cout<<name<<" - "<<profit()<<endl;
    }

    bool daliseisti(Product &p){
        if(strcmp(name, p.name)==0){
            return true;
        }
        else {
            return false;
        }
    }

};

class Company{
private:
    char ime[20];
    Product *products;
    int num_of_products;

public:
    
    Company(char *ime=" ", Product *products=0,int num_of_products=0){
        strcpy(this->ime, ime);
        this->num_of_products=num_of_products;
        this->products=new Product[num_of_products];
        for(int i=0;i<num_of_products;i++){
            this->products[i]=products[i];
        }

    }

    Company(const Company &c){
        strcpy(this->ime, c.ime);
        this->num_of_products=c.num_of_products;
        this->products=new Product[num_of_products];

        for(int i=0;i<num_of_products;i++){
            this->products[i]=c.products[i];
        }

    }

    ~Company(){
        delete [] products;
    }

    Company &operator=(const Company &c){
        if(this!=&c){
            delete [] products;
            strcpy(this->ime, c.ime);
            this->num_of_products=c.num_of_products;
            this->products=new Product[num_of_products];

            for(int i=0;i<num_of_products;i++){
                this->products[i]=c.products[i];
            }
        }
        return *this;
    }

    int totalProfit(){

        int total=0;
        for(int i=0;i<num_of_products;i++){
            total+=products[i].profit();
        }
        return total;
    }

    void display(){
        for(int i=0;i<num_of_products;i++){
            products[i].display();

        }
    }

    void addNewProduct(Product p){
        Product *temp=products;
        this->products=new Product[num_of_products+1];
        for(int i=0;i<num_of_products;i++){
            products[i]=temp[i];
        }
        temp[num_of_products++]=p;
        delete [] products;
        products=temp;

    }


    void deleteProduct(Product p){

        int brojac=0;
        for(int i=0;i<num_of_products;i++){
            if(!products[i].daliseisti(p)){
                brojac++;
            }
        }

        Product *tmp=new Product[brojac];
        brojac=0;
        for(int i=0;i<num_of_products;i++){
            if(!products[i].daliseisti(p)){
                tmp[brojac++]=products[i];
            }
        }

        delete [] products;
        products=tmp;
        num_of_products=brojac;

    }


};

int main()
{
   int check;
   cin>>check;
   if(check == 0) 
   {
       cout<<"--- Testing Product class ---"<<endl;
       Product p1;
       char name[100];
       cin>>name;
       p1=Product(name, 80, 111);
       Product p2=p1;
       p2.display();
   }
   Product products[100];
   for(int i=0; i<7; i++)
   {
       char name[100];
       int originalCost;
       int sellingPrice;
       cin>>name>>originalCost>>sellingPrice;
       products[i]=Product(name, originalCost, sellingPrice);
   }
   if(check == 1)
   {
       cout<<"--- Testing Company class ---"<<endl;
       char cmpName[100];
       cin>>cmpName;
       Company company;
       company=Company(cmpName, products, 7);
       company.display();
   }
   if(check == 2)
   {
       cout<<"--- Testing addNewProduct() and deleteProduct() method ---"<<endl;
       char n[100];
       cin>>n;
       Product p=Product(n, 29, 49);
       char cmpName[100];
       cin>>cmpName;
       Company company;
       company=Company(cmpName, products, 7);
       company.addNewProduct(p);
       company.display();
       company.deleteProduct(p);
       company.display();
   }
}

