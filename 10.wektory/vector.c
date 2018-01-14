// vector.c  Anna Nagi
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector){
  vector->size=0;
  vector->capacity=VECTOR_INITIAL_CAPACITY;
  vector->data=malloc(sizeof(int)*vector->capacity);
  vector->nowa=malloc(sizeof(int)*vector->capacity);
}
int vector_size(Vector *vector){
	int rozmiar=(vector->size);
    return rozmiar;
}
int vector_capacity(Vector *vector){
    int pojemnosc=(vector->capacity);
    return pojemnosc;
}
void vector_empty(vector_size){
    if(vector_size==0){
        printf("\nVector is empty.\n");
    }
}
void vector_remove(Vector *vector, int number){
    if(number>0||number<=vector->size){
        int index;
        for(index=number-1;index<vector->size;index++){
            vector->data[index]=vector->data[index+1];
        }
        vector->size=(vector->size)-1;
        printf("\nYou have removed 1 element");
    }
    else{
        printf("\nYou can't remove this element");
    }
}
void vector_reverse(Vector *vector){
   int temp;
   int i=vector->size;
   int j=i-1;
   i=0;
   while(i<j){
      temp=vector->data[i];
      vector->data[i]=vector->data[j];
      vector->data[j]=temp;
      i++;
      j--;
   }
   printf("\nYou have reversed your array.");
}
void vector_reserve(Vector *vector){
    int i;
    for(i=0;i<=vector->size;i++){
        vector->nowa[i]=vector->data[i];
    }
    printf("\nYou have reserved your array\n");
}
void vector_push_back(Vector *vector, int value){
  vector_double_capacity_if_full(vector);
  vector->data[vector->size++]=value;
}
int vector_at(Vector *vector, int index){
  if(index>=vector->size||index<0){
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}
void vector_insert(Vector *vector, int index, int value) {
  while (index>=vector->size) {
    vector_push_back(vector, 0);
  }
  vector->data[index]=value;
}
void vector_double_capacity_if_full(Vector *vector) {
  if (vector->size>=vector->capacity) {
    vector->capacity*=2;
    vector->data = realloc(vector->data, sizeof(int)*vector->capacity);
  }
}
void vector_free(Vector *vector) {
  free(vector->data);
}
