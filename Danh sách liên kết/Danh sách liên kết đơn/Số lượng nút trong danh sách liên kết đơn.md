**Chủ đề**: [[Danh sách liên kết đơn]]

> _Cách làm cũng giống như Duyệt và in danh sách liên kết, nhưng chỉ khác là ta không in mà ta cộng từng nút vào một biến và trả về biến đó, tới đây thì không cần mô tả thuật toán rồi, và có hai cách tiếp cận là **đệ quy** và **tuần tự**. Trong bài đọc này ta dùng tuần tự vì chỉ cần dùng 1 space_

#### C++
---
``` cpp
// Hàm đếm số lượng nút trong danh sách liên kết đơn
int count(Node* head) {
    // Khởi tạo một nút tạm
    Node* temp = head;

    // Tạo một biến tạm lưu trữ kích thước
    int length = 0;

    // Lặp nếu nút tiếp theo không phải là NULL
    while (temp != nullptr) {
        length++;                   // Tăng kích thước
        temp = temp->next;          // Trỏ đến nút tiếp theo
    }
    
    return length;      // Trả về kích thước cho chương trình
}
```
#### Python
---
``` python
# Hàm đếm số lượng nút trong danh sách liên kết đơn
def count(head: Node) -> int:
	# Khởi tạo một nút tạm
	curr: Node | None = head

	# Khởi tạo một biến tạm lưu trữ kích thước
	length: int = 0

	# Lặp cho đến khi nút tạm có con trỏ là NULL
	while curr is not None:
		length += 1			# Tăng kích thước			
		curr = curr.next	# Trỏ con trỏ nút tạm đến nút tiếp theo
	
	# Trả về kích thước cho chương trình
	return length
```
---
**Bài trước**: [[Tìm kiếm trong Danh sách liên kết đơn]]
**Bài sau**: [[Chèn nút trong Danh sách liên kết đơn]]