//
//  QuickSort.hpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#ifndef QuickSortMedian3_hpp
#define QuickSortMedian3_hpp

#include <stdio.h>
#include <iostream>

int* medianPort(int* leftPtr, int* rightPtr);
int* recpartitionPort(int* left, int* right, int* Pivot);
void recquickPort(int* left, int* right);
#endif /* QuickSort_hpp */
