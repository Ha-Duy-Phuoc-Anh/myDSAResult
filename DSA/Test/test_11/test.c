// Thêm các thư viện cần thiết
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include "cnarr.h"

// Mặc định cho SLOT rỗng
int EMPTY_SLOT = INT_MAX;

typedef struct Hash {
    int bucketCount;
    int elementCount;
    double hashRand;
    Cnarr* hashMap;
} Hash;

Hash* Hash_init(int size) {
    Hash* tmp = (Hash*) malloc(sizeof(Hash));
    tmp->bucketCount = size;
    tmp->elementCount = 0;

    srand(time(NULL));
    tmp->hashRand = (double)rand() / RAND_MAX;

    tmp->hashMap = Cnarr_init(4);
    for (int i = 0; i < tmp->bucketCount; i++) {
        Cnarr_append(tmp->hashMap, EMPTY_SLOT);
    }

    return tmp;
}
int Hash_hashIndex(Hash* hashTable, int key) {
    double step = fmod(key * hashTable->hashRand, 1);
    if (step < 0) step++;
    return (int) (hashTable->bucketCount * step);
}
bool Hash_getLoadFactor(Hash* hashTable) {
    return ((double) hashTable->elementCount / hashTable->bucketCount) > 0.75;
}

Hash* Hash_rehash(Hash* hashTable);

Hash* Hash_insert(Hash* hashTable, int key) {
    if (Hash_getLoadFactor(hashTable)) {
        Hash_rehash(hashTable);
    }

    int i = 0;
    int index = Hash_hashIndex(hashTable, key);
    while (Cnarr_get(hashTable->hashMap, index) != EMPTY_SLOT) {
        i++;
        index = (index + (i * i)) % hashTable->bucketCount;
    }

    hashTable->hashMap->data[index] = key;
    hashTable->elementCount++;
    return hashTable;
}
Hash* Hash_remove(Hash* hashTable, int key) {
    int index = Hash_hashIndex(hashTable, key);
    int startIndex = index;
    int i = 0;
    while (Cnarr_get(hashTable->hashMap, index) != EMPTY_SLOT) {
        if (Cnarr_get(hashTable->hashMap, index) == key) {
            hashTable->hashMap->data[index] = EMPTY_SLOT;
            hashTable->elementCount--;
            return hashTable;
        }
        i++;
        index = (index + (i * i)) % hashTable->bucketCount;
        if (index == startIndex) break;
    }
    printf("ERROR 001: Item not found!\n");
    return hashTable;
}
void Hash_display(Hash* hashTable) {
    for (int i = 0; i < hashTable->bucketCount; i++) {
        printf("[%d] --> ", i);
        if (Cnarr_get(hashTable->hashMap, i) == INT_MAX) {
            printf("EMPTY");
        }
        else {
            printf("%i", Cnarr_get(hashTable->hashMap, i));
        }
        printf("\n");
    }
}

Hash* Hash_rehash(Hash* hashTable) {
    Cnarr* oldTable = hashTable->hashMap;
    int oldBucketCount = hashTable->bucketCount;

    hashTable->bucketCount *= 2;
    hashTable->elementCount = 0;

    Cnarr* newTable = Cnarr_init(hashTable->bucketCount);
    for (int i = 0; i < hashTable->bucketCount; i++) {
        Cnarr_append(newTable, EMPTY_SLOT);
    }
    hashTable->hashMap = newTable;

    for (int i = 0; i < oldBucketCount; i++) {
        int key = Cnarr_get(oldTable, i);
        if (key != EMPTY_SLOT) hashTable = Hash_insert(hashTable, key);
    }

    Cnarr_free(oldTable);
    return hashTable;
}

void Hash_free(Hash* hashTable) {
    Cnarr_free(hashTable->hashMap);
    free(hashTable);
}

int main() {
    Hash* hashTable = Hash_init(6);

    hashTable = Hash_insert(hashTable, 14);
    hashTable = Hash_insert(hashTable, 23);
    hashTable = Hash_insert(hashTable, 39);
    hashTable = Hash_insert(hashTable, 47);
    hashTable = Hash_insert(hashTable, 34);
    hashTable = Hash_insert(hashTable, 15);
    hashTable = Hash_insert(hashTable, 35);

    printf("BEFORE DELETE:\n");
    Hash_display(hashTable);

    hashTable = Hash_remove(hashTable, 14);
    hashTable = Hash_remove(hashTable, 34);
    hashTable = Hash_remove(hashTable, 47);
    hashTable = Hash_insert(hashTable, 58);

    printf("\nAFTER DELETE:\n");
    Hash_display(hashTable);

    Hash_free(hashTable);

    return 0;
}