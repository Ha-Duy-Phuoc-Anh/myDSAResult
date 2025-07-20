#file **Chủ đề**: [[Giới thiệu về danh sách liên kết]]

| Mảng                                                                                        | Danh sách liên kết                                                         |
| ------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Dữ liệu trong mảng được lưu ở vị trí liền kề nhau.                                          | Dữ liệu trong danh sách liên kết không được lưu ở vị trí liền kề nhau.     |
| Kích thước cố định (Mảng dữ liệu động cũng gián tiếp sử dụng kích thước cố định)            | Kích thước động                                                            |
| Chỉ lưu dữ liệu, không chứa con trỏ hoặc địa chỉ tham chiếu                                 | Lưu trữ cả dữ liệu và con trỏ                                              |
| Các phần tử có thể dễ dàng tiếp cận với thời gian là $O(1)$                                 | Phần tử được tiếp cận bằng cách duyệt tứng nút cho tới khi đúng phần tử đó |
| Chèn và xóa chậm hơn Danh sách liên kết (vì còn phải sắp xếp lại vị trí sau khi hoàn thành) | Chèn và xóa nhanh hơn Mảng (vì chỉ cần nối con trỏ tới nút)                |

---
**Bài trước**: [[Các thao tác của Danh sách liên kết vòng tròn]]
**Bài sau**: [[Phân tích thời gian của các thao tác trong Danh sách liên kết và Mảng]]