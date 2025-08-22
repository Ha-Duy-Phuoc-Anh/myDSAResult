#file **Chủ đề**: [[Danh sách liên kết vòng tròn]]

> _Cũng giống như [[Tìm kiếm trong Danh sách liên kết đơn]] thôi :)_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm tìm kiếm trong danh sách liên kết đơn
bool search(Node* last, int target) {
    // Khởi tạo một nút tạm
    Node* curr = last->next;
    
    // Lắp nếu con trỏ nút tạm khôn phải là NULL
    while (curr != last) {
        // Trả về true để ngắt hàm nếu dữ liệu của nút tạm bằng với mục tiêu của người dùng
        if (curr->data == target) {
            return true;
        }

        // Chuyển đến nút tiếp theo
        curr = curr->next;
    } 

    // Trả về false nếu không có giá trị bằng với mục tiêu
    return false;
}
```
#### Python
---
``` python
# Hàm tìm kiếm trong danh sách liên kết đơn
def search(last: Node | None, target: int) -> bool:
    # Khởi tạo một nút tạm
    curr: Node | None = last.next
    
    # Lắp nếu con trỏ nút tạm khôn phải là NULL
    while curr != last:
        # Trả về true để ngắt hàm nếu dữ liệu của nút tạm bằng với mục tiêu của người dùng
        if curr.data == target:
            return True

        # Chuyển đến nút tiếp theo
        curr = curr.next

    # Trả về false nếu không có giá trị bằng với mục tiêu
    return False
```