# Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node:
	# Hàm khởi tạo nút mới trong Danh sách liên kết
	def __init__(self, data: int):
		self.data: int = data   # Gán dữ liệu vào nút
		self.next: Node = None  # Gán con trỏ tới nút tiếp theo là NULL

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


def printList(last: Node) -> None:
	if last is None:
		return None

	current: Node = last.next
	while True:
		print(f"{current.data} ", end="")
		current = current.next
		if current == last.next:
			break

	print("")

# Khởi tạo danh sách liên kết vòng tròn
last: Node = None

last = insertEmpty(last, 1)
last = insert(last, 2)
last = insert(last, 3)
last = insert(last, 4)
last = insert(last, 5)

printList(last)