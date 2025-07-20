#file **Chủ đề**: [[Danh sách liên kết vòng tròn]]
## Xóa nút ở đầu Danh sách liên kết vòng tròn
---
> _Làm giống như [[Xóa nút trong Danh sách liên kết đơn]] nhưng nhớ rằng do nút đầu không phải **HEAD** mà là **LAST** nên phải thêm vào `last->next` thay vì chỉ ghi là `delete head` (CASE C++)_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm xóa nút ở đầu danh sách liên kết
Node* remove(Node* last) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::println("ERROR 002: Nothing to delete");
        return nullptr;
    }

    // Kiểm tra nếu nút tiếp theo là nullptr
    if (last->next == nullptr) {
        delete last;
        return nullptr;
    }

    // Nếu không thì xóa như bình thường
    Node* head = last->next;
    last->next = head->next;
    delete head;
    return last;
}
```
#### Python
---
``` python
# Hàm xóa nút ở đầu danh sách liên kết
def remove(last: Node) -> Node:
    # Kiểm tra nếu Danh sách rỗng
    if last is None:
        print("ERROR 002: Nothing to delete")
        return None

    # Kiểm tra nếu nút tiếp theo là nullptr
    if last.next is None:
        del last
        return None

    # Nếu không thì xóa như bình thường
    head: Node = last.next
    last.next = head.next
    del head
    return last
```

## Xóa nút ở cuối danh sách liên kết
---
> _Làm giống như [[Xóa nút trong Danh sách liên kết đơn]] nhưng cũng nhớ là ta dùng **LAST** không phải **HEAD**_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Xóa nút ở cuối danh sách liên kết
Node* delette(Node* last) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::println("ERROR 002: Nothing to delete");
        return nullptr;
    }

    // Kiểm tra nếu nút tiếp theo là nullptr
    if (last->next == nullptr) {
        delete last;
        return nullptr;
    }

    // Nếu không thì tạo nút duyệt đến nút trước nút cuối cùng và xóa
    Node* head = last->next;
    Node* temp = last;
    while (temp->next != last) temp = temp->next;

    // Chỉnh con trỏ để tránh lỗi không thể truy cập bộ nhớ
    temp->next = head;
    delete last;
    last = temp;

    // Trả về Danh sách đã được chỉnh sửa
    return last;
}
```
#### Python
---
``` python
# Xóa nút ở cuối danh sách liên kết
def delete(last: Node) -> Node:
    # Kiểm tra nếu Danh sách rỗng
    if last is None:
        print("ERROR 002: Nothing to delete")
        return None

    # Kiểm tra nếu nút tiếp theo là nullptr
    if last.next is None:
        del last
        return None
    
    # Nếu không thì tạo nút duyệt đến nút trước nút cuối cùng và xóa
    head: Node = last.next
    temp: Node = last
    while temp.next != last:
        temp = temp.next

    # Chỉnh con trỏ để tránh lỗi không thể truy cập bộ nhớ
    temp.next = head
    del last
    last = temp

    # Trả về Danh sách đã được chỉnh sửa
    return last
```

## Xóa nút cụ thể trong Danh sách liên kết
---
> _Làm giống như [[Xóa nút trong Danh sách liên kết đơn]] thôi :), có điều nhớ là giá trị không phải vị trí_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Xóa nút ở nút cụ thể trong danh sách liên kết
Node* delAt(Node* last, int val) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::cout << "ERROR 002: Nothing to delete\n";
        return nullptr;
    }

    // Tạo nút duyệt đến vị trí người dùng đưa ra
    Node* tmp = last->next;
    Node* prev = last;

    // Nếu nút để xóa là nút duy nhất trong danh sách
    if (tmp == last && prev->data == val) {
        delete tmp;
        last = nullptr;
        return last;
    }

    // Nêu nút để xóa là nút đâu tiên
    if (tmp->data == val) {
        last->next = tmp->next;
        delete tmp;
        return last;
    }

    // Duyệt tới nút dự định sẽ xóa
    while (tmp != last && tmp->data != val) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Nếu nút bị xóa được tìm thấy
    if (tmp->data == val) {
        prev->next = tmp->next;
        if (tmp == last) {
            last = prev;
        }
        delete tmp;
    }
    else {
        std::cout << "Node with data " << val << " was not found\n";
    }
    return last;
}
```
#### Python
---
``` python

# Xóa nút ở nút cụ thể trong danh sách liên kết
def delAt(last: Node, val: int) -> Node:
    # Kiểm tra nếu Danh sách rỗng
    if last is None:
        print("ERROR 002: Nothing to delete")
        return None

    # Tạo nút duyệt đến vị trí người dùng đưa ra
    tmp = last.next
    prev = last

    # Nếu nút để xóa là nút duy nhất trong danh sách
    if tmp == last and prev.data == val:
        del tmp
        last = None
        return last

    # Nêu nút để xóa là nút đâu tiên
    if tmp.data == val:
        last.next = tmp.next
        del tmp
        return last

    # Duyệt tới nút dự định sẽ xóa
    while tmp != last and tmp.data != val:
        prev = tmp
        tmp = tmp.next

    # Nếu nút bị xóa được tìm thấy
    if tmp.data == val:
        prev.next = tmp.next
        if tmp == last:
            last = prev
        del tmp
    else:
        print(f"ERROR 003: Node with data {val} was not found")
    return last
```
---
**Bài trước**: [[Chèn nút trong Danh sách liên kết vòng tròn]]
**Bài sau**: [[Tìm kiếm trong Danh sách liên kết vòng tròn]]