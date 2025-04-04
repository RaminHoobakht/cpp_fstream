#ifndef HEADER_MAIN_CPP
#define HEADER_MAIN_CPP

#include <iostream>

#define NL '\n'
#define RT '\r'
#define SP '\x20'
#define LINEFEED std::cout << NL
#define SEP util::separator()

namespace util {
    constexpr size_t zero{0LU};

    void separator(size_t, char) noexcept;


    inline void separator(const size_t no = 64LU,
                          const char ch = '-') noexcept {
        for (size_t i{zero}; i < no; ++i) {
            std::cout << ch;
        }
        std::cout << NL;
    }

    /* -------------------------------------------------- */

    class publicexception final : public std::exception {
    private:
        std::string message_{};

    public:
        explicit publicexception(std::string message) :
            message_(std::move(message)) {}

        // publicexception(const exception &exception, std::string message) :
        //     std::exception(exception), message_(std::move(message)) {}

        // publicexception(exception &&exception, std::string message) :
        //     std::exception(exception), message_(std::move(message)) {}

        [[nodiscard]] const char *what() const noexcept override {
            return this->message_.c_str();
        }
    };
} // namespace util

#endif /* HEADER_MAIN_CPP */
