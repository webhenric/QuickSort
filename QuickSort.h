//
// Created by henric on 2018-11-11.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <vector>

using namespace std;


class QuickSort {
public:
    void sort(vector<int *> &, long, long);

protected:
    long choose_pivot(vector<int *> &, long, long);
    long partition(vector<int *> &, long, long);
};


#endif //QUICKSORT_QUICKSORT_H
