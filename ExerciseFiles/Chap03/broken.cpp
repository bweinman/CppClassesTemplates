// broken.cpp by Bill Weinman [bw.org]
// updated 2022-08-11
#include <format>
#include <iostream>
#include <exception>

using std::format;
using std::cout;

void broken(int x) {
    if (x > 9) {
        throw std::range_error("ouch!");
    }
    cout << "woohoo!\n";
}

int main() {
    try {
        broken(47);
    } catch (std::range_error &e) {
        cout << format("range error: {}\n", e.exception::what());
    }
}
