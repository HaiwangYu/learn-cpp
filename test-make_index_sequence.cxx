#include <iostream>
#include <utility>

template <size_t... Indices>
void printIndices(std::index_sequence<Indices...>)
{
    ((std::cout << Indices << ' '), ...);
}

int main()
{
    constexpr size_t N = 10;
    using Indices = std::make_index_sequence<N>;
    printIndices(Indices{});
    return 0;
}
