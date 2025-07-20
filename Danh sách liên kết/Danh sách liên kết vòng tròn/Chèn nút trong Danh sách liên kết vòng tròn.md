#file **Chủ đề**: [[Danh sách liên kết vòng tròn]]
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

## Chèn nút vào đầu Danh sách liên kết
---
> _Để làm điều này, ta tạo một nút mới và kiểm tra nếu danh sách rỗng thì làm giống như Chèn nút ở Danh sách liên kết rỗng, nếu không thì trỏ con trỏ của nút mới đến nút tiếp theo của last, sau đó cập nhật nút tiếp theo của last đến nút mới_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm thêm nút vào đầu Danh sách liên kết
Node* insert(Node* last, int data) {
	// Kiểm tra nếu danh sách rỗng
	if (last == nullptr) {
		last = insertEmpty(last, data);
		return last;
	}

	// Tạo một nút mới với dữ liệu được cho
	Node* newNode = new Node(data);

	// Điều chỉnh con trỏ để thêm nút mới vào danh sách
	newNode->next = last->next;
	last->next = newNode;

	// Trả về danh sách đã được chỉnh sửa
	return last;
}
```
#### Python
---
``` python
# Hàm thêm nút vào đầu Danh sách liên kết
def insert(last: Node, data: int) -> Node:
	# Kiểm tra nếu danh sách rỗng
	if last is None:
		last = insertEmpty(last, data)
		return last

	# Tạo một nút mới với dữ liệu được cho
	newNode: Node = Node(data)

	# Điều chỉnh con trỏ để thêm nút mới vào danh sách
	newNode.next = last.next
	last.next = newNode

	# Trả về danh sách đã được chỉnh sửa
	return last
```

## Chèn nút vào cuối Danh sách liên kết
---
> _Vì ta dùng Danh sách liên kết vòng tròn đơn, mà nút đầu lại nằm ở cuối danh sách, nên chỉ cần chèn nút mới giữa nút đầu và nút đầu thứ hai, sau đó chuyển nút đầu lại là nút mới_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm thêm nút vào cuối Danh sách liên kết
Node* append(Node* last, int data) {
    // Kiểm tra nếu danh sách là rỗng
    if (last == nullptr) {
        last = insertEmpty(last, data);
        return last;
    }

    // Tạo một nút mới với dữ liệu được cho
    Node* newNode = new Node(data);

    // Cập nhật con trỏ đên thêm nút vào Danh sách
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    // Trả về Danh sách liên kết đã được chỉnh sửa
    return last;
}
```
#### Python
---
``` python
# Hàm thêm nút vào cuối Danh sách liên kết
def append(last: Node, data: int) -> Node:
    # Kiểm tra nếu danh sách là rỗng
    if last is None:
        last = insertEmpty(last, data)
        return last

    # Tạo một nút mới với dữ liệu được cho
    newNode: Node = Node(data)

    # Cập nhật con trỏ đên thêm nút vào Danh sách
    newNode.next = last.next
    last.next = newNode
    last = newNode

    # Trả về Danh sách liên kết đã được chỉnh sửa
    return last
```

## Chèn nút ở vị trí cụ thể trong Danh sách liên kết
---
> _Làm giống như [[Chèn nút trong Danh sách liên kết đơn]]_

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$
#### C++
---
``` cpp
// Hàm thêm nút ở vị trí cụ thể trong danh sách liên kết
Node* add(Node* last, int pos, int data) {
    // Kiểm tra nếu danh sách rỗng và vị trí người dùng đưa ra không phải là 0
    if (last == nullptr) {
        if (pos != 0) {
            std::println("ERROR 001: Position out of range");
            return last;
        }
        last = insertEmpty(last, data);
        return last;
    }
    // Nếu vị trí người dùng đưa ra là 1
    if (pos == 1) {   
        last = insert(last, data);
        return last;
    }

    // Nếu hai điều kiện trên đều là FALSE
    // Tạo một nút tạm và duyệt đến vị trí người dùng đưa ra (kèm theo việc kiểm tra nếu vị trí người dùng vượt quá kích thước danh sách)
    Node* temp = last;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
        if (temp == last) {
            std::println("ERROR 001: Position out of range");
            return last;
        }
    }

    // Tạo nút với dữ liệu đã cho và chèn nút
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    // Nếu nút được chèn ở vi trí cuối cùng thì update nút
    if (newNode->next == last->next) last = newNode;
    
    // Trả về danh sách đã được chỉnh sửa
    return last;
}
```
#### Python
---
``` python
# Hàm thêm nút ở vị trí cụ thể trong danh sách liên kết
def add(last: Node, pos: int, data: int) -> Node:
    # Kiểm tra nếu danh sách rỗng và vị trí người dùng đưa ra không phải là 0
    if last is None:
        if pos != 0:
            print("ERROR 001: Position out of range")
            return last
		
        last = insertEmpty(last, data)
        return last

    # Nếu vị trí người dùng đưa ra là 1
    if pos == 1: 
        last = insert(last, data)
        return last

    # Nếu hai điều kiện trên đều là FALSE
    # Tạo một nút tạm và duyệt đến vị trí người dùng đưa ra (kèm theo việc kiểm tra nếu vị trí người dùng vượt quá kích thước danh sách)
    temp: Node = last
    for _ in range(1, pos):
        temp = temp.next
        if temp == last:
            print("ERROR 001: Position out of range")
            return last
    
    # Tạo nút với dữ liệu đã cho và chèn nút
    newNode: Node = Node(data)
    newNode.next = temp.next
    temp.next = newNode

    # Nếu nút được chèn ở vi trí cuối cùng thì update nút
    if newNode.next == last.next:
        last = newNode
    
    # Trả về danh sách đã được chỉnh sửa
    return last
```
---
**Bài trước**: [[Danh sách liên kết/Danh sách liên kết vòng tròn/Khai báo kiểu dữ liệu|Khai báo kiểu dữ liệu]]
**Bài sau**: [[Xóa nút trong Danh sách liên kết vòng tròn]]