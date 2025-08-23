#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define ENTER '\n'

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

	// Bảng băm cho lưu trữ dữ liệu
	vector<vector<int>> table;

	// Hàm băm khóa
	int _get_hash(int key) const {
		double step = fmod(key * HASH_RAND, 1);
		if (step < 0) step++;
		return (int) (bucketCount * step);
	}

public:	
	// Hàm khởi tạo đối tượng
	HashTable(size_t size) : bucketCount(size) {
		table.resize(bucketCount);
	}

	// Hàm chèn khóa vào bảng băm
	void insert(int key) {
		int index = _get_hash(key);			// Lấy chỉ số của khóa
		table[index].push_back(key);	// Đẩy dữ liệu vào chỉ số của khóa được băm
	}

	// Hàm xóa khóa khỏi bảng băm
	void remove(int key) {
		// Lấy chỉ số của khóa
		int index = _get_hash(key);

		// Dùng hàm tìm kiếm có sẵn trong <algorithm> để tìm kiếm vị trí của phần tử
		auto it = find(table[index].begin(), table[index].end(), key);

		// Nếu không tìm thấy
		if (it == table[index].end()) {
			cout << "ERROR 001: Can't find key to delete (key is not exist)"
				 << ENTER;
		}
		else {	// Nếu có thì xóa
			table[index].erase(it);
		}
	}

	// Hàm hiển thị bảng băm
	void display() const {
		for (int i = 0; i < (int)bucketCount; i++) {
			cout << '[' << i << ']';
			for (int keyIndex = 0; keyIndex < table[i].size(); keyIndex++) {
				cout << " --> " << table[i][keyIndex];
			}
			cout << ENTER;
		}
		cout << ENTER;
	}
};

int main() {    
    HashTable hashTable(7);

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