# Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
class Node:
	# Hàm khởi tạo nút mới trong Danh sách liên kết
	def __init__(self, data: int):
		self.data: int = data   # Gán dữ liệu vào nút
		self.next: Node | None = None  # Gán con trỏ tới nút tiếp theo là NULL
		
# Hàm duyệt danh sách liên kết đơn
def tranversalList(head: Node | None) -> None:
	# Khởi tạo một nút tạm
	temp: Node | None = head

	# Lặp cho đến khi nút tạm có con trỏ là NULL
	while temp is not None:
		print(f"{temp.data} ", end="")	# In ra cửa sổ dòng lệnh
		temp = temp.next				# Trỏ con trỏ nút tạm đến nút tiếp theo
	
	print()	# Ngắt dòng
	# Do Python có Garbage Collector nên ta không phải xóa con trỏ temp

# Hàm tìm kiếm trong danh sách liên kết đơn
def search(head: Node | None, target: int) -> bool:
    # Khởi tạo một nút tạm
    curr: Node | None = head
    
    # Lắp nếu con trỏ nút tạm khôn phải là NULL
    while curr is not None:
        # Trả về true để ngắt hàm nếu dữ liệu của nút tạm bằng với mục tiêu của người dùng
        if curr.data == target:
            return True

        # Chuyển đến nút tiếp theo
        curr = curr.next

    # Trả về false nếu không có giá trị bằng với mục tiêu
    return False

# Hàm đếm số lượng nút trong danh sách liên kết đơn
def count(head: Node | None) -> int:
	# Khởi tạo một nút tạm
	curr: Node | None = head

	# Khởi tạo một biến tạm lưu trữ kích thước
	length: int = 0

	# Lặp cho đến khi nút tạm có con trỏ là NULL
	while curr is not None:
		length += 1			# Tăng kích thước			
		curr = curr.next	# Trỏ con trỏ nút tạm đến nút tiếp theo
	
	# Trả về kích thước cho chương trình
	return length

# Hàm thêm nút mới ở đầu danh sách liên kết
def insert(head: Node | None, data: int) -> Node:
	# Tạo một nút mới dựa trên dữ liệu đã cho
	newNode: Node | None = Node(data)

	# Trỏ con trỏ của nút mới đến HEAD
	newNode.next = head

	# Trả về danh sách liên kết mới với newNode là HEAD
	return newNode

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

# Hàm xóa nút nhất định trong danh sách liên kết
def remove(head: Node, pos: int) -> Node:
    # Điều kiện này cho biết vị trí có ít hơn 1 không, nếu có thì báo lỗi
    if pos < 1:
        print("ERROR 001: Position out of range")
        return head

    # Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với xóa nút vào đầu danh sách liên kết
    if pos == 1:
        head = removeFirst(head)
        return head

    # Tạo một nút tạm để duyệt đến vị trí mà người dùng đưa ra
    curr: Node = head
    if curr is not None:
        for i in range(1, pos - 1):
            if curr is None:
                break
            curr = curr.next

    # Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
    if curr is None or curr.next is None:
        print("ERROR 001: Position out of range")
        return head

    # Tạo một nút tạm để xóa nút
    temp: Node = curr.next

    # Chuyển con trỏ của nút tạm đến nút tiếp theo
    curr.next = temp.next

    # Xóa nút tạm
    del temp

    # Trả về danh sách đã sửa
    return head

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

head: Node = Node(1)
head = insert(head, 2)
head = insert(head, 3)
head = insert(head, 4)
head = insert(head, 5)
head = append(head, 2)
head = append(head, 3)
head = append(head, 4)
head = append(head, 5)
head = add(head, 2, 10)
head = add(head, 10, 20)

print("Before delete: ")
tranversalList(head)  

head = removeFirst(head)
head = removeFirst(head)
head = removeLast(head)
head = removeLast(head)
head = remove(head, 2)
head = remove(head, 5)

print("After delete: ")
tranversalList(head)

head = modify(head)
print("After modified: ")
tranversalList(head)


print(search(head, 13))
print(search(head, 12))
print(count(head))