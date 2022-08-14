// incr-decr.cpp by Bill Weinman [bw.org]
// as of 2022-08-10
#include <format>
#include <iostream>

using std::format;
using std::cout;

class num {
    int value {};
public:
    num(int x = 0) : value{x} {}
    int getvalue() const { return value; }
    void setvalue(int x) { value = x; }
    operator int () { return value; }
    num& operator++ ();
    num operator++ (int);
    num& operator-- ();
    num operator-- (int);
};


// pre-increment
num& num::operator++ () {
    cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment
num num::operator++ (int) {
    cout << "post-increment: ";
    auto temp = *this;
    value += 1;
    return temp;
}

// pre-decrement
num& num::operator-- () {
    cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement
num num::operator-- (int) {
    cout << "post-decrement: ";
    auto temp = *this;
    value -= 1;
    return temp;
}

// formatter specialization
template<>
struct std::formatter<num>: std::formatter<unsigned> {
    template<typename FormatContext>
    auto format(const num& o, FormatContext& ctx) {
        return format_to(ctx.out(), "{}", o.getvalue());
    }
};

int main() {
    num n(42);
    cout << format("value is: {}\n", n);
    cout << format("value is: {}\n", ++n);
    cout << format("value is: {}\n", n);

    return 0;
}
