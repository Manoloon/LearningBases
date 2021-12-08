//
// Created by Manoloon on 08/12/2021.
//

#ifndef LEARNINGBASES_CONTAINERS_H
#define LEARNINGBASES_CONTAINERS_H
#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>
namespace containers
{
    struct row{
        int key =0;
        std::string value;
    };
    std::vector<row> NewData={{1,"Hola"},{2,"You"}};
    void LookupTable(std::vector<row>data)
    {
        if(auto it = std::find_if(data.begin(),data.end(),
                                 [] (const auto &row)
                                 {
                                    return row.key == 2;
                                 });
                                 it != data.end())
                                 {
                                    assert(it->value == "you");
                                 }
    }

    /////// usando algoritmo de std en vez de for loop
    std::vector<float> Prices={3.4,4.3,10.1,201.5,100.3};
    bool FindPricePeak(std::vector<float>PriceList)
    {
       if( auto it = std::adjacent_find(PriceList.begin(),PriceList.end(),
                           [](auto p1,auto p2){return p2 -p1 > 5;});
                           it != PriceList.end())
                            {
                                std::cout << "The price have rise by period : " << std::distance(PriceList.begin(),
                                                                                         ++it)+1 << std::endl;
                                return true;
                            }
                            else
                            {
                                std::cout << "No significant change!" << std::endl;
                                return false;
                            }
    }
}

#endif //LEARNINGBASES_CONTAINERS_H
