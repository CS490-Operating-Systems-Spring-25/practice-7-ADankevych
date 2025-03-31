#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file1, file2;
    std::cout << "Enter first filename: ";
    std::cin >> file1;
    std::cout << "Enter second filename: ";
    std::cin >> file2;

    std::ifstream f1(file1), f2(file2);
    if (!f1 || !f2) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string line1, line2;
    int lineNum = 1;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            std::cout << "Difference at line " << lineNum << ":\n";
            std::cout << file1 << ": " << line1 << "\n";
            std::cout << file2 << ": " << line2 << "\n";
            return 0;
        }
        lineNum++;
    }

    if (f1.eof() != f2.eof()) {
        std::cout << "Files have different lengths.\n";
    } else {
        std::cout << "Files are identical.\n";
    }

    return 0;
}
