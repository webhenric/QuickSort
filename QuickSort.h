//
// Created by henric on 2018-11-11.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <vector>

using namespace std;


class QuickSort {
public:
    void sort(vector<int *> &, unsigned long, unsigned long);

protected:
    unsigned long choose_pivot(vector<int *> &, unsigned long, unsigned long);
    unsigned long partition(vector<int *> &, unsigned long, unsigned long);
};


#endif //QUICKSORT_QUICKSORT_H
