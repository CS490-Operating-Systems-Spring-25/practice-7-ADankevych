#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

int main() {
    std::vector<std::ofstream> files;

    for (int i = 0; i < 100000; i++) {
        std::string filename = "file_" + std::to_string(i + 1) + ".txt";
        files.emplace_back(filename);

        if (!files.back()) {
            std::cerr << "Failed to open " << filename << " at iteration " << i + 1 << "\n";
            break;
        }

        if ((i + 1) % 1000 == 0) {
            std::cout << "Opened " << i + 1 << " files\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    std::cout << "Press Enter to exit...\n";
    std::cin.get();
    return 0;
}
