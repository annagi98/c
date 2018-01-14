//Anna Nagi
#include <stdio.h>
#include <stdlib.h>

const char* podaj_nazwe_pliku(void){
    char *nazwa_pliku;
    nazwa_pliku = malloc(sizeof(char)*100);
    printf("Wpisz tekst: ");
    scanf("%s",nazwa_pliku);
    return nazwa_pliku;
}
void wyswietlanie_liczb(FILE*wyswietlanie_pliku){
    printf("Plik docelowy nie istnieje.\n");
    int n=0;
    printf("Wyswietlam liczby z pliku wejsciowego: \n");
    while (fscanf(wyswietlanie_pliku,"%d",&n)!= EOF){
        printf("%d\n",n);
    }
    exit(0);
}
int policz_linie(const char *plik_wejsciowy){
    FILE *fp = fopen(plik_wejsciowy,"r");
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
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(tablica_liczb[j]<tablica_liczb[min]){
                min=j;
            }
        }
        int tmp=tablica_liczb[i];
        tablica_liczb[i]=tablica_liczb[min];
        tablica_liczb[min]=tmp;
    }
}

int main(void){
    printf("Podaj nazwe pliku wejsciowego.\n");
    const char*plik_wejsciowy=podaj_nazwe_pliku();
    FILE*wyswietlanie_pliku;
    wyswietlanie_pliku=fopen(plik_wejsciowy,"r");
    if(wyswietlanie_pliku==NULL){
        printf("\nNie mozna otworzyc pliku wejsciowego.\n");
        exit(0);
    }
    printf("Podaj nazwe pliku wyjsciowego: \n");
    const char*plik_wyjsciowy=podaj_nazwe_pliku();
    FILE*plik_posortowany;
    plik_posortowany=fopen(plik_wyjsciowy,"r+");

    if(plik_posortowany==NULL){
        wyswietlanie_liczb(wyswietlanie_pliku);
    }
    int ilosc_liczb_wejsciowo=policz_linie(plik_wejsciowy);
    int tablica_liczb[ilosc_liczb_wejsciowo];
    int liczba=0;
    int i=0;
    while(i<ilosc_liczb_wejsciowo&&fscanf(wyswietlanie_pliku,"%d",&liczba)==1){
        tablica_liczb[i]=liczba;
        i++;
    }
    fclose(wyswietlanie_pliku);
    sortowanie(tablica_liczb,ilosc_liczb_wejsciowo);
    for(i=0;i<ilosc_liczb_wejsciowo;i++){
        fprintf(plik_posortowany,"%d\n", tablica_liczb[i]);
    }
    fclose(plik_posortowany);
    return 0;
}
