

#include <iostream>
#include <memory>

class Foo {
public:
    int value;

    Foo(int val) : value(val) {
        std::cout << "Constructor called " << value << std::endl;
    }

    ~Foo() {
        std::cout << "Destructor called " << value << std::endl;
    }
};

void print_Foo(std::unique_ptr<Foo>& ptr) {
    std::unique_ptr<Foo> tmp(new Foo(100));
    ptr = std::move(tmp);
    std::cout << "print_Foo " << ptr->value << std::endl;
}

int main() {
    auto* ptr = new Foo(42);

    std::unique_ptr<Foo> uptr1(ptr);
    std::cout << "uptr1 value: " << uptr1->value << std::endl;
    {
        std::unique_ptr<Foo> uptr2(ptr);
        std::cout << "uptr2 value: before " << uptr2->value << std::endl;
        print_Foo(uptr2);
        std::cout << "uptr2 value: after " << uptr2->value << std::endl;
    }
    std::cout << "uptr1 value: " << uptr1->value << std::endl;

    return 0;
}
