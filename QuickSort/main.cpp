//
//  main.cpp
//  QuickSort
//
//  Created by Fredrik Sellgren on 2019-04-26.
//  Copyright © 2019 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "MergeSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include "QuickSortMedian3.hpp"
#include "OSSA.hpp"
#include "Generate.hpp"
#include "TimeMeasuring.hpp"
#include "Functions.hpp"


void mergesortData(int size, int times)
{

    std::string filename = "mergsort";
    std::ofstream myfile;
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(mergsort,randNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(mergsort,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(mergsort,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(mergsort,constNum,size,INT_MIN,times,filename);
}
void selectsortData(int size, int times)
{

    std::string filename = "selectionsort";
    std::ofstream myfile;
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(selectionsort,randNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(selectionsort,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(selectionsort,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(selectionsort,constNum,size,INT_MIN,times,filename);
}
void OSSAsortData(int size, int times)
{

    std::string filename = "OSSAsort";
    std::ofstream myfile;
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(OSSA,randNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(OSSA,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(OSSA,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(OSSA,constNum,size,INT_MIN,times,filename);
}
void quicksortData(int size, int times)
{
    std::string filename = "quicksort";
    std::ofstream myfile;
    
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksort,randNum,size,INT_MIN,times,filename);
   
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksort,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksort,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksort,constNum,size,INT_MIN,times,filename);
    
}
void medianof3sortData(int size, int times)
{

    std::string filename = "medianof3sort";
    std::ofstream myfile;
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksortMedianof3,randNum,size,INT_MIN,times,filename);
  
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksortMedianof3,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksortMedianof3,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(quicksortMedianof3,constNum,size,INT_MIN,times,filename);
   
}
void insertsortData(int size, int times)
{

    std::string filename = "insertionsort";
    std::ofstream myfile;
    myfile.open (filename+".txt");
    myfile << filename << " Sorting Random Element " << "\r\n";
    myfile.close();
    TimeMeas(insertionsort,randNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Incresing Element " << "\r\n";
    myfile.close();
    TimeMeas(insertionsort,incNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Decresing Element " << "\r\n";
    myfile.close();
    TimeMeas(insertionsort,decNum,size,INT_MIN,times,filename);
    
    myfile.open (filename+".txt", std::ios::app);
    myfile << filename << " Sorting Constant Element " << "\r\n";
    myfile.close();
    TimeMeas(insertionsort,constNum,size,INT_MIN,times,filename);
}



int main(int argc, const char * argv[])
{
    int size = 10000;
    int times = 5;
    //TimeMeas(quicksort,incNum,size,INT_MIN,times,"test");
//    mergesortData(size,times);
//    selectsortData(size,times);
//    OSSAsortData(size,times);
    quicksortData(size,times);
    //medianof3sortData(size,times);
    //insertsortData(size,times);

        
        
    return 0;
}
