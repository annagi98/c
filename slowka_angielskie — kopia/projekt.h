//projekt.h Anna Nagi
#ifndef projekt_h
#define projekt_h

enum Kierunek_tlumaczenia {POLSKI_NA_ANGIELSKI=1, ANGIELSKI_NA_POLSKI};

int wczytaj_wybor_jezyka(void);

int policz_linie(char **wybor_pliku_1);

int losowanie_slowka(int linie);

void przypisanie_jezyka_danej_tablicy(char *wybor_pliku_1[], char *wybor_pliku_2[], int jezyk);

const char *wyluskanie_slowa_z_pliku(int wylosowany_numer_linii, char *wybor_pliku[]);

void wyswietlanie_podpowiedzi(const char* slowo_przetlumaczone);

int czy_chcesz_skorzystac_z_podpowiedzi(int liczba_podpowiedzi, const char* slowo_przetlumaczone);

int porownywanie_slow(const char* slowo_przetlumaczone, char* slowo_uzytkownika);


#endif
