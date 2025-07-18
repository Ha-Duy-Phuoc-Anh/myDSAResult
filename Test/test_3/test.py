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

    print()

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
        for _ in range(1, pos - 1):
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
    if newNode.next is not None:
        newNode.next.prev = newNode

    # Trả về Danh sách liên kết đã được chỉnh sửa
    return head

# Hàm xóa nút đầu của Danh sách liên kết
def removeFirst(head: Node) -> Node:
    # Nếu danh sách rỗng thì báo lỗi và trả về null
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Lưu trữ nút vào biến tạm để xóa sau
    temp: Node = head

    # Chuyển con trỏ đến nút tiếp theo
    head = head.next

    # Xóa nút và trả về danh sách đã chỉnh sửa
    del temp
    return head

# Hàm xóa nút cuối của danh sách liên kết
def removeLast(head: Node) -> Node:
    # Kiểm tra nếu danh sách rỗng
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Kiểm tra nếu chỉ có một nút trong danh sách
    if head.next is None:
        del head # Xóa nút duy nhất
        return None # Danh sách trở thành rỗng

    # Duyệt tới nút cuối cùng
    last: Node = head
    while last.next is not None:
        last = last.next

    # Chuyển con trỏ của nút trước để bỏ nút sau để tránh lỗi không thể truy cập bộ nhớ
    last.prev.next = None

    # Xóa nút cuối cùng (đây là nút 'last')
    del last

    # Trả về head của danh sách đã được chỉnh sửa
    return head

# Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
def remove(head: Node, pos: int) -> Node:
    # Kiểm tra nếu danh sách rỗng thì báo lỗi
    if head is None:
        print("ERROR 002: List is empty")
        return None

    # Tạo một nút tạm duyệt tới vị trí người dùng đưa ra
    curr: Node = head
    if curr is not None:
        for _ in range(1, pos):
            if curr is None:
                break
            curr = curr.next

    # Nếu như vị trí người dùng đưa ra vượt quá kích thước danh sách
    if curr is None:
        print("ERROR 001: Index out of range")
        return head

    # Cập nhật con trỏ nút để xóa nút an toàn
    if curr.prev is not None:
        curr.prev.next = curr.next
    if curr.next is not None:
        curr.next.prev = curr.prev

    # Nếu như nút bị xóa chính là HEAD
    if head is curr:
        head = curr.next

    # Xóa nút và trả về danh sách đã được chỉnh sửa
    del curr    
    return head

# Khởi tạo danh sách liên kết đôi
head: Node = Node(1)

head = insert(head, 2)
head = insert(head, 3)
head = insert(head, 4)
head = insert(head, 5)
head = append(head, 2)
head = append(head, 3)
head = append(head, 4)
head = append(head, 5)
head = add(head, 10, 2)
head = add(head, 10, 10)

print("Before delete: ", end="")
tranversal(head)

head = removeFirst(head)
head = removeFirst(head)
head = removeLast(head)
head = removeLast(head)
head = remove(head, 2)
head = remove(head, 5)

print("After delete: ", end="")
tranversal(head)

print(f"The list length: {getLength(head)}")
