#file [[Cây nhị phân]]

``` cpp
// Khởi tạo kiểu dữ liệu của Cây nhị phân
typedef struct Node {
	// Phần dữ liệu của Cây nhị phân
	int data;
	
	// Con trỏ đến nút tiếp theo
	struct Node* left;
	struct Node* right;
} Node;

// Hàm khởi tạo nút
Node* Tree_init(int data) {
    Node* head = (Node*) malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút
    head->data = data;  // Cấp dữ liệu
    head->left = NULL;  // Cấp con trỏ đến nút trái
    head->right = NULL; // Cấp con trỏ đến nút phải
    return head;    // Trẩ về nút
}
```
---
**Bài trước**: [[Cây nhị phân]]
**Bài sau**: [[Các giá trị trong cây nhị phân]]