#include "Rope.h"

int main() {
    std::string str = "Hello world!!";
    std::string other = "Hovsep";
    Rope r(str);
    r.insert(5,other);
    r.insert(6,other);
    r.insert(7,other);
    r.insert(13,other);
    r.insert(55,str);
}