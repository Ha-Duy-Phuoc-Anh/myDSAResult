#file [[Các kỹ thuật xử lí va chạm]]

Chuỗi riêng biệt là một kỹ thuật được sử dụng nhiều nhất trong việc xử lí va chạm của hàm băm.
Ý tưởng đằng sau chuỗi riêng biết là khai triển mảng dưới dạng danh sách liên kết được gọi là một chuỗi.
Ở đây, tất cả các phần tử băm vào cùng một chỉ mục khe cắm được chèn vào một danh sách được liên kết. Bây giờ, chúng ta có thể sử dụng một khóa K để tìm kiếm trong danh sách được liên kết chỉ bằng cách di chuyển tuyến tính. Nếu khóa nội tại cho bất kỳ mục nhập nào bằng K thì điều đó có nghĩa là chúng ta đã tìm thấy mục nhập của mình. Nếu chúng ta đã đến cuối danh sách được liên kết nhưng chúng ta vẫn chưa tìm thấy mục nhập của mình thì điều đó có nghĩa là mục đó không tồn tại. Do đó, kết luận là trong chuỗi riêng biệt, nếu hai phần tử khác nhau có cùng giá trị băm thì chúng ta lưu trữ cả hai phần tử trong cùng một danh sách liên kết lần lượt.

**Ví dụ**: Hãy xém xét một hàm băm với **Key mod 5** và các khóa là 12, 22, 15, 25

![[Bảng băm/VID_1.mp4|VID_1]]

> _Ở video trên nói về Chuỗi cơ bản, trong video tiếp theo, ta sẽ dùng **Chuỗi riêng biệt với băm lại**_

![[Bảng băm/VID_2.mp4|VID_2]]

---
**Bài trước**: [[Các kỹ thuật xử lí va chạm]]
**Bài sau**: [[Tạo bảng băm xử lí chuỗi riêng biệt]]