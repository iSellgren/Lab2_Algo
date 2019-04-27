//
//  Generate.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-27.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef Generate_hpp
#define Generate_hpp

#include <stdio.h>
#include <random>
#include <iostream>
static std::random_device rd;
static std::mt19937 mt (rd());
int gen(int lowBound,int highBound)
{
    static std::uniform_int_distribution<int> range(lowBound, highBound);
    return range(mt);
    
}
namespace Generate{
    template <typename Iter>
    void Random(Iter left, Iter right,int lowBound,int highBound)
    {


        for(int* LeftPtr = &*left; LeftPtr < &*right; LeftPtr++)
        {
            *LeftPtr = gen(lowBound,highBound);
        }
        
        
    }
}
namespace Generate{
    template <typename Iter>
    void Const(Iter left, Iter right,int Const)
    {
        
        
        for(int* LeftPtr = &*left; LeftPtr < &*right; LeftPtr++)
        {
            *LeftPtr = Const;
        }
        
        
    }
}
namespace Generate{
    template <typename Iter>
    void Increasing(Iter left, Iter right,int Const)
    {
        
        
        for(int* LeftPtr = &*left; LeftPtr < &*right; LeftPtr++)
        {
            *LeftPtr = Const;
            Const++;
        }
        
        
    }
}
namespace Generate{
    template <typename Iter>
    void Decreasing(Iter left, Iter right,int Const)
    {
        
        
        for(int* RightPtr = &*right-1; RightPtr >= &*left; RightPtr--)
        {
            *RightPtr = Const;
            Const++;
        }
        
        
    }
}
#endif /* Generate_hpp */
