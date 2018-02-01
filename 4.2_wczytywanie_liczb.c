//Anna Nagi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int zakres_od=1;
const int zakres_do=10;

int wczytaj_liczbe(void){
    int podana;
    scanf("%d", &podana);
    return podana;
}

int czy_liczba_jest_poprawna(int liczba_usera, int wylosowana, int ilosc_prob){
    int liczba_jest_poprawna=0;
    if (liczba_usera==wylosowana){
        liczba_jest_poprawna=1;
        ilosc_prob++;
        printf("\nGratulacje! Zgadles poprawnie :) \n\n"
               "Wylosowana liczba to %d, zgadles za %d razem\n",wylosowana, ilosc_prob);
    }
    return liczba_jest_poprawna;
}

void sprawdzanie_wyniku(int wylosowana, int liczba_usera){
    while (liczba_usera<zakres_od || liczba_usera>zakres_do){
        printf("\n\nPodales liczbe spoza zakresu [%d,%d]\n\n", zakres_od, zakres_do);
        liczba_usera=zakres_od+rand()%zakres_do;
        printf("Twoja nowa liczba to: %d", liczba_usera);
    }

    int ilosc_prob=0;
    int liczba_jest_poprawna=0;
    do{
        liczba_jest_poprawna=czy_liczba_jest_poprawna(liczba_usera, wylosowana, ilosc_prob);
        if (liczba_usera<wylosowana){
            ilosc_prob++;
            printf("\nPodales za mala liczbe, sprobuj jeszcze raz:  \n");
            liczba_usera=wczytaj_liczbe();
        }
        else if (liczba_usera>wylosowana){
            ilosc_prob++;
            printf("\nPodales za duza liczbe, sprobuj jeszcze raz:  \n");
            liczba_usera=wczytaj_liczbe();
        }
    } while (liczba_jest_poprawna==0);
}

int main(void){
    srand(time(NULL));
    int wylosowana=rand()%zakres_do+zakres_od;
    printf("Wylosowano liczbe z przedzialu [1,10]\n\n");
    printf("Zgadnij ja! \n \n");
    printf("\nWpisz liczbe: ");
    int liczba_usera=wczytaj_liczbe();
    sprawdzanie_wyniku(wylosowana, liczba_usera);
    return 0;
}
