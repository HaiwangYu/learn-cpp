#include <memory>
#include <cassert>
#include <iostream>

struct Foo
{
    int value; // int member

    Foo(const int value) : value(value)
    {
        std::cout << "Foo ctor " << this << " value: " << value << std::endl;
    }

    ~Foo()
    {
        std::cout << "Foo dtor " << this << " value: " << value << std::endl;
    }

    // Move assignment operator
    Foo &operator=(Foo &&other)
    {
        std::cout << "Move assignment operator" << std::endl;
        if (this != &other)
        {
            value = other.value;
            other.value = 0;
        }
        return *this;
    }

    // Copy assignment operator
    Foo &operator=(const Foo &other)
    {
        std::cout << "Copy assignment operator" << std::endl;
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }
};

int main()
{
    auto *rptr = new Foo(42);
    std::unique_ptr<Foo> ptr2;
    {
        std::unique_ptr<Foo> ptr1(rptr);
        std::cout << "ptr1: " << ptr1.get() << std::endl;
        ptr2.reset(ptr1.release());
        std::cout << "rptr->value: " << rptr->value << std::endl;
        std::cout << "leaving inner scope" << std::endl;
    }
    std::cout << "rptr->value: " << rptr->value << std::endl;
    std::cout << "ptr2: " << ptr2.get() << std::endl;

    return 0;
}