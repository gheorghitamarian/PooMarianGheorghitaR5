#pragma once
#include <initializer_list>

class Sort
{
private:
    int* elements;
    int elementsCount;
    int Partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);

public:
   
    Sort();
    ~Sort();
    Sort(int elementsCount, int minval, int maxval);
    Sort(int* elements, int elementsCount);
    Sort(std::initializer_list<int> list);
    Sort(const char* str);
    Sort(int elementsCount, ...);

    
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();

    int GetElementsCount();
    int GetElementFromIndex(int index);
};