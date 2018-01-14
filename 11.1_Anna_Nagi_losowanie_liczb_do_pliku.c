//Anna Nagi
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int zadana_ilosc_liczb(void){
	int n;
	printf("Podaj liczbe: ");
	scanf("%d",&n);
	while (n<=0){
		printf("Podales nieprawidlowa liczbe\n");
		printf("Podaj liczbe: ");
		scanf("%d",&n);
	}
    return n;
}

const char* podaj_nazwe_pliku(void){
    char *nazwa_pliku;
    nazwa_pliku = malloc(sizeof(char)*100);
    printf("Wpisz tekst: ");
    scanf("%s",nazwa_pliku);
    return nazwa_pliku;
}

void generowanie_liczb(void){
    int n=zadana_ilosc_liczb();
    const char* plik=podaj_nazwe_pliku();
    int tab[n];
    srand(time(NULL));
    FILE*zapisywanie_do_pliku;
    zapisywanie_do_pliku=fopen(plik,"w");
    if(zapisywanie_do_pliku==NULL){
        printf("Nie moge otworzyc pliku");
    }
    int i=0;
    while(i<n){
        fprintf(zapisywanie_do_pliku,"%d\n",rand()%1000);
        i+=1;
    }
    fclose(zapisywanie_do_pliku);
}

int main(void){
    generowanie_liczb();
    return 0;
}
