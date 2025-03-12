/* specifies size of the file ... */

#include "../header/main.hpp"
#include <fstream>
#include <iostream>
#include <memory>

int main() {

    constexpr auto file_name{"destination.txt"};
    constexpr auto in_mode{std::ios::in};
    constexpr auto out_mode{std::ios::out};
    constexpr auto app_mode{std::ios::app};
    constexpr auto mode{in_mode | out_mode | app_mode};

    std::fstream fs{file_name, mode};
    if (!fs.is_open()) {
        throw util::publicexception("error in open file ...");
    }

    std::filebuf *file_buffer{fs.rdbuf()};
    const std::streamsize s{file_buffer->in_avail()};
    const size_t ss{static_cast<size_t>(s)};
    std::unique_ptr<char[]> buffer{std::make_unique<char[]>(ss)};

    file_buffer->sgetn(buffer.get(), s);

    if (file_buffer->is_open()) {
        file_buffer->close();
    }

    if (fs.is_open()) {
        fs.close();
    }

    std::cout << "file countent is: " << NL;
    std::cout << buffer.get() << NL;
    buffer.release();

    std::cout << "\n #(00:07:31): The End ..." << std::endl;
    return EXIT_SUCCESS;
}
