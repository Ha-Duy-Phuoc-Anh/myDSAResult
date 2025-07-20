#file [[Ngăn xếp]]

**Một số thao tác của ngăn xếp là**:
- **push()**: Chèn dữ liệu vào Ngăn xếp
- **pop()**: Xóa dữ liệu trong Ngăn xếp
- **top()**: Trả về dữ liệu nằm đằng trước Ngăn xếp
- **isEmpty()**: Cho biết Ngăn xếp rỗng hay không
- **isFull()**: Cho biết Ngăn xếp đã đầy chưa (Thường thấy ở **Mảng**)

## Thao tác chèn
---
> _Thêm dữ liệu vào Ngăn xếp, nếu đầy thì gọi là **trạng thái tràn**_

> **Các bước để chèn vào Ngăn xếp**: 
> 	1. Kiểm tra nếu ngăn xếp đầy, nếu đầy thì báo lỗi, nếu không thì tiếp tục
> 	2. Nếu không thì tăng vị trí của **TOP** lên 1

![[Ngăn xếp/IMG_3.png]]

## Thao tác xóa
---
> _Xóa dữ liệu khỏi Ngăn xếp, nếu thiếu thì gọi là **tràn ngược**_

> **Các bước để xóa khỏi Ngăn xếp**:
> 	1. Kiểm tra nếu ngăn xếp rỗng, nếu rỗng thì báo lỗi, không thì tiếp tục
> 	2. Giảm vị trí của **TOP** xuống 1

![[Ngăn xếp/IMG_4.png]]

## Lấy giá trị của TOP
---
> _Trả về giá trị của **TOP**_

> **Các bước**:
> 	1. Kiểm tra nếu Ngăn xếp rỗng, nếu phải ngắt chương trình và trả về **STACK IS EMPTY**
> 	2. Nếu không thì lấy giá trị đó và trả về dữ liệu

![[Ngăn xếp/IMG_5.png]]

## Thao tác kiểm tra Ngăn xếp rỗng
---
> _Trả về TRUE nếu rỗng, FALSE nếu không_

> **Kiểm tra nếu top là -1**

![[IMG_6.png]]
## Thao tác kiểm tra Ngăn xếp đầy
---
> _Trả về TRUE nếu đầy, FALSE nếu không_

> **Kiểm tra nếu top lớn hơn kích thước có trước**

![[IMG_7.png]]

## VIDEO MẪU PUSH VÀ POP
---
![[Ngăn xếp/VID_1.mp4|VID_1]]

---
**Bài trước**: [[Biểu diễn Ngăn xếp]]
**Bài sau**: [[Phân tích Ngăn xếp]]