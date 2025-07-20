#file **Chủ đề**: [[Danh sách liên kết vòng tròn]]
## Cách khởi tạo
---
> _Về cách khởi tạo kiểu dữ liệu này thì cũng không cần phải nhắc đến nữa, vì ta có thể dùng cách khởi tạo của Danh sách liên kết đơn_

## Sử dụng
---
> _Như bạn đã biết là nút cuối sẽ trỏ đến nút đầu tiên nên chỉ cần dùng `last->next = first;` là xong!_
#### C++
---
``` cpp
Node* first = new Node(1);
Node* second = new Node(2);
Node* third = new Node(3);

first->next = second;
second->next = third;
third->next = first;
```
#### Python
---
``` python
first: Node = Node(1)
second: Node = Node(2)
third: Node = Node(3)

first.next = second
second.next = third
third.next = first
```
---
**Bài trước**: [[Danh sách liên kết vòng tròn]]
**Bài sau**: [[Chèn nút trong Danh sách liên kết vòng tròn]]