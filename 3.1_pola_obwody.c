//Anna Nagi
#include <stdio.h>
#include <math.h>

int wybor_pole_czy_obwod(void){
    int operacja;
    printf("Chcesz obliczyc pole czy obwod? 1-pole, 2-obwod \n");
    scanf("%d", &operacja);
    while (operacja!=1 && operacja!=2){
        printf("Podales nieprawidlowa liczbe, sprobuj ponownie: \n\n");
        printf("Co chcesz obliczyc? 1-pole, 2-obwod \n");
        scanf("%d",&operacja);
    }
    return operacja;
}

double wczytaj_dlugosc_boku(void){
    double bok;
    scanf("%lf",&bok);
    while(bok<=0){
        printf("Wartosc dlugosci musi byc dodatnia. Sprobuj ponownie:  \n");
        scanf("%lf",&bok);
    }
    return bok;
}

void kwadrat(){
    printf("Wybrana figura to kwadrat.\n");
    int pole_czy_obwod_kwadratu=wybor_pole_czy_obwod();

    printf("Podaj dlugosc boku kwadratu: \n");
    double bok_kwadratu=wczytaj_dlugosc_boku();
    if(pole_czy_obwod_kwadratu==1){
        obliczanie_pola_kwadratu(bok_kwadratu);
    }
    if(pole_czy_obwod_kwadratu==2){
        obliczanie_obwodu_kwadratu(bok_kwadratu);
    }
}

void obliczanie_pola_kwadratu(double bok_kwadratu){
    double pole1=(bok_kwadratu*bok_kwadratu);
    printf("Pole kwadratu = %lf", pole1);
}

void obliczanie_obwodu_kwadratu(double bok_kwadratu){
    double obwod_kwadratu=4*bok_kwadratu;
    printf("Obwod kwadratu = %lf", obwod_kwadratu);
}


void prostokat(){
    printf("Wybrana figura to prostokat.\n");
    int pole_czy_obwod_prostokata=wybor_pole_czy_obwod();

    printf("Podaj dlugosc pierwszego boku prostokata: \n");
    double bok_prostokata1=wczytaj_dlugosc_boku();
    printf("Podaj dlugosc drugiego boku prostokata: \n");
    double bok_prostokata2=wczytaj_dlugosc_boku();
    if(pole_czy_obwod_prostokata==1){
        obliczanie_pola_prostokata(bok_prostokata1,bok_prostokata2);
    }
    if(pole_czy_obwod_prostokata==2){
        obliczanie_obwodu_prostokata(bok_prostokata1,bok_prostokata2);
    }
}

void obliczanie_pola_prostokata(double bok_prostokata1, double bok_prostokata2){
    double pole_prostokata=(bok_prostokata1*bok_prostokata2);
    printf("Pole prostokata = %lf", pole_prostokata);
}

void obliczanie_obwodu_prostokata(double bok_prostokata1,double bok_prostokata2){
    double obwod_prostokata=2*(bok_prostokata1+bok_prostokata2);
    printf("Obwod prostokata = %lf", obwod_prostokata);
}


void trojkat(){
    printf("Wybrana figura to trojkat.\n");
    int pole_czy_obwod_trojkata=wybor_pole_czy_obwod();
    printf("Podaj dlugosc pierwszego boku trojkata: \n");
    double bok_trojkata1=wczytaj_dlugosc_boku();
    if(pole_czy_obwod_trojkata==1){
        printf("Podaj dlugosc wysokosci trojkata: \n");
        double wysokosc_trojkata=wczytaj_dlugosc_boku();
        obliczanie_pola_trojkata(bok_trojkata1,wysokosc_trojkata);
    }
    if(pole_czy_obwod_trojkata==2){
        printf("Podaj dlugosc drugiego boku trojkata: \n");
        double bok_trojkata2=wczytaj_dlugosc_boku();
        printf("Podaj dlugosc trzeciego boku trojkata: \n");
        double bok_trojkata3=wczytaj_dlugosc_boku();
        while((bok_trojkata1+bok_trojkata2<=bok_trojkata3)||(bok_trojkata1+bok_trojkata3<=bok_trojkata2)||(bok_trojkata2+bok_trojkata3<=bok_trojkata1)){
            printf("Taki trojkat nie istnieje, wprowadz ponownie dlugosci bokow\n");
            bok_trojkata1=wczytaj_dlugosc_boku();
            bok_trojkata2=wczytaj_dlugosc_boku();
            bok_trojkata3=wczytaj_dlugosc_boku();
        }
        obliczanie_obwodu_trojkata(bok_trojkata1,bok_trojkata2,bok_trojkata3);
    }

}

void obliczanie_pola_trojkata(double bok_trojkata1,double wysokosc_trojkata){
    double pole_trojkata=(bok_trojkata1*wysokosc_trojkata/2);
    printf("Pole trojkata = %lf",pole_trojkata);
}

void obliczanie_obwodu_trojkata(double bok_trojkata1, double bok_trojkata2, double bok_trojkata3){
    double obwod_trojkata=(bok_trojkata1+bok_trojkata2+bok_trojkata3);
    printf("Obwod trojkata = %lf", obwod_trojkata);
}


void kolo(){
    printf("Wybrana figura to kolo.\n");
    int pole_czy_obwod_kola=wybor_pole_czy_obwod();
    printf("Podaj dlugosc promienia kola: \n");
    double promien=wczytaj_dlugosc_boku();
    if(pole_czy_obwod_kola==1){
        obliczanie_pola_kola(promien);
    }
    if(pole_czy_obwod_kola==2){
        obliczanie_obwodu_kola(promien);
    }
}

void obliczanie_pola_kola(double promien){
    double pola_kola=(M_PI*(promien*promien));
    printf("Pole kola = %lf",pola_kola);
}

void obliczanie_obwodu_kola(double promien){
    double obwod_kola=(2*M_PI*promien);
    printf("Obwod kola = %lf", obwod_kola);
}


int main(void){
    int figura;
    printf("Program oblicza pola lub obwody wybranych figur. \n \n");
    printf("Jaka figure bierzemy pod uwage? 1-kwadrat, 2-prostokat, 3-trojkat, 4-kolo \n");
    scanf("%d",&figura);
    switch(figura){
        case 1:
            kwadrat();
            break;
        case 2:
            prostokat();
            break;
        case 3:
            trojkat();
            break;
        case 4:
            kolo();
            break;
    }
}
