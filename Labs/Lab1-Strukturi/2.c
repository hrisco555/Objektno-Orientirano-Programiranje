/*
За програмски јазик да се употреби C.


Од стандарден влез се внесува број n, број на кругови кои ќе се внесуваат, каде 0<n<100. Потоа во наредните n линии се внесуваат x и y кои го претставуваат центарот на кругот како и радиусот на кругот. На стандарден излез се печати плоштината и центарот само најголемиот круг (со најголема плоштина).



Напомена: Доколку има повеќе кругови со иста плоштина се печати само првиот круг со таа плоштина.



Во структурата Точка (Point) треба да се чуваат следните информации:

-x координата (int)

-y координата (int)



Во структурата Круг (Circle) треба да се чуваат следните информации:

-Центар (Point)

-Радиус (int)
  */

#include <stdio.h>

const float PI=3.14;
struct Tocka{
  
    int x;
    int y;
    
};

typedef struct Tocka Tocka;

struct Krug {
  
    int radius;
    Tocka centar;

};

typedef struct Krug Krug;

int main(){
    
    Krug k[20];
    
    int n,i;
    int x_koordinata=0, y_koordinata=0;
    float plostina = 0, max_plostina=0;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d", &k[i].centar.x); //x i y go pretstavuvaat centarot na krugot kako i radiusot na krugot
        scanf("%d", &k[i].centar.y);
        scanf("%d", &k[i].radius);
        
        plostina=k[i].radius * k[i].radius * PI;
        
        if(plostina>max_plostina){
            max_plostina=plostina;
            
            //x koord i y koord gi zima za da znae deka ovie specificni koordinati za da gi isprinta
            x_koordinata = k[i].centar.x;
            y_koordinata = k[i].centar.y;
        }
    }
    
    printf("Largest circle has area of: %.2f with centre: (%d,%d)", max_plostina, x_koordinata, y_koordinata);
    
    return 0;
}
