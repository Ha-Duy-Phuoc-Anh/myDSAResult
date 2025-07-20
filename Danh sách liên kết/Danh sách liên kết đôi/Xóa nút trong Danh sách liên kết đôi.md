#file **Chủ đề**: [[Danh sách liên kết đôi]]
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
// Hàm xóa nút cuối của danh sách liên kết
Node* removeLast(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Kiểm tra nếu chỉ có một nút trong danh sách
    if (head->next == nullptr) {
        delete head; // Xóa nút duy nhất
        return nullptr; // Danh sách trở thành rỗng
    }

    // Duyệt tới nút cuối cùng
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Chuyển con trỏ của nút trước để bỏ nút sau để tránh lỗi không thể truy cập bộ nhớ
    last->prev->next = nullptr;

    // Xóa nút cuối cùng (đây là nút 'last')
    delete last;

    // Trả về head của danh sách đã được chỉnh sửa
    return head;
}
```
#### Python
---
``` python
# Hàm xóa nút cuối của danh sách liên kết
def removeLast(head: Node) -> Node:
    # Kiểm tra nếu danh sách rỗng
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Kiểm tra nếu chỉ có một nút trong danh sách
    if head.next is None:
        del head # Xóa nút duy nhất
        return None # Danh sách trở thành rỗng

    # Duyệt tới nút cuối cùng
    last: Node = head
    while last.next is not None:
        last = last.next

    # Chuyển con trỏ của nút trước để bỏ nút sau để tránh lỗi không thể truy cập bộ nhớ
    last.prev.next = None

    # Xóa nút cuối cùng (đây là nút 'last')
    del last

    # Trả về head của danh sách đã được chỉnh sửa
    return head
```

## Xóa nút ở vị trí cụ thể trong Danh sách liên kết
---
> _Cũng giống như [[Xóa nút trong Danh sách liên kết đơn]], chỉ khác là nhớ nối con trỏ **PREV**_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
Node* remove(Node* head, int pos) {
    // Kiểm tra nếu danh sách rỗng thì báo lỗi
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Tạo một nút tạm duyệt tới vị trí người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos; i++) curr = curr->next;

    // Nếu như vị trí người dùng đưa ra vượt quá kích thước danh sách
    if (curr == nullptr) {
        std::println("ERROR 001: Index out of range");
        return head;
    }

    // Cập nhật con trỏ nút để xóa nút an toàn
    if (curr->prev != nullptr) curr->prev->next = curr->next;
    if (curr->next != nullptr) curr->next->prev = curr->prev;

    // Nếu như nút bị xóa chính là HEAD
    if (head == curr) head = curr->next;

    // Xóa nút và trả về danh sách đã được chỉnh sửa
    delete curr;    
    return head;
}
```
#### Python
---
``` python
# Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
def remove(head: Node, pos: int) -> Node:
    # Kiểm tra nếu danh sách rỗng thì báo lỗi
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Tạo một nút tạm duyệt tới vị trí người dùng đưa ra
    curr: Node = head
    if curr is not None:
        for _ in range(1, pos):
            if curr is None:
                break
            curr = curr.next

    # Nếu như vị trí người dùng đưa ra vượt quá kích thước danh sách
    if curr is None:
        print("ERROR 001: Index out of range")
        return head

    # Cập nhật con trỏ nút để xóa nút an toàn
    if curr.prev is not None:
        curr.prev.next = curr.next
    if curr.next is not None:
        curr.next.prev = curr.prev

    # Nếu như nút bị xóa chính là HEAD
    if head is curr:
        head = curr.next

    # Xóa nút và trả về danh sách đã được chỉnh sửa
    del curr    
    return head
```
---
**Bài trước**: [[Chèn nút trong Danh sách liên kết đôi]]
**Bài sau**: [[So sánh giữa Danh sách liên kết đơn và Danh sách liên kết đôi]]