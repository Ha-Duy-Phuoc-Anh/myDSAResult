> _Tìm kiếm trong danh sách liên kết đơn có hai loại tiếp cận là tiếp cận tuần tự và tiếp cận đệ quy, như ta đã có có hai loại thuật toán tìm kiếm là **Tìm kiếm tuần tự** và **Tìm kiếm chị phân**. Trong Danh sách liên kết ta dùng **Tiềm kiếm tuần tự** vì ta không thể tiếp cận phần tử ngẫu nhiên như Mảng đươc, thêm nữa là **Tiềm kiếm tuần tự** là $O(n)$ trong khi **Tìm kiếm nhị phân** là $O(n \times log(n))$, trong bài này ta dùng tiếp cận tuần tự_

> Từng bước thực hiện thuật toán:
> 	1. Tạo một con trỏ tạm trỏ đến nút đầu tiên
> 	2. Làm những thứ sau khi con trỏ chưa phải là **NULL**:
> 		1. Nếu giá trị của nút hiện tại bằng với giá trị của mục tiêu, trả về **TRUE**
> 		2. Nếu tới **NULL** mà không tìm thấy thì trả về **FALSE**
## Video mẫu
---
### Tìm thấy mục tiêu
---
![[VID_2.mp4]]
### Không tìm thấy mục tiêu
---
![[VID_3.mp4]]

## Mẫu method
---
### C++
---
``` cpp
// Hàm tìm kiếm trong danh sách liên kết đơn
bool search(Node* head, int target) {
    // Khởi tạo một nút tạm
    Node* curr = head;
    
    // Lắp nếu con trỏ nút tạm khôn phải là NULL
    while (curr != nullptr) {
        // Trả về true để ngắt hàm nếu dữ liệu của nút tạm bằng với mục tiêu của người dùng
        if (curr->data == target) {
            return true;
        }

        // Chuyển đến nút tiếp theo
        curr = curr->next;
    } 

    // Trả về false nếu không có giá trị bằng với mục tiêu
    return false;
}
```
### Python
---
``` python
# Hàm tìm kiếm trong danh sách liên kết đơn
def search(head: Node, target: int) -> bool:
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
```
---
**Bài trước**: [[Duyệt qua danh sách liên kết đơn]]
**Bài sau**: [[Chèn nút trong Danh sách liên kết đôi]]