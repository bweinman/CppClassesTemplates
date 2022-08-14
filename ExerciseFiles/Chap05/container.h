// container.h by Bill Weinman [bw.org]
// updated 2022-08-07
#ifndef _CONTAINER
#define _CONTAINER

#include <string>
#include <vector>
#include <initializer_list>

template<typename T>
class container {
    std::vector<T> things {};
public:
    container() {}  // default ctor
    container(std::initializer_list<T> il) : things {il.begin(), il.end()} {}
    container(const container& rhs) : things {rhs.things} {}
    container(container&& rhs) noexcept : things {std::move(rhs.things)} {}
    container<T>& operator = (container<T> rhs);    // copy/swap
    void swap(container& o);
    ~container();
    void reset();
    std::string str() const;
};

#endif // _CONTAINER
