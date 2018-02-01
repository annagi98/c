//Anna Nagi
#include <stdio.h>

const int liczba_elementow=3;

void dodawanie_liczb_do_tablicy(int* czas, int liczba_elementow){
    printf("\nWprowadz czas do tablicy w formacie [hh-mm-ss]:\n");
    int i;
    for(i=0; i<liczba_elementow; i++) {
        scanf("%d", &czas[i]);
    }
}

void weryfikacja_czasu(int* czas){
    if ((czas[2]<0) || (czas[1]<0) || (czas[0]<0) || (czas[2]>59) || (czas[1]>59) || (czas[0]>23)){
        printf("Format czasu jest nieprawidlowy, zmien go.\n");
        dodawanie_liczb_do_tablicy(czas,liczba_elementow);
        weryfikacja_czasu(czas);
    }
}

void porownanie_czasow(int godzina_1[liczba_elementow], int godzina_2[liczba_elementow], int liczba_elementow){
    printf("pierwsza>drugiej:1, pierwsza=druga:0, pierwsza<drugiej:-1\n\nWynik: \n");
    int j;
    int k=0;
    while(k<liczba_elementow){
        if(godzina_1[k]>godzina_2[k]){
            j=1;
            break;
        }
        else if(godzina_1[k]<godzina_2[k]){
            j=-1;
            break;
        }
        else{
            j=0;
        }
        k++;
    }
    printf("%d",j);
}

int main(void){
    int czas_1[liczba_elementow];
    int czas_2[liczba_elementow];

    dodawanie_liczb_do_tablicy(czas_1, liczba_elementow);
    weryfikacja_czasu(czas_1);
    dodawanie_liczb_do_tablicy(czas_2, liczba_elementow);
    weryfikacja_czasu(czas_2);
    porownanie_czasow(czas_1, czas_2, liczba_elementow);
    return 0;
}
