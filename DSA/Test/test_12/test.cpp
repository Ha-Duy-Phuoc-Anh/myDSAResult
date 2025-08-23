#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define ENTER '\n'
#define EMPTY_SLOT INT_MAX
#define DELETED_SLOT (INT_MAX - 1)

double HASH_RAND = [](){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dist(0, 1);
	return (double)dist(gen);
}();

class HashTable {
private:
	// Số thùng trong trong bảng băm
	size_t bucketCount;

	// Số phần tử trong bảng băm
	int elementCount;

	// Bảng băm cho lưu trữ dữ liệu
	vector<int> table;

	// Hàm băm khóa
	int _get_hash(int key) const {
		double step = fmod(key * HASH_RAND, 1);
		if (step < 0) step++;
		return (int) (bucketCount * step);
	}

	// Jump step của bảng bảm để xử lí va chạm
	int _get_jumpStep(int key) {
		return 1 + (key % ((int)bucketCount - 1));
	}

	// Hàm lấy hệ số tải của bảng băm
	float _get_loadFacter() const {
		return (float)elementCount / ((int)bucketCount);
	}

	// Hàm băm lại bảng băm
	void rehash() {
		// Tạo biến lưu trữ các giá trị cũ
		vector<int> oldTable = table;
		size_t oldBucketCount = bucketCount;

		// Tăng gấp đôi số thùng (mảng) và reset giá trị
		bucketCount *= 2;
		elementCount = 0;
		table.clear();
		table.resize(bucketCount);
		fill(table.begin(), table.end(), EMPTY_SLOT);

		// Gán các phần tử cũ vào trong bảng băm
		for (int i = 0; i < (int)oldBucketCount; i++) {
			if (oldTable[i] != EMPTY_SLOT) {
				this->insert(oldTable[i]);
			}
		}
	}

public:	
	// Hàm khởi tạo đối tượng
	HashTable(size_t size) : bucketCount(size), elementCount(0) {
		table.resize(bucketCount);
		fill(table.begin(), table.end(), EMPTY_SLOT);
	}

	// Hàm chèn khóa vào bảng băm
	void insert(int key) {
		// Nếu Hệ số tải lớn hơn 0.5 thì băm lại
		if (this->_get_loadFacter() > 0.5f) {
			this->rehash();
		}

		int index = this->_get_hash(key);	// Lấy chỉ số của khóa
		int i = 0;
		while (table[index] != EMPTY_SLOT && table[index] != DELETED_SLOT) {
			i++;
			index = (index + (i * this->_get_jumpStep(key))) % (int)bucketCount;
		}
		table[index] = key;					// Đẩy dữ liệu vào chỉ số của khóa được băm
		elementCount++;					    // Cập nhật số lượng phần tử trong bảng băm
	}

	// Hàm xóa khóa khỏi bảng băm
	void remove(int key) {
		// Lấy chỉ số của khóa
		int index = _get_hash(key);
		int startIndex = index;

		// Dùng vòng lặp đề tìm slot còn trống
		int i = 0;
		while (table[index] != EMPTY_SLOT) {
			// Nếu tìm thấy thì xóa nút đó (thay nó với DELETED_SLOT)
			if (table[index] == key) {
				table[index] = DELETED_SLOT;
				elementCount--;
				return;	// Ngắt
			}

			// Nếu ko thì tăng chỉ số lên cho tới khi thử hết mọi input (giống brute-force quá)
			i++;
			index = (index + (i * this->_get_jumpStep(key))) % (int)bucketCount;
			if (index == startIndex) break;
		}

		// Nếu code có thể chạy tới đây thì có nghĩa là ko có key bên trong bảng băm
		cout << "ERROR 001: Key is not found" << ENTER;
	}

	// Hàm hiển thị bảng băm
	void display() const {
		for (int i = 0; i < (int)bucketCount; i++) {
			cout << '[' << i << ']';
			if (table[i] != EMPTY_SLOT && table[i] != DELETED_SLOT) {
				cout << " --> " << table[i];
			}
			cout << ENTER;
		}
		cout << ENTER;
	}
};

int main() {    
    HashTable hashTable(4);

    hashTable.insert(14);
    hashTable.insert(23);
    hashTable.insert(39);
    hashTable.insert(47);
    hashTable.insert(55);
    hashTable.insert(34);

    cout << "BEFORE DELETE: " << ENTER;
    hashTable.display();

    hashTable.remove(14);
    hashTable.remove(34);
    hashTable.remove(55);
    hashTable.insert(58);

    cout << "AFTER DELETE: " << ENTER;
    hashTable.display();

    return 0;
}