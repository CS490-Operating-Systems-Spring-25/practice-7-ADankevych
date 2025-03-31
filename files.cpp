#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::vector<std::ofstream> files;

    for (int i = 0; i < 100; i++) {
        std::string filename = "file_" + std::to_string(i+1) + ".txt";
        files.emplace_back(filename);

        if (!files.back()) {
            std::cerr << "Failed to open " << filename << "\n";
            break;
        }
        std::cout << "Opened: " << filename << "\n";
    }

    std::cout << "Press Enter to exit...\n";
    std::cin.get();
    return 0;
}
