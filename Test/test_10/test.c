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

Hash* init(int size) {
    Hash* tmp = (Hash*) malloc(sizeof(Hash));
    tmp->bucketCount = size;
    tmp->elementCount = 0;

    srand(time(NULL));
    tmp->hashRand = (double)rand() / RAND_MAX;

    tmp->hashMap = Cnarr_init(4);
    for (int i = 0; i < Cnarr_getFullSize(tmp->hashMap); i++) {
        
    }
}


/*
public:
    // Hàm khởi tạo bảng băm
    Hash(int buckets) {
        bucketCount = buckets;
        table.resize(bucketCount);
        for (int i = 0; i < table.size(); i++) {
            table[i] = EMPTY_SLOT;
        }
    }

    // Hàm chèn giá trị vào bảng băm
    void insert(int key) {
        // Gọi hàm băm
        int original_index = this->getHash(key);
        int index = original_index;

        // Lặp để tìm vị trí còn sót lại
        for (int i = 0; i < bucketCount; ++i) {
            if (table[index] == EMPTY_SLOT) {
                table[index] = key;
                return;
            }
            if (table[index] == key) {
                return;
            }
            index = (index + 1) % bucketCount;
        }

        // Nếu không còn vị trí nào, băm lại bảng băm
        this->rehash();
        this->insert(key);
    }

    // Hàm xóa khóa khỏi băng băm
    void remove(int key) {
        // Gọi hàm băm
        int original_index = this->getHash(key);
        int index = original_index;

        // Lặp để tìm vị trí còn sót lại
        for (int i = 0; i < bucketCount; ++i) {
            if (table[index] == key) {
                table[index] = EMPTY_SLOT;
                return;
            }
            index = (index + 1) % bucketCount;
        }

        // Nếu không tìm thấy khóa cần xóa
        std::cout << "ERROR 001: Key is not found" << std::endl;
    }

    // Hàm hiển thị bảng băm
    void display() {
        for (int i = 0; i < bucketCount; i++) {
            std::cout << i;
            if (table[i] != EMPTY_SLOT) {
                std::cout << " --> " << table[i];
            }
            else {
                std::cout << " --> " << "EMPTY";
            }
            std::cout << std::endl;
        }
    }

private:
    // Hàm chứa thuật toán băm nhân
    int getHash(int key) {
        double step = fmod(key * RANDOM_NUMBER, 1);
        return static_cast<int> (bucketCount * step);
    }

    // Hàm băm lại bảng băm
    void rehash() {
        std::vector<int> oldTable = table;
        bucketCount *= 2;
        table.clear();
        table.resize(bucketCount);
        table.assign(bucketCount, EMPTY_SLOT);
        for (const auto& i : oldTable) {
            if (i != EMPTY_SLOT) {
                this->insert(i);
            }
        }
    }
};
*/

int main() {
    /*
    Hash hashTable(6);

    hashTable.insert(14);
    hashTable.insert(23);
    hashTable.insert(39);
    hashTable.insert(47);
    hashTable.insert(34);
    hashTable.insert(15);
    hashTable.insert(35);

    std::cout << "BEFORE DELETE: " << std::endl;
    hashTable.display();

    hashTable.remove(14);
    hashTable.remove(34);
    hashTable.remove(47);
    hashTable.insert(58);

    std::cout << std::endl << "AFTER DELETE: " << std::endl;
    hashTable.display();

    return 0;
    */
}