**Chủ đề**: [[Danh sách liên kết đôi]]
## Chèn nút ở đầu Danh sách liên kết
---
> _Cách thực hiện cũng khá giống như [[Chèn nút trong Danh sách liên kết đơn]], nhưng ta phải kết nối nút **PREV** thành **NULL** (Cái này được auto thực hiện)_

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

## Chèn nút ở cuối Danh sách liên kết
---
> _Trong trường hợp này, ta sẽ làm giống như [[Chèn nút trong Danh sách liên kết đơn]]. nhưng nối thêm con trỏ **PREV**_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút ở cuối danh sách liên kết đôi
Node* append(Node* head, int data) {
    // Tạo nút với dữ liệu được cho
    Node* newNode = new Node(data);

    // Kiểm tra nếu danh sách rỗng thì làm giống như thêm nút ở đầu danh sách liên kết đôi
    if (head == nullptr) {
        head = newNode;
    }
    else {
        // Nếu không thì tạo một nút tạm duyệt đến cuối danh sách
        Node* last = head;
        while (last->next != nullptr) last = last->next;

        // Thêm nút vào danh sách và nối con trỏ
        last->next = newNode;
        newNode->prev = last;
    }

    // Trả về danh sách đã được chỉnh sửa
    return head;
}
```
#### Python
---
``` python
# Hàm thêm nút ở cuối danh sách liên kết đôi
def append(head: Node, data: int) -> Node:
    # Tạo nút với dữ liệu được cho
    newNode: Node = Node(data)

    # Kiểm tra nếu danh sách rỗng thì làm giống như thêm nút ở đầu danh sách liên kết đôi
    if head is None:
        head = newNode
    
    else:
        # Nếu không thì tạo một nút tạm duyệt đến cuối danh sách
        last: Node = head
        while last.next is not None:
            last = last.next

        # Thêm nút vào danh sách và nối con trỏ
        last.next = newNode
        newNode.prev = last

    # Trả về danh sách đã được chỉnh sửa
    return head
```

## Chèn nút ở vị trí cụ thể trong Danh sách liên kết
---
> _Trong trường hợp này, ta cũng làm giống như [[Chèn nút trong Danh sách liên kết đôi]], nhưng phải nối thêm con trỏ **PREV**_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút ở một vị trí cụ thể trong Danh sách liên kết
Node* add(Node* head, int data, int pos) {
    // Tạo một nút với dữ liệu được cho
    Node* newNode = new Node(data);

    // Thêm nút ở đầu danh sách liên kết
    if (pos == 1) {
        head = insert(head, data);
        return head;
    }

    // Tạo môt nút tạm để duyệt đến vị trí của người dùng
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) temp = temp->next;

    // Kiểm tra nếu vị trí mà người dùng đưa ra vượt kích thước của danh sách
    if (temp == nullptr) {
        std::println("ERROR 001: Index out of range");
        delete newNode; // Giải phóng bộ nhớ
        return head;
    }

    // Nếu không thì thêm nút và nối con trỏ vào danh sách
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;

    // Nếu nút được thêm vào không phải là nút cuối cùng, thì nối con trỏ PREV mà nút trước đó
    if (newNode->next == nullptr) newNode->next->prev = newNode;

    // Trả về Danh sách liên kết đã được chỉnh sửa
    return head;
}
```
#### Python
---
``` python
# Hàm thêm nút ở một vị trí cụ thể trong Danh sách liên kết
def add(head: Node, data: int, pos: int) -> Node:
    # Tạo một nút với dữ liệu được cho
    newNode: Node = Node(data)

    # Thêm nút ở đầu danh sách liên kết
    if pos == 1:
        head = insert(head, data)
        return head

    # Tạo môt nút tạm để duyệt đến vị trí của người dùng
    temp: Node = head
    if temp is not None:
        for i in range(1, pos - 1):
            if temp is None:
                break
            temp = temp.next

    # Kiểm tra nếu vị trí mà người dùng đưa ra vượt kích thước của danh sách
    if temp is None:
        print("ERROR 001: Index out of range")
        return head

    # Nếu không thì thêm nút và nối con trỏ vào danh sách
    newNode.prev = temp
    newNode.next = temp.next
    temp.next = newNode

    # Nếu nút được thêm vào không phải là nút cuối cùng, thì nối con trỏ PREV mà nút trước đó
    if newNode.next is None:
        newNode.next.prev = newNode

    # Trả về Danh sách liên kết đã được chỉnh sửa
    return head
```
---
**Bài trước**: [[Kích thước của Danh sách liên kết đôi]]
**Bài sau**: [[Xóa nút trong Danh sách liên kết đôi]]