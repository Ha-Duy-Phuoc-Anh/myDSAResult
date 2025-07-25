#file [[Bảng băm]]

Ví dụ ta có một tập hợp chuỗi ***{ 'ab', 'cd', 'efg' }*** và ta muốn luu nó trong một bảng.
- **Bước 1**: Chúng ta đã biết Hàm băm dùng để tính giá trị trong tập hợp dữ liệu, dùng để tạo ra chỉ số để lấy dữ liệu từ tập hợp ra.
- **Bước 2**: Gán cho từng chữ cái với một số, ví dụ _a = 1_, _b = 2_,...
- **Bước 3**: Chuyển hết chữ cái sang số và cộng với nhau:
```
'ab' = 1 + 2 = 3
'cd' = 3 + 4 = 7
'efg' = 5 + 6 + 7 = 18
```
- **Bước 4**: Thừa nhận rằng ta có một bảng với kích thước là 7 để lưu trữ các chuỗi đó. Hàm băm bây giờ có công thức băm là `input / 7, lấy dư`.
- **Bước 5**: Băm
```
3 // 7 = 3
7 // 7 = 0
18 // 7 = 4
```
![[Bảng băm/IMG_3.png]]

---
**Bài trước**: [[Các thành phần của bảng băm]]
**Bài sau**: [[Cách hàm băm hoạt động]]