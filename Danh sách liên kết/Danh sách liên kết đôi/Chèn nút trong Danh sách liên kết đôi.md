## Chèn nút ở đầu Danh sách liên kết
---
> _Cách thực hiện cũng khá giống như Danh sách liên kết đơn, nhưng ta phải kết nối nút **PREV** thành **NULL** (Cái này được auto thực hiện)_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút ở đầu danh sách liên kết đôi
Node* insert(Node* head, int data) {
    // Tạo một nút mới
    Node* newNode = new Node(data);

    // Gán newNode trở thành HEAD mới của danh sách liên kết đơn
    newNode->next = head;

    // Nếu HEAD không phải là NULL thì gán con trỏ PREV của head vào newNode
    if (head != nullptr) head->prev = newNode;

    // Trả về danh sách liên kết đã được chỉnh sửa
    return newNode;
}
```
#### Python
---
``` python
# Hàm thêm nút ở đầu danh sách liên kết đôi
def insert(head: Node, data: int) -> Node:
    # Tạo một nút mới
    newNode: Node = Node(data)

    # Gán newNode trở thành HEAD mới của danh sách liên kết đơn
    newNode.next = head

    # Nếu HEAD không phải là NULL thì gán con trỏ PREV của head vào newNode
    if head is not None:
        head.prev = newNode

    # Trả về danh sách liên kết đã được chỉnh sửa
    return newNode
```
