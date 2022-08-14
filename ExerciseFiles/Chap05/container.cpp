// container.cpp by Bill Weinman [bw.org]
// updated 2022-08-07
#include "container.h"

// copy/swap operator
template<typename T>
container<T>& container<T>::operator = (container rhs) {
    swap(rhs);
    return *this;
}

template<typename T>
void container<T>::swap(container& o) {
    std::swap(things, o.things);
}

template<typename T>
container<T>::~container() {
    reset();
}

template<typename T>
void container<T>::reset() {
    things.clear();
}

template<typename T>
std::string container<T>::str() const {
    std::string out {};
    if(things.empty()) return "[empty]";
    for(auto i : things) {
        if(out.size()) out += ':';
        out += format("{}", i);
    }
    return out;
}

