//
//  OSSA.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-29.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef OSSA_hpp
#define OSSA_hpp

#include <stdio.h>
#include <iostream>
namespace Sorting_Algorithms{
    template <typename Iter>
    void OSSA(Iter left, Iter right)
    {
        for (Iter i = right, k = left; i > k; --i, ++k)
        {
            Iter small = k;
            Iter large = k;
            
            for(Iter j = k+1; j<=i; ++j)
            {
                
                if(*j > *large)
                    large = j;
                if(*j < *small)
                    small = j;
            }
            int tmp = *k;
            int LARGE = *large;
            int SMALL = *small;
            *large = *i;
            *small = tmp;
            
            
            
            
            if(large == k)
            {
                tmp = *i;
                *i = LARGE;
                *small = tmp;
            }
            else
            {
                *i = LARGE;
            }
            
            if(small == i)
            {
                tmp = *k;
                *k = SMALL;
                *large = tmp;
            }else
            {
                *k = SMALL;
            }
        }
        
    }
}

#endif /* OSSA_hpp */
