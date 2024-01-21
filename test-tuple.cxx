#include <iostream>
#include <tuple>
#include <typeinfo>

// Base case: empty tuple
template <int Idx = 0, typename... Tp>
inline typename std::enable_if<Idx == sizeof...(Tp), void>::type
print_tuple(std::ostream& out, const std::tuple<Tp...>& t) {}

// Recursive case
template <int Idx = 0, typename... Tp>
inline typename std::enable_if<Idx < sizeof...(Tp), void>::type
print_tuple(std::ostream& out, const std::tuple<Tp...>& t) {
    out << typeid(std::get<Idx>(t)).name();
    if (Idx + 1 != sizeof...(Tp)) {
        out << ", ";
    }
    print_tuple<Idx + 1, Tp...>(out, t);
}

// Overload operator<< for std::tuple
template <typename... Tp>
std::ostream& operator<<(std::ostream& out, const std::tuple<Tp...>& t) {
    out << "(";
    print_tuple(out, t);
    out << ")";
    return out;
}

int main() {
    std::tuple<int, std::string, float> InputTuple = std::make_tuple(1, "Hello", 3.14);
    std::cout << InputTuple << std::endl;
    return 0;
}