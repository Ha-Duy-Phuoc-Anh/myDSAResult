# Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node:
	# Hàm khởi tạo nút mới trong Danh sách liên kết
	def __init__(self, data: int):
		self.prev: Node = None  # Gán con trỏ tới nút trước là NULL
		self.data: int = data   # Gán dữ liệu vào nút
		self.next: Node = None  # Gán con trỏ tới nút tiếp theo là NULL

# Hàm duyệt qua danh sách liên kết đôi (từ phía sau)
def tranversal(head: Node) -> Node:
    # Tạo một biến tạm từ điểm cuổi cùng
    curr: Node = head

    # Lắp nếu curr không phải là NULL
    while curr is not None:
        # In dữ liệu
        print(f"{curr.data} ", end="")

        # Di chuyển về nút đằng sau
        curr = curr.next

# Hàm tìm kích thước của danh sách liên kết đôi (từ dưới đi lên)
def getLength(head: Node) -> int:
    # Tạo một biến tạm từ điểm cuổi cùng
    curr: Node = head

    # Tạo một biến tạm lưu trữ kết quả
    length: int = 0

    # Lặp cho tới khi curr là NULL
    while curr is not None:
        length += 1;        # Cập nhật độ dài
        curr = curr.next;   # Di chuyển đến nút trước đó
    
    return length;  # Trả về độ dài của danh sách

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
    

# Khởi tạo danh sách liên kết đơn
head: Node = Node(1)
head.next = Node(2)
head.next.prev = head
head.next.next = Node(3)
head.next.next.prev = head.next

head = insert(head, 2)
head = insert(head, 3)

tranversal(head)
print("\nLength of the list:", getLength(head))

# head = insert(head, 2)
# head = insert(head, 3)
# head = insert(head, 4)
# head = insert(head, 5)
# head = append(head, 2)
# head = append(head, 3)
# head = append(head, 4)
# head = append(head, 5)
# head = add(head, 2, 10)
# head = add(head, 10, 20)

# print("Before delete: ")
# tranversalList(head)  

# head = removeFirst(head)
# head = removeFirst(head)
# head = removeLast(head)
# head = removeLast(head)
# head = remove(head, 2)
# head = remove(head, 5)

# print("After delete: ")
# tranversalList(head)

# head = modify(head)
# print("After modified: ")
# tranversalList(head)

# print(search(head, 13))
# print(search(head, 12))
# print(count(head))