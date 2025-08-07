#file [[Bảng băm]]

> _Trong bài đọc này, ta sẽ sử dụng phương pháp băm **Polynomial**, thuật toán này khá phức tạp vì sẽ chứa một dạng toán trong **Giải tích**_
## Thuật toán
---
> [!QUOTE] Phương pháp băm **Polynomial** là phương pháp dùng duy nhất cộng và nhân
> $$hash(s)=\sum_{i=0}^{n-1} s[i] \times p^i \bmod n$$

**Trong đó:
- Chuỗi $s$ là đầu vào với $n$ là kích thước của $s$
- $p$ và $m$ là số dương
- Sự lựa chọn của $p$ và $m$ ảnh hưởng đến hiệu năng và bảo mật của thuật toán.
- Nếu $s$ chỉ có các ký tự không in hoa thì $p = 32$ là một lựa chọn tốt
- Lập trình thi đấu nên chọn số $p$ lớn và là số nguyên tố khi mà khả năng hai khóa bị va chạm là $\frac{1}{m} \times 10^9 + 7$ và $10^9 + 7$ được sử dụng nhiều cho $m$ (kích thước bảng băm).
- Đầu ra của hàm băm này là từ $0$ đến $m - 1$.

## Thực hiện hàm băm bằng C _(từ nay về sau dùng C)_
---
``` c
// Thêm các thư viện cần thiết
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "phixah.h"
#include "cnarr.h"

// Mặc định cho SLOT rỗng
string* EMPTY_SLOT = NULL;
void Global_Init() {
    EMPTY_SLOT = strinit("EMPTY_SLOT");
}


typedef struct Hash {
    int bucketCount;
    int elementCount;
    Cnarr* hashMap;
} Hash;

Hash* Hash_init(int size) {
    Hash* tmp = (Hash*) malloc(sizeof(Hash));
    tmp->bucketCount = size;
    tmp->elementCount = 0;

    tmp->hashMap = Cnarr_init(size);
    for (int i = 0; i < tmp->bucketCount; i++) {
        Cnarr_append(tmp->hashMap, EMPTY_SLOT);
    }

    return tmp;
}
int Hash_hashIndex(Hash* hashTable, string* key) {
    int N = (int) key->length;
    int P = 31;
    long long M = 1e9 + 7;
    long long HashValue = 0;
    long long PowerP = 1;

    for (int i = 0; i < N; ++i) {
        HashValue = (HashValue + (long long)(key->content[i] - 'a' + 1) * PowerP) % M;
        PowerP = (PowerP * P) % M;
    }

    return (int) HashValue % hashTable->bucketCount;
}
bool Hash_getLoadFactor(Hash* hashTable) {
    return ((double) hashTable->elementCount / hashTable->bucketCount) > 0.75;
}

Hash* Hash_rehash(Hash* hashTable);

Hash* Hash_insert(Hash* hashTable, char* key) {
    if (Hash_getLoadFactor(hashTable)) {
        Hash_rehash(hashTable);
    }

    string* strkey = strinit(key);

    int i = 0;
    int index = Hash_hashIndex(hashTable, strkey);
    while (Cnarr_get(hashTable->hashMap, index) != EMPTY_SLOT) {
        i++;
        index = (index + (i * i)) % hashTable->bucketCount;
    }

    hashTable->hashMap->data[index] = strkey;
    hashTable->elementCount++;

    return hashTable;
}
Hash* Hash_remove(Hash* hashTable, char* key) {
    string* strkey = strinit(key);

    int index = Hash_hashIndex(hashTable, strkey);
    int startIndex = index;
    int i = 0;
    while (Cnarr_get(hashTable->hashMap, index) != EMPTY_SLOT) {
        string* current =  Cnarr_get(hashTable->hashMap, index);
        if (strcmp(current->content, strkey->content) == 0) {
            strfree(current);
            hashTable->hashMap->data[index] = EMPTY_SLOT;
            hashTable->elementCount--;
            strfree(strkey);
            return hashTable;
        }
        i++;
        index = (index + (i * i)) % hashTable->bucketCount;
        if (index == startIndex) break;
    }
    printf("ERROR 001: Item not found!\n");

    strfree(strkey);
    return hashTable;
}
void Hash_display(Hash* hashTable) {
    for (int i = 0; i < hashTable->bucketCount; i++) {
        printf("[%d] --> ", i);
        string* val = Cnarr_get(hashTable->hashMap, i);
        if (val == EMPTY_SLOT) {
            printf("EMPTY");
        }
        else {
            strprint(val, false);
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
        string* key = Cnarr_get(oldTable, i);
        if (key != EMPTY_SLOT) hashTable = Hash_insert(hashTable, key->content);
    }

    for (int i = 0; i < oldBucketCount; i++) {
        string* key = Cnarr_get(oldTable, i);
        if (key != EMPTY_SLOT) {
            strfree(key);
        }
    }

    free(oldTable->data);
    free(oldTable);
    return hashTable;
}

void Hash_free(Hash* hashTable) {
    for (int i = 0; i < hashTable->bucketCount; i++) {
        string* val = Cnarr_get(hashTable->hashMap, i);
        if (val != EMPTY_SLOT) {
            strfree(val);
        }
    }
    free(hashTable->hashMap->data);
    free(hashTable->hashMap);
    free(hashTable);
}
```

> [!QUOTE] Thư viện `cnarr.h` và `phixah.h` là hai thư viện tự chế của tôi

