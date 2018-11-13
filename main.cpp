#include <iostream>
#include <fstream>
#include <vector>
#include "QuickSort.h"

using namespace std;

int main(int argc, char* argv[]) {
    string file_name;
    vector<int *> numbers;
    QuickSort quickSort;

    ios_base::sync_with_stdio(false);

    if (argc < 2) {
        cerr << "File path expected, exiting..." << endl;
        return 1;
    }

    file_name = argv[1];
    ifstream ifs {file_name};
    int number;
    if (ifs) {
        cout << "Opened file: " << file_name << endl;
        while (ifs.good()) {
            ifs >> number;
            numbers.push_back(&number);
        }
        quickSort.sort(numbers, 0, numbers.size() - 1);
    } else {
        cerr << "Could not open file: " << file_name << endl;
        return 1;
    }

    return 0;
}