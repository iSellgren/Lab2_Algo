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
#include "Functions.hpp"
#include <string>
template <typename Iter>
void StdDiv(Iter left, Iter right)
{
    float N = std::distance(left, right);
    float const mean = std::accumulate(left, right, float{}) / N;
    
    float accum = 0.0;
    std::for_each (left, right, [&](const double d) {
        accum += (d - mean) * (d - mean);
    });
    float variance = accum / N;
    float stdev = sqrt(variance);
    
    std::cout << mean <<" T[ms] " << std::endl;
    std::cout << stdev <<" Stdev[ms] " << std::endl;

    std::cout << N <<" Samples" <<std::endl;

}

template <typename T,typename F1,typename F2>
void TimeMeas(F1 SortAlg, F2 GenAlg, T size, T lowBound, T times)
    {
        for(int x = 1; x < times+1; x++)
        {
            
            int N = pow(size+(2000*x),1);
            std::vector<float> values;
            std::vector<int> container(N);
            GenAlg(container,lowBound);
            
            for(int i = 1; i < times+1; i++)
            {
                
                
                auto start = std::chrono::steady_clock::now();
                SortAlg(container);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::milli> duration = end - start;
                
                
                values.push_back(duration.count());
                
            }
            std::cout << container.size() << " N " << std::endl;
            StdDiv(values.begin(), values.end());
            values.clear();
            container.clear();
        }
        
        
    }
        

#endif /* TimeMeasuring_hpp */
