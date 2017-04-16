#include <iostream>
#include <string>
#include <strstream>


int main(){
    std::strstream& x = (std::strstream &)std::cout;
    std::string str = "Hell\n";
    x.str() = "Hello";
    x << str.c_str();
    str.clear();
    return 0;
}
