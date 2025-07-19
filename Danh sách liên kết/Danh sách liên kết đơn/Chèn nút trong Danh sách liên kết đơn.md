**Chủ đề**: [[Danh sách liên kết đơn]]
## Chèn nút vào đầu Danh sách liên kết đơn
---
> _Để chèn một nút ở trước danh sách liên kết đơn, ta tạo một nút có dữ liệu đã cho trước đó, sau đó trỏ đến **HEAD** (sau đó trả về lại Danh sách liên kết với nút mới là **Head**)_

> **Time complexity**: $O(1)$
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút vào đầu danh sách liên kết
Node* insert(Node* head, int data) {
    // Tạo một nút mới dựa trên dữ liệu đã cho
    Node* newNode = new Node(data);

    // Trỏ con trỏ của nút mới đến HEAD
    newNode->next = head;

    // Trả về danh sách liên kết đã điều chỉnh, và cho newNode là HEAD mới của nh sách
    return newNode;
}
```
#### Python
---
``` python
# Hàm thêm nút mới ở đầu danh sách liên kết
def insert(head: Node, data: int) -> Node:
	# Tạo một nút mới dựa trên dữ liệu đã cho
	newNode: Node | None = Node(data)

	# Trỏ con trỏ của nút mới đến HEAD
	newNode.next = head

	# Trả về danh sách liên kết mới với newNode là HEAD
	return newNode
```

## Chèn nút vào cuối danh sách liên kết đơn
---
> _Để chèn một nút ở sau danh sách liên kết, ta kiểm tra trước nếu danh sách là rỗng thì ta chèn thẳng nút vào **Head**, nếu không thì tạo một nút tạm và duyệt cho tới cuối danh sách, sau đó chèn nút vào nút tạm đó để thay thế_

> **Time complexity**: $O(n)$ với $n$ là kích thước của danh sách liên kết
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút vào cuối danh sách liên kết
Node* append(Node* head, int data) {
    // Khởi tạo một nút với giá trị đã cho
    Node* newNode = new Node(data);
    
    // Kiểm tra nếu danh sách rỗng, nếu rỗng thì chèn thẳng nút vào HEAD và ngắt hàm
    if (head == nullptr) return newNode;

    // Tạo một nút tạm
    Node* last = head;

    // Lặp tới khi tới nút cuối cùng
    while (last->next != nullptr) last = last->next;

    // Chèn nút tại nút tạm last
    last->next = newNode;

    // Trả về danh sách liên kết đã chỉnh sửa
    return head;
}
```
#### Python
---
``` python
# Hàm thêm nút mới vào cuối danh sách liên kết
def append(head: Node | None, data: int) -> Node:
	# Tạo một nút mới với dữ liệu đã cho
	newNode: Node | None = Node(data)

	# Kiểm tra nếu danh sách rỗng, nếu rỗng thì chèn thẳng nút vào HEAD và ngắt hàm
	if head is None:
		return newNode
	
	# Tạo một nút tạm
	last: Node | None = head

	# Lặp cho tới nút cuối cùng
	while last.next is not None:
		last = last.next

	# Chèn nút có dữ liệu đã cho vào nut tạm
	last.next = newNode

	# Trả về danh sách liên kết đã được chỉnh sửa
	return head
```

## Chèn nút vào một vị trí cụ thể trong Danh sách liên kết đơn
---
> _Để chèn một nút vào vị trí nhất định trong danh sách liên kết đơn, ta dùng **tiếp cận tuần tự** để tới được vị trí người dùng đưa ra, sau đó chèn nút vào. Nếu vị trí bé hơn 1 thì không làm gì cả, chỉ trả về **Head**. Nếu vị trí lớn hơn kích thước danh sách thì trả lại Danh sách mà không chỉnh sửa (**Báo lỗi** hoặc **Không làm gì**, tùy người viết code :)) _

> **Time complexity**: $O(n)$ với $n$ là vị trí đầu vào
> **Space complexity**: $O(1)$

#### C++
---
``` cpp
// Hàm thêm nút vào một vị trí cụ thể trong danh sách liên kết
Node* add(Node* head, int pos, int data) {
    // Điều kiện này cho biết vị trí của người dùng có ít hơn 1 không, nếu có thì báo lỗi
    if (pos < 1) {
        std::println("ERROR 001: Position out of range");
        return head;
    }

    // Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với thêm nút vào đầu danh sách liên kết
    if (pos == 1) {
        Node* newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    // Nếu như tất cả các điều kiện trên đều sai thì tạo một nút tạm duyệt tới vị trí mà người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos - 1; i++) curr = curr->next;

    // Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
    if (curr == nullptr) {
        std::println("ERROR 001: Position out of range");
        return head;
    }

    // Nếu bình thường thì tiếp tục
    Node* newNode = new Node(data);     // Tạo nút với dữ liệu được cho
    
    // Chèn nút mới vào vị trí curr
    newNode->next = curr->next;
    curr->next = newNode;

    // Trả về danh sách đã được chỉnh sửa
    return head;
}
```
#### Python
``` python
# Hàm thêm nút vào một vị trí cụ thể trong danh sách liên kết
def add(head: Node | None, pos: int, data: int) -> Node:
	# Điều kiện này cho biết vị trí của người dùng có ít hơn 1 không, nếu có thì báo lỗi
	if pos < 1:
		print("ERROR 001: Position out of range")
		return head
	
	# Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với thêm nút vào đầu danh sách liên kết
	if pos == 1:
		newNode: Node = Node(data)
		newNode.next = head
		return newNode
	
	# Nếu như tất cả các điều kiện trên đều sai thì tạo một nút tạm duyệt tới vị trí mà người dùng đưa ra
	curr: Node = head
	if curr is not None:
		for i in range(1, pos - 1):
			if curr is None:
				break
			curr = curr.next
	
	# Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
	if curr is None:
		print("ERROR 001: Position out of range")
		return head
	
	# Nếu bình thường thì tiếp tục
	newNode: Node = Node(data)		# Tạo nút mới với dữ liệu đã cho

	# Chèn nút mới vào vị trí curr
	newNode.next = curr.next
	curr.next = newNode

	# Trả về danh sách đã được chỉnh sửa
	return head
```
---
**Bài trước**: [[Số lượng nút trong danh sách liên kết đơn]]
**Bài sau**: [[Xóa nút trong Danh sách liên kết đơn]]