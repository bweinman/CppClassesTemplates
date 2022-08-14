// functor.cpp by Bill Weinman [bw.org]
// updated 2022-07-21
#include <format>
#include <iostream>

using std::format;
using std::cout;

class MultBy {
    int mult {};
public:
    MultBy (int n = 1) : mult(n) {}
    int operator () (int n) const { return mult * n; }
};

int main() {
    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);

    cout << format("times4(5) is {}\n", times4(5));
    cout << format("times4(15) is {}\n", times4(15));
    cout << format("times10(5) is {}\n", times10(5));
    cout << format("times10(15) is {}\n", times10(15));
    cout << format("times15(5) is {}\n", times15(5));
    cout << format("times15(15) is {}\n", times15(15));
}
