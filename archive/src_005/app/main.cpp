#include "../header/main.hpp"
#include <fstream>
#include <iostream>
#include <exception>

int main() {
    /* code */

    char ch{};
    constexpr auto end_message{
        "content of the source.txt file copied "
        "to destination file successfully ..."
    };
    constexpr auto src_file_name{"source.txt"};
    constexpr auto des_file_name{"destination.txt"};
    constexpr std::ios_base::openmode in_mode{std::ios::in};
    constexpr std::ios_base::openmode out_mode{std::ios::out};
    constexpr std::ios_base::openmode app_mode{std::ios::app};
    constexpr std::ios_base::openmode ioa_mode{in_mode | out_mode | app_mode};
    std::fstream fs_src{};
    std::fstream fs_des{};

    fs_src.open(src_file_name, ioa_mode);
    if (!fs_src.is_open()) {
        throw util::fs_exception("error in open source.txt file");
    }

    fs_des.open(des_file_name, ioa_mode);
    if (!fs_des.is_open()) {
        throw util::fs_exception("error in open destination.txt file");
    }

    std::filebuf *src_buf{fs_src.rdbuf()};
    std::filebuf *des_buf{fs_des.rdbuf()};

    while ((ch = static_cast<char>(src_buf->sbumpc())) != EOF) {
        (void) des_buf->sputc(ch);
    }

    if (des_buf->is_open()) {
        (void) des_buf->close();
    }

    if (src_buf->is_open()) {
        (void) src_buf->close();
    }

    if (fs_des.is_open()) {
        fs_des.close();
    }

    if (fs_src.is_open()) {
        fs_src.close();
    }

    std::cout << end_message << NL;

    std::cout << "\n #(22:48:25): The End ..." << std::endl;
    return EXIT_SUCCESS;
}
