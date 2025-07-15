> _Để chỉnh sửa Danh sách liên kết đơn, ta làm như sau:
> 	1. Tìm nút ở giữa Danh sách liên kết và **đảo ngược phần nửa thứ hai** bắt đầu từ sau **nút giữa**
> 	2. Sau đó, duyệt đồng thời **nửa đầu** và **nửa thứ hai đảo ngược**, cập nhật nút của giá trị **nửa đầu** bằng cách trừ **trừ** giá trị của chúng khỏi các nút tương ứng trong nửa thứ hai và hoán đổi chúng
> 	3. Sau khi duyệt, **đảo ngược** nửa thứ hai một lần nửa và **hồi lại** thứ tự trước đó của chúng
> 	4. Cuối cùng, **kết nối lại** nửa đầu và hồi lại nửa cuối để hoàn thành thao tác

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm đảo ngược danh sách liên kết
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Hàm sửa đổi Danh sách liên kết đơn
Node* modify(Node* head) {
    // Kiểm tra nếu nút tiếp theo là NULL thì thoát
    if (!head->next) {
        return head;
    }

    // Khởi tạo các nút hỗ trợ thao tác
    Node* slow = head;
    Node* fast = head;
    Node* mid;

    // Tìm nút ở giữa Danh sách liên kết
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;

    // Tạo nút đánh dấu điểm đảo ngược
    Node* reverseList = mid->next;

    // Tách danh sahcs liên kết thành hai nửa
    mid->next = nullptr;

    // Tạo hai nút tạm để duyệt danh sách
    Node* curr1 = head;
    Node* curr2 = reverseList;
    std::vector<int> firstHalf, secondHalf;

    // Sao chép hết dữ liệu của hai nút vào hai vector
    while (curr1) {
        firstHalf.push_back(curr1->data);
        curr1 = curr1->next;
    }

    while (curr2) {
        secondHalf.push_back(curr2->data);
        curr2 = curr2->next;
    }

    // Chỉnh sửa dữ liệu của vector
    for (int i = 0; i < secondHalf.size(); i++) {
        int x = firstHalf[i];
        firstHalf[i] = secondHalf[i] - x;
        secondHalf[i] = x;
    }

    // Chuyẻn Vector trở về Danh sách liên kết
    curr1 = head;
    for (int value : firstHalf) {
        curr1->data = value;
        curr1 = curr1->next;
    }

    curr2 = reverseList;
    for (int value : secondHalf) {
        curr2->data = value;
        curr2 = curr2->next;
    }

    // Đảo ngược hai nửa và ráp lại hai danh sách liên kết
    mid->next = reverse(reverseList);

    // Trả về danh sách đã được chỉnh sửa
    return head;
}
```
**Lưu ý**: Phải nạp thư viện `<vector>`, và có hàm đảo ngược danh sách liên kết

#### Python
---
``` python
# Hàm đảo ngược danh sách liên kết
def reverse(head: Node) -> Node:
    prev: Node = None
    curr: Node = head
    next: Node = None

    while curr is not None:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev

# Hàm sửa đổi Danh sách liên kết đơn
def modify(head: Node) -> Node:
    # Kiểm tra nếu nút tiếp theo là NULL thì thoát
    if not head.next:
        return head

    # Khởi tạo các nút hỗ trợ thao tác
    slow: Node = head
    fast: Node = head
    mid = None

    # Tìm nút ở giữa Danh sách liên kết
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    mid = slow

    # Tạo nút đánh dấu điểm đảo ngược
    reverseList: Node = mid.next

    # Tách danh sahcs liên kết thành hai nửa
    mid.next = None

    # Tạo hai nút tạm để duyệt danh sách
    curr1: Node = head
    curr2: Node = reverseList
    firstHalf: list[int] = []
    secondHalf: list[int] = []

    # Sao chép hết dữ liệu của hai nút vào hai vector
    while curr1:
        firstHalf.append(curr1.data)
        curr1 = curr1.next

    while curr2:
        secondHalf.append(curr2.data)
        curr2 = curr2.next

    # Chỉnh sửa dữ liệu của vector
    for i in range(len(secondHalf)):
        x: int = firstHalf[i]
        firstHalf[i] = secondHalf[i] - x
        secondHalf[i] = x

    # Chuyẻn Vector trở về Danh sách liên kết
    curr1 = head
    for value in firstHalf:
        curr1.data = value
        curr1 = curr1.next

    curr2 = reverseList
    for value in secondHalf:
        curr2.data = value
        curr2 = curr2.next

    # Đảo ngược hai nửa và ráp lại hai danh sách liên kết
    mid.next = reverse(reverseList)

    # Trả về danh sách đã được chỉnh sửa
    return head
```
---
**Bài trước**: [[Xóa nút trong Danh sách liên kết đơn]]
**Bài sau**: [[Đảo ngược Danh sách liên kết đơn]]