//Anna Nagi
#include <stdio.h>

int wybieranie_rodzaju_stopni(void){
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

void Celsjusz_do_Fahrenheita(void){
    double stopnie_poczatkowe_celsjusza;
    printf("Podaj wartosc temperatury w stopniach Celsjusza.\n \n");
    scanf("%lf", &stopnie_poczatkowe_celsjusza);

    double stopnie_koncowe_fahrenheita=(stopnie_poczatkowe_celsjusza*1.8)+32;
    printf("Podana wartosc to %lf stopni Fahrenheita.", stopnie_koncowe_fahrenheita);
}

void Fahrenheit_do_Celsjusza(void){
    double stopnie_poczatkowe_fahrenheita;
    printf("Podaj wartosc temperatury w stopniach Fahrenheita.\n \n");
    scanf("%lf", &stopnie_poczatkowe_fahrenheita);

    double stopnie_koncowe_celsjusza=(stopnie_poczatkowe_fahrenheita-32)*5/9;
    printf("Podana wartosc to %lf stopni Celsjusza.", stopnie_koncowe_celsjusza);
}

int main(void){
    printf("Program przelicza stopnie Celsjusza na stopnie Fahrenheita i odwrotnie.\n \n");
    int rodzaj_stopni=wybieranie_rodzaju_stopni();

    if(rodzaj_stopni==1){
        printf("Przeliczasz stopnie Celsjusza na Fahrenheita.\n \n");
        Celsjusz_do_Fahrenheita();
    }
    if(rodzaj_stopni==2){
        printf("Przeliczasz stopnie Fahrenheita na Celsjusza.\n \n");
        Fahrenheit_do_Celsjusza();
    }
    return 0;
}
