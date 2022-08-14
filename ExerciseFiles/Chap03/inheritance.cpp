// inheritance.cpp by Bill Weinman [bw.org]
// updated 2022-08-11
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;
using std::string;

struct identifiers {
    string name {};
    string type {};
    string sound {};
};

struct action {
    string verb {};
    string verb_pt {};
};

// Base class
class animal {
    identifiers id {};
    action action {};
protected:
    // protected constructor for use by derived classes
    animal ( const string & n, const string & t, const string & s, const string& v, const string& vpt )
    : id {n, t, s}, action {v, vpt} {}
public:
    animal() = delete;    // deleted constructor prevents construction of base class
    void speak() const;
    const string& name() const { return id.name; }
    const string& type() const { return id.type; }
    const string& sound() const { return id.sound; }
    const string& verb() const { return action.verb; }
    const string& verb_pt() const { return action.verb_pt; }
};

void animal::speak() const {
    cout << format("{} the {} says {}\n", name(), type(), sound());
}

// dog class - derived from animal
class dog : public animal {
    int walk_count {};
public:
    dog( string n ) : animal(n, "dog", "woof", "walk", "walked") {};
    int walk() { return ++walk_count; }
};

// cat class - derived from animal
class cat : public animal {
    int pet_count {};
public:
    cat( string n ) : animal(n, "cat", "meow", "pet", "petted") {};
    int pet() { return ++pet_count; }
};

// pig class - derived from animal
class pig : public animal {
    int feed_count {};
public:
    pig( string n) : animal(n, "pig", "oink", "feed", "fed") {};
    int feed() { return ++feed_count; }
};

int main() {
    dog d("Rover");
    cat c("Fluffy");
    pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    cout << format("{} the {} has been {} {} times\n", d.name(), d.type(), d.verb_pt(), d.walk());
    cout << format("{} the {} has been {} {} times\n", c.name(), c.type(), c.verb_pt(), c.pet());
    cout << format("{} the {} has been {} {} times\n", p.name(), p.type(), p.verb_pt(), p.feed());
}
