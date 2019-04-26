//
//  main.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <climits>
#include <functional>
#include <iterator>
#include <chrono>
void printVec(std::vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
}
int* medianPort(int* leftPtr, int* rightPtr)
{
    int* midptr = rightPtr;
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
int* partitionPort(int* left, int* right)
{
    int* i = left-1;
    int* j = right;
    
    //int* pos = medianPort((right-1), left, (left + (right - left)/2));
    int pivot = *(right);
    
    //std::cout << pivot << std::endl;
    while(true)
    {
        while(*++i < pivot);
        while(pivot < *--j) if(j == left) break;
        
        if(i >= j)
            break;
        std::swap(*i,*j);
            
    }
    std::swap(*i,*right);
    return i;
}
int* recpartitionPort(int* left, int* right, int* Pivot)
{
    
    int* i = left-1;
    int* j = right;

    int pivot = *Pivot;
    
    while(true)
    {
        while(*++i < pivot);
        while(pivot < *--j) if(j == left) break;
        
        if(i >= j)
            break;
        std::swap(*i,*j);
        
    }
    std::swap(*i,*right);
    return i;
}
void insertionPort(int* left ,int* right)
{
    
    int *i;
    for (i = right; i > left; i--)
        if(*(i-1) > *i)
        {
            std::swap(*(i-1),*i);
        }
    
    for (int* i = left + 2; i <= right; i++)
    {
        int value = *i;
        int* j = i;
        
        while (j > left && *(j-1) > value)
        {
            *j = *(j - 1);
            j--;
        }
        *j = value;
    }
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
void selectionPort(int* left, int* right)
{
    std::cout << "SelectionPort" << std::endl;
    auto start = std::chrono::steady_clock::now();
    for(int *i = left; i < right; i++)
    {
        int *min = i;
        for(int* j = i+1; j < right ; j++)
        {
            if(*j < *min)
                min = j;
        }
        
        if(min != i)
            std::swap(*i , *min);
    }
    
    auto end = std::chrono::steady_clock::now();
    float diff = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
    
    std::cout << diff << " sec " << std::endl;
}

int main(int argc, const char * argv[])
{
    int size = 100000;
    std::vector<int> container(size);
    std::random_device rand;
    std::mt19937 mt {rand()};
    std::uniform_int_distribution<int> range{INT_MIN, INT_MAX};
    std::cout << "Sorting " << size <<" random elements whit range " << INT_MIN << " to " << INT_MAX << " This may take a while" << std::endl;
    auto gen = [&range, &mt]()
    {
        return range(mt);
    };
    
    std::generate(std::begin(container), std::end(container), gen);
    auto tmp = container;
    //printVec(container);
    for(int i = 0; i < 1; i++)
    {
        std::cout << "Sorting....." << std::endl;
        auto  start1 = std::chrono::steady_clock::now();
        //selectionPort(&container.front(), &container.back()+1);
        insertionPort(&container.front(), &container.back());
        //quickPort(&container.front(), &container.back());
        

        auto end1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff1=(end1 - start1);
        std::cout << diff1.count() << " quickPort " << std::endl;
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            //std::cin.get();
        }
        container = tmp;
        std::cout << "Sorting....." << std::endl;
        auto  start = std::chrono::steady_clock::now();
        //selectionPort(&container.front(), &container.back()+1);
        //insertionPort(&container.front(), &container.back());
        recquickPort(&container.front(), &container.back());
        
        
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff=(end - start);
        std::cout << diff.count() << " recquickPort " << std::endl;
        if(std::is_sorted(container.begin(), container.end()))
        {
            std::cout << "Sorted" << std::endl;
            
        }else
        {
            std::cout << "not sorted" << std::endl;
            //std::cin.get();
        }
        //printVec(container);

        
        
    }
    return 0;
}
