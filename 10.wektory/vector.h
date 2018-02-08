// vector.h  Anna Nagi
#ifndef VECTOR_H
#define VECTOR_H
    #define VECTOR_INITIAL_CAPACITY 100

    typedef struct {
      int size;
      int capacity;
      int *data;
      int *nowa;
    } Vector;

    void vector_init(Vector *vector);

    int vector_size(Vector *vector);
    int vector_capacity(Vector *vector);

    void vector_empty(vector_size);

    void vector_remove(Vector *vector, int number);
    void vector_reverse(Vector *vector);
    void vector_reserve(Vector *vector);

    void vector_push_back(Vector *vector, int value);
    int vector_at(Vector *vector, int index);

    void vector_insert(Vector *vector, int index, int value);

    void vector_double_capacity_if_full(Vector *vector);
    void vector_free(Vector *vector);

#endif
