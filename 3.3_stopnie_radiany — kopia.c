//Anna Nagi
#include <stdio.h>
#include <math.h>

enum Wybieranie_jednostki {STOPNIE_NA_RADIANY=1,RADIANY_NA_STOPNIE};

int wybieranie_stopni_lub_radianow(void){
    int wybor;
    printf("Wybierz co chcesz przeliczyc: \n");
    printf("1 - stopnie na radiany, 2 - radiany na stopnie \n \n");
    scanf("%d", &wybor);
    while (wybor!=1 && wybor!=2){
        printf("Podales nieprawidlowa liczbe, sprobuj ponownie \n\n");
        scanf("%d", &wybor);
    }
    return wybor;
}

void przeliczanie_stopni_na_radiany(void){
    double poczatkowe_stopnie;
    printf("Podaj ilosc stopni.\n \n");
    scanf("%lf", &poczatkowe_stopnie);
    double koncowe_radiany=(poczatkowe_stopnie*M_PI/180);
    printf("Podana wartosc to %lf radianow.", koncowe_radiany);
}

void przeliczanie_radianow_na_stopnie(void){
    double poczatkowe_radiany;
    printf("Podaj wartosc w radianach.\n \n");
    scanf("%lf", &poczatkowe_radiany);
    double koncowe_stopnie=(poczatkowe_radiany*180/M_PI);
    printf("Podana wartosc to %lf stopni.", koncowe_stopnie);
}

int main(void){
    printf("Program przelicza stopnie na radiany i odwrotnie.\n \n");
    enum Wybieranie_jednostki wybor=wybieranie_stopni_lub_radianow();

    if(wybor==STOPNIE_NA_RADIANY){
        printf("Przeliczasz stopnie na radiany.\n \n");
        przeliczanie_stopni_na_radiany();
    }
    if(wybor==RADIANY_NA_STOPNIE){
        printf("Przeliczasz radiany na stopnie.\n \n");
        przeliczanie_radianow_na_stopnie();
    }
    return 0;
}
