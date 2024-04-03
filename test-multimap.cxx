#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultimap;

    // Inserting elements into the multimap
    myMultimap.insert({1, "Apple"});
    myMultimap.insert(std::make_pair(1, "Apple"));
    myMultimap.insert(std::make_pair(2, "Apple"));
    myMultimap.insert(std::make_pair(2, "Banana"));
    // myMultimap[3] = "Apple"; // Error: operator[] not supported by multimap
    myMultimap.emplace(3, "Apple");
    myMultimap.emplace(3, "Apple");

    // Accessing elements in the multimap
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // Output:
    // 1: Apple
    // 1: Apple
    // 2: Apple
    // 2: Banana
    // 3: Apple
    // 3: Apple

    // Finding elements in the multimap
    auto it = myMultimap.find(2);
    if (it != myMultimap.end()) {
        std::cout << "Found: " << it->first << ": " << it->second << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    // Output:
    // Found: 2: Apple

    return 0;
}
