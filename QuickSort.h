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

    long get_comparisons();

protected:
    virtual long choose_pivot(vector<int *> &, long, long);

    long partition(vector<int *> &, long, long);

    void add_comparisons(long);

private:
    int comparisons = 0;
};

class QuickSortPivotLast : public QuickSort {
    long choose_pivot(vector<int *> &, long, long) override;

};

class QuickSortPivotMedian : public QuickSort {
    long choose_pivot(vector<int *> &, long, long) override;

};


#endif //QUICKSORT_QUICKSORT_H
