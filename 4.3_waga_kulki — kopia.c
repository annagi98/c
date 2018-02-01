//Anna Nagi
#include <stdio.h>

enum wybieranie_rodzaju_kulek {WCZESNIEJ_NIEWAZONE=1, Z_LEWEJ_SZALKI, Z_PRAWEJ_SZALKI};

int ponowne_polozenie_kulek(void){
    int wazenie;
    printf("\n\tPodales za duzo kulek. Sprobuj ponownie\n\t");
    scanf("%d", &wazenie);
    return wazenie;
}

void ktore_waza_wiecej(int waga_lewej, int waga_prawej){
    if (waga_lewej==waga_prawej){
        printf("\n\n\tKulki po prawej i lewej stronie waza tyle samo\n");
    }
    else if (waga_lewej<waga_prawej){
        printf("\n\n\tKulki po prawej waza wiecej niz kulki po lewej\n");
    }
    else{
        printf("\n\n\tKulki po lewej waza wiecej niz kulki po prawej\n");
    }
}

int z_ktorej_szalki_wazyc_kulki(void){
    int ktore_kulki;
    printf("\n\n\n Dokonujesz drugiego wazenia. \n Z ktorej grupy chcesz zwazyc kulki? ");
    printf("\n\n\t 1 - wczesniej niewazone,  2 - z lewej szalki,  3 - z prawej szalki\n");
    scanf("%d", &ktore_kulki);

    while(ktore_kulki!=1 && ktore_kulki!=2 && ktore_kulki!=3){
        printf("\n\tPodales nieprawidlowa liczbe. Wybierz 1, 2 lub 3.\n");
        scanf("%d", &ktore_kulki);
    }
    return ktore_kulki;
}

int main(void){
    srand(time(0));
    int wagi_kulek[]={1,1,1,1,1,1,1,1,1};
    const int liczba_kulek=sizeof(wagi_kulek)/sizeof(wagi_kulek[0]);

    int losowa_kulka=1+rand()%liczba_kulek;
    wagi_kulek[losowa_kulka]=2;
    printf("\nJest 9 kulek: 8 wazy tyle samo, 1 jest ciezsza. \nWszystkie wygladaja tak samo. ");
    printf("\n\nMusisz znalezc ciezsza w 2 wazeniach\n");

    int kulki_lewa_1;
    printf("\n\tIle kulek chcesz polozyc na lewej szalke?  ");
    scanf("%d", &kulki_lewa_1);
    int kulki_prawa_1;
    printf("\n\tIle kulek chcesz polozyc na prawej szalke?  ");
    scanf("%d", &kulki_prawa_1);

    while(kulki_lewa_1+kulki_prawa_1>liczba_kulek){
        int kulki_lewa_1=ponowne_polozenie_kulek();
        int kulki_prawa_1=ponowne_polozenie_kulek();
    }

    int waga_lewej=0;
    int waga_prawej=0;
    int i;
    for (i=0; i<kulki_lewa_1; i++){
        waga_lewej=waga_lewej+wagi_kulek[i];
    }
    for (i=kulki_lewa_1; i<kulki_lewa_1+kulki_prawa_1; i++){
        waga_prawej=waga_prawej+wagi_kulek[i];
    }
    ktore_waza_wiecej(waga_lewej, waga_prawej);

    enum wybieranie_rodzaju_kulek ktore_kulki=z_ktorej_szalki_wazyc_kulki();
    int kulki_lewa_2, kulki_prawa_2;
    printf("\n\n\tIle kulek chcesz polozyc na lewej szalce? ");
    scanf("%d", &kulki_lewa_2);
    printf("\n\tIle kulek chcesz polozyc na prawej szalce? ");
    scanf("%d", &kulki_prawa_2);

    waga_lewej=0;
    waga_prawej=0;

    if (ktore_kulki==WCZESNIEJ_NIEWAZONE){
        while(kulki_lewa_2+kulki_prawa_2>liczba_kulek-(kulki_lewa_1+kulki_prawa_1)){
              kulki_lewa_2=ponowne_polozenie_kulek();
              kulki_prawa_2=ponowne_polozenie_kulek();
        }
        for (i=kulki_lewa_1+kulki_prawa_1; kulki_lewa_1+kulki_prawa_1+kulki_lewa_2>i; i++){
            waga_lewej=waga_lewej+wagi_kulek[i];
        }
        for (i=kulki_lewa_1+kulki_prawa_1+kulki_lewa_2; kulki_lewa_1+kulki_prawa_1+kulki_lewa_2+kulki_prawa_2>i; i++){
            waga_prawej=waga_prawej+wagi_kulek[i];
        }
        ktore_waza_wiecej(waga_lewej,waga_prawej);
    }
    else if (ktore_kulki==Z_LEWEJ_SZALKI){
        while(kulki_lewa_2+kulki_prawa_2>kulki_lewa_1){
            kulki_lewa_2=ponowne_polozenie_kulek();
            kulki_prawa_2=ponowne_polozenie_kulek();
        }
        for (i=0; i<kulki_lewa_2; i++){
            waga_lewej=waga_lewej+wagi_kulek[i];
        }
        for (i=kulki_lewa_2; kulki_lewa_2+kulki_prawa_2>i; i++){
            waga_prawej=waga_prawej+wagi_kulek[i];
        }
        ktore_waza_wiecej(waga_lewej,waga_prawej);
    }
    else if (ktore_kulki==Z_PRAWEJ_SZALKI){
        while(kulki_lewa_2+kulki_prawa_2>kulki_prawa_1){
            kulki_lewa_2=ponowne_polozenie_kulek();
            kulki_prawa_2=ponowne_polozenie_kulek();
        }
        for (i=kulki_lewa_1; kulki_lewa_1+kulki_lewa_2>i; i++){
            waga_lewej=waga_lewej+wagi_kulek[i];
        }
        for (i=kulki_lewa_1+kulki_lewa_2; kulki_lewa_1+kulki_lewa_2+kulki_prawa_2>i; i++){
            waga_prawej=waga_prawej+wagi_kulek[i];
        }
        ktore_waza_wiecej(waga_lewej, waga_prawej);
    }
    printf("\n\n\tKtora kulka jest ciezsza od pozostalych?\n");
    return 0;
}
