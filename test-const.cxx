#include <set>
#include <memory>
#include <iostream>

struct Foo {
    int value;

    Foo(int val) : value(val) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }

    ~Foo() {
        std::cout << "Destructor called with value: " << value << std::endl;
    }
};

int test_pointer () {
    {
        const Foo* foo = new Foo(1);
        // foo->value = 2; // error: assignment of member 'Foo::value' in read-only object
        foo = new Foo(2); // no error, but memory leak
        std::cout << "const Foo* foo: " << foo->value << std::endl;
        delete foo;
    }

    {
        Foo* const foo = new Foo(1);
        foo->value = 2; // no error
        // foo = new Foo(2); // error: assignment of read-only location 'foo'
        std::cout << "Foo* const foo: " << foo->value << std::endl;
        delete foo;
    }

    {
        std::shared_ptr<const Foo> foo2 = std::make_shared<const Foo>(1);
        // foo2->value = 2; // error: assignment of member 'Foo::value' in read-only object
        foo2 = std::make_shared<const Foo>(2); // no error, no memory leak
        std::cout << "std::shared_ptr<const Foo>: " << foo2->value << std::endl;
    }

    return 0;
}

int test_set_of_pointers() {
    std::set<std::shared_ptr<const Foo>> mySet;

    // Add elements to the set
    mySet.insert(std::make_shared<Foo>(1));

    // Print out the elements in the set
    for (const auto& element : mySet) {
        // element->value = 2; // error: assignment of member 'Foo::value' in read-only object
        // element = std::make_shared<Foo>(2); // error: assignment of read-only location 'element'
        std::cout << "Value: " << element->value << std::endl;
    }

    std::set<const Foo*> mySet2;
    mySet2.insert(new Foo(10));

    for (const auto& element : mySet2) {
        // element->value = 20; // error: assignment of member 'Foo::value' in read-only object
        // element = new Foo(20); // error: assignment of read-only location 'element'
        std::cout << "std::set<const Foo*>: " << element->value << std::endl;
    }

    std::set<Foo*> mySet3;
    mySet3.insert(new Foo(100));
    for (const auto& element : mySet3) {
        element->value = 200; // no error
        // element = new Foo(200); // error: assignment of read-only location 'element'
        std::cout << "std::set<Foo*>: " << element->value << std::endl;
    }

    return 0;
}

int main() {
    test_pointer();
    test_set_of_pointers();
    return 0;
}
