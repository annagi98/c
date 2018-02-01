//Anna Nagi
#include <stdio.h>
#include <math.h>

int wprowadzanie_wartosci_wspolczynnikow(void){
    int wspolczynnik;
    scanf("%d", &wspolczynnik);
    return wspolczynnik;
}

int liczenie_delty(const int a, const int b, const int c){
    float delta=b*b-4*a*c;
    printf("\nDelta wynosi: %.2f \n", delta);
    return delta;
}

void obliczanie_jednego_piewiastka(const int a, const int b){
    float x0=-b/2*a;
    printf("\nWystepuje jeden pierwiastek rownania: %.2f\n", x0);
}

void obliczanie_dwoch_pierwiastkow(float delta, const int a, const int b){
    float pierwiastek_z_delty=sqrt(delta);
    float x1=(-b-pierwiastek_z_delty)/2*a;
    float x2=(-b+pierwiastek_z_delty)/2*a;
    printf("\nWystepuja dwa pierwiastki rownania: %.2f, %.2f \n", x1, x2);
}

int main(void){
    printf("Program liczy pierwiastki rownania kwadratowego\n\n");
    printf("Podaj wartosci wspolczynnikow: ax^2+bx+c \n\n");
    printf("\na = ");
    int a=wprowadzanie_wartosci_wspolczynnikow();
    while (a==0){
        printf("Wspolczynnik a nie moze byc rowny zero, sprobuj ponownie: \n");
        a=wprowadzanie_wartosci_wspolczynnikow();
    }
    printf("\nb = ");
    int b=wprowadzanie_wartosci_wspolczynnikow();
    printf("\nc = ");
    int c=wprowadzanie_wartosci_wspolczynnikow();

    float delta=liczenie_delty(a, b, c);
    if (delta<0){
        printf("\nTo rownanie kwadratowe nie ma rozwiazan rzeczywistych\n");
    }
    if (delta==0){
        obliczanie_jednego_piewiastka(a, b);
    }
    if (delta>0){
        obliczanie_dwoch_pierwiastkow(delta, a, b);
    }
    return 0;
}
