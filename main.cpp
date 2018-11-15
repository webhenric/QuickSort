#include <iostream>
#include <fstream>
#include <vector>
#include "QuickSort.h"

using namespace std;

int main(int argc, char *argv[]) {
    string option;
    string file_name;
    vector<int *> numbers;
    QuickSort *quickSort = nullptr;

    ios_base::sync_with_stdio(false);

    if (argc < 2) {
        cerr << "File path expected, exiting..." << endl;
        return 1;
    }

    if (argc == 3) {
        option = argv[2];
        if (option == "last") {
            quickSort = new QuickSortPivotLast;
        }
        else if (option == "median") {
            quickSort = new QuickSortPivotMedian;
        } else {
            quickSort = new QuickSort;
        }
    } else {
        quickSort = new QuickSort;
    }

    file_name = argv[1];
    ifstream ifs{file_name};
    int *number = nullptr;
    if (ifs) {
        cout << "Opened file: " << file_name << endl;
        while (ifs.good()) {
            number = new int;
            ifs >> *number;
            numbers.push_back(number);
        }
        quickSort->sort(numbers, 0, numbers.size() - 1);
        cout << "Number of comparisons: " << quickSort->get_comparisons() << endl;
    } else {
        cerr << "Could not open file: " << file_name << endl;
        return 1;
    }

    return 0;
}