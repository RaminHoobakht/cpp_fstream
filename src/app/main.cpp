#include "../header/main.hpp"
#include <fstream>
#include <ios>
#include <iostream>

int main() {

    char ch{};
    constexpr char const *const src_file_name{"source.txt"};
    constexpr char const *const des_file_name{"destination.txt"};
    constexpr std::ios_base::openmode in_mode{std::ios::in};
    constexpr std::ios_base::openmode out_mode{std::ios::out};
    constexpr std::ios_base::openmode app_mode{std::ios::app};
    std::fstream fs_src{};
    std::fstream fs_des{};

    fs_src.open(src_file_name, in_mode | out_mode | app_mode);
    if (!fs_src.is_open()) {
        perror("error in open source file");
        exit(EXIT_FAILURE);
    }

    fs_des.open(des_file_name, in_mode | out_mode | app_mode);
    if (!fs_des.is_open()) {
        perror("error in open destination file");
        exit(EXIT_FAILURE);
    }

    std::filebuf *src_filebuf{fs_src.rdbuf()};
    std::filebuf *des_filebuf{fs_des.rdbuf()};

    ch = static_cast<char>(src_filebuf->sbumpc());
    while (ch != EOF) {
        des_filebuf->sputc(ch);
        ch = static_cast<char>(src_filebuf->sbumpc());
    }

    if (src_filebuf->is_open()) {
        src_filebuf->close();
    }

    if (des_filebuf->is_open()) {
        des_filebuf->close();
    }

    if (fs_src.is_open()) {
        fs_src.close();
    }

    if (fs_des.is_open()) {
        fs_des.close();
    }

    std::cout << "file copy operation was over successfully ..." << NL;

    std::cout << "\n #(08:10:58): The End ..." << std::endl;
    return EXIT_SUCCESS;
}
