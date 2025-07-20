#file [[Ngăn xếp]]

> _C++ STL đã có sẵn hàm built-in cho STACK, thư viện của nó tên là `<stack>`_
## Khai báo `<stack>` 
---
> `stack<type> name`
> `type` gồm các loại Data type của C++_
> `name` là tên của STACK
## Mẫu FULL Code + Code test
---
``` cpp
#include <iostream>
#include <stack>

void print(std::stack<int> stack) {
    std::stack<int> tmp(stack);
    while (!tmp.empty()) {
        std::cout << tmp.top() << " ";
        tmp.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Khởi tạo stack
    std::stack<int> stack;

    // Thêm dữ liệu vào stack
    stack.push(23);
    stack.push(43);
    stack.push(29);
    stack.push(44);
    stack.push(67);

    std::cout << "New Stack: "; 
    print(stack);

    // Xóa dữ liệu khỏi stack
    stack.pop();
    stack.pop();
    stack.pop();

    // Trả về TOP
    std::cout << "The TOP element: " << stack.top() << std::endl;

    // Print lại Danh sách
    std::cout << "After delete: ";
    print(stack); 

    // Thêm nút bằng emplace và print danh sách
    stack.emplace(23);
    stack.emplace(87);
    std::cout << "After emplace: ";
    print(stack);

    // Trả về kích thước Danh sách
    std::cout << "The size: " << stack.size() << std::endl;

    // Xóa hết phần tử và kiểm tra rỗng
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    std::cout << (stack.empty() ? "TRUE" : "FALSE") << std::endl;

    return 0;
}
```
## Giải thích về `stack.emplace`
---
> _Không giống như `stack.push`, `stack.emplace` cho phép thêm phần tử vào dữ liệu trực tiếp mà không cần phải tạo trước, điều này đặc biệt hữu ích khi sử dụng class trong Stack_