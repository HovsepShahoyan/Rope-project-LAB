#include "Rope.h"

int main(){
Rope rp ;
Rope rp1;
rp1.insert("Wor");
rp1.insert("l");
rp1.insert("d");
rp.insert("Hel");
rp.insert("lo");
rp.insert("!");
std::cout << rp.Index(4);
std::cout << rp.concat(rp1,rp).Index(4);
}