//projekt.c Anna Nagi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "projekt.h"

int wczytaj_wybor_jezyka(void){
    int jezyk;
    scanf("%d", &jezyk);
    while(jezyk!=1 && jezyk!=2){
        printf("Podales nieprawidlowa liczbe, wybierz 1 lub 2.\n");
        scanf("%d", &jezyk);
    }
    return jezyk;
}

int policz_linie(char **wybor_pliku_1){
    FILE *do_policzenia = fopen(*wybor_pliku_1, "r");
    int liczba_linii = 0;
    char c;
    for (c = getc(do_policzenia); c != EOF; c = getc(do_policzenia)){
        if (c == '\n'){
            liczba_linii++;
        }
    }
    fclose(do_policzenia);
    return liczba_linii;
}

int losowanie_slowka(int linie){
    int wylosowana=rand()%linie+1;
    return wylosowana;
}

void przypisanie_jezyka_danej_tablicy(char *wybor_pliku_1[], char *wybor_pliku_2[], int jezyk){
    if (jezyk==POLSKI_NA_ANGIELSKI){
        printf("Wybrales losowanie slow w jezyku polskim.");
        wybor_pliku_1[0] = "polskie.txt";
        wybor_pliku_2[0] = "angielskie.txt";
    }
    if (jezyk==ANGIELSKI_NA_POLSKI){
        printf("Wybrales losowanie slow w jezyku angielskim.");
        wybor_pliku_1[0] = "angielskie.txt";
        wybor_pliku_2[0] = "polskie.txt";
    }
}

const char *wyluskanie_slowa_z_pliku(int wylosowany_numer_linii, char *wybor_pliku[]){
    FILE *otwierany_plik = fopen(*wybor_pliku, "r");
    int licznik1 = 0;

    if (otwierany_plik!= NULL){
        static char wylosowane_slowo[100];
        while (fgets(wylosowane_slowo, sizeof wylosowane_slowo, otwierany_plik)!=NULL){
            if (licznik1==wylosowany_numer_linii){
                break;
            }
            else{
                licznik1++;
            }
        }
        fclose(otwierany_plik);
        return wylosowane_slowo;
    }

    else{
        fprintf( stderr, "Nie mozna wczytac pliku \n");
        exit(1);
    }
}

void wyswietlanie_podpowiedzi(const char* slowo_przetlumaczone){
    int ilosc_liter_w_slowie=strlen(slowo_przetlumaczone);
    printf("Slowo, ktore musisz wpisac ma tyle liter:  ");
    for(int i=0; i<ilosc_liter_w_slowie-1; i++){
        printf("_");
    }
}

int czy_chcesz_skorzystac_z_podpowiedzi(int liczba_podpowiedzi, const char* slowo_przetlumaczone){
    int podpowiedz=2;
    printf("\nCzy chcesz skorzystac z podpowiedzi?\n");
    printf("\nIlosc podpowiedzi do wykorzystania: %d\n", liczba_podpowiedzi);
    printf("1-tak, 2-nie   ");
    scanf("%d", &podpowiedz);

    while (podpowiedz!=1 && podpowiedz!=2){
        printf("Podales niepoprawna liczbe, wpisz 1 lub 2.\n");
        scanf("%d", &podpowiedz);
    }

    if (podpowiedz==1){
        wyswietlanie_podpowiedzi(slowo_przetlumaczone);
        liczba_podpowiedzi--;
    }
    return liczba_podpowiedzi;
}


int porownywanie_slow(const char* slowo_przetlumaczone, char* slowo_uzytkownika){
    int czy_sa_rowne=0;

    if(strcmp(slowo_przetlumaczone, slowo_uzytkownika)==0){
        printf("\nBadane lancuchy znakow sa rowne.\n" );
        czy_sa_rowne=1;
    }
    else{
        printf( "Badane lancuchy znakow nie sa rowne.\n" );
    }
    return czy_sa_rowne;
}
