#file [[Cây Heap]]

## Heapify

Thao tác này sắp xếp lại toàn bộ cây để duy trì thuộc tính Heap. Thường dùng sau khi xóa nút, chèn nút. Thao tác này có độ phức tạp là $O(\log n)$.
- Đối với **max-heap**, nó đảm bảo tuân thủ phần tử lớn nhất là gốc của cây nhị phân đó, và toàn bộ hậu duệ đều phải theo thuộc tính heap
- Đối với **min-heap**, nó cân bằng bằng theo cách mà phần tử nhỏ nhất là gốc, và toàn bộ hậu duệ đều phải theo quy tắc này

## Insert (chèn)

Khi một phần tử mới được chèn vào heap, nó có thể làm gián đoạn các thành phần heap. Để khôi phục và duy trì hệ thống này, thao tác **heapify** sẽ cần thiết nhất. Thao tác này đảm bảo thuộc tính heap được bảo quản và có độ phức tạp thời gian là $O(\log n)$

![[Cây/Cây Heap/IMG_3.png]]

## Deletion (xóa)

- Nếu ta xóa phần tử từ heap, nó luôn xóa phần tử gốc của cây và thay thế nó bằng một nút lá
- Từ khi ta xóa nút gốc từ heap, nó sẽ làm biến dạng các giá trị của heap cho nên ta cần phải làm thao tác **heapify** để duy trì hệ thống heap.
- Độ phức tạp thời gian: $O(\log n)$

![[Cây/Cây Heap/IMG_4.png]]

## getMax (dành cho max-heap) & getMin (dành cho min-heap)

Tìm kiếm phần tử lớn nhất hoặc phần tử bé nhất trong max-heap hoặc min-heap vói độ phức tạp thời gian là hằng số $O(1)$

## removeMin hoặc removeMax

Thao tác này trả về và xóa phần tử lớn nhất hoặc bé nhất trong heap. Tóm lại là xóa root

---
**Bài trước**: [[Các thành phần của Heap]]
**Bài sau**: [[Thực hiện cấu trúc dữ liệu Heap]]