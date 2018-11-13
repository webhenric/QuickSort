//
// Created by henric on 2018-11-11.
//

#include "QuickSort.h"

void QuickSort::sort(vector<int *> &numbers, long left, long right) {
    if (left >= right) {
        return;
    }

    int *temp = numbers.at(left);
    long pivot = choose_pivot(numbers, left, right);
    numbers[left] = numbers.at(pivot);
    numbers[pivot] = temp;

    long new_pivot = partition(numbers, left, right);

    sort(numbers, left, new_pivot - 1);
    sort(numbers, new_pivot + 1, right);
}

long QuickSort::partition(vector<int *> &numbers, long left, long right) {
    int *pivot = numbers[left];
    long i = left + 1;
    int *temp;

    for (long j = left + 1; j <= right; ++j) {
        if (*numbers[j] < *pivot) {
            temp = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = temp;
            ++i;
        }
    }
    temp = numbers[left];
    numbers[left] = numbers[i - 1];
    numbers[i - 1] = temp;

    return i - 1;
}

long QuickSort::choose_pivot(vector<int *> &numbers, long left, long right) {
    return left;
}
