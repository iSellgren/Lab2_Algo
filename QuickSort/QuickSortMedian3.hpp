//
//  QuickSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef QuickSortMedian3_hpp
#define QuickSortMedian3_hpp

#include <stdio.h>
#include <iostream>
#include "InsertionSort.hpp"
    template <typename Iter>
Iter medianOfThree(Iter leftPtr, Iter rightPtr)
    {
        Iter midptr = (leftPtr +((rightPtr-leftPtr)/2));
        if (*rightPtr < *leftPtr)
        {
            std::swap(*rightPtr,*leftPtr);
            //std::cout << "swapping left, mid" << std::endl;
        }
        if(*midptr < *leftPtr)
        {
            std::swap(*midptr, *leftPtr);
            //std::cout << "swapping left, right" << std::endl;
        }
        if(*rightPtr < *midptr)
        {
            std::swap(*rightPtr, *midptr);
        }
        
        std::swap(*midptr, *(rightPtr-1));
        //std::cout << rightPtr <<" rightPTR after end median " << std::endl;
        return (rightPtr);
        
    }
    template <typename Iter>
Iter recpartitionSort(Iter left, Iter right, Iter Pivot)
    {
        Iter LeftPtr = (left-1);
        Iter RightPtr = right;
        int pivot = *Pivot;
        while(true)
        {
            while(*++LeftPtr < pivot);
            while(pivot < *--RightPtr) if(RightPtr == left) break;
            
            if(LeftPtr >= RightPtr)
                break;
            std::swap(*LeftPtr,*RightPtr);
            
        }
        std::swap(*LeftPtr,*right);
        return LeftPtr;
    }
namespace Sorting_Algorithms{
    template <typename Iter>
void recquickSort(Iter left, Iter right)
    {
        
        
        if(left + 10 < right)
        {
            Iter pivot = medianOfThree(left, right);
            Iter pivotElement = recpartitionSort(left, right, pivot);
            
            recquickSort(left , (pivotElement-1));
            recquickSort((pivotElement+1), right);
            
        }
        else
            Sorting_Algorithms::insertionSort(left, right);
    }
}
#endif /* QuickSort_hpp */
