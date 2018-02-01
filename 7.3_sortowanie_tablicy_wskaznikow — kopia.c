//Anna Nagi
#include <stdio.h>

void tworzenie_i_wyswietlanie_tablicy(const int rozmiar, int A[rozmiar]){
    int i;
    int *B[rozmiar];
    srand(time(0));

    printf("\nTablica nieposortowana: \n\n");
    for(i=0; i<rozmiar; ++i){
        A[i]=rand()%100;
        printf("Tablica A. Element nr %d = %d \n", i, A[i]);
        B[i]=&A[i];
    }

    int *schowek;
    int zamiana;
    do{
        zamiana=0;
        for (i=0; i<rozmiar-1; i++){
            if (*B[i]>*B[i+1]){
                zamiana=zamiana+1;
                schowek=B[i+1];
                B[i+1]=B[i];
                B[i]= schowek;
            }
        }
    }

    while(zamiana!=0);
    printf("\n\nTablica posortowana:\n\n");
    for(i=0; i<rozmiar; i++){
        printf("Tablica A. Element nr %d = %d \n", i, *B[i]);
    }
}

int main(void){
    int A[10];
    const int rozmiar=sizeof(A)/sizeof(A[0]);
    tworzenie_i_wyswietlanie_tablicy(rozmiar, A);
    return 0;
}
