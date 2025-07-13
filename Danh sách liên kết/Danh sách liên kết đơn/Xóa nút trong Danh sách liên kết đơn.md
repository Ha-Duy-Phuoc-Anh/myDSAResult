## Xóa nút đầu tiên trong Danh sách liên kết
---
>_Để xóa nút nút ở đầu Danh sách liên kết đơn, ta xóa nút đó, sau đó trỏ con trỏ **HEAD** vào nút tiếp theo_

>**Time complexity**: $O(1)$
>**Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm xóa nút đầu tiên trong danh sách liên kết
Node* removeFirst(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Tạo một nút tạm để xóa nút
    Node* temp = head;

    // Chuyển head đến con trỏ tiếp theo
    head = head->next->next;

    // Xóa nút đầu trong danh sách
    delete temp->next;

    // Trả về head
    return head;
}
```
#### Python
---
``` python
# Hàm xóa nút ở đầu danh sách liên kết
def removeFirst(head: Node) -> Node:
	# Kiểm tra nếu danh sách rỗng
	if head is None:
		print("ERROR 002: List is empty")
		return None
	
	# Tạo một nút tạm để xóa nút
	temp: Node = head

	# Chuyển head đến con trỏ tiếp theo
	head = head.next

	# Xóa con trỏ để giải phóng bộ nhớ
	del temp

	# Trả về danh sách đã chỉnh sửa
	return head
```

## Xóa nút cuối cùng trong danh sách liên kết
---
> _Để xóa nút cuối cùng trong danh sách liên kết, ta tạo một nút tạm có giá trị là **HEAD**, sau đó duyệt nó tới trước nút có con trỏ đến **NULL**, sau đó xóa nó và chỉnh con trỏ trước lại thành **NULL**_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm xóa nút cuối trong danh sách liên kết
Node* removeLast(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Tạo một nút tạm thời và di chuyển nó đến nút sau nút cuối cùng
    Node* temp = head;
    while (temp->next->next != nullptr) temp = temp->next;

    // Xóa nút sau nút tạm
    delete temp->next;

    // Trỏ con trỏ sang NULL
    temp->next = nullptr;

    // Trả về danh sách đã sửa
    return head;
}
```
#### Python
---
``` python
# Hàm xóa nút cuối trong danh sách liên kết
def removeLast(head: Node) -> Node:
	# Kiểm tra nếu danh sách rỗng
	if head is None:
		print("ERROR 002: List is empty")
		return None
	
	# Tạo một nút tạm thời và di chuyển nó đến nút sau nút cuối cùng
	temp: Node = head
	while temp.next.next is not None:
		temp = temp.next

	# Xóa nút sau nút tạm
	del temp.next

	# Trỏ con trỏ sang NULL
	temp.next = None

	# Trả về danh sách đã sửa
	return head
```

## Xóa nút ở vị trí nhất định trong danh sách liên kết
---
>_Để xóa nút ở vị trí nhất định trong danh sách liên kết đơn, ta tạo một nút tạm duyệt tới nút trước nút có vị trí giống với vị trí người dùng đưa ra, sau đó xóa và nối con trỏ lại với nhau. Nếu như vị trí là 1 thì thao tác giống thư thêm nút vào đầu danh sách liên kết, nếu như vị trí bé hơn 1 hoặc lớn hơn kích thước của danh sách thì báo lỗi và ngắt hàm_

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