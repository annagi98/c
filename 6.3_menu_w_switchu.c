//Anna Nagi
#include <stdio.h>
#include <time.h>

const int rozmiar=10;

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

void losowanie_tablicy(int tab[rozmiar], int rozmiar){
    int i;
    srand(time(0));
    for(i=0; i<rozmiar; ++i){
        tab[i]=rand()%100;
    }
}

void wyswietlanie_tablicy(int* tab, int rozmiar){
    int j;
    losowanie_tablicy(tab,rozmiar);
    printf("Tablica: \n");
    for(j=0; j<rozmiar; j++){
        printf("Element nr %d = %d \n", j, tab[j]);
    }
}

void liczenie_sredniej(int* tab, int rozmiar){
    int suma=0;
    int k;
    losowanie_tablicy(tab, rozmiar);
    wyswietlanie_tablicy(tab, rozmiar);

    for (k=0;k<10;k++){
        suma+=tab[k];
    }

    float srednia=0;
    srednia=suma/10;
    printf("\nSrednia liczb w tablicy wynosi: %f \n",srednia);
}

void sortowanie_tablicy(int* tab, int rozmiar){
    losowanie_tablicy(tab, rozmiar);
    wyswietlanie_tablicy(tab, rozmiar);
    int schowek;
    int zamiana;
    int i;
    do{
        zamiana=0;
        for (i=0; i<9; i++){
            if (tab[i]>tab[i+1]){
                zamiana=zamiana+1;
                schowek=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=schowek;
            }
        }
    }
    while(zamiana!=0);
    int j;
    printf("\nTablica posortowana: \n");
    for(j=0; j<10; j++){
        printf("Element nr %d = %d \n", j, tab[j]);
    }
}

void liczenie_mediany(int* tab, int rozmiar){
    sortowanie_tablicy(tab, rozmiar);
    int mediana=0;
    mediana=(tab[4]+tab[5])/2;
    printf("\n\nMediana to: %d", mediana);
}

void element_max_min(int* tab, int rozmiar){
    sortowanie_tablicy(tab, rozmiar);
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
            losowanie_tablicy(tab, rozmiar);
            break;
        case 2:
            wyswietlanie_tablicy(tab, rozmiar);
            break;
        case 3:
            liczenie_sredniej(tab, rozmiar);
            break;
        case 4:
            liczenie_mediany(tab, rozmiar);
            break;
        case 5:
            element_max_min(tab, rozmiar);
            break;
    }

    return 0;
}
