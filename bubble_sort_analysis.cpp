
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

// Bubble Sort implementation
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Measure execution time in milliseconds
double measureTime(vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

int main() {
    vector<int> Arr1 = {1,2,3,4,5};
    vector<int> Arr2 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> Arr3;
    vector<int> Arr4;

    for (int i = 1; i <= 50; ++i) Arr3.push_back(i);
    for (int i = 1; i <= 100; ++i) Arr4.push_back(i);

    vector<vector<int>> arrays = {Arr1, Arr2, Arr3, Arr4};
    vector<int> arraySizes = {5, 10, 50, 100};
    vector<double> averageTimes;

    for (auto& arr : arrays) {
        double totalTime = 0.0;
        for (int i = 0; i < 5; ++i) {
            totalTime += measureTime(arr);
        }
        averageTimes.push_back(totalTime / 5);
    }

    // Print results
    cout << "Input Size\tAverage Time (ms)" << endl;
    for (size_t i = 0; i < arraySizes.size(); ++i) {
        cout << arraySizes[i] << "\t\t" << averageTimes[i] << endl;
    }

    return 0;
}
