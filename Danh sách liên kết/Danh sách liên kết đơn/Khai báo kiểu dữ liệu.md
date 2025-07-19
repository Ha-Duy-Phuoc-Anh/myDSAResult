**Chủ đề**: [[Danh sách liên kết đơn]]
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
---
**Bài trước:** [[Danh sách liên kết đơn]]
**Bài sau**: [[Duyệt qua danh sách liên kết đơn]]