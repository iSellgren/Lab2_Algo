//
//  main.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "QuickSortMedian3.hpp"
#include "Generate.hpp"
#include "TimeMeasuring.hpp"
#include "Functions.hpp"



int main(int argc, const char * argv[])
{
    //int size = 100000;
    //std::vector<int> container(size);
    float test = 0;
    //std::cout << "Sorting " << size <<" random elements whit range " << INT_MIN << " to " << INT_MAX << " This may take a while" << std::endl;

    //Generate::Random(container.begin(), container.end(), INT_MIN,INT_MAX);
    //Generate::Increasing(container.begin(), container.end(), 9);
    //printVec(container);
    
    test = RandomAvgTime(selectionsort, 10,INT_MIN,INT_MAX,10);
    
    
    //auto tmp = container;
    //printVec(container);
    for(int i = 0; i < 1; i++)
    {
        std::cout << "Sorting....." << std::endl;
        
        
        //container = tmp;
        
        
        //Sorting_Algorithms::insertionSort(container.begin(), container.end());

        /*
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            //std::cin.get();
            
            
        }
         */
        //container = tmp;
        //std::cout << "Sorting....." << std::endl;
        //selectionPort(&container.front(), &container.back()+1);
        //auto start = std::chrono::steady_clock::now();
        //Sorting_Algorithms::selectionSort(container.begin(), container.end());
        //recquickPort(&container.front(), &container.back());
        //printVec(container);
        //auto end = std::chrono::steady_clock::now();
        //std::chrono::duration<float,std::milli> duration = end - start;
        std::cout << test <<" NEW "<<  std::endl;
        //std::cout << duration.count() <<" OLDIE "<<  std::endl;
       /*
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            std::cin.get();
        }
        //printVec(container);

        
     */
    }
    return 0;
}
