//
//  QuickSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp
#include <iostream>
#include <stdio.h>
namespace Sorting_Algorithms{
    template <typename Iter>
    int* partitionPort(Iter left, Iter right)
    {
        int* LeftPtr = &*(left-1);
        int* RightPtr = &*right;
        
        int pivot = *(right);
        
        while(true)
        {
            while(*++LeftPtr < pivot);
            while(pivot < *--RightPtr) if(RightPtr == &*left) break;
            
            if(LeftPtr >= RightPtr)
                break;
            std::swap(*LeftPtr,*RightPtr);
            
        }
        std::swap(*LeftPtr,*right);
        return LeftPtr;
    }
}
namespace Sorting_Algorithms{
    template <typename Iter>
    void quickPort(Iter left, Iter right)
    {
        
        int* pivot;
        
        if(left < right)
        {
            pivot = partitionPort(&*left, &*right);
            
            quickPort(&*left , &*pivot-1);
            quickPort(&*pivot+1, &*right);
            
        }
    }
}
#endif /* QuickSort_hpp */
