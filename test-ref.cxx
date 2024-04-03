#include <iostream>

struct Foo
{
    int value; // int member

    Foo(const int value) : value(value)
    {
        std::cout << "Foo ctor" << this << " value: " << value << std::endl;
    }

    ~Foo()
    {
        std::cout << "Foo dtor" << this << " value: " << value << std::endl;
    }

    // Move assignment operator
    Foo& operator=(Foo&& other)
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
    Foo& operator=(const Foo& other)
    {
        std::cout << "Copy assignment operator" << std::endl;
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }
};

void bar(Foo &foo)
{
    // foo = std::move(Foo{43});
    Foo tmp{43};
    foo = tmp;
    std::cout << "end of bar" << std::endl;
}

int main()
{
    Foo foo{42};
    bar(foo);
    /**
     * Output:
     * Foo ctor0x7fffffffe0a4 value: 42
     * Foo ctor0x7fffffffe084 value: 43
     * Foo dtor0x7fffffffe084 value: 43
     * end of bar
     * Foo dtor0x7fffffffe0a4 value: 43
     */

    return 0;
}
