//Anna Nagi
#include <stdio.h>

void losowanie_macierzy(const int rozmiar, int m[rozmiar][rozmiar]){
    srand(time(0));
    int i,j;
    for(i=0; i<rozmiar; i++){
        for(j=0; j<rozmiar; j++){
            m[i][j]=rand()%10;
        }
    }
}

void wyswietlanie_macierzy(const int rozmiar, int m[rozmiar][rozmiar]){
    losowanie_macierzy(rozmiar, m);
    int i,j;
    for(i=0; i<rozmiar; i++){
        printf("\n\n");
        for(j=0; j<rozmiar; j++){
            printf("%d  ", m[i][j]);
        }
    }
}

void obliczanie_wyznacznika(const int rozmiar, int m[rozmiar][rozmiar]){
    int wyznacznik=((m[0][0]*m[1][1])*m[2][2]+(m[0][1]*m[1][2])*m[2][0]+(m[0][2]*m[1][0])*m[2][1])\
                    -((m[0][2]*m[1][1])*m[2][0]+(m[0][1]*m[1][0])*m[2][2]+(m[0][0]*m[1][2])*m[2][1]);

    printf("\n \n \nWyznacznik tej macierzy wynosi: %d \n", wyznacznik);
}

int main(void){
    int macierz[3][3];
    const int rozmiar=sizeof(macierz)/sizeof(macierz[0]);
    printf("Obliczanie wyznacznika macierzy 3x3. Wartosci w macierzy sa losowo dobrane.\n\n");

    printf("\nPostac macierzy:\n");
    wyswietlanie_macierzy(rozmiar, macierz);

    obliczanie_wyznacznika(rozmiar, macierz);
    return 0;
}
