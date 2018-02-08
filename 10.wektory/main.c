//main.c Anna Nagi
#include <stdio.h>
#include <stdbool.h>
#include "vector.h"

int main(void) {
  Vector vector;
  vector_init(&vector);

  for(int i=0; i<50; i++) {
    vector_push_back(&vector, i);
  }

  printf("\nThe value at 27: %d", vector_at(&vector, 27));
  printf("\nThe value at 26: %d", vector_at(&vector, 26));
  printf("\n\nSize of vector: %d", vector_size(&vector));
  printf("\nCapacity of vector: %d", vector_capacity(&vector));

  vector_empty(vector_size(&vector));
  vector_remove(&vector, 2);

  printf("\n\nThe value at 27: %d", vector_at(&vector, 27));
  printf("\nThe value at 26: %d\n", vector_at(&vector, 26));
  printf("\nSize of vector: %d",vector_size(&vector));
  printf("\nCapacity of vector: %d",vector_capacity(&vector));
  printf("\n\nThe value at 1: %d",vector_at(&vector, 1));

  vector_reverse(&vector);
  printf("\n\nThe value at 1: %d",vector_at(&vector, 1));
  vector_reserve(&vector);

  vector_free(&vector);
}
