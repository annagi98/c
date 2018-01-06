//Anna Nagi
#include <stdio.h>
#include <stdarg.h>

void wypisywanie(va_list wskaznik_do_pierwszego_elementu_listy,char* lista_argumentow){
    printf("%s",lista_argumentow);
    while(lista_argumentow=va_arg(wskaznik_do_pierwszego_elementu_listy,char*)){
        while(lista_argumentow=="%d"){
            int liczba=0;
            scanf("%d",&liczba);
            lista_argumentow="";
        }
    printf("%s",lista_argumentow);
    }
}
void podawanie(char* lista_argumentow,...){
    va_list wskaznik_do_pierwszego_elementu_listy;
    va_start(wskaznik_do_pierwszego_elementu_listy,lista_argumentow);
    wypisywanie(wskaznik_do_pierwszego_elementu_listy,lista_argumentow);
    va_end(wskaznik_do_pierwszego_elementu_listy);
}
int main(void){
    podawanie("Podaj ","krotszy ", "bok ","prostokata: ","%d","teraz ","podaj "," dluzszy: ","%d",NULL);
    return 0;
}
