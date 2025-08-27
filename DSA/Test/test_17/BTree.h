#pragma once

#include <iostream>

using namespace std;

// Khởi tạo nút của cây B
class BNode {
private:
	int n;			  // Số lượng khóa trong nút hiện tại
	int t;			  // Mức độ tối thiểu (xác định số lượng khóa)
	int* keys;		  // Mảng lưu trữ khóa trong nút
	BNode** children; // Mảng lưu trữ con trỏ đến các nút trong trong cây
	bool isLeaf;	  // Boolean cho biết nút đó có phải nút lá ko

public:
	BNode(bool _isLeaf, int _t); // Hàm khởi tạo đối tượng Nút

	// Một hàm chèn khóa mới vào cây con có gốc là nút này, giả định là nút chưa
	// đầy khi hàm này được gọi
	void insertNoneFull(int key);

	// Một hàm tách nút y của nút này ra hai phần, i là chỉ số của y trong mảng
	// nút con. Nút con y bắt buộc phải đầy trước khi gọi hàm này
	void splitChild(int i, BNode* y);

	// Một hàm để hiển thị toàn bộ nhánh cây (hoặc cây đó)
	void display() const;

	// Hàm tìm kiếm nút trong cây, hoặc nhánh cây
	BNode* search(int target) const;

	// Làm cho cây B friend để ta có thể truy cập private element
	friend class BTree;
};

// Khởi tạo cây B
class BTree {
private:
	BNode* root; // Khởi tạo nút root của cây B
	int t;		 // Mức độ tối thiểu

public:
	// Hàm khởi tạo cây
	BTree(int _t) : root(nullptr), t(_t) {}

	// Hàm hiển thị cây
	void display() const {
		if (root != nullptr)
			root->display();
	}

	// Hàm tìm kiếm nút trong cây
	BNode* search(int key) const { return (root == nullptr) ? nullptr : root->search(key); }

	// Hàm chèn nút vào trong cây
	void insert(int key);
};