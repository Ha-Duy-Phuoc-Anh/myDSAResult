**Chủ đề**: [[Danh sách liên kết đơn]]

> _Để đảo ngược danh sách liên kết, ta tạo một nút đầu ở phía sau nút đầu tiên, để cho các nút khác trỏ đến thứ tự ngược này, tạo một nút khác để cho phép di chuyển giữa các nút, và một biến để kiểm soát con trỏ_

> **Time complexity**: $O(n)$ 
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm đảo ngược danh sách liên kết
Node* reverse(Node* head) {
    Node* prev = nullptr;   // Tạo nút đứng trước
    Node* curr = head;      // Tạo nút hiện tại
    Node* next = nullptr;   // Tạo nút kiểm soát con trỏ

    // Lặp khi curr không phải là NULL
    while (curr) {
        next = curr->next;  // Chuyển next đến con trỏ tiếp theo của danh sách liên kết
        curr->next = prev;  // Chuyển con trỏ tiếp theo của danh sách liên kết đến nút đứng trước
        prev = curr;        // Nối con trỏ nút đứng trước đến nút hiện tại
        curr = next;        // Nối nút hiện tại đến nút kiểm soát con trỏ
    }

    // Trả về danh sách đã được chỉnh sửa
    return prev;
}
```
#### Python
---
``` python
# Hàm đảo ngược danh sách liên kết
def reverse(head: Node) -> Node:
    prev: Node = None	# Tạo nút đứng trước
    curr: Node = head	# Tạo nút hiện tại
    next: Node = None	# Tạo nút kiểm soát con trỏ

	# Lặp khi curr không phải là NULL
    while curr is not None:
        next = curr.next	# Chuyển next đến con trỏ tiếp theo của danh sách liên kết
        curr.next = prev	# Chuyển con trỏ tiếp theo của danh sách liên kết đến nút đứng trước
        prev = curr			# Nối con trỏ nút đứng trước đến nút hiện tại
        curr = next			# Nối nút hiện tại đến nút kiểm soát con trỏ

	# Trả về danh sách đã được chỉnh sửa
    return prev
```
---
**Bài trước**: [[Sửa đổi Danh sách liên kết đơn]]