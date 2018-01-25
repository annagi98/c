//Anna Nagi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N=2;

void losowanie_macierzy(int macierz_2x2[N][N], int N){
    int i,j;
    srand(time(0));
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            macierz_2x2[i][j]=(rand()%200)-100;
        }
    }
}

void dwie_macierze_2x2_do_jednej_2x2x2(int pierwsza_macierz_2x2[N][N], int druga_macierz_2x2[N][N], int macierz_trojwymiarowa_2x2x2[N][N][N], int N){
    losowanie_macierzy(pierwsza_macierz_2x2, N);
    losowanie_macierzy(druga_macierz_2x2, N);

    int i,j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            macierz_trojwymiarowa_2x2x2[0][i][j]=pierwsza_macierz_2x2[i][j];
            macierz_trojwymiarowa_2x2x2[1][i][j]=druga_macierz_2x2[i][j];
        }
    }
}

void macierz_2x2x2_do_2_macierzy_2x2(int macierz_trojwymiarowa_2x2x2[2][2][2], int pierwsza_macierz_2x2[2][2], int druga_macierz_2x2[2][2], int N){
    int i,j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            pierwsza_macierz_2x2[i][j]=macierz_trojwymiarowa_2x2x2[0][i][j];
            druga_macierz_2x2[i][j]=macierz_trojwymiarowa_2x2x2[1][i][j];
        }
    }
}

void mnozenie_macierzy(int macierz[2][2][2], int N){
    int pierwsza_macierz_2x2[2][2],druga_macierz_2x2[2][2];
    macierz_2x2x2_do_2_macierzy_2x2(macierz, pierwsza_macierz_2x2, druga_macierz_2x2, N);

    int wynik_mnozenia[2][2];
    int i,j;
    printf("\nWynik mnozenia:\n\n\n\n");
    for (i=0; i<N; i++){
        wynik_mnozenia[0][i]= pierwsza_macierz_2x2[0][0]*druga_macierz_2x2[0][i] + pierwsza_macierz_2x2[0][1]*druga_macierz_2x2[1][i];
        printf("\t%d  ", wynik_mnozenia[0][i]);
    }
    printf("\n\n\n");

    for (j=0; j<N; j++){
        wynik_mnozenia[1][j]= pierwsza_macierz_2x2[1][0]*druga_macierz_2x2[0][j]+ pierwsza_macierz_2x2[1][1]*druga_macierz_2x2[1][j];
        printf("\t%d  ", wynik_mnozenia[1][j]);
    }
    printf("\n\n");
}

int main(void){
    int pierwsza_macierz_2x2[N][N],druga_macierz_2x2[N][N],macierz_trojwymiarowa_2x2x2[N][N][N];
    dwie_macierze_2x2_do_jednej_2x2x2(pierwsza_macierz_2x2, druga_macierz_2x2, macierz_trojwymiarowa_2x2x2, N);

    mnozenie_macierzy(macierz_trojwymiarowa_2x2x2, N);
    return 0;
}
