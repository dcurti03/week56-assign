#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

Vector vectorNew(int size) {
    Vector v = malloc(sizeof(struct vector));

    if(v == NULL)
        return NULL;

    v->data = malloc(size * sizeof(int));

    if(v->data == NULL) {
        free(v);
        return NULL;
    }

    v->allocated = size;
    v->used = 0;

    return v;
}

void vectorDelete(Vector vector) {
    if(vector == NULL)
        return;

    free(vector->data);
    free(vector);
}

void vectorPush(Vector *vector, int value) {
    if(vector == NULL || *vector == NULL) {
        return;
    }

    // Check whether the vector is full
    if((*vector)->used == (*vector)->allocated) {
        if(vectorResize(vector, (*vector)->allocated) == NULL) {
            return;
        }
    }

    // Add value to the next available position
    (*vector)->data[(*vector)->used] = value;

    // Increase number of elements being used
    (*vector)->used++;
}

int *vectorResize(Vector *vector, int addSize) {
    int newSize = (*vector)->allocated + addSize;

    // Allocate a larger array
    int *newData = malloc(newSize * sizeof(int));

    if(newData == NULL) {
        return NULL;
    }

    // Copy existing elements into new array
    for(int i = 0; i < (*vector)->used; i++) {
        newData[i] = (*vector)->data[i];
    }

    // Free the old array
    free((*vector)->data);

    // Make data piont to the new array
    (*vector)->data = newData;

    // Update allocated capacity
    (*vector)->allocated = newSize;

    return newData;
}

void vectorStatus(Vector vector) {
    if(vector == NULL) {
        printf("Vector is NULL/n");
        return;
    }

    printf("Vector address: %p\n", (void *)vector);
    printf("Data address:   %p\n", (void *)vector->data);
    printf("Allocated:      %d\n", vector->allocated);
    printf("Used:           %d\n", vector->used);
    printf("Contents:\n");

    for(int i = 0; i < vector->used; i++) {
        printf("[%d] address: %p value: %d\n", i, (void *)&vector->data[i], vector->data[i]);
    }
}

int vectorPop(Vector vector) {
    if(vector == NULL || vector->used == 0) {
        return 0;
    }

    vector->used--;

    return vector->data[vector->used];
}

int vectorGet(Vector vector, int index) {
    if(vector == NULL || index < 0 || index >= vector->used) {
        return 0;
    }

    return vector->data[index];
}

int vectorSet(Vector vector, int index, int value) {
    if(vector == NULL || index < 0 || index >= vector->used) {
        return 0;
    }

    vector->data[index] = value;

    return value;
}

int vectorLen(Vector vector) {
    if(vector == NULL) {
        return 0;
    }

    return vector->used;
}
