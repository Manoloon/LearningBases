#include <iostream>
#include <vector>
#include "Src/containers.h"



int main()
{
    std::vector<float> Prices={3.4,4.3,10.1,201.5,100.3};
    containers::FindPricePeak(Prices);
    return 0;
}
