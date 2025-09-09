#file [[Cây Heap]]

- Phần tủ lớn nhất hoặc nhỏ nhất luôn luôn là gốc của Heap, cho phép truy cấp với thời gian hằng số
- Mối quan hệ giữa nút cha ở chỉ số **i** và nút con của nó được đưa ra với công thức: nút con trái ở chỉ số $2i+1$ và nút con phải ở chỉ số $2i+2$ để lập chỉ số dựa trên 0 cho số nút.
- Vì là cây nhị phân hoàn chỉnh, mọi cấp của cây đều được điền trừ cấp cuối cùng. Và cấp cuối cùng được điền từ trái sang phải
- Khi ta chèn một phần tử, ta chèn nó vào chỗ cuối cùng còn sót lại, sau đó sắp xếp lại để duy trình thuộc tính heap.
- Khi ta xóa một phần tử, ta hoán đổi vị trí của root với nút cuối cùng để chắc chắn là nút lớn nhất hoặc bé nhất sẽ được xóa. Sau đó sắp xếp lại vị trí để duy trì thuộc tính heap.

---
**Bài trước**: [[Cây Heap]]
**Bài sau**: [[Các thao tác hỗ trợ Cây Heap]]