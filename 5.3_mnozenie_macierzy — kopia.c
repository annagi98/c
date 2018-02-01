//Anna Nagi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie_macierzy(const int rozmiar, int macierz_2x2[rozmiar][rozmiar]){
    int i,j;
    srand(time(0));
    for (i=0; i<rozmiar; i++){
        for(j=0; j<rozmiar; j++){
            macierz_2x2[i][j]=(rand()%200)-100;
        }
    }
}

void dwie_macierze_2x2_do_jednej_2x2x2(const int rozmiar, int pierwsza_macierz_2x2[rozmiar][rozmiar], int druga_macierz_2x2[rozmiar][rozmiar], int macierz_trojwymiarowa_2x2x2[rozmiar][rozmiar][rozmiar]){
    losowanie_macierzy(rozmiar, pierwsza_macierz_2x2);
    losowanie_macierzy(rozmiar, druga_macierz_2x2);

    int i,j;
    for (i=0; i<rozmiar; i++){
        for (j=0; j<rozmiar; j++){
            macierz_trojwymiarowa_2x2x2[0][i][j]=pierwsza_macierz_2x2[i][j];
            macierz_trojwymiarowa_2x2x2[1][i][j]=druga_macierz_2x2[i][j];
        }
    }
}

void macierz_2x2x2_do_2_macierzy_2x2(const int rozmiar, int macierz_trojwymiarowa_2x2x2[rozmiar][rozmiar][rozmiar], int pierwsza_macierz_2x2[rozmiar][rozmiar], int druga_macierz_2x2[rozmiar][rozmiar]){
    int i,j;
    for (i=0; i<rozmiar; i++){
        for (j=0; j<rozmiar; j++){
            pierwsza_macierz_2x2[i][j]=macierz_trojwymiarowa_2x2x2[0][i][j];
            druga_macierz_2x2[i][j]=macierz_trojwymiarowa_2x2x2[1][i][j];
        }
    }
}

void mnozenie_macierzy(const int rozmiar, int macierz[rozmiar][rozmiar][rozmiar]){
    int pierwsza_macierz_2x2[rozmiar][rozmiar],druga_macierz_2x2[rozmiar][rozmiar];
    macierz_2x2x2_do_2_macierzy_2x2(rozmiar, macierz, pierwsza_macierz_2x2, druga_macierz_2x2);

    int wynik_mnozenia[rozmiar][rozmiar];
    int i,j;
    printf("\nWynik mnozenia:\n\n\n\n");
    for (i=0; i<rozmiar; i++){
        wynik_mnozenia[0][i]= pierwsza_macierz_2x2[0][0]*druga_macierz_2x2[0][i] + pierwsza_macierz_2x2[0][1]*druga_macierz_2x2[1][i];
        printf("\t%d  ", wynik_mnozenia[0][i]);
    }
    printf("\n\n\n");

    for (j=0; j<rozmiar; j++){
        wynik_mnozenia[1][j]= pierwsza_macierz_2x2[1][0]*druga_macierz_2x2[0][j]+ pierwsza_macierz_2x2[1][1]*druga_macierz_2x2[1][j];
        printf("\t%d  ", wynik_mnozenia[1][j]);
    }
    printf("\n\n");
}

int main(void){
    int pierwsza_macierz_2x2[2][2],druga_macierz_2x2[2][2],macierz_trojwymiarowa_2x2x2[2][2][2];
    const int rozmiar=sizeof(pierwsza_macierz_2x2)/sizeof(pierwsza_macierz_2x2[0]);
    dwie_macierze_2x2_do_jednej_2x2x2(rozmiar, pierwsza_macierz_2x2, druga_macierz_2x2, macierz_trojwymiarowa_2x2x2);

    mnozenie_macierzy(rozmiar, macierz_trojwymiarowa_2x2x2);
    return 0;
}
