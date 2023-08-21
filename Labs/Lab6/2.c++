/*
Да се напише класа InvoiceItem во која се чуваат информации за:

име на ставка (динамичка алокација од карактери)
опис на ставка (динамичка алокација од карактери)
цена на ставка (цел број)
Да се креираат:

copy конструктор
конструктор без параметри
конструктор со параметри
оператор =
деструктор
Дополнително да се преоптоварат следниве оператори:

оператор за печатење, кој што ги печати информациите за ставката во следниов формат:
Name: [name]
Description: [description]
Price: [price]
оператор ++ кој има за цел да ја зголеми цената на ставката за 10.
Потоа да се креира класа Invoice во која што ги има следните имформации:

број на фактура (низа од максимум 10 карактери)
низа од ставки (динамички алоцирана низа од InvoiceItem)
број на ставки (број на елементи во низата, цел број)
Да се креираат:
конструктор со еден параметар (број на фактура)
деструктор
функција totalPrice() што го пресметува вкупниот збир на сите ставки во фактурата
Дополнително да се преоптовари следниот оператор:

оператор += за додавање на ставка во фактурата
оператор << за печатење на сите ставки во една фактура во форматот:
Invoice Items:
Name: [inv_item_1_name]
Description: [inv_item_1_name]
Price: [inv_item_1_price]
...
Total invoice price: [totalPrice()]
  */

#include <iostream>
#include <cstring>

using namespace std;

class InvoiceItem{

private:
    char *name;
    char *description;
    int price;

public:
    InvoiceItem(char *name=" ", char *description=" ", int price=0){

        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->description=new char[strlen(description)+1];
        strcpy(this->description, description);
        this->price=price;

    }

    InvoiceItem(const InvoiceItem &ii){
        this->name=new char[strlen(ii.name)+1];
        strcpy(this->name, ii.name);
        this->description=new char[strlen(ii.description)+1];
        strcpy(this->description, ii.description);
        this->price=ii.price;
    }

    InvoiceItem &operator=(const InvoiceItem &ii) {
        if (this != &ii) {
            delete [] name;
            delete [] description;
            this->name = new char[strlen(ii.name) + 1];
            strcpy(this->name, ii.name);
            this->description = new char[strlen(ii.description) + 1];
            strcpy(this->description, ii.description);
            this->price = ii.price;
        }
        return *this;
    }

    ~InvoiceItem(){
        delete [] name;
        delete [] description;
    }

    friend ostream &operator<<(ostream &out, const InvoiceItem &ii){

        out<<"Name: "<<ii.name<<endl;
        out<<"Description: "<<ii.description<<endl;
        out<<"Price: "<<ii.price<<endl;

    }

    InvoiceItem &operator ++(){

        price+=10;
        return *this;
    }

    int getPrice() const {
        return price;
    }

};


class Invoice {

private:

    char br_faktura[10];
    InvoiceItem *items;
    int broj_stavki;

public:

    Invoice(char *br_faktura=" "){

        strcpy(this->br_faktura, br_faktura);
        items=0;
        this->broj_stavki=0;
    }

    Invoice(const Invoice &other){

        strcpy(this->br_faktura, other.br_faktura);
        this->broj_stavki=other.broj_stavki;
        this->items=new InvoiceItem[other.broj_stavki];

    }

    Invoice &operator=(const Invoice &other){

        if(this!=&other) {

            delete [] items;
            strcpy(this->br_faktura, other.br_faktura);
            this->broj_stavki = other.broj_stavki;
            this->items = new InvoiceItem[other.broj_stavki];

        }
        return *this;
    }


    ~Invoice(){
        delete [] items;
    }

    int totalPrice(){
        int vkupno=0;
        for(int i=0;i<broj_stavki;i++){
            vkupno+=items[i].getPrice();
        }
        return vkupno;
    }
    
    Invoice &operator+=(InvoiceItem inv){
        
        InvoiceItem *tmp=new InvoiceItem[broj_stavki+1];
        for(int i=0;i<broj_stavki;i++){
            tmp[i]=items[i];
        }
        tmp[broj_stavki++]=inv;
        delete [] items;
        items=tmp;
        return *this;
        
    }
    
    friend ostream &operator<<(ostream &out,  Invoice &other){
        out<<"Invoice Items: "<<endl;
        for(int i=0;i<other.broj_stavki;i++){
            
            out<<other.items[i];
            
        }
        
        out<<"Total invoice price: "<<other.totalPrice()<<endl;
        
        return out;
    }

};

int main()
{
    // -- TESTING INVOICE CONSTRUCTOR WITH ONLY ONE PARAMETER
    Invoice invoice("inv001");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char name[100];
        char description[100];
        int price;

        cin >> name;
        cin >> description;
        cin >> price;

        // -- TESTING CONSTRUCTOR WITH PARAMETERS FOR INVOICE ITEM
        InvoiceItem tempParameters = InvoiceItem(name, description, price);

        // --  TESTING COPY CONSTRUCTOR FOR INVOICE ITEM
        InvoiceItem tempCopy(tempParameters);

        // -- TESTING OPERATOR = FOR INVOICE ITEM
        InvoiceItem invoiceItem = tempCopy;

        // -- TESTING OPERATOR ++ FOR INVOICE ITEM
        ++invoiceItem;

        // -- TESTING OPERATOR += FOR INVOICE
        invoice += invoiceItem;
    }

    // -- TESTING OPERATOR << FOR INVOICE
    cout << invoice;

    return 0;
}
