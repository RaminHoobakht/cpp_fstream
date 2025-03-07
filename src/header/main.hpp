#ifndef HEADER_MAIN_CPP
#define HEADER_MAIN_CPP

#include <iostream>

#define NL '\n'
#define RT '\r'
#define SP '\x20'
#define LINE_FEED std::cout << NL
#define SEP util::separator()

namespace util {

    constexpr size_t zero{0LU};

    void separator(size_t, char) noexcept;


    inline void separator(const size_t no = 64, const char ch = '-') noexcept {
        for (size_t i{zero}; i < no; ++i) {
            std::cout << ch;
        }
        std::cout << NL;
    }


} // namespace util

#endif /* HEADER_MAIN_CPP */
