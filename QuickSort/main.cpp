//
//  main.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "QuickSortMedian3.hpp"
#include "Generate.hpp"
#include "TimeMeasuring.hpp"
#include "Functions.hpp"



int main(int argc, const char * argv[])
{
    for( int i = 0; i < 1000000; i++)
    {
        TimeMeas(selectionsort,randNum,10,INT_MIN,5);

        TimeMeas(insertionsort,randNum,10,INT_MIN,5);
        
        TimeMeas(quicksort,randNum,10,INT_MIN,5);
        TimeMeas(quicksortMedianof3,randNum,10,INT_MIN,5);
    }
    return 0;
}
