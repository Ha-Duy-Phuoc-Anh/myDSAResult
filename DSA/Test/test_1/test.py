class Node:
    def __init__(self, _data):
        """Khởi tạo kiểu dữ liệu nút

        Args:
            _data (any): Dữ liệu của nút
        """
        self.data = _data
        self.next = None


# Khởi tạo kiểu dữ liệu Danh sách liên kết đơn
class LinkedList:
    def __init__(self):
        """ Khởi tạo Danh sách liên kết """
        self.head = None
    def __str__(self):
        curr = self.head
        while curr is not None:
            print(f"{curr.data}", end=" -> ")
            curr = curr.next
            
        print("nullptr")
    def push_front(self, _data):
        """Hàm chèn nút vào đầu danh sách

        Args:
            _data (any): Dữ liệu của nút mới
        """
        newNode = Node(_data)
        newNode.next = self.head
        self.head = newNode
    def push_back(self, _data):
        """Hàm chèn nút vào sau danh sách liên kết

        Args:
            _data (any): Dữ liệu của nút mới
        """
        newNode = Node(_data)
        
        if self.head is None:
            self.head = newNode
            return
            
        curr = self.head
        while curr.next is not None:
            curr = curr.next
            
        curr.next = newNode
    def push_at(self, _data, _position):
        
    