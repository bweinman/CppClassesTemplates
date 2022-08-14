// vector-test.cpp by Bill Weinman [bw.org]
// version of 2022-08-11
#include <format>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::format;
using std::cout;
using std::string;
using std::vector;

void disp_t(auto& v, const string& label = "") {
    if (!label.empty()) cout << format("{}: ", label);
    if (v.empty()) cout << "[empty]";
    else for (auto& s : v) cout << format("{} ", s);
    cout << '\n';
}

template <typename T>
void swap(T & a, T & b) {
    cout << "::swap\n";
    T _tmp(std::move(a));
    a = std::move(b);
    b = std::move(_tmp);
}

int main() {
    vector<string> v1 = { "one", "two", "three", "four", "five" };
    vector<string> v2 = { "six", "seven", "eight", "nine", "ten" };

    disp_t(v1, "v1");
    disp_t(v2, "v2");
}
