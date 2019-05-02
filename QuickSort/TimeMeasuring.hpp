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


int multiply(int value,int mul) {
    
    int ret=0;
    
    int mulabs = mul;
    if(mulabs < 0) mulabs = 0 -mulabs;
    
    for(int n=0;n<mulabs;n++) {
        ret += value;
    }
    
    if(mul < 0) ret = 0-ret;
    
    return ret+ret;
}
struct subject {
    float mean;
    float Stdev;
    float Sample;
    float Size;
    
};
template <typename Iter>
subject StdDiv(Iter left, Iter right,int size)
{
    float N = std::distance(left, right);
    float  mean = std::accumulate(left, right, float{}) / N;
    
    float accum = 0.0;
    std::for_each (left, right, [&](const double d) {
        accum += (d - mean) * (d - mean);
    });
    float variance = accum / N;
    float stdev = sqrt(variance);
    
    subject test ={mean,stdev,N,static_cast<float>(size)};
    return test;
    

}

template <typename T,typename F1,typename F2>
void TimeMeas(F1 SortAlg, F2 GenAlg, T size, T lowBound, T times, std::string name)
    {
        int Tid = (times+1);
       std::vector<subject> bar;
        std::vector<float> values;
        for(int j = 1; j < Tid; j++)
        {
            int test = multiply(size, j);
            for(int i = 1; i < Tid; i++)
            {
        
                std::vector<int> container(test);
                
                GenAlg(container,lowBound);
                
                auto start = std::chrono::steady_clock::now();
                SortAlg(container);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<float,std::milli> duration = end - start;
                
                
                values.push_back(duration.count());

                if(!std::is_sorted(container.begin(), container.end()))
                {
                    std::cout << "Not Sorted" << std::endl;
                    std::cin.get();
                }

            }
            bar.push_back(StdDiv(values.begin(), values.end(),test));
            values.clear();
        }
        std::ofstream myfile;
        myfile.open (name+".txt", std::ios::app);
        for(int k = 0; k < bar.size(); k++)
        {
            //std::string meanStr = std::to_string(bar[k].mean),
              //  stdevStr = std::to_string(bar[k].Stdev);
            //meanStr[meanStr.find('.')] = ',';
            //stdevStr[stdevStr.find('.')] = ',';
         
            myfile << bar[k].Size << ';' << bar[k].mean << ';' << bar[k].Stdev << ';' << bar[k].Sample << "\r\n";
         
            
//            myfile << bar[k].Size << ';' << meanStr << ';' << stdevStr << ';' << bar[k].Sample << "\r\n";
            
        }
        myfile.close();
    }
        

#endif /* TimeMeasuring_hpp */
