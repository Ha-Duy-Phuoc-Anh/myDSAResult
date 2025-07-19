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
last = append(last, 2)
last = append(last, 3)
last = append(last, 4)
last = append(last, 5)
last = add(last, 2, 10)
last = add(last, 10, 10)

print("Before delete: ", end="")
printList(last)

last = remove(last)
last = remove(last)

print("After delete: ", end="")
printList(last)