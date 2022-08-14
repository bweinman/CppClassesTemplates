// template-variable.cpp by Bill Weinman [bw.org]
// upated 2022-08-12
#include <format>
#include <iostream>

using std::format;
using std::cout;

// 𝜋 is roughly 3.14159265358979323846
template<typename T>
constexpr T pi {245850922.0L / 78256779.0L};

int main() {
    cout << format("{:20.20}\n", pi<double>);
}
