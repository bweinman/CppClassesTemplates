// variadic.cpp by Bill Weinman [bw.org]
// updated 2022-08-12
#include <format>
#include <cstdio>

constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

void func(const auto&... args) {
    (print("{} ", args), ...);
    print("\n");
}

int main() {
    func(1, 2, "three", "four", 5.0);
}
