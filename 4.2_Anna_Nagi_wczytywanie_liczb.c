//Anna Nagi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int podaj_liczbe(void){
    int podana;
    scanf("%d",&podana);
    return podana;
}
int czy_liczba_jest_poprawna(int liczba_usera,int wylosowana,int ilosc_prob){
    int liczba_jest_poprawna=0;
    if (liczba_usera==wylosowana){
        liczba_jest_poprawna=1;
        ilosc_prob++;
        printf("\nGratulacje! Zgadles poprawnie :) \n\nWylosowana liczba to %d, zgadles za %d razem\n",wylosowana,ilosc_prob);
    }
    return liczba_jest_poprawna;
}
void sprawdzanie_wyniku(int wylosowana,int liczba_usera){
    int zakres_od=1;
    int zakres_do=10;
    while(liczba_usera<zakres_od||liczba_usera>zakres_do){
        printf("\n\nPodales liczbe spoza zakresu [1,10]\n\n");
        srand(time(0));
        liczba_usera=1+rand()%10;
        printf("Twoja nowa liczba to: %d",liczba_usera);
    }
    int ilosc_prob=0;
    int liczba_jest_poprawna=0;
    do{
        liczba_jest_poprawna=czy_liczba_jest_poprawna(liczba_usera,wylosowana,ilosc_prob);
        if(liczba_usera<wylosowana){
            ilosc_prob++;
            printf("\nPodales za mala liczbe, sprobuj jeszcze raz:  \n");
            liczba_usera=podaj_liczbe();
        }
        else if(liczba_usera>wylosowana){
            ilosc_prob++;
            printf("\nPodales za duza liczbe, sprobuj jeszcze raz:  \n");
            liczba_usera=podaj_liczbe();
        }
    } while (liczba_jest_poprawna==0);
}
int main(void){
    srand(time(NULL));
    int wylosowana=rand()%10+1;
    printf("Wylosowano liczbe z przedzialu [1,10]\n\n");
    printf("Zgadnij ja! \n \n");
    printf("\nWpisz liczbe: ");
    int liczba_usera=podaj_liczbe();
    sprawdzanie_wyniku(wylosowana,liczba_usera);
    return 0;
}
