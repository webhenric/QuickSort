//
// Created by henric on 2018-11-11.
//

#include "QuickSort.h"

void QuickSort::sort(vector<int *> &numbers, unsigned long left, unsigned long right) {
    if (left >= right) {
        return;
    }

    int *temp = numbers.at(left);
    unsigned long pivot = choose_pivot(numbers, left, right);
    numbers[left] = numbers.at(pivot);
    numbers[pivot] = temp;

    unsigned long new_pivot = partition(numbers, left, right);

    sort(numbers, left, new_pivot - 1);
    sort(numbers, new_pivot + 1, right);
    
}

unsigned long QuickSort::partition(vector<int *> &numbers, unsigned long left, unsigned long right) {
    return 0;
}

unsigned long QuickSort::choose_pivot(vector<int *> &numbers, unsigned long left, unsigned long right) {
    return left;
}
