//Anna Nagi
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sprawdzanie_liczby(int ilosc_liczb){
    if (ilosc_liczb<0 || ilosc_liczb>1000){
        printf("Podales nieprawidlowy argument - liczbe.\n");
        exit(1);
    }
}

const char* podaj_nazwe_pliku(void){
    char *nazwa_pliku;
    nazwa_pliku = malloc(sizeof(char)*100);
    printf("Wpisz tekst: ");
    scanf("%s", nazwa_pliku);
    return nazwa_pliku;
}

void generowanie_liczb(int n, char argv[1]){
    char *plik=argv;
    int tab[n];
    srand(time(NULL));

    FILE*zapisywanie_do_pliku;
    zapisywanie_do_pliku=fopen(plik, "w");
    if(zapisywanie_do_pliku==NULL){
        printf("Nie moge otworzyc pliku");
    }

    int i=0;
    while(i<n){
        fprintf(zapisywanie_do_pliku, "%d\n", rand()%1000);
        i+=1;
    }
    fclose(zapisywanie_do_pliku);
}

int main(int argc, char *argv[]){
    int ilosc_liczb=atoi(argv[0]);
    sprawdzanie_liczby(ilosc_liczb);
    generowanie_liczb(ilosc_liczb, argv[1]);
    return 0;
}
