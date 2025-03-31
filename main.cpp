#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

int main() {
    std::ofstream file("task-7-2-1.txt");
    if (!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    for (int i = 1; i <= 1000; i++) {
        file << "Line " << i << "\n";
        file.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    file.close();
    return 0;
}
