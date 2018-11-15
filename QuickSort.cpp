//
// Created by henric on 2018-11-11.
//

#include "QuickSort.h"

void QuickSort::sort(vector<int *> &numbers, long left, long right) {
    if (left >= right) {
        return;
    }

    int *temp = numbers[left];
    long pivot = choose_pivot(numbers, left, right);
    numbers[left] = numbers[pivot];
    numbers[pivot] = temp;

    // size of sub-array - 1
    long comparisons = right - left;
    add_comparisons(comparisons > 0 ? comparisons : 0);

    long new_pivot = partition(numbers, left, right);

    sort(numbers, left, new_pivot - 1);
    sort(numbers, new_pivot + 1, right);
}

long QuickSort::partition(vector<int *> &numbers, long left, long right) {
    int *pivot = numbers[left];
    long i = left + 1;
    int *temp = nullptr;

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

void QuickSort::add_comparisons(const long comparisons) {
    this->comparisons += comparisons;
}

long QuickSort::get_comparisons() {
    return comparisons;
}

long QuickSortPivotLast::choose_pivot(vector<int *> &numbers, long left, long right) {
    return right;
}

long QuickSortPivotMedian::choose_pivot(vector<int *> &numbers, long left, long right) {
    long length = right - left + 1;
    long middle = ((length % 2) == 0 ? (length / 2) - 1 : length / 2) + left;
    long a[3];
    a[0] = left;
    a[1] = right;
    a[2] = middle;
    long temp = 0;

    if (*numbers[a[0]] > *numbers[a[1]]) {
        temp = a[1];
        a[1] = a[0];
        a[0] = temp;
    }
    if (*numbers[a[0]] > *numbers[a[2]]) {
        temp = a[2];
        a[2] = a[0];
        a[0] = temp;
    }
    if (*numbers[a[1]] > *numbers[a[2]]) {
        temp = a[2];
        a[2] = a[1];
        a[1] = temp;
    }

    return a[1];
}
