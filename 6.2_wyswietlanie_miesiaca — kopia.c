//Anna Nagi
#include <stdio.h>
#include <time.h>

int zamiana_string_na_int (char tekst[]){
    char *str=tekst;
    int intt;
    sscanf(str, "%d", &intt);
    return intt;
}

void aktualny_miesiac(char *buffer){
    printf("\n\t\tAktualny miesiac i rok to: %s  ", buffer);
}

void aktualny_rok(int ktory_rok){
    printf("%d\n\n\n", ktory_rok);
}

int ile_dni_w_miesiacu (int nr_miesiaca, int ktory_rok){
    int dlugosc_miesiaca;
    if (nr_miesiaca==2){
        if (((ktory_rok%4==0) && (ktory_rok%100!=0)) || (ktory_rok%400==0)){
            return dlugosc_miesiaca=29;
        }
        else {
            return dlugosc_miesiaca=28;
        }
    }
    else if ((nr_miesiaca==4) || (nr_miesiaca==6) || (nr_miesiaca==9) || (nr_miesiaca==11)){
        return dlugosc_miesiaca=30;
    }
    else {
        return dlugosc_miesiaca=31;
    }
}

void wyswietlanie_miesiaca(int jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca, int dlugosc_miesiaca){
    printf("\t pon      wt      sr     czw      pt     sob     nd\n\n\n");
    int liczba=0;
    int pokaz_miesiac[40],e=0;

    for (e=0; e<jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca-2; e++){
            printf("\t0");
    }
    for (e=jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca-1; e<=dlugosc_miesiaca+jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca-1; e++){
        pokaz_miesiac[e]=liczba;
        printf("\t%d", pokaz_miesiac[e]);
        liczba++;
        if (e%7==0){
            printf("\n\n");
        }
    }
}

int main(void){
    time_t czas_ogolnie;
    struct tm* informacja_czas;
    char buffer[100];
    time(&czas_ogolnie);
    informacja_czas=localtime(&czas_ogolnie);

    strftime(buffer, 100, "%B", informacja_czas);
    aktualny_miesiac(buffer);

    strftime(buffer, 100, "%d", informacja_czas);
    int dzien_dzisiaj=zamiana_string_na_int(buffer);

    strftime(buffer, 100, "%w", informacja_czas);
    int jaki_dzien_tygodnia=zamiana_string_na_int(buffer);//(string 0-6, gdzie 0 to nd, 1 to pn itd.)

    strftime(buffer, 100, "%m", informacja_czas);
    int nr_miesiaca=zamiana_string_na_int(buffer);

    strftime(buffer, 100, "%Y", informacja_czas);
    int ktory_rok=zamiana_string_na_int(buffer);
    aktualny_rok(ktory_rok);

    int dlugosc_miesiaca=ile_dni_w_miesiacu (nr_miesiaca, ktory_rok);
    int jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca=0;
    jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca=(abs(jaki_dzien_tygodnia-dzien_dzisiaj+1))%7;

    if ((jaki_dzien_tygodnia-dzien_dzisiaj+1)<0){
        jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca=7-jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca;
    }
    if (jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca==0){
        jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca=7;
    }

    wyswietlanie_miesiaca(jaki_dzien_tygodnia_to_pierwszy_dzien_miesiaca, dlugosc_miesiaca);
    return 0;
}
