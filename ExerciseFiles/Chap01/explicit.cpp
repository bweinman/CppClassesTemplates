// explicit.cpp by Bill Weinman [bw.org]
// as of 2022-08-09
#include <format>
#include <iostream>

using std::format;
using std::cout;

class C1 {
    int _value;
public:
    C1 (const int& i) : _value(i) {}
    C1& operator=(const C1& rhs) { _value = rhs._value; return *this; }
    void setvalue(const int& v) { _value = v; }
    int getvalue() const { return _value; }
};

void func(const C1& o) {
    printf("value is %d\n", o.getvalue());
}

int main() {
    C1 o {47};
    cout << format("value is {}\n", o.getvalue());
    o = 73;
    cout << format("value is {}\n", o.getvalue());
    func('x');
    return 0;
}
