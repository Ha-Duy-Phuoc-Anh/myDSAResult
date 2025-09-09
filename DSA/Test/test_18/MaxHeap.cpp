#include "MaxHeap.h"

#include <iostream>
#include <utility>

// Contructor cho lớp
MaxHeap::MaxHeap(int _maxSize) {
	this->heapSize = 0;
	this->maxSize = _maxSize;
	this->elements = new int[_maxSize];
};

// Hàm trả về chỉ số của nutscha của phần tử ở chỉ số ith
int MaxHeap::parent(int i) {
	return (i - 1) / 2;
}

// Hàm trả về chỉ số của nút con trái
int MaxHeap::lChild(int i) {
	return (2 * i + 1);
}

// Hàm trả về chỉ mục của nút con phải
int MaxHeap::rChild(int i) {
	return (2 * i + 2);
}

// Trả về khóa lớn nhất (khóa ở root) tronmg max heap
int MaxHeap::getMax() {
	return this->elements[0];
}

// Trả về kích thước của heap
int MaxHeap::curSize() {
	return this->heapSize;
}

// Chèn một khóa mới 'x' vào trong Max Heap
void MaxHeap::insertKey(int x) {
	// Kiểm tra khóa có thể chèn vào hay ko
	if (this->heapSize == this->maxSize) {
		std::cout << ENTER << "Overflow: Could not insert key" << ENTER;
		return;
	}

	// Khóa mới sẽ được chèn vào cuối
	this->heapSize++;
	int i = this->heapSize - 1;
	this->elements[i] = x;

	// Điều kiện của heap được kiểm tả và nếu có sự vi phạm xảy ra, thì nó sẽ
	// được hồi lại
	while (i != 0 && this->elements[this->parent(i)] < this->elements[i]) {
		std::swap(this->elements[i], this->elements[this->parent(i)]);
		i = this->parent(i);
	}
}

// Tăng giá trị của khóa được đưa ra bởi chỉ mục của của một số giá trị mới
void MaxHeap::increaseKey(int i, int newVal) {
	this->elements[i] = newVal;
	while (i != 0 && this->elements[this->parent(i)] < this->elements[i]) {
		std::swap(this->elements[i], this->elements[this->parent(i)]);
		i = this->parent(i);
	}
}

// Xóa root trong trường hợp có chứa nút lớn nhất
int MaxHeap::removeMax() {
	// Kiểm tra mảng heap có rỗng hay ko
	if (this->heapSize <= 0)
		return INT_MIN;
	if (this->heapSize == 1) {
		this->heapSize--;
		return this->elements[0];
	}

	// Lưu trữ phần tử lớn nhất để xóa nó
	int root = this->elements[0];
	this->elements[0] = this->elements[this->heapSize - 1];
	this->heapSize--;

	// Để lưu trữ giá trị của Max Heap
	this->MaxHeapify(0);

	return root;
}

// Xóa khóa ở chỉ mục i được đưa ra
void MaxHeap::deleteKey(int i) {
	// Nó tăng giá trị của khóa lên đến vô hạn và sau đó xóa phần từ lớn nhất
	this->increaseKey(i, INT_MAX);
	this->removeMax();
}

// Heapify một con con lấy chỉ số như root
void MaxHeap::MaxHeapify(int i) {
	int l = this->lChild(i);
	int r = this->rChild(i);
	int largest = i;

	if (l < this->heapSize && this->elements[l] > this->elements[i])
		largest = l;
	if (r < this->heapSize && this->elements[r] > this->elements[largest])
		largest = r;
	if (largest != i) {
		std::swap(this->elements[i], this->elements[largest]);
		this->MaxHeapify(largest);
	}
}