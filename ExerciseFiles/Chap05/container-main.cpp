// container-main.cpp by Bill Weinman [bw.org]
// updated 2022-07-25
#include <format>
#include <iostream>
#include <string>
#include "container.h"

using std::format;
using std::cout;

int main() {
    container<std::string> a {"one", "two", "three", "four", "five"};
    container<std::string> b {"five", "six", "seven"};

    cout << format("a: {}\n", a.str());
    cout << format("b: {}\n", b.str());
}
