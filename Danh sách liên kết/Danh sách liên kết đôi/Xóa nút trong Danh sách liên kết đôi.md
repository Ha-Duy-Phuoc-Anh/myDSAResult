## Xóa nút ở đầu Danh sách liên kết
---
> _Thao tác này giống như [[Xóa nút trong Danh sách liên kết đơn]], chỉ khác là cần nối **PREV** vào **HEAD**_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(n)$

#### C++
---
``` cpp
// Hàm xóa nút đầu của Danh sách liên kết
Node* removeFirst(Node* head) {
    // Nếu danh sách rỗng thì báo lỗi và trả về null
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Lưu trữ nút vào biến tạm để xóa sau
    Node* temp = head;

    // Chuyển con trỏ đến nút tiếp theo
    head = head->next;

    // Xóa nút và trả về danh sách đã chỉnh sửa
    delete temp;
    return head;
}
```
#### Python
---
``` python
# Hàm xóa nút đầu của Danh sách liên kết
def removeFirst(head: Node) -> Node:
    # Nếu danh sách rỗng thì báo lỗi và trả về null
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Lưu trữ nút vào biến tạm để xóa sau
    temp: Node = head

    # Chuyển con trỏ đến nút tiếp theo
    head = head.next

    # Xóa nút và trả về danh sách đã chỉnh sửa
    del temp
    return head
```

## Xóa nút ở cuối Danh sách liên kết
---
> _Thao tác này giống như [[Xóa nút trong Danh sách liên kết đơn]], lí do là vì ta chưa thể tìm được nút cuối ngay lập tức nên tạm thời làm giống như [[Xóa nút trong Danh sách liên kết đơn]].

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp

```
#### Python
---
``` python

```