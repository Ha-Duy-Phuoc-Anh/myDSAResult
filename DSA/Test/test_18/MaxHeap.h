#pragma once

#define ENTER '\n'

// Một lớp cho Max-Heap
class MaxHeap {
private:
    // Một con trỏ trỏ đến các phần tử trong mảng của heap
    int* elements;

    // Kích thước lớn nhất có thể của Max Heap
    int maxSize;

    // Số lượng phần tử ở trong Max Heap ngay bây giờ
    int heapSize;

public:
    // Contructor cho lớp
    MaxHeap(int _maxSize);

    // Heapify một con con lấy chỉ số như root
    void MaxHeapify(int i);

    // Hàm trả về chỉ số của nutscha của phần tử ở chỉ số ith
    int parent(int i);

    // Hàm trả về chỉ số của nút con trái
    int lChild(int i);

    // Hàm trả về chỉ mục của nút con phải
    int rChild(int i);

    // Xóa root trong trường hợp có chứa nút lớn nhất
    int removeMax();

    // Tăng giá trị của khóa được đưa ra bởi chỉ mục của của một số giá trị mới
    void increaseKey(int i, int newVal);

    // Trả về khóa lớn nhất (khóa ở root) tronmg max heap
    int getMax();

    // Trả về kích thước của heap
    int curSize();

    // Xóa khóa ở chỉ mục i được đưa ra
    void deleteKey(int i);

    // Chèn một khóa mới 'x' vào trong Max Heap
    void insertKey(int x);
};
