// Thêm các thư viện cần thiết
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "cnarr.h"

typedef struct Hash {
    int bucketCount;
    double hashRand;
    Cnarr* table;
} Hash;

Hash* Hash_init(int size) {
    Hash* tmp = (Hash*) malloc(sizeof(Hash));
    tmp->bucketCount = size;

    srand(time(NULL));
    tmp->hashRand = (double)rand() / RAND_MAX;

    tmp->table = Cnarr_init(size, sizeof(Cnarr*));
    for (int i = 0; i < tmp->bucketCount; i++) {
        Cnarr* tmp_arr = Cnarr_init(5, sizeof(int));
        Cnarr_append(tmp->table, &tmp_arr);
    }
    return tmp;
}

int getHashIndex(Hash* hashBoard, int key) {
    double step = fmod(key * hashBoard->hashRand, 1);
    if (step < 0) step++;
    return (int) (hashBoard->bucketCount * step);
}

Hash* Hash_insert(Hash* hashBoard, int key) {
    int index = getHashIndex(hashBoard, key);
    Cnarr_append(*(Cnarr**)Cnarr_get(hashBoard->table, index), &key);
    return hashBoard;
}

Hash* Hash_remove(Hash* hashBoard, int key) {
    int index = getHashIndex(hashBoard, key);
    Cnarr* bucket = *(Cnarr**)Cnarr_get(hashBoard->table, index);
    Cnarr* newBucket = Cnarr_init(5, sizeof(int));
    bool found = false;
    for (size_t i = 0; i < bucket->size; i++) {
        int* current_key = (int*) Cnarr_get(bucket, i);
        if (*current_key == key && !found) {
            found = true;
        }
        else {
            Cnarr_append(newBucket, current_key);
        }
    }
    if (found) {
        Cnarr_free(bucket);
        *(Cnarr**)Cnarr_get(hashBoard->table, index) = newBucket;
    }
    else {
        Cnarr_free(newBucket);
        printf("ERROR 001: Key is not found\n");
    }
    return hashBoard;
}

void Hash_display(Hash* hashBoard) {
    for (int i = 0; i < hashBoard->bucketCount; i++) {
        Cnarr* bucket = *(Cnarr**) Cnarr_get(hashBoard->table, i);
        printf("[%d]", i);
        for (int keyIndex = 0; keyIndex < Cnarr_getSize(bucket); keyIndex++) {
            int element = *(int*) Cnarr_get(bucket, keyIndex);
            printf(" --> %d", element);
        }
        printf("\n");
    }
}

void Hash_free(Hash* hashBoard) {
    for (int i = 0; i < hashBoard->bucketCount; i++) {
        Cnarr* bucket = *(Cnarr**) Cnarr_get(hashBoard->table, i);
        Cnarr_free(bucket);
    }
    Cnarr_free(hashBoard->table);
    free(hashBoard);
}

int main() {    
    Hash* hashTable = Hash_init(6);

    hashTable = Hash_insert(hashTable, 14);
    hashTable = Hash_insert(hashTable, 23);
    hashTable = Hash_insert(hashTable, 39);
    hashTable = Hash_insert(hashTable, 47);
    hashTable = Hash_insert(hashTable, 55);
    hashTable = Hash_insert(hashTable, 34);

    printf("BEFORE DELETE:\n");
    Hash_display(hashTable);

    hashTable = Hash_remove(hashTable, 14);
    hashTable = Hash_remove(hashTable, 34);
    hashTable = Hash_remove(hashTable, 55);
    hashTable = Hash_insert(hashTable, 58);

    printf("\nAFTER DELETE:\n");
    Hash_display(hashTable);

    Hash_free(hashTable);

    return 0;
}