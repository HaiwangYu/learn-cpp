#include <iostream>
#include <string>

// Function that takes an rvalue reference to a std::string
void processString_r(std::string&& s) {
    std::cout << "Processing rvalue: " << s << std::endl;
    // Modify the string to demonstrate that we have an actual reference
    s += " (modified)";
    std::cout << "Modified rvalue: " << s << std::endl;
}

void processString_l(std::string& s) {
    std::cout << "Processing lvalue: " << s << std::endl;
    // Modify the string to demonstrate that we have an actual reference
    s += " (modified)";
    std::cout << "Modified lvalue: " << s << std::endl;
}

std::string generateHello() {
    return "Hello";
}

int main() {
    processString_r(generateHello()); // OK

    // processString_l(generateHello()); // WRONG: initial value of reference to non-const must be an lvalueC/C++(461)
    std::string s = generateHello();
    processString_l(s); // OK
    std::cout << "Modified lvalue: " << s << std::endl;

    return 0;
}
