#file [[Cấu trúc dữ liệu cây]]

## Lợi ích
---
- **Tìm kiếm Hiệu quả**: Cây thường hiệu quả cho việc tìm kiếm và xuất dữ liệu. Thời gian để tìm kiếm trên một cây là $O(log \space n)$ trong **AVL** và **Cây đỏ đen**. Tốt hơn Mảng và [[Danh sách liên kết]] nhưng không tốt bằng [[Bảng băm]].
- **Chèn và xóa nhanh**: Chèn và xáo nút trong Cây nhị phân tự cân bằng như **AVL** hay **Cây đỏ đen** có thể hoàn thành trong $O(n)$ thời gian. Cũng giống như tìm kiếm, tốt hơn Mảng và [[Danh sách liên kết]] nhưng không tốt bằng [[Bảng băm]].
- **Tổ chức tự nhiên**: Cây có tổ chức phân cấp tự nhiên có thể được sử dụng để đại diện cho những thứ như hệ thống tệp, cấu trúc tổ chức và phân loại.
- **Kích thước động**: Giống như [[Danh sách liên kết]]

## Bất lợi
---
- **Chi phí bộ nhớ**: Cây có thể yêu cấu lượng lớn bộ nhớ đáng kể để lưu trữ, đặc biệt nếu chúng rất lớn. Đây là vấn đề đối với ứng dụng có bộ tài nguyên hạn chế.
- **Cây không cân bằng**: Nếu một cây không cân bằng, nó có thể dẫn đến thời gian tìm kiếm không đồng đều. Đây là một vấn đề khi tốc độ là rất quan trọng.
- **Phức tạp**: Không giống như Mảng và [[Danh sách liên kết]], cây khó hiểu hơn và khiến việc thực hiện chúng trở nên khó chính xác. 
- Để thực hiện cấu trúc dữ liệu cây cần có kiến thức về Giải thuật cao.

---
**Bài trước**: [[Cây/Khai báo kiểu dữ liệu|Khai báo kiểu dữ liệu]]
**Bài sau**: [[Các thao tác cơ bản của cây]]