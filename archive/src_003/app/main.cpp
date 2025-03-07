#include "../header/main.hpp"
#include <fstream>
#include <ios>
#include <iostream>

int main() {

    constexpr std::ios_base::openmode in_mode{std::ios::in};
    constexpr std::ios_base::openmode out_mode{std::ios::out};
    constexpr std::ios_base::openmode app_mode{std::ios::app};
    constexpr auto src_file_name{"source.txt"};
    constexpr auto des_file_naem{"destination.txt"};
    char ch{};

    std::fstream src{src_file_name, in_mode | out_mode | app_mode};
    std::fstream des{des_file_naem, in_mode | out_mode | app_mode};

    std::filebuf *in_buff{src.rdbuf()};
    std::filebuf *out_buff{des.rdbuf()};

    ch = static_cast<char>(in_buff->sbumpc());
    while (ch != EOF) {
        out_buff->sputc(ch);
        ch = static_cast<char>(in_buff->sbumpc());
    }

    if (src.is_open()) {
        src.close();
    }

    if (des.is_open()) {
        des.close();
    }

    std::cout << "\n #(06:57:50): The End ..." << std::endl;
    return EXIT_SUCCESS;
}
