//Anna Nagi
#include <stdio.h>

enum Wybieranie_rodzaju_stopni {CELSJUSZ_DO_FAHRENHEITA=1,FAHRENHEIT_DO_CELSJUSZA};

int wczytaj_wybor_stopni(void){
    int rodzaj_stopni;
    printf("Podaj co chcesz przeliczyc: \n");
    printf("1 - stopnie Celsjusza na Fahrenheita, 2 - stopnie Fahrenheita na Celsjusza \n \n");
    scanf("%d", &rodzaj_stopni);

    while (rodzaj_stopni!=1 && rodzaj_stopni!=2){
        printf("Podales nieprawidlowa liczbe, sprobuj ponownie \n\n");
        scanf("%d", &rodzaj_stopni);
    }
    return rodzaj_stopni;
}

void przeliczanie_celsjusz_do_fahrenheita(void){
    double stopnie_poczatkowe_celsjusza;
    printf("Podaj wartosc temperatury w stopniach Celsjusza.\n \n");
    scanf("%lf", &stopnie_poczatkowe_celsjusza);

    double stopnie_koncowe_fahrenheita=(stopnie_poczatkowe_celsjusza*1.8)+32;
    printf("Podana wartosc to %lf stopni Fahrenheita.", stopnie_koncowe_fahrenheita);
}

void przeliczanie_fahrenheit_do_celsjusza(void){
    double stopnie_poczatkowe_fahrenheita;
    printf("Podaj wartosc temperatury w stopniach Fahrenheita.\n \n");
    scanf("%lf", &stopnie_poczatkowe_fahrenheita);

    double stopnie_koncowe_celsjusza=(stopnie_poczatkowe_fahrenheita-32)*5/9;
    printf("Podana wartosc to %lf stopni Celsjusza.", stopnie_koncowe_celsjusza);
}

int main(void){
    printf("Program przelicza stopnie Celsjusza na stopnie Fahrenheita i odwrotnie.\n \n");
    enum Wybieranie_rodzaju_stopni rodzaj_stopni=wczytaj_wybor_stopni();

    if(rodzaj_stopni==CELSJUSZ_DO_FAHRENHEITA){
        printf("Przeliczasz stopnie Celsjusza na Fahrenheita.\n \n");
        przeliczanie_celsjusz_do_fahrenheita();
    }
    if(rodzaj_stopni==FAHRENHEIT_DO_CELSJUSZA){
        printf("Przeliczasz stopnie Fahrenheita na Celsjusza.\n \n");
        przeliczanie_fahrenheit_do_celsjusza();
    }
    return 0;
}
