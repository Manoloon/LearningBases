#include <iostream>
#include <vector>
#include "Src/moveSemantics.h"
int main()
{
    // auto
    auto a = 1;
    auto b =a+2;
    auto &&c =b;
    int *p;
    auto f=p;
    std::cout << b <<" " << c <<" " << p  <<" " << f << std::endl;

    Entity entity("Pablo");
    return 0;
}
