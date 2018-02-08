//Anna Nagi
#include <stdio.h>
#include <time.h>

int wybieranie_czynnosci(void){
    int czynnosc;
    scanf("%d", &czynnosc);
    while(czynnosc>5 || czynnosc<1){
        printf("Podales nieprawidlowa liczbe, sprobuj ponownie \n\n");
        scanf("%d", &czynnosc);
    }
    printf("Operacja to: %d\n\n", czynnosc);
    return czynnosc;
}

void losowanie_tablicy(const int rozmiar, int tab[rozmiar]){
    srand(time(0));
    for(int i=0; i<rozmiar; ++i){
        tab[i]=rand()%100;
    }
}

void wyswietlanie_tablicy(const int rozmiar, int* tab){
    losowanie_tablicy(rozmiar, tab);
    printf("Tablica: \n");
    for(int j=0; j<rozmiar; j++){
        printf("Element nr %d = %d \n", j, tab[j]);
    }
}

void liczenie_sredniej(const int rozmiar, int* tab){
    int suma=0;
    losowanie_tablicy(rozmiar, tab);
    wyswietlanie_tablicy(rozmiar, tab);

    for (int k=0; k<rozmiar; k++){
        suma+=tab[k];
    }

    float srednia=(float)suma/(float)rozmiar;
    printf("\nSrednia liczb w tablicy wynosi: %f \n",srednia);
}

void sortowanie_tablicy(const int rozmiar, int* tab){
    losowanie_tablicy(rozmiar, tab);
    wyswietlanie_tablicy(rozmiar, tab);
    int schowek;
    int zamiana;
    do{
        zamiana=0;
        for (int i=0; i<rozmiar-1; i++){
            if (tab[i]>tab[i+1]){
                zamiana=zamiana+1;
                schowek=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=schowek;
            }
        }
    }
    while(zamiana!=0);
    printf("\nTablica posortowana: \n");
    for(int j=0; j<rozmiar; j++){
        printf("Element nr %d = %d \n", j, tab[j]);
    }
}

void liczenie_mediany(const int rozmiar, int* tab){
    sortowanie_tablicy(rozmiar, tab);
    int mediana;
    if (rozmiar%2==0){
        mediana=(tab[(rozmiar/2)-1]+tab[rozmiar/2])/2;
    }
    else{
        mediana=(tab[(rozmiar/2)-1]);
    }
    printf("\n\nMediana to: %d", mediana);
}

void element_max_min(const int rozmiar, int* tab){
    sortowanie_tablicy(rozmiar, tab);
    int min=tab[0];
    int max=tab[rozmiar-1];
    printf("\n\nElement minimalny w tablicy to: %d, a maksymalny to %d\n\n", min, max);
}

int main(void){
    int tab[10];
    const int rozmiar=sizeof(tab)/sizeof(tab[0]);

    printf("Witaj. Jaka czynnosc chcesz wykonac? \n\n1. Losowanie tablicy 10 liczb \
           \n2. Wyswietlenie tablicy 10 wylosowanych liczb \n3. Wyliczenie sredniej tych liczb\
           \n4. Wyliczenie mediany tych liczb \n5. Pokazanie maksymalnego i minimalnego elementu tej tablicy\n\n");

    int czynnosc=wybieranie_czynnosci();
    switch(czynnosc){
        case 1:
            losowanie_tablicy(rozmiar, tab);
            break;
        case 2:
            wyswietlanie_tablicy(rozmiar, tab);
            break;
        case 3:
            liczenie_sredniej(rozmiar, tab);
            break;
        case 4:
            liczenie_mediany(rozmiar, tab);
            break;
        case 5:
            element_max_min(rozmiar, tab);
            break;
    }

    return 0;
}
