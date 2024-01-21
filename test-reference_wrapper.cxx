#include <iostream>
#include <vector>
#include <functional> // std::reference_wrapper

class Foo {
public:
    Foo(int value) : value_(value) {
        std::cout << "Foo(" << value_ << ")" << std::endl;
    }
    Foo(const Foo& other) : value_(other.value_) {
        std::cout << "Foo(const Foo& " << other.value_ << ")" << std::endl;
    }
    // move constructor
    Foo(Foo&& other) : value_(other.value_) {
        std::cout << "Foo(Foo&& " << other.value_ << ")" << std::endl;
    }
    int value_;
};

int main() {

    Foo foo1(1);
    Foo foo2(2);
    Foo foo3(3);
    std::cout << "Foo's created" << std::endl; // "Foo's created

    std::vector<Foo> fooVector;
    std::cout << "Foo vector created" << std::endl;
    fooVector.push_back(foo1);
    std::cout << "foo1 pushed back" << std::endl;
    fooVector.push_back(foo2);
    std::cout << "foo2 pushed back" << std::endl;
    fooVector.push_back(foo3);
    std::cout << "foo3 pushed back" << std::endl;

    fooVector[0].value_ = 10;
    std::cout << foo1.value_ << std::endl; // 1

    std::cout << "---------------------" << std::endl;
    /// use std::reference_wrapper
    std::vector<std::reference_wrapper<Foo>> fooVector2;
    // push bask foo's
    fooVector2.push_back(foo1);
    fooVector2.push_back(foo2);
    fooVector2.push_back(foo3);
    // change foo1 value
    fooVector2[0].get().value_ = 10;
    std::cout << foo1.value_ << std::endl; // 10

    return 0;
}
