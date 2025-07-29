#file [[Địa chỉ mở]]

Trong thăm dò tuyến tính, bảng băm được tìm kiếm tuần tự bắt đầu từ vị trí ban đầu của bảng băm. Nếu vị trí bị chiếm dụng, ta sẽ chuyển sang ô tiếp theo cho tới khi tìm thấy ô rỗng

> [!BUG] Lười làm video quá :)

## Tạo bảng băm xử lí va chạm thăm dò tuyến tính
---
``` cpp
// Thêm các thư viện cần thiết
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

// Tạo số ngẫu nhiên
static const double RANDOM_NUMBER = []() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(gen);
}();
    

// Mặc định cho SLOT rỗng
const int EMPTY_SLOT = EMPTY_SLOT;

// Khởi tạo hàm băm
class Hash {
    // Số thùng
    int bucketCount;

    // Bảng băm
    std::vector<int> table;

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
```