//
//  TimeMeasuring.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-27.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef TimeMeasuring_hpp
#define TimeMeasuring_hpp

#include <stdio.h>
#include <iostream>
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "QuickSortMedian3.hpp"
template <typename Iter>
float StdDiv(Iter left, Iter right)
{
    float N = std::distance(left, right);
    float const mean = std::accumulate(left, right, float{}) / N;
    ;
    
    float accum = 0.0;
    std::for_each (left, right, [&](const double d) {
        accum += (d - mean) * (d - mean);
    });
    float variance = accum / N;
    float stdev = sqrt(variance);
    std::cout << stdev << std::endl;
    std::cout << variance << std::endl;
    std::cout << mean << std::endl;
    
    return mean;
}

template <typename T, class Function>
float RandomAvgTime(Function func,T size, T lowBound, T highBound,T times)
    {
        std::vector<float> values;
        std::vector<int> container(size);
        for(int i = 0; i < times; i++)
        {
            Generate::Random(container.begin(), container.end(), lowBound,highBound);
            
            auto start = std::chrono::steady_clock::now();
            func(container);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<float,std::milli> duration = end - start;
            
            //std::cout << duration.count() << std::endl;
            values.push_back(duration.count());
            
        }
        float mean = StdDiv(values.begin(), values.end());
        return mean;
        
    }
template <typename T, class Function>
float IncreasingAvgTime(Function func,T size, T lowBound, T highBound,T times)
{
    std::vector<int> container(size);
    float meanTime = 0.0;
    float Time = 0.0;
    for(int i = 0; i < times; i++)
    {
        Generate::Increasing(container.begin(), container.end(), lowBound,highBound);
        
        auto start = std::chrono::steady_clock::now();
        func(container);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<float,std::milli> duration = end - start;
        
        Time += duration.count();
        
    }
    meanTime = Time / times;
    return meanTime;
    
}
template <typename T, class Function>
float DecreasingAvgTime(Function func,T size, T lowBound, T highBound,T times)
{
    std::vector<int> container(size);
    float meanTime = 0.0;
    float Time = 0.0;
    for(int i = 0; i < times; i++)
    {
        Generate::Decreasing(container.begin(), container.end(), lowBound,highBound);
        
        auto start = std::chrono::steady_clock::now();
        func(container);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<float,std::milli> duration = end - start;
        
        //std::cout << duration.count() << std::endl;
        Time += duration.count();
        
    }
    meanTime = Time / times;
    return meanTime;
    
}
        

#endif /* TimeMeasuring_hpp */
