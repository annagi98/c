//projekt.c Anna Nagi

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "projekt.h"

void listuj_slowniki( const char * nazwa_sciezki ) {
    struct dirent * plik;
    DIR * sciezka;

    if((sciezka=opendir(nazwa_sciezki))) {
        while((plik=readdir(sciezka)))
             puts(plik->d_name);

        closedir(sciezka);
    }
    else
         printf( "Podano nieprawidlowa sciezke.\n");
}

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
    FILE *do_policzenia=fopen(*wybor_pliku_1, "r");
    int liczba_linii = 0;
    char c;
    for (c=getc(do_policzenia); c!=EOF; c=getc(do_policzenia)){
        if (c=='\n'){
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
    const char *plikZeSlowamiPolskimi="slowniki/slowa_polskie.txt";
    const char *plikZeSlowamiAngielskimi="slowniki/slowa_angielskie.txt";

    if (jezyk==POLSKI_NA_ANGIELSKI){
        printf("Wybrales losowanie slow w jezyku polskim.");
        wybor_pliku_1[0] = plikZeSlowamiPolskimi;
        wybor_pliku_2[0] = plikZeSlowamiAngielskimi;
    }
    if (jezyk==ANGIELSKI_NA_POLSKI){
        printf("Wybrales losowanie slow w jezyku angielskim.");
        wybor_pliku_1[0] = plikZeSlowamiAngielskimi;
        wybor_pliku_2[0] = plikZeSlowamiPolskimi;
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
    int i;
    for(i=0; i<ilosc_liter_w_slowie-1; i++){
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

void sprawdzanie_slowa(char *slowo_uzytkownika){
    int znak=0;
    char litera;
    while (slowo_uzytkownika[znak]){
        if (!isalpha(slowo_uzytkownika[znak])){
            printf("\n\nW twoim wyrazie wystepuja znaki inne niz litery. Wprowadz slowo ponownie: \n");
            scanf("%s", slowo_uzytkownika);
            znak=0;
        }
        slowo_uzytkownika[znak]=(tolower(slowo_uzytkownika[znak]));
        znak++;
    }
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
