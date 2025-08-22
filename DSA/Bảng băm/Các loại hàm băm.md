#file [[Bảng băm]] 

**Hàm băm** là một  khái niệm cơ bản trong Khoa học máy tính và đống vai trò quan trọng trong cấc ứng dụng khác nhau như lưu trữ dữ liệu, truy xuất và mật mã. Hàm băm ánh xạ từ khóa đầu vào đến chỉ mục trong bảng băm. Dưới đây là một vài ví dụ:
- **Số điện thoại như Khóa đầu vào**: Chọn một bảng băm có kích thước là 100. Một ví dụ cơ bản về hàm băm xem xét hai sao cuối cùng của số điện thoại để ta có các chỉ mục bảng băm hợp lệ làm đầu ra. Điều này chủ yếu lấy phần còn lại của số điện thoại nhập được và chia cho 100.
- **Chữ cái tiếng anh làm Khóa đầu vào**: Xem xét một bảng băm có kích thước là 100. Một cách đơn giản đề băm chuỗi thành số là thêm mã vào từng chữ cái, và lấy phần dư của tổng chia.

**Các lợi ích chính của hàm băm**:
- **Xác định**: Một hàm băm nhất quán phải tạo ra cùng một đầu ra cho cùng một đầu vào.
- **Đầu ra cố định**: Đầu ra của một hàm băm nên có một kích thước cố định, bất kể kích thước đầu vào.
- **Hiệu quả**: Một hàm băm nên có thể hoàn thành băm một đầu vào nhanh chóng.
- **Tính đồng nhất**: Hàm băm nên phân phối cấc giá trị băm đồng nhất trên không gian đầu ra để tránh phân cụm.
- **Kháng thước hình ảnh**: Không khả thi về mặt tính toán để đảo ngược hàm băm, tức là tìm đầu vào ban đầu giá trị băm.
- **Ít va chạm**: Nó nên khó có thể tìm thấy hai đầu vào khác nhau có chỉ mục giống nhau
- **Hiệu ứng tuyết lở**: Một thay đổi nhỏ trong đầu vào sẽ tạo ra một giá trị băm khác biệt đáng kể.

**Các loại hàm băm**:
1. Phương pháp Chia
2. Phương pháp Nhân
3. Phương pháp Bình phương lấy trung tâm
4. Phương pháp Gấp
5. Hàm băm mã hóa
6. Băm phổ quát
7. Băm hoàn hảo

## **Phương pháp Chia**
---
Phương pháp Chia: Chia khóa cho một số nguyên tố và sử dụng dư làm giấ trị sau khi băm
$$
h(k) = k \bmod m
$$
## **Phương pháp Nhân**
---
Trong phương pháp nhân, một hằng số $A(0 < A < 1)$ được sử dụng để nhân khóa.
$$
h(k) = [\space m (k \times A \bmod 1)\space]
$$
## **Phương pháp Bình phương lấy trung tâm**
---
Trong phương pháp bình phương lấy trung tâm, khóa sẽ được bình phương, và ký tự giữa kết quả sẽ được chọn làm giá trị sau khi băm

## **Phương pháp gấp**
---
Phương pháp gấp chia khóa thành nhiều phần bằng nhau, sau đó tổng các phần lại và lấy tổng của nó chia cho kích thước của bảng (hoặc một số nguyên tố)

## **Hàm mã hóa**
---
Hàm băm mã hóa được cấu tạo với mục đích an toàn và bảo mật, ví dụ **SHA-256**, **SHA-1**, **MD5**

## **Băm tổng quát**
---
Hàm tổng quát sử dụng một lượng lớn loại băm khác nhau để giảm thiểu sự va chạm cho mọi đầu vào
$$
h(k) = ((a \times k + b) \bmod p)\mod m
$$
## **Băm hoàn hảo**
---
Băm hoàn hảo sử dụng để **Không có loại va chạm nào có thể xảy ra**, nhược điểm là rất phức tạp

---
**Bài trước**: [[Cách hàm băm hoạt động]]
**Bài sau**: [[Va chạm trong băm]]