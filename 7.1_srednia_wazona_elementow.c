//Anna Nagi
#include <stdio.h>

void losowanie_tablicy(int rozmiar, int tablica[rozmiar]){
    int i;
    srand(time(0));
    for(i=0; i<rozmiar; ++i){
        tablica[i]=rand()%100;
    }
}

void wyswietlanie_tablicy(int*wskaznik_poczatkowy, int*wskaznik_koncowy){
    printf("\n\n");
    printf("Tablica:  ");
    while(wskaznik_poczatkowy<wskaznik_koncowy){
        printf("%d ", *wskaznik_poczatkowy);
        ++wskaznik_poczatkowy;
    }
}

int obliczanie_sumy_liczb_x_ich_indeksow(int* wskaznik_poczatkowy, int* wskaznik_koncowy){
    int nr_indeksu=0;
    int suma_elementow_tablicy_x_ich_indeksy=0;

    while(wskaznik_poczatkowy<wskaznik_koncowy){
        suma_elementow_tablicy_x_ich_indeksy=suma_elementow_tablicy_x_ich_indeksy+((*wskaznik_poczatkowy)*nr_indeksu);
        wskaznik_poczatkowy++;
        nr_indeksu++;
    }
    return suma_elementow_tablicy_x_ich_indeksy;
}

int obliczanie_sumy_indeksow(int* wskaznik_poczatkowy, int* wskaznik_koncowy){
    int nr_indeksu=0;
    int suma_indeksow=0;

    while(wskaznik_poczatkowy<wskaznik_koncowy){
        suma_indeksow=suma_indeksow+nr_indeksu;
        nr_indeksu++;
        wskaznik_poczatkowy++;
    }
    return suma_indeksow;
}

void srednia_wazona(int suma_elementow_tablicy_x_ich_indeksy, int suma_indeksow){
    int srednia=suma_elementow_tablicy_x_ich_indeksy/suma_indeksow;
    printf("\tSrednia wazona elementow: %d\n", srednia);
}

int main(void){
    int tablica[10];
    const int rozmiar=sizeof(tablica)/sizeof(tablica[0]);

    losowanie_tablicy(rozmiar, tablica);
    wyswietlanie_tablicy(tablica, tablica+rozmiar);

    int suma_elementow_tablicy_x_ich_indeksy=obliczanie_sumy_liczb_x_ich_indeksow(tablica, tablica+rozmiar);
    int suma_indeksow=obliczanie_sumy_indeksow(tablica, tablica+rozmiar);
    srednia_wazona(suma_elementow_tablicy_x_ich_indeksy, suma_indeksow);
    return 0;
}
