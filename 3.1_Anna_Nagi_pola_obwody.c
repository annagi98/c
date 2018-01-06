//Anna Nagi
#include <stdio.h>
#include <math.h>

int operacjaa(void){
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

double wprowadzanie_dlugosci(void){
    double bok;
    scanf("%lf",&bok);
    while(bok<=0){
        printf("Wartosc dlugosci musi byc dodatnia. Sprobuj ponownie:  \n");
        scanf("%lf",&bok);
    }
    return bok;
}

void pole_kwadratu(double bok_kwadratu){
    double pole1=(bok_kwadratu*bok_kwadratu);
    printf("Pole kwadratu = %lf", pole1);
}
void obwod_kwadratu(double bok_kwadratu){
    double obwod1=4*bok_kwadratu;
    printf("Obwod kwadratu = %lf", obwod1);
}

void pole_prostokata(double bok_prostokata1, double bok_prostokata2){
    double pole2=(bok_prostokata1*bok_prostokata2);
    printf("Pole prostokata = %lf", pole2);
}
void obwod_prostokata(double bok_prostokata1,double bok_prostokata2){
    double obwod2=2*(bok_prostokata1+bok_prostokata2);
    printf("Obwod prostokata = %lf", obwod2);
}

void pole_trojkata(double bok_trojkata1,double wysokosc_trojkata){
    double pole3=(bok_trojkata1*wysokosc_trojkata/2);
    printf("Pole trojkata = %lf",pole3);
}
void obwod_trojkata(double bok_trojkata1, double bok_trojkata2, double bok_trojkata3){
    double obwod3=(bok_trojkata1+bok_trojkata2+bok_trojkata3);
    printf("Obwod trojkata = %lf", obwod3);
}

void pole_kola(double promien){
    double pole4=(M_PI*(promien*promien));
    printf("Pole kola = %lf",pole4);
}
void obwod_kola(double promien){
    double obwod4=(2*M_PI*promien);
    printf("Obwod kola = %lf", obwod4);
}

int main(void){
    int figura;
    printf("Program oblicza pola lub obwody wybranych figur. \n \n");
    printf("Jaka figure bierzemy pod uwage? 1-kwadrat, 2-prostokat, 3-trojkat, 4-kolo \n");
    scanf("%d",&figura);
    switch(figura){
        case 1:
            printf("Wybrana figura to kwadrat.\n");
            int operacja1=operacjaa();
            printf("Podaj dlugosc boku kwadratu: \n");
            double bok_kwadratu=wprowadzanie_dlugosci();
            if(operacja1==1){
                pole_kwadratu(bok_kwadratu);
            }
            if(operacja1==2){
                obwod_kwadratu(bok_kwadratu);
            }
            break;

        case 2:
            printf("Wybrana figura to prostokat.\n");
            int operacja2=operacjaa();
            printf("Podaj dlugosc pierwszego boku prostokata: \n");
            double bok_prostokata1=wprowadzanie_dlugosci();
            printf("Podaj dlugosc drugiego boku prostokata: \n");
            double bok_prostokata2=wprowadzanie_dlugosci();
            if(operacja2==1){
                pole_prostokata(bok_prostokata1,bok_prostokata2);
            }
            if(operacja2==2){
                obwod_prostokata(bok_prostokata1,bok_prostokata2);
            }
            break;

        case 3:
            printf("Wybrana figura to trojkat.\n");
            int operacja3=operacjaa();
            printf("Podaj dlugosc pierwszego boku trojkata: \n");
            double bok_trojkata1=wprowadzanie_dlugosci();
            if(operacja3==1){
                printf("Podaj dlugosc wysokosci trojkata: \n");
                double wysokosc_trojkata=wprowadzanie_dlugosci();
                pole_trojkata(bok_trojkata1,wysokosc_trojkata);
            }
            if(operacja3==2){
                printf("Podaj dlugosc drugiego boku trojkata: \n");
                double bok_trojkata2=wprowadzanie_dlugosci();
                printf("Podaj dlugosc trzeciego boku trojkata: \n");
                double bok_trojkata3=wprowadzanie_dlugosci();
                while((bok_trojkata1+bok_trojkata2<=bok_trojkata3)||(bok_trojkata1+bok_trojkata3<=bok_trojkata2)||(bok_trojkata2+bok_trojkata3<=bok_trojkata1)){
                    printf("Taki trojkat nie istnieje, wprowadz ponownie dlugosci bokow\n");
                    bok_trojkata1=wprowadzanie_dlugosci();
                    bok_trojkata2=wprowadzanie_dlugosci();
                    bok_trojkata3=wprowadzanie_dlugosci();
                }
                obwod_trojkata(bok_trojkata1,bok_trojkata2,bok_trojkata3);
            }
            break;

        case 4:
            printf("Wybrana figura to kolo.\n");
            int operacja4=operacjaa();
            printf("Podaj dlugosc promienia kola: \n");
            double promien=wprowadzanie_dlugosci();
            if(operacja4==1){
                pole_kola(promien);
            }
            if(operacja4==2){
                obwod_kola(promien);
            }
            break;
    }
}
