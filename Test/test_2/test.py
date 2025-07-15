# Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node:
	# Hàm khởi tạo nút mới trong Danh sách liên kết
	def __init__(self, data: int):
		self.prev: Node = None  # Gán con trỏ tới nút trước là NULL
		self.data: int = data   # Gán dữ liệu vào nút
		self.next: Node = None  # Gán con trỏ tới nút tiếp theo là NULL

# Hàm duyệt qua danh sách liên kết đôi (từ phía sau)
def tranversal(tail: Node) -> Node:
    # Tạo một biến tạm từ điểm cuổi cùng
    curr: Node = tail

    # Lắp nếu curr không phải là NULL
    while curr is not None:
        # In dữ liệu
        print(f"{curr.data} ", end="")

        # Di chuyển về nút đằng sau
        curr = curr.prev
    

first: Node = Node(1)
second: Node = Node(2)
third: Node = Node(3)

first.next = second
second.next = third

third.prev = second
second.prev = first

tranversal(third)

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