> _Như đã biết trong Danh sách liên kết đơn, có một phương thức là duyệt từ **HEAD**, hôm nay ta không nhắc đến điều này, thay vào đó, ta duyệt từ **TAIL**, nghĩa là duyệt từ cuối lên_

>**Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm duyệt qua danh sách liên kết đôi (từ phía sau)
void tranversal(Node* tail) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = tail;

    // Lắp nếu curr không phải là NULL
    while (curr != nullptr) {
        // In dữ liệu
        std::print("{} ", curr->data);

        // Di chuyển về nút đằng sau
        curr = curr->prev;
    }
}
```
#### Python
---
``` python
# Hàm duyệt qua danh sách liên kết đôi (từ phía sau)
def tranversal(tail: Node) -> Node:
    # Tạo một biến tạm từ điểm cuổi cùng
    curr: Node = tail

    # Lắp nếu curr không phải là NULL
    while curr is not None:
        # In dữ liệu
        print(f"{curr.data} ", end="")

        # Di chuyển về nút đằng sau
        curr = curr.prev
```
---
**Bài trước**: [[Danh sách liên kết/Danh sách liên kết đôi/Khai báo kiểu dữ liệu|Khai báo kiểu dữ liệu]]
**Bài sau**: [[Kích thước của Danh sách liên kết đôi]]