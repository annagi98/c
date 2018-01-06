//Anna Nagi
#include <stdio.h>
#include <math.h>

int wybieranie(void){
    int wybor;
    printf("Wybierz co chcesz przeliczyc: \n");
    printf("1 - stopnie na radiany, 2 - radiany na stopnie \n \n");
    scanf("%d",&wybor);
    while (wybor!=1&&wybor!=2){
        printf("Podales nieprawidlowa liczbe, sprobuj ponownie \n\n");
        scanf("%d",&wybor);
    }
    return wybor;
}
void stopnie_na_radiany(void){
    double poczatkowe_stopnie;
    printf("Podaj ilosc stopni.\n \n");
    scanf("%lf",&poczatkowe_stopnie);
    double koncowe_radiany=(poczatkowe_stopnie*M_PI/180);
    printf("Podana wartosc to %lf radianow.",koncowe_radiany);
}
void radiany_na_stopnie(void){
    double poczatkowe_radiany;
    printf("Podaj wartosc w radianach.\n \n");
    scanf("%lf",&poczatkowe_radiany);
    double koncowe_stopnie=(poczatkowe_radiany*180/M_PI);
    printf("Podana wartosc to %lf stopni.",koncowe_stopnie);
}
int main(void){
    printf("Program przelicza stopnie na radiany i odwrotnie.\n \n");
    int wybor=wybieranie();
    if(wybor==1){
        printf("Przeliczasz stopnie na radiany.\n \n");
        stopnie_na_radiany();
    }
    if(wybor==2){
        printf("Przeliczasz radiany na stopnie.\n \n");
        radiany_na_stopnie();
    }
    return 0;
}
