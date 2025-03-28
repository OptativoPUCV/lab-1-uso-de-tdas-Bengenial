#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para ca
da elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for (int i = 10; i >= 1; i--){
      int* num = (int*) malloc(sizeof(int));
      *num = i;
      pushFront(L, num);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int* num = first(L);
   int suma = 0;
   while(num != NULL){
      suma += *num;
      num = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* num = first(L);
   while(num != NULL){
      if (*num == elem){
         popCurrent(L);
      }
      num = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* S = create_stack();
   void* elem = top(P1);
   while(elem != NULL){
      push(S, elem);
      pop(P1);
      elem = top(P1);
   }
   void* elem2 = top(S);
   while(elem2 != NULL){
      push(P1, elem2);
      push(P2, elem2);
      pop(S);
      elem2 = top(S);
   }

}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* S1 = create_stack();
   Stack* S2 = create_stack();

   if (strlen(cadena) % 2 != 0) return 0;

   for (int i = 0, j = strlen(cadena) - 1; i < j; i++ ,j--){
      push(S1,&cadena[i]);
      push(S2,&cadena[j]);

   }

   char* elem1 = top(S1);
   char* elem2 = top(S2);
   while(elem1 != NULL){
      if ((*elem1 == '(' && *elem2 != ')') ||
          (*elem1 == '{' && *elem2 != '}') ||
          (*elem1 == '[' && *elem2 != ']'))
            return 0;

      pop(S1);
      pop(S2);
      elem1 = top(S1);
      elem2 = top(S2);
   }
   return 1; 
}
