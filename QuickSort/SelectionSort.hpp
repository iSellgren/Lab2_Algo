//
//  SelectionSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp

#include <stdio.h>
#include <iostream>
namespace Sorting_Algorithms{
    template <typename Iter>
void selectionPort(Iter left, Iter right)
    {
        for(int *LeftPtr = &*left; LeftPtr < &*right; LeftPtr++)
        {
            int *min = LeftPtr;
            for(int* RightPtr = LeftPtr+1; RightPtr < &*right ; RightPtr++)
            {
                if(*RightPtr < *min)
                    min = RightPtr;
            }
            
            if(min != LeftPtr)
                std::swap(*LeftPtr , *min);
        }
        
    }
}

#endif /* SelectionSort_hpp */
