// variadic.cpp by Bill Weinman [bw.org]
// updated 2022-08-16
#include <format>
#include <iostream>
#include <cstdio>

using std::format;
using std::cout;

template<typename... Args>
constexpr void print(const std::string_view str_fmt, Args&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template<typename T>
void func(T final) {
    cout << format("{}\n", final);
}

template<typename T, typename... Args>
void func(T first, Args... args) {
    cout << format("{} ", first);
    func(args...);
}

int main() {
    func(1, 2, "three", "four", 5.0);
}
