#file [[Cây B]]

- Mọi nút lá trong một **Cây B** đều có cùng cấp, có cùng chiều cao
- Mỗi khóa trong một nút của **Cây B** đều phải sắp sếp theo thứ tự tăng dần
- Trong **Cây B**, mọi nút không phải nút lá (trừ nút gốc **root**) nên có ít nhất $m  \div 2$ nút con.
- Mọi nút (trừ nút gốc **root**) đều phải có ít nhất $m \div 2 - 1$ khóa.
- Nếu nút **root** là một nút lá, nút đó sẽ không có nút con và có ít nhất $1$ khóa. Nếu nút **root** không phải là một nút lá, nút đó sẽ có ít nhất $2$ nút con và $m \div 2 - 1$ khóa.
- Một nút không phải nút lá có $m-1$ nên có $m$ nút con không phải là `nullptr` 

**Bài trước**: [[Cây B]]
**Bài sau**: [[Những điểm đặc biệt của cây B]]