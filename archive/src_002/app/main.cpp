#include "../header/main.hpp"
#include <fstream>
#include <ios>
#include <iostream>

int main() {

    constexpr size_t buff_size{1024LU};
    char read_buffer[buff_size]{};

    constexpr auto file_name{"temp_test.txt"};
    constexpr auto in_mode{std::ios::in};
    constexpr auto out_mode{std::ios::out};
    constexpr auto app_mode{std::ios::app};

    std::fstream fs{};

    fs.open(file_name, in_mode | out_mode | app_mode);
    if (!fs) {
        perror("error in open file");
        exit(EXIT_FAILURE);
    }

    fs << "I am a C/C++ Developer" << NL;

    if (fs.is_open()) {
        fs.close();
    }

    fs.open(file_name, in_mode | out_mode | app_mode);
    if (!fs) {
        perror("error in open file");
        exit(EXIT_FAILURE);
    }

    fs.read(read_buffer, buff_size - 1);

    if (fs.is_open()) {
        fs.close();
    }

    std::cout << "countent of file is: " << NL;
    std::cout << read_buffer << NL;
    SEP;

    std::cout << "\n #(23:40:04): The End ..." << std::endl;
    return EXIT_SUCCESS;
}
