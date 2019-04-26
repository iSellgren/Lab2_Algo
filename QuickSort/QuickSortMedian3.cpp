//
//  QuickSort.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include "QuickSortMedian3.hpp"
#include "InsertionSort.hpp"
int* medianPort(int* leftPtr, int* rightPtr)
{
    int* midptr = leftPtr +((rightPtr-leftPtr)/2);
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
int* recpartitionPort(int* left, int* right, int* Pivot)
{
    
    int* LeftPtr = left-1;
    int* RightPtr = right;
    
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
void recquickPort(int* left, int* right)
{
    
    
    if(left + 3 <= right)
    {
        int *pivot = medianPort(left, right);
        int *pivotElement = recpartitionPort(left, right, pivot);
        
        recquickPort(left , pivotElement-1);
        recquickPort(pivotElement+1, right);
        
    }
    else
        insertionPort(left, right);
}
