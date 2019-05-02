//
//  MergeSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-30.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <iostream>
#include <iterator>
#include <vector>
template<typename D, typename Iter, typename Iter2>
void merge(Iter left, Iter midIter, Iter right, Iter2 tmp)
{
    auto save  = tmp;
    auto leftPtr  = left;
    auto rightPtr = midIter;
    D    diff;
    
    while(leftPtr != midIter && rightPtr != right)
    {
        *tmp = std::move(diff(*leftPtr, *rightPtr) ? *leftPtr++: *rightPtr++);
        ++tmp;
    }
    tmp = std::move(leftPtr, midIter, tmp);
    tmp = std::move(rightPtr, right, tmp);
    
    std::move(save, tmp, left);
}

template<typename Iter, typename Iter2, typename D = std::less<typename std::iterator_traits<Iter>::value_type>>
void MergeSort(Iter left, Iter right, Iter2 tmpBegin)
{
    auto size = std::distance(left, right);
    if (size < 2)
    {
        return;
    }
    auto mid = size/2;
    auto midIter = left;
    auto midBuf  = tmpBegin;
    std::advance(midIter, mid);
    std::advance(midBuf, mid);
    
    MergeSort(left, midIter, tmpBegin);
    MergeSort(midIter, right, midBuf);
    
    merge<D>(left, midIter, right, tmpBegin);
}
namespace Sorting_Algorithms{
template<typename Iter, typename D = std::less<typename std::iterator_traits<Iter>::value_type>>
void mergeSort(Iter left, Iter right)
    {
        std::vector<typename std::iterator_traits<Iter>::value_type> buffer;
        buffer.resize(std::distance(left, right));
        
        MergeSort(left, right, std::begin(buffer));
    }
}
#endif /* MergeSort_hpp */
