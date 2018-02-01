//main.c Anna Nagi

#include <stdio.h>
#include "projekt.h"

int main(void){
    printf("Program pomaga w nauce technicznego jezyka angelskiego.\n\n");
    printf("Wybierz jezyk, w ktorym chcesz, aby wyswietlilo sie slowo. \n1-polski, 2-angielski\n\n");

    enum Kierunek_tlumaczenia jezyk=wczytaj_wybor_jezyka();

    int liczba_zyc=5;
    int liczba_podpowiedzi=3;
    int punkty=0;

    srand(time(NULL));
    char *wybor_pliku_1[100];
    char *wybor_pliku_2[100];

    przypisanie_jezyka_danej_tablicy(wybor_pliku_1, wybor_pliku_2, jezyk);
    int linie=policz_linie(wybor_pliku_1);

    while(liczba_zyc>0){
        int wylosowany_numer_linii = losowanie_slowka(linie);

        const char *slowo_1=wyluskanie_slowa_z_pliku(wylosowany_numer_linii, wybor_pliku_1);
        printf("\n\n\nWylosowano slowo: %s", slowo_1);
        const char *slowo_2=wyluskanie_slowa_z_pliku(wylosowany_numer_linii, wybor_pliku_2);

        liczba_podpowiedzi=czy_chcesz_skorzystac_z_podpowiedzi(liczba_podpowiedzi, slowo_2);

        char slowo_uzytkownika[100];
        const char tmp[10]="\n\0";
        printf("\n\nPodaj to slowo w drugim jezyku:\n");
        scanf("%s",slowo_uzytkownika);

        int p=0;
        char litera;
        while (slowo_uzytkownika[p]){
            if (!isalpha(slowo_uzytkownika[p])){
                printf("\n\nW twoim wyrazie wystepuja znaki inne niz litery. Wprowadz slowo ponownie: \n");
                scanf("%s",slowo_uzytkownika);
                p=0;
            }
            litera=slowo_uzytkownika[p];
            slowo_uzytkownika[p]=(tolower(litera));
            p++;
        }

        strcat(slowo_uzytkownika, tmp);

        int rowne=porownywanie_slow(slowo_2, slowo_uzytkownika);
        if (rowne==1){
            printf("\nBrawo!");
            punkty++;
            printf("Zdobyles punkt!.\n");
        }
        if (rowne==0){
            printf("\nPodales nieprawidlowe slowo. Tracisz zycie.\n");
            liczba_zyc--;
            printf("\nPozostale zycia:  ");
            int j;
            for(j=0; j<liczba_zyc; j++){
                printf("x");
            }

            printf("\n");
            printf("Poprawne slowo: %s\n", slowo_2);
        }
    }
    printf("Gra skonczona! Zdobyles tyle punktow: %d\n", punkty);
    return 0;
}
