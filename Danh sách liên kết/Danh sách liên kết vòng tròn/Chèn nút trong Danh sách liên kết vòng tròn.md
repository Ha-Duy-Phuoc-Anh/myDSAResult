## Chèn nút vào Danh sách liên kết trống
---
> _Có lẽ ta sẽ hỏi tại sao có cái này, nhưng thật ra cái gì cũng có lí do, danh sách liên kết vòng tròn có kết cấu đặc biệt, nên khi tạo một nút mới ta sẽ phải dùng nút vòng liên kết ngay chính nó_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút vào Danh sách liên kết rỗng
Node* insertEmpty(Node* last, int data) {
    // Kiểm tra nếu danh sách không rỗng
    if (last != nullptr) return last;

    // Tạo một nút mới và trỏ đến chính nó
    Node* newNode = new Node(data);
    newNode->next = newNode;

    // Chuyển last đến nút mới
    last = newNode;
    return last;
}
```
#### Python
---
``` python
# Hàm thêm nút vào Danh sách liên kết rỗng
def insertEmpty(last: Node, data: Node) -> Node:
    # Kiểm tra nếu danh sách không rỗng
	if last is not None:
		return last

    # Tạo một nút mới và trỏ đến chính nó
	newNode: Node = Node(data)
	newNode.next = newNode

    # Chuyển last đến nút mới
	last = newNode
	return last
```

## Chèn nut vào đầu Danh sách liên kết
---
> _Để làm điều này, ta tạo một nút mới và kiểm tra nếu danh sách rỗng thì làm giống như Chèn nút ở Danh sách liên kết rỗng, nếu không thì trỏ con trỏ của nút mới đến nút tiếp theo của last, sau đó cập nhật nút tiếp theo của last đến nút mới_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp

```
#### Python
---
``` python

```