//Anna Nagi
#include <stdio.h>
#include <stdlib.h>

void wyswietlanie_liczb(FILE*wyswietlanie_pliku){
    printf("Plik docelowy nie istnieje.\n");
    int n=0;
    printf("Wyswietlam liczby z pliku wejsciowego: \n");
    while (fscanf(wyswietlanie_pliku, "%d", &n)!= EOF){
        printf("%d\n", n);
    }
    exit(0);
}

int policz_linie(const char *plik_wejsciowy){
    FILE *fp = fopen(plik_wejsciowy, "r");
    int znak=0;
    int linie=0;
    while((znak=fgetc(fp))!= EOF){
        if(znak=='\n'){
            linie++;
        }
    }

    fclose(fp);
    return linie;
}

void sortowanie(int tablica_liczb[], int n){
    int min,i,j;
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(tablica_liczb[j]<tablica_liczb[min]){
                min=j;
            }
        }
        int tmp=tablica_liczb[i];
        tablica_liczb[i]=tablica_liczb[min];
        tablica_liczb[min]=tmp;
    }
}


int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Przy wywolaniu podale nieprawidlowa liczbe argumentow.\n");
        exit(1);
    }

    const char*plik_wejsciowy=argv[0];

    FILE*wyswietlanie_pliku;
    wyswietlanie_pliku=fopen(plik_wejsciowy, "r");
    if(wyswietlanie_pliku==NULL){
        fprintf (stderr, "Blad przy otwieraniu pliku: %s", strerror (errno));
        exit(1);
    }
    const char*plik_wyjsciowy=argv[1];

    FILE*plik_posortowany;
    plik_posortowany=fopen(plik_wyjsciowy, "r+");

    int ilosc_liczb_wejsciowo=policz_linie(plik_wejsciowy);
    int tablica_liczb[ilosc_liczb_wejsciowo];
    int liczba=0;
    int i=0;
    while(i<ilosc_liczb_wejsciowo && fscanf(wyswietlanie_pliku, "%d", &liczba)==1){
        tablica_liczb[i]=liczba;
        i++;
    }
    fclose(wyswietlanie_pliku);

    if(plik_posortowany==NULL){
        sortowanie(tablica_liczb, ilosc_liczb_wejsciowo);
        int j;
        for (j=0; j<ilosc_liczb_wejsciowo; j++){
            printf("%d\n", tablica_liczb[i]);
        }
    }

    sortowanie(tablica_liczb, ilosc_liczb_wejsciowo);
    for(i=0; i<ilosc_liczb_wejsciowo; i++){
        fprintf(plik_posortowany,"%d\n", tablica_liczb[i]);
    }
    fclose(plik_posortowany);

    return 0;
}
