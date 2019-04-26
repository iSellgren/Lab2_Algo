//
//  SelectionSort.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include "SelectionSort.hpp"
void selectionPort(int* left, int* right)
{
    std::cout << "SelectionPort" << std::endl;
    auto start = std::chrono::steady_clock::now();
    for(int *LeftPtr = left; LeftPtr < right; LeftPtr++)
    {
        int *min = LeftPtr;
        for(int* RightPtr = LeftPtr+1; RightPtr < right ; RightPtr++)
        {
            if(*RightPtr < *min)
                min = RightPtr;
        }
        
        if(min != LeftPtr)
            std::swap(*LeftPtr , *min);
    }
    
    auto end = std::chrono::steady_clock::now();
    float diff = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
    
    std::cout << diff << " sec " << std::endl;
}
