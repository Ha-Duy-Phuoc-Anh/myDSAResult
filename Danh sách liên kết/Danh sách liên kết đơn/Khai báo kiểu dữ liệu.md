### C++
---
``` cpp
// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
struct Node {
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	Node* next;

	// Hàm khởi tạo Nút
	Node(int value) : data(value), next(nullptr) {};
}
```
### C
---
``` c
// Thư viện cần thiết cho việc sử dụng kiểu dữ liệu NULL
#include <stddef.h>

// Thư viện cần thiết cho việc sử dụng malloc() để cấp phát bộ nhớ
#include <stdlib.h>

// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
struct Node {
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	struct Node* next;
};

// Hàm khởi tạo nút mới trong danh sách liên kết đơn
struct Node* newNode(int data) {
	// Cấp phát bộ nhớ cho nút
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;    // Cấp dữ liệu cho nút
	temp->next = NULL;    // Gán con trỏ tới nút tiếp theo là NULL
	return temp;          // Trả về con trỏ cho nút chính
}
```
### Java
---
``` java
// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node {
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;

	// Con trỏ đến nút tiếp theo
	Node next;

	// Hàm khởi tạo nút
	public Node(int data) {
		this.data = data;
		this.next = null;
	}
}
```
### Python
---
``` python
# Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node:
	# Hàm khởi tạo nút mới trong Danh sách liên kết
	def __init__(self, data):
		self.data: int = data   # Gán dữ liệu vào nút
		self.next: Node = None  # Gán con trỏ tới nút tiếp theo là NULL
```
### Javascript
---
``` javascript
// Hàm khởi tạo danh sách liên kết đơn
class Node {
	// Hàm khởi tạo nút mới trong Danh sách liên kết
	constructor(data) {
		this.data = data;   // Gán dữ liệu cho nút
		this.next = null;   // Gán con trỏ đến nút tiếp theo là null
	}
}
```

---
**Bài trước:** [[Danh sách liên kết đơn]]
**Bài sau**: [[Duyệt qua danh sách liên kết đơn]]