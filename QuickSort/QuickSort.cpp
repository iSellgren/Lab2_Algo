//
//  QuickSort.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include "QuickSort.hpp"


int* partitionPort(int* left, int* right)
{
    int* LeftPtr = left-1;
    int* RightPtr = right;
    
    //int* pos = medianPort((right-1), left, (left + (right - left)/2));
    int pivot = *(right);
    
    //std::cout << pivot << std::endl;
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
void quickPort(int* left, int* right)
{
    
    int* pivot;
    
    if(left < right)
    {
        pivot = partitionPort(left, right);
        
        quickPort(left , pivot-1);
        quickPort(pivot+1, right);
        
    }
}
