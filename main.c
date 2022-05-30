#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include "Librerias/pila.h"

/// PROTOTIPADO
void ingresar(Pila* pilaMain);
void pasarPila(Pila* pilaMain, Pila* aux);
void pasarPilaMismOrden(Pila* pilaMain, Pila* aux2);
int eliminarMenorElemento(Pila* pilaMain);
void pasarPilaOrdenada(Pila* pilaMain, Pila* aux3);
void insertarOrdenado(Pila* pilaMain, Pila* aux4);
void crearPilaOrdenada(Pila* pilaMain, Pila* desordenada);
int sumarDosElementos(Pila* pilaMain);
float promedio(Pila* pilaMain);
int sumar(Pila* pilaMain);
int cantidad(Pila* pilaMain);
void cargarPila(Pila* pilaMain);
int verPila(Pila* pilaMain);
float numeroDecimal(Pila* pilaMain);
int menu();

/// MAIN
int main(){
    setlocale(LC_ALL,"");
    Pila main;
    inicpila(&main);
    Pila aux;
    inicpila(&aux);
    Pila ordenada;
    inicpila(&ordenada);
    int opt=0;
    do{
        opt=menu();
        system("cls");
        switch(opt){
        case 1:{
            printf(" 1.Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.\n\n");
            ingresar(&main);
            mostrar(&main);
            system("pause");
            system("cls");
        }
        break;
        case 2:{
            printf(" 2.Hacer una función que pase todos los elementos de una pila a otra.\n\n");
            pasarPila(&main, &aux);
            mostrar(&aux);
            system("pause");
            system("cls");
        }
        break;
        case 3:{
            printf(" 3.Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden. \n\n");
            pasarPilaMismOrden(&main, &aux);
            mostrar(&aux);
            system("pause");
            system("cls");
        }
        break;
        case 4:{
            printf(" 4.Hacer una función que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila.\n\n");
            int menorElemento=0;
            menorElemento = eliminarMenorElemento(&main);
            mostrar(&main);
            printf("EL MENOR ELEMENTO ELIMINADO ES: %i\n\n", menorElemento);
            system("pause");
            system("cls");
        }
        break;
        case 5:{
            printf(" 5.Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)\n\n");
            pasarPilaOrdenada(&main, &aux);
            mostrar(&aux);
            system("pause");
            system("cls");
        }
        break;
        case 6:{
            printf(" 6.Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta. \n\n");
            fflush(stdin);
            insertarOrdenado(&main, &aux);
            mostrar(&main);
            system("pause");
            system("cls");
        }
        break;
        case 7:{
            printf(" 7.Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)\n\n");
            crearPilaOrdenada(&main, &ordenada);
            mostrar(&ordenada);
            system("pause");
            system("cls");
        }
        break;
        case 8:{
            printf(" 8.Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido. \n\n");
            sumarDosElementos(&ordenada);
            mostrar(&ordenada);
            printf(" LA SUMA DE LOS ELEMENTOS ES DE: %i\n\n", sumarDosElementos(&ordenada));
            system("pause");
            system("cls");
        }
        break;
        case 9:{
            printf(" 9.Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.\n\n");
            mostrar(&ordenada);
            promedio(&ordenada);
            printf("LA SUMA DE LOS ELEMENTOS DE LA PILA ES DE: %i\n", sumar(&ordenada));
            printf("\nLA CANTIDAD DE ELEMENTOS DE LA PILA ES DE: %i\n", cantidad(&ordenada));
            printf("\nEL PROMEDIO DE LOS ELEMENTOS DE LA PILA ES DE: %.2f\n\n", promedio(&ordenada));
            system("pause");
            system("cls");
        }
        break;
        case 10:{
            printf(" 10.Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila: \n\n");
            ingresar(&main);
            mostrar(&main);
            numeroDecimal(&main);
            system("pause");
            system("cls");
        }
        break;
        case 11:{
            printf("  9.SALIR\n");
            system("pause");
            system("cls");
        }
        break;
        default:
            printf("\n OPCION INCORRECTA\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opt!=11);
    printf("\n FIN DEL PROGRAMA\n\n");
    system("pause");
    return 0;
}

/// FUNCIONES
///1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void ingresar(Pila* pilaMain){
    char opt;
    int valor;
    do{
        printf(" INGRESE UN ELEMENTO: ");
        scanf("%i",&valor);
        apilar(pilaMain,valor);
        printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
        fflush(stdin);
        scanf("%c", &opt);
        printf("\n");
    }while(opt=='Y'||opt=='y');
    printf(" PILA ORIGINAL\n");
}

///2. Hacer una función que pase todos los elementos de una pila a otra
void pasarPila(Pila* pilaMain, Pila* aux){
    while(!pilavacia(pilaMain)){
        apilar(aux,desapilar(pilaMain));
    }
    printf(" PILA SECUNDARIA\n");
}

///3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.
void pasarPilaMismOrden(Pila* pilaMain, Pila* aux2){
    Pila funcion3;
    inicpila(&funcion3);
    while(!pilavacia(pilaMain)){
        apilar(&funcion3, desapilar(pilaMain));
    }
    while(!pilavacia(&funcion3)){
        apilar(aux2, desapilar(&funcion3));
    }
    printf(" PILA SECUNDARIA MISMO ORDEN\n");
}

///4. Hacer una función que encuentre el menor elemento de una pila y lo retorna.
///La misma debe eliminar ese dato de la pila.
int eliminarMenorElemento(Pila* pilaMain){
    Pila aux3;
    Pila pilaMenor;

    inicpila(&aux3);
    inicpila(&pilaMenor);
    apilar(&pilaMenor, desapilar(pilaMain));

    while (!pilavacia(pilaMain)){
        if (tope(pilaMain) < tope(&pilaMenor)){
            apilar(&aux3, desapilar(&pilaMenor));
            apilar(&pilaMenor, desapilar(pilaMain));
        }
        else{
            apilar(&aux3, desapilar(pilaMain));
        }
    }
    while(!pilavacia(&aux3)){
        apilar(pilaMain, desapilar(&aux3));
    }
    return tope(&pilaMenor);
}

///5.   Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una pila ordenada.
///     Usar la funcion del ejercicio 4 (Ordenamiento por seleccion).
void pasarPilaOrdenada(Pila* pilaMain, Pila* aux3){
    while(!pilavacia(pilaMain)){
        apilar(aux3, eliminarMenorElemento(pilaMain));
    }
}

///6.Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.
void insertarOrdenado(Pila* pilaMain, Pila* elemento){
    Pila funcion6;
    inicpila(&funcion6);
    leer(elemento);
    while((!pilavacia(pilaMain))&&(tope(elemento)<tope(pilaMain))){
        apilar(&funcion6, desapilar(pilaMain));
    }
    apilar(pilaMain, desapilar(elemento));

    while(!pilavacia(&funcion6)){
        apilar(pilaMain, desapilar(&funcion6));
    }
}

///7.Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila
///  ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)
void crearPilaOrdenada(Pila* pilaMain, Pila* desordenada){
    insertarOrdenado(pilaMain, desordenada);
    pasarPilaMismOrden(pilaMain, desordenada);
}

///8.Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.
int sumarDosElementos(Pila* pilaMain){
    int suma=0;
    int count=0;
    Pila funcion8;
    inicpila(&funcion8);

    while(!pilavacia(pilaMain)&&count!=2){
        suma = suma+tope(pilaMain);
        apilar(&funcion8, desapilar(pilaMain));
        count++;
    }
    while(!pilavacia(&funcion8)){
        apilar(pilaMain, desapilar(&funcion8));
    }
    return suma;
}

/// 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una
/// función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones,
/// y la función que calcula el promedio invoca a las otras 3.
float promedio(Pila* pilaMain){
    float promedio;
    promedio = (float)sumar(pilaMain)/cantidad(pilaMain);
    return promedio;
}
int sumar(Pila* pilaMain){
    int suma=0;
    Pila auxSuma;
    inicpila(&auxSuma);
    while(!pilavacia(pilaMain)){
        suma=suma+tope(pilaMain);
        apilar(&auxSuma, desapilar(pilaMain));
    }
    while(!pilavacia(&auxSuma)){
        apilar(pilaMain, desapilar(&auxSuma));
    }
    return suma;
}
int cantidad(Pila* pilaMain){
    int elementos=0;
    Pila auxCant;
    inicpila(&auxCant);
    while(!pilavacia(pilaMain)){
        apilar(&auxCant, desapilar(pilaMain));
        elementos++;
    }
    while(!pilavacia(&auxCant)){
        apilar(pilaMain, desapilar(&auxCant));
    }
    return elementos;
}

/// 10.Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa)
/// y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:
void cargarPila(Pila* pilaMain){
    char opt;
    int valor;
    do{
        printf(" INGRESE UN ELEMENTO: ");
        scanf("%i",&valor);
        apilar(pilaMain,valor);
        printf("\n DESEA CARGAR UN NUEVO ELEMENTO? Y/N: ");
        fflush(stdin);
        scanf("%c", &opt);
        printf("\n");
    }while(opt=='Y'||opt=='y');
}
int verPila(Pila* pilaMain){
    Pila funcion11;
    inicpila(&funcion11);{
        apilar(&funcion11, desapilar(&pilaMain));
        printf("| %d |", &funcion11);
    }
}
float numeroDecimal(Pila* pilaMain){
    float acc=0;
    float base;
    float digito=1;
    float number;
    Pila funcion10;
    inicpila(&funcion10);

    while(!pilavacia(pilaMain)){
        base=tope(pilaMain);
        number=base*digito;
        acc+=number;
        digito*=10;
        desapilar(pilaMain);
    }
    printf("\n EL NUMERO FORMADO POR LOS ELEMENTOS DE LA PILA ES: %.2f\n\n", acc);
    return acc;
}

int menu(){
    int opt;
        printf("\n================================\n");
        printf(" TRABAJO PRACTICO N° 3: FUNCIONES\n");
        printf("=================================\n\n");
        printf(" 1.Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.\n\n");
        printf(" 2.Hacer una función que pase todos los elementos de una pila a otra.\n\n");
        printf(" 3.Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden. \n\n");
        printf(" 4.Hacer una función que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila.\n\n");
        printf(" 5.Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)\n\n");
        printf(" 6.Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta. \n\n");
        printf(" 7.Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)\n\n");
        printf(" 8.Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido. \n\n");
        printf(" 9.Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.\n\n");
        printf(" 10.Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila: \n\n");
        printf(" 11.SALIR\n\n");
        printf("\n ELIJA UNA OPCIÓN: ");
        fflush(stdin);
        scanf("%i", &opt);
        return opt;
}







//int main()
//{
//
//            Pila main;
//            inicpila(&main);
//            Pila aux;
//            inicpila(&aux);
//            Pila ordenada;
//            inicpila(&ordenada);
////
////            printf("FUNCION 1\n");
//    ingresar(&main);
//    mostrar(&main);
////            printf("\nFUNCION 2\n");
////    pasarPila(&main, &aux);
////    mostrar(&aux);
//printf("\nFUNCION 3\n");
////    pasarPilaMismOrden(&main, &aux);
////    mostrar(&aux);
//printf("FUNCION 4\n");
////    int menorElemento=0;
////    menorElemento = eliminarMenorElemento(&main);
////    mostrar(&main);
////    printf("EL MENOR ELEMENTO ELIMINADO ES: %i\n", menorElemento);
//printf("FUNCION 5\n");
////    pasarPilaOrdenada(&main, &aux);
////    mostrar(&aux);
//    printf("FUNCION 6\n");
//    fflush(stdin);
//    insertarOrdenado(&main, &aux);
//    mostrar(&main);
//printf("FUNCION 7\n");
//    crearPilaOrdenada(&main, &ordenada);
//    mostrar(&ordenada);
//printf("FUNCION 8\n");
//    sumarDosElementos(&main);
//    mostrar(&main);
//    printf("\nLA SUMA DE LOS ELEMENTOS ES DE: %i\n", sumarDosElementos(&main));
//printf("FUNCION 9\n");
//    promedio(&main);
//    printf("LA SUMA DE LOS ELEMENTOS DE LA PILA ES DE: %i\n", sumar(&main));
//    printf("LA CANTIDAD DE ELEMENTOS DE LA PILA ES DE: %i\n", cantidad(&main));
//    printf("EL PROMEDIO DE LOS ELEMENTOS DE LA PILA ES DE: %.2f\n", promedio(&main));
//printf("FUNCION 10\n");
//cargarPila(&main);
//mostrar(&main);
//numeroDecimal(&main);
//}
