#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// -------------------------- DEFINE DATA TYPE -------------------------- //
// Cnarr
typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Cnarr;
// -------------------------- DEFINE DATA TYPE -------------------------- //

// -------------------------- CREATE ARRAY DEFINITION -------------------------- //
Cnarr* Cnarr_init(size_t initialSize, size_t elementSize) {
    Cnarr* arr = (Cnarr*) malloc(sizeof(Cnarr));
    if (!arr) {
        fprintf(stderr, "ERROR 001: Faild to allocate memory for array");
        exit(EXIT_FAILURE);
    }

    arr->data = malloc(initialSize * elementSize);
    if (!arr->data) {
        fprintf(stderr, "ERROR 002: Faild to allocate memory for array's data");
        free(arr);
        exit(EXIT_FAILURE);
    }

    arr->size = 0;
    arr->capacity = initialSize;
    arr->element_size = elementSize;

    return arr;
};
// -------------------------- CREATE ARRAY DEFINITION -------------------------- //

// -------------------------- APPEND ELEMENT INTO ARRAY FUNCTION -------------------------- //
void Cnarr_append(Cnarr *arr, const void* element) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;    // Auto resize array

        void* new_data = realloc(arr->data, arr->capacity * arr->element_size);
        if (!new_data) {
            fprintf(stderr, "ERROR 003: Failed to resize array");
            exit(EXIT_FAILURE);
        }

        arr->data = new_data;
    }
    memcpy((char*)arr->data + arr->size * arr->element_size, element, arr->element_size);
    arr->size++;
}
// -------------------------- APPEND ELEMENT INTO ARRAY FUNCTION -------------------------- //

// -------------------------- REMOVE ELEMENT FROM ARRAY FUNCTION -------------------------- //
void Cnarr_pop(Cnarr *arr) {
    if (arr->size == 0) {
        fprintf(stderr, "ERROR 004: Array is empty");
        exit(EXIT_FAILURE);
    }
    arr->size--;

    if (arr->size > 0 && arr->size <= arr->capacity / 4 && arr->capacity > 4) {
        arr->capacity /= 2;
        void* newData = realloc(arr->data, arr->capacity * arr->element_size);
        if (!newData) {
            fprintf(stderr, "ERROR 005: Faild to remove array element");
            exit(EXIT_FAILURE);
        }
        arr->data = newData;
    }
}
// -------------------------- REMOVE ELEMENT FROM ARRAY FUNCTION -------------------------- //

// -------------------------- GET ARRAY ELEMENT FUNCTION -------------------------- //
void* Cnarr_get(Cnarr *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "ERROR 006: Index out of range");
        exit(EXIT_FAILURE);
    }
    return (char*)arr->data + index * arr->element_size;
}
// -------------------------- GET ARRAY ELEMENT FUNCTION -------------------------- //

// -------------------------- SLICE ARRAY FUNCTION -------------------------- //
// Cnarr* Cnarr_slice(Cnarr *arr, size_t start, size_t stop) {
//     if (start > stop || stop > arr->size) {
//         fprintf(stderr, "ERROR 007: Invalid slice indices");
//         exit(EXIT_FAILURE);
//     }

//     size_t sizeOfNewArr = stop - start;
//     Cnarr* newArr = Cnarr_init(sizeOfNewArr);

//     for (size_t i = start; i <  stop; i++) {
//         Cnarr_append(newArr, Cnarr_get(arr, i));
//     }

//     return newArr;
// }
// -------------------------- SLICE ARRAY FUNCTION -------------------------- //

// -------------------------- PRINT ARRAY FUNCTION -------------------------- //
void Cnarr_print(Cnarr *arr) {
    printf("[");
    for (int i = 0; i < (int)arr->size; i++) {
        printf("%p", Cnarr_get(arr, i));
        if (i < (int)arr->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
// -------------------------- PRINT ARRAY FUNCTION -------------------------- //

// -------------------------- SWAP ARRAY ELEMENT FUNCTION -------------------------- //
// void Cnarr_swap(Cnarr *arr, int index1, int index2) {
//     if (index1 >= arr->size || index2 >= arr->size) {
//         fprintf(stderr, "ERROR 008: Swap indices out of range");
//         exit(EXIT_FAILURE);
//     }

//     if (index1 != index2) {
//         int temp = arr->data[index1];
//         arr->data[index1] = arr->data[index2];
//         arr->data[index2] = temp;
//     }
// }
// -------------------------- SWAP ARRAY ELEMENT FUNCTION -------------------------- //

// -------------------------- GET CURRENT ARRAY SIZE -------------------------- //
int Cnarr_getSize(Cnarr *arr) {
    return (int) arr->size;
}
// -------------------------- GET CURRENT ARRAY SIZE -------------------------- //

// -------------------------- GET CURRENT ARRAY MAX SIZE -------------------------- //
int Cnarr_getFullSize(Cnarr *arr) {
    return (int) arr->capacity;
}
// -------------------------- GET CURRENT ARRAY MAX SIZE -------------------------- //

// -------------------------- FREE ALL RAM DATA -------------------------- //
void Cnarr_free(Cnarr *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
    free(arr);
}
// -------------------------- FREE ALL RAM DATA -------------------------- //
