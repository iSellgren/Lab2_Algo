//
//  InsertionSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef InsertionSort_hpp
#define InsertionSort_hpp
#include <iostream>
#include <stdio.h>
namespace Sorting_Algorithms{
template <typename Iter>
    void insertionPort(Iter left ,Iter right)
    {
        
         int *LeftPtr;
        for (LeftPtr = &*right; LeftPtr > &*left; LeftPtr--)
         if(*(LeftPtr-1) > *LeftPtr)
         {
         std::swap(*(LeftPtr-1),*LeftPtr);
         }
         
         for (int* LeftPtr = &*(left + 2); LeftPtr <= &*right; LeftPtr++)
         {
         int value = *LeftPtr;
         int* RightPtr = LeftPtr;
         
         while (RightPtr > &*left && *(RightPtr-1) > value)
         {
         *RightPtr = *(RightPtr - 1);
         RightPtr--;
         }
         *RightPtr = value;
         }
    }
}
#endif /* InsertionSort_hpp */
