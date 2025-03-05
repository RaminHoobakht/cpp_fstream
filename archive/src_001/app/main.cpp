#include "../header/main.hpp"
#include <fstream>
#include <iostream>

int main() {

    constexpr size_t times{10LU};
    std::fstream fs{};

    fs.open("text.txt",
            std::fstream::in | std::fstream::out | std::fstream::app);
    if (!fs) {
        perror("error in open file");
        SEP;
        exit(EXIT_FAILURE);
    }

    for (size_t i{util::zero}; i < times; ++i) {
        fs << i + 1 << " - I am a C/C++ Developer ..." << NL;
    }

    if (fs.is_open()) {
        fs.close();
    }

    std::cout << "file was created and closed ..." << NL;
    SEP;

    std::cout << "\n #(02:28:54): The End ..." << std::endl;
    return (EXIT_SUCCESS);
}
