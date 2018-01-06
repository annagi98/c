//Anna Nagi
#include <stdio.h>

const int N=3;
void losowanie_macierzy(int m[N][N],int N){
    srand(time(0));
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            m[i][j]=rand()%10;
        }
    }
}
void wyswietlanie_macierzy(int m[N][N],int N){
    losowanie_macierzy(m,N);
    int i,j;
    for(i=0;i<N;i++){
        printf("\n\n");
        for(j=0;j<N;j++){
            printf("%d  ",m[i][j]);
        }
    }
}
void obliczanie_wyznacznika(int m[N][N]){
    int wyznacznik=((m[0][0]*m[1][1])*m[2][2]+(m[0][1]*m[1][2])*m[2][0]+(m[0][2]*m[1][0])*m[2][1])-((m[0][2]*m[1][1])*m[2][0]+(m[0][1]*m[1][0])*m[2][2]+(m[0][0]*m[1][2])*m[2][1]);
    printf("\n \n \nWyznacznik tej macierzy wynosi: %d \n",wyznacznik);
}
int main(void){
    int macierz[N][N];
    printf("Obliczanie wyznacznika macierzy 3x3. Wartosci w macierzy sa losowo dobrane.\n\n");
    printf("\nPostac macierzy:\n");
    wyswietlanie_macierzy(macierz,N);
    obliczanie_wyznacznika(macierz);
    return 0;
}
