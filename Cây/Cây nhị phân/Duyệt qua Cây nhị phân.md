#file [[Cây nhị phân]]

## Depth First Search (DFS)
---
**Thuật toán Depth First Search (DFS)**: Khám phá càng xa càng tốt trong một nhánh cây trước khi quay lại _(Backtracking)_. Nó sử dụng đệ quy để thực hiện thao tác này. Các phương pháp duyệt chính trong DFS cho [[Cây nhị phân]] là:
- **Preoder Traversal (current - left - right) { Tạm dịch: Duyệt tiền tự (hiện tại - trái - phải) }**: Tới **nút** đầu trước, nút con bên trái, rồi đến nút con bên phải.
- **Inorder Traversal (left - current - right) { Tạm dịch: Duyệt trung tự (trái - hiện tại - phải) }**: Tới nút con bên trái trước, sau đó mới đến nút đầu rồi đến nút phải
- **Postorder Traversal (left - right - current) { Tạm dịch: Duyệt hậu tự (trái - phải - hiện tại) }:** Tới nút con bên trái trước, rồi đến bên phải và cuối cùng là nút đầu.

### Thực hiện thuật toán **Preorder Traversal** trong **DFS**
---
``` cpp

```