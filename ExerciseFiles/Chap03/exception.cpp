// exception.cpp by Bill Weinman [bw.org]
// updated 2022-08-11
#include <format>
#include <iostream>
#include <exception>

using std::format;
using std::cout;

class Err : public std::exception {
    const char* msg {};
public:
    Err() = delete;
    Err(const char* s) : msg(s) {}
    const char* what() const noexcept { return msg; }
};

void broken(int x) {
    if(x > 9) {
        throw Err("ouch!");
    }
    cout << "woohoo!\n";
}

int main() {
    try {
        broken(47);
    } catch (Err& e) {
        cout << format("Error: {}\n", e.what());
    }
}
