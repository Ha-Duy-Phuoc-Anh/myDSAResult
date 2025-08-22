#file [[Bảng băm]]

- Cấu trúc dữ liệu được sử dụng nhiều nhất sau **Mảng**.
- Hỗ trợ tìm kiếm, chèn, xóa với $O(1)$ trong trung bình mọi trường hợp. Tốt hơn so với **Mảng**, [[Danh sách liên kết]] và **Cây nhị phân tự cân bằng**.
- Chúng ta sử dụng Băm cho từ điển, đếm thường xuyên, hỗ trợ dữ liệu cho việc lấy dữ liệu nhanh bằng khóa.
- Ứng dụng thức tế gồm mã hóa, Caches, Từ điển, bảng,...
- Gồm hai loại bảng băm:
	- **Bộ băm**: Bộ sưu tầm khóa duy nhất (`Set` trong Python, `unordered_set` trong C++, `HashSet` trong Java)
	- **Bản đồ băm**: Bộ sưu tầm đôi khóa và dữ liệu (`Dict` trong Python, `unordered_map` trong C++, `HashMap` trong Java)

## Trường hợp Băm không được sử dụng
---
- Cần hỗ trợ dữ liệu được sắp xếp, xóa, và chèn. Trong trường hợp này nên dùng **Cây nhị phân tự cân bằng**
- Khi Chuỗi là khóa và chúng ta cần các thao tác như tìm kiếm, chèn, xóa. Ta nên dùng **Cây** trong trường hợp này
- Khi chúng ta cần các thao tác như floor và ceil cùng với tìm kiếm, chèn hoặc xóa. Ta nên dùng **Cây nhị phân tự cân bằng**.
---
**Bài trước**: [[Bảng băm]]
**Bài sau**: [[Các thành phần của bảng băm]]