/*
Да се дефинира класа Film во која ќе се чуваат информации за:

name(низа од максимум 100 карактери) -име на филмот

rating (децимален број) - рејтинг на филмот

revenue(децимален број) - колку заработил филмот во милиони долари

Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

конструктор (без и со параметри)

деструктор

set методи

get методи

Да се дефинираат следните методи во класата:

display() која што ќе ги печати информациите за сметката во следниот формат:

Name of film: …

Rating: …

Revenue: …

Надвор од класата:

printMostPopularFilm(Film *films, int n) која што ќе го најде филмот со најголема заработувачка,

ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА
  */
#include <iostream>
#include <cstring>

using namespace std;

class Film {
  char name[101];
  float rating;
  float rev;
    
    public:
    
        // Konstruktori
        Film (char ime[101], float rr, float profit) 
        {
            strcpy(name, ime);
            rating = rr;
            rev = profit;
        }
        Film() 
        {
            strcpy(name, "");
            rating = 0;
            rev = 0;
        }
        
        // Desturkotri
        ~Film()
        {
        }
        
    void setName(char* newName)
    {
        for(int i = 0; i < 101; i++)
            name[i] = newName[i];
    }
    void setRating(float newRating)
    {
        rating = newRating;
    }
    void setRevenue(float newRev)
    {
        rev = newRev;
    }
    
    char* getName() 
    {
        return name;
    }
    float getRating()
    {
        return rating;
    }
    float getRevenue()
    {
        return rev;
    }
    
    void display()
    {
        cout << "Name of film: " << name << endl << "Rating: " << rating <<endl 
        << "Revenue: " << rev <<endl;
    }
    
};

void printMostPopularFilm(Film *films, int n)
{
    Film f;
    f.setRevenue(0);
    
    for(int i = 0; i < n; i++)
    {
        if(films[i].getRevenue() > f.getRevenue())
        {
            f.setRevenue(films[i].getRevenue());
            f.setRating(films[i].getRating());
            f.setName(films[i].getName());
        }
    }
    
    f.display();
}



int main() {
    int n;
    cin >> n;
    Film films[100];

    char name[100];
    double rating;
    double revenue;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> rating;
        cin >> revenue;

        // testing constructor with arguments
        films[i] = Film(name, rating, revenue);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> rating;
    cin >> revenue;
    films[n-1].setName(name);
    films[n-1].setRating(rating);
    films[n-1].setRevenue(revenue);

    cout<<"-->Testing set methods and display()"<<endl;
    films[n-1].display();
    cout<<endl;

    cout<<"-->Testing printMostPopularFilm()"<<endl;
    printMostPopularFilm(films , n);
    return 0;
}
