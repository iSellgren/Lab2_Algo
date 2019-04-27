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
namespace Sorting_Algorithms{
    template <typename Iter>
int* medianOfThree(Iter leftPtr, Iter rightPtr)
    {
        int* midptr = (&*leftPtr +((&*rightPtr-&*leftPtr)/2));
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
        return (&*rightPtr);
        
    }
}
namespace Sorting_Algorithms{
    template <typename Iter>
int* recpartitionSort(Iter left, Iter right, Iter Pivot)
    {
        
        int* LeftPtr = &*(left-1);
        int* RightPtr = &*right;
        
        int pivot = *Pivot;
        
        while(true)
        {
            while(*++LeftPtr < pivot);
            while(pivot < *--RightPtr) if(&*RightPtr == &*left) break;
            
            if(LeftPtr >= RightPtr)
                break;
            std::swap(*LeftPtr,*RightPtr);
            
        }
        std::swap(*LeftPtr,*&*right);
        return &*LeftPtr;
    }
}
namespace Sorting_Algorithms{
    template <typename Iter>
void recquickSort(Iter left, Iter right)
    {
        
        
        if(&*left + 3 <= &*right)
        {
            int *pivot = medianOfThree(&*left, &*right);
            int *pivotElement = recpartitionSort(&*left, &*right, pivot);
            
            recquickSort(&*left , (pivotElement-1));
            recquickSort((pivotElement+1), &*right);
            
        }
        else
            Sorting_Algorithms::insertionSort(left, right);
    }
}
#endif /* QuickSort_hpp */
