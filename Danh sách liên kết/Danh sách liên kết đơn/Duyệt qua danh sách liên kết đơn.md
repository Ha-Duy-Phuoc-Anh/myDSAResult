#file **Chủ đề**: [[Danh sách liên kết đơn]]

_Duyệt qua danh sách liên kết đơn là một trong những thao tác cơ bản của Danh sách liên kết. Trong bài đọc này, ta sẽ tìm hiểu cách duyệt qua danh sách liên kết đơn_

![[VID_1.mp4]]

#### Ví dụ
---
```
Đầu vào: A -> B -> C -> D -> NULL
Đầu ra: A B C D
Giải thích: Mỗi phần tử của mỗi nút từ HEAD cho đến NULL đều được ghi ra cửa sổ dòng lệnh, điều đó chứng tỏ đã duyệt qua danh sách thành công
```

### Mẫu method
---
> _Thực chất cả hai loại là tuần tự và đệ quy, nhưng khuyến khích dùng tuần tự để giảm số Stack không cần thiết_

>_Quá trình duyệt qua một danh sách được liên kết đơn lẻ liên quan đến việc in giá trị của mỗi nút và sau đó chuyển sang nút tiếp theo và in giá trị của nút đó, v.v., cho đến khi chúng ta đến nút cuối cùng trong danh sách liên kết đơn lẻ, có nút tiếp theo hướng về null._

> **Quá trình**:
>	1. Khởi tạo một con trỏ tạm thời trỏ đến nút đầu tiên
>	2. Kiểm tra nút tiếp theo có phải NULL không, nếu phải thì dừng thao tác, nếu không thì in dữ liệu ra cửa sổ dòng lên và tiếp tục trỏ đến nút tiếp theo

> **Time complexity**: $O(n)$
> **Space complexity**: $O(1)$

![[IMG_2.png]]
### C++
---
``` cpp
// Hàm duyệt danh sách liên kết đơn
void tranversalList(Node* head) {
	// Khởi tạo một nút tạm
	Node* temp = head;  

	// Lặp nếu nút tiếp theo không phải là NULL
	while (temp != nullptr) {
		std::cout << temp << " ";   // In ra cửa sổ dòng lệnh
		temp = temp->next;          // Trỏ đến nút tiếp theo
	}
	std::cout << std::endl; // Ngắt dòng
	// Không được xóa nút tạm vì nút tạm này không sử dụng new, nếu xóa thì sẽ xóa nguyên danh sách
}
```
### Python
---
``` python
# Hàm duyệt danh sách liên kết đơn
def tranversalList(head: Node) -> None:
	# Khởi tạo một nút tạm
	temp: Node | None = head

	# Lặp cho đến khi nút tạm có con trỏ là NULL
	while temp is not None:
		print(f"{temp.data} ", end="")	# In ra cửa sổ dòng lệnh
		temp = temp.next				# Trỏ con trỏ nút tạm đến nút tiếp theo
	
	print()	# Ngắt dòng
```

<div style="background-color: #EFEFEF; line-height:0.3em; padding: 5px 20px;">
	<p><b>Input</b>:  1 -> 2 -> 3 -> 4 -> 5</p>
	<p><b>Output</b>: 1 2 3 4 5</p>
</div>

---
**Bài trước**: [[Danh sách liên kết/Danh sách liên kết đơn/Khai báo kiểu dữ liệu]]
**Bài sau**: [[Số lượng nút trong danh sách liên kết đơn]]