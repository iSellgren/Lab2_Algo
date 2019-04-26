//
//  main.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <climits>
#include <functional>
#include <iterator>
#include <chrono>
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "QuickSortMedian3.hpp"

void printVec(std::vector<int> &data)
{
    for (int LeftPtr = 0; LeftPtr < data.size(); LeftPtr++)
    {
        std::cout << data[LeftPtr] << std::endl;
    }
}





int main(int argc, const char * argv[])
{
    int size = 10000000;
    std::vector<int> container(size);
    std::random_device rand;
    std::mt19937 mt {rand()};
    std::uniform_int_distribution<int> range{INT_MIN, INT_MAX};
    std::cout << "Sorting " << size <<" random elements whit range " << INT_MIN << " to " << INT_MAX << " This may take a while" << std::endl;
    auto gen = [&range, &mt]()
    {
        return range(mt);
    };
    
    std::generate(std::begin(container), std::end(container), gen);
    auto tmp = container;
    //printVec(container);
    for(int i = 0; i < 1; i++)
    {
        std::cout << "Sorting....." << std::endl;
        auto  start1 = std::chrono::steady_clock::now();
        

        auto end1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff1=(end1 - start1);
        std::cout << diff1.count() << " quickPort " << std::endl;
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            //std::cin.get();
        }
        container = tmp;
        std::cout << "Sorting....." << std::endl;
        auto  start = std::chrono::steady_clock::now();
        //selectionPort(&container.front(), &container.back()+1);
        Sorting_Algorithms::recquickPort(container.begin(), container.end());
        //recquickPort(&container.front(), &container.back());
        
        
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff=(end - start);
        std::cout << diff.count() << " Test " << std::endl;
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            //std::cin.get();
        }
        //printVec(container);

        
        
    }
    return 0;
}
