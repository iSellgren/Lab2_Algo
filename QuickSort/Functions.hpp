//
//  Algorithms.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-27.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
void printVec(std::vector<int> &data)
{
    for (int LeftPtr = 0; LeftPtr < data.size(); LeftPtr++)
    {
        std::cout << data[LeftPtr] << std::endl;
    }
}
//WHY DO I NEED TO DO THIS?????
//WHY CANT I YEETA Sorting_Algorithms::quickSort ??
// ASK SEMMEL
void quicksort(std::vector<int> &data)
{
    Sorting_Algorithms::quickSort(data.begin(),data.end());
}
void quicksortMedianof3(std::vector<int> &data)
{
    Sorting_Algorithms::recquickSort(data.begin(),data.end());
}
void insertionsort(std::vector<int> &data)
{
    Sorting_Algorithms::insertionSort(data.begin(),data.end());
}
void selectionsort(std::vector<int> &data)
{
    Sorting_Algorithms::selectionSort(data.begin(),data.end());
}
#endif /* Functions_hpp */
