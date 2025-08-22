#file [[Các kỹ thuật xử lí va chạm]]

## Xử lí chuỗi riêng biệt theo kiểu chuỗi đơn giản
---
``` cpp
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
```

> **Tìm kiếm**: $O(1+(n \div m))$
> **Xóa**: $O(1+(n \div m))$
> **Chiều dài chuỗi dữ kiến**: $O(∝)$
> **Thời gian tìm kiếm dữ kiến**: $O(1\space+∝)$
> **Thời gian dữ kiến để chèn / xóa**: $O(1 \space +∝ )$

> _Trong đó:_
> 	_$n$: Tổng số phần tử trong một bảng._
> 	_$m$: Kích thước của bảng băm._
> 	_$n \div m \space (∝)$: Hệ số tải._

> **Không gian**: $O(1)$

> [!WARNING]
> **Hệ số tải (∝)** cần nhỏ nhất có thể
> Nếu **Hệ số tải** tăng, khả năng xảy ra va chạm càng cao
> **Hệ số tải** là giao dịch giữa không gian và thời gian của chương trình

## Xử lí chuỗi riêng biệt theo kiểu băm lại
---
``` cpp
// Thêm các thư viện cần thiết
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

// Tạo số ngẫu nhiên
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dist(0.0, 1.0);
double RANDOM_NUMBER = dist(gen);

// Khởi tạo hàm băm
class Hash {
    // Số thùng
    int bucketCount;

    // Số phần tử
    int elementCount;

    // Bảng băm
    std::vector<std::vector<int>> table;

public:
    // Hàm khởi tạo bảng băm
    Hash(int buckets) {
        bucketCount = buckets;
        elementCount = 0;
        table.resize(bucketCount);
    }

    // Hàm chèn giá trị vào bảng băm
    void insert(int key) {
        // Băm lại nếu hệ số tải lớn hơn 0.5
        if (this->getLoadFacter() > 0.5f) {
            this->rehash();
        }

        // Gọi hàm băm
        int index = this->getHash(key);

        // Chèn khóa vào bảng băm
        table[index].push_back(key);

        // Tăng số lượng phần tử
        elementCount++;
    }

    // Hàm xóa giá trị khỏi bảng băm
    void remove(int key) {
        // Gọi hàm băm
        int index = this->getHash(key);

        // Tìm kiếm và xóa khóa trong thùng
        auto it = std::find(table[index].begin(), table[index].end(), key);

        // Xóa khóa trong bảng băm
        if (it != table[index].end()) {
            table[index].erase(it);
            elementCount--; // Giảm số lượng phần tử trong bảng băm
        }
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
        return static_cast<int> (bucketCount * step);
    }

    // Hàm chứa kết quả tính toán hệ số tải
    float getLoadFacter() {
        return (float) elementCount / bucketCount;
    }

    // Hàm băm lại bảng băm
    void rehash() {
        std::vector<std::vector<int>> oldTable = table;
        bucketCount *= 2;
        elementCount = 0;
        table.clear();
        table.resize(bucketCount);
        for (const auto& i : oldTable) {
            for (int j : i) {
                this->insert(j);
            }
        }
    }
};
```

> **Thời gian**: $O(n)$
> **Không gian**: $O(n)$ vì phải gọi STACK liên tục

> [!TIP] Khuyến khích dùng kiểu chuỗi thay vì băm lại vì băm lại sẽ tốn không gian

