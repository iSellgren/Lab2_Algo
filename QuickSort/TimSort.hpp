//
//  TimSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-05-01.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef TimSort_hpp
#define TimSort_hpp

#include <stdio.h>
template<typename Iter>
void insertionSort(Iter left ,Iter right)
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
template<typename Iter, typename D = std::less<typename std::iterator_traits<Iter>::value_type>>
void merge(Iter left, Iter midIter, Iter right)
{
    std::vector<typename std::iterator_traits<I>::value_type> buffer;
    buffer.reserve(std::distance(begin, end));
    
    auto leftPtr  = left;
    auto rightPtr = midIter;
    D    diff;
    
    while(leftPtr != midIter && right != end)
    {
        buffer.push_back(std::move(diff(*leftPtr, *rightPtr) ? *leftPtr++: *rightPtr++));
    }
    std::move(leftPtr, midIter, std::back_inserter(buffer));
    std::move(rightPtr, right,    std::back_inserter(buffer));
    
    std::move(std::begin(buffer), std::end(buffer), begin);
}
#endif /* TimSort_hpp */
