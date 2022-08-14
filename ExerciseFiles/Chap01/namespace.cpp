// namespace.cpp by Bill Weinman [bw.org]
// as of 2022-07-20
#include <format>
#include <iostream>
#include <string>

namespace bw {
    const static std::string prefix = "(bw::string) ";
    
    class string {
        std::string _s {};
    public:
        string(const std::string& s) : _s {prefix + s} {}
        const char* c_str() const { return _s.c_str(); }
        operator std::string& () { return _s; }
        operator const char* () const { return _s.c_str(); }
    };
};  // namespace bw

int main() {
    const std::string s1 {"This is a string"};
    std::cout << std::format("{}\n", s1);
    
    const bw::string s2 {s1};
    std::cout << std::format("{}\n", s2);

    return 0;
}
