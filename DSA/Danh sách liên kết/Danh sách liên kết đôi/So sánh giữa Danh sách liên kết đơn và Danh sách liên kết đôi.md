#file **Chủ đề**: [[Danh sách liên kết đôi]]
## Lợi thế của Danh sách liên kết đôi
---
- Dễ dàng di chuyển lên trước, về sau
- Dễ dành hơn trong việc xóa và chèn
- Sử dụng cho ngăn xếp và hàng đợi
## Bất lợi của Danh sách liên kết đôi
---
- Phức tạp hơn danh sách liên kết đơn vì có thể con trỏ **PREV**
- Tốn thêm 8 byte cho con trỏ **PREV**, nghĩa là một nút sẽ tốn khoảng: $pointer + int + pointer = 8 + 4 + 8 = 20 \space bytes$, hơn Danh sách liên kết đơn 8 bytes