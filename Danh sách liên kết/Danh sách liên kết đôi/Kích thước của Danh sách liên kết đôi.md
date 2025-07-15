> _Như đã biết trong Danh sách liên kết đơn, có một phương thức là duyệt từ **HEAD**, hôm nay ta không nhắc đến điều này, thay vào đó, ta duyệt từ **TAIL**, nghĩa là duyệt từ cuối lên để đếm từng nút._

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm tìm kích thước của danh sách liên kết đôi (từ dưới đi lên)
int getLength(Node* tail) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = tail;

    // Tạo một biến tạm lưu trữ kết quả
    int length = 0;

    // Lặp cho tới khi curr là NULL
    while (curr != nullptr) {
        length++;           // Cập nhật độ dài
        curr = curr->prev;  // Di chuyển đến nút trước đó
    }
    return length;  // Trả về độ dài của danh sách
}
```
#### Python
---
``` python
# Hàm tìm kích thước của danh sách liên kết đôi (từ dưới đi lên)
def getLength(tail: Node) -> int:
    # Tạo một biến tạm từ điểm cuổi cùng
    curr: Node = tail

    # Tạo một biến tạm lưu trữ kết quả
    length: int = 0

    # Lặp cho tới khi curr là NULL
    while curr is not None:
        length += 1;        # Cập nhật độ dài
        curr = curr.prev;   # Di chuyển đến nút trước đó
    
    return length;  # Trả về độ dài của danh sách
```
---
**Bài trước**: [[Duyệt qua Danh sách liên kết đôi]]
**Bài sau**: [[Chèn nút trong Danh sách liên kết đôi]]