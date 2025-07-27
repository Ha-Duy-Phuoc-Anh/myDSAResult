// Thêm các thư viện cần thiết
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

// Tạo số ngẫu nhiên
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dist(1.0, 0.0);
double RANDOM_NUMBER = dist(gen);

// Khởi tạo hàm băm
class Hash {
    // Số thùng
    int bucketCount;
    std::vector<std::vector<int>> table;

public:
    // Hàm khởi tạo bảng băm
    Hash(int buckets) {
        bucketCount = buckets;
        table.resize(bucketCount);
    }

    // Hàm chèn giá trị vào bảng băm
    void insert(int key) {
        // Gọi hàm băm
        int index = this->getHash(key);

        // Chèn khóa vào bảng băm
        table[index].push_back(key);
    }

    // Hàm xóa giá trị khỏi bảng băm
    void remove(int key) {
        // Gọi hàm băm
        int index = this->getHash(key);

        // Tìm kiếm và xóa khóa trong thùng
        auto it = std::find(table[index].begin(), table[index].end(), key);

        // Xóa khóa trong bảng băm
        if (it != table[index].end()) table[index].erase(it);
    }

    // Hàm hiển thị bảng băm
    void display() {
        for (int i = 0; i < bucketCount; i++) {
            std::cout << i;
            for (int key : table[i]) {
                std::cout << " --> " << key;
            }
            std::cout << std::endl;
        }
    }

private:
    // Hàm chứa thuật toán băm nhân
    int getHash(int key) {
        double step = fmod(key * RANDOM_NUMBER, 1);
        if (step < 0) {
            step += 1;
        }

        return static_cast<int> (bucketCount * step);
    }
};

int main() {
    Hash hashTable(6);

    hashTable.insert(14);
    hashTable.insert(23);
    hashTable.insert(39);
    hashTable.insert(47);
    hashTable.insert(55);
    hashTable.insert(34);

    std::cout << "BEFORE DELETE: " << std::endl;
    hashTable.display();

    hashTable.remove(14);
    hashTable.remove(34);
    hashTable.remove(55);
    hashTable.insert(58);

    std::cout << std::endl << "AFTER DELETE: " << std::endl;
    hashTable.display();

    return 0;
}