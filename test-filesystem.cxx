#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

int main() {
    std::string directoryPath = "path/to/directory";

    if (!fs::exists(directoryPath)) {
        if (fs::create_directories(directoryPath)) {
            std::cout << "Directory created successfully." << std::endl;
        } else {
            std::cout << "Failed to create directory." << std::endl;
        }
    } else {
        std::cout << "Directory already exists." << std::endl;
    }

    return 0;
}
