#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    // Implementation of merging two sorted arrays
}

std::vector<int> mergeSort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

std::vector<int> parallelMergeSort(const std::vector<int>& arr, int numThreads) {
    if (numThreads == 1 || arr.size() <= 1)
        return mergeSort(arr);

    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    std::vector<int> leftSorted, rightSorted;

    std::thread leftThread([&]() {
        leftSorted = parallelMergeSort(left, numThreads / 2);
    });

    rightSorted = parallelMergeSort(right, numThreads / 2);

    leftThread.join();

    return merge(leftSorted, rightSorted);
}

int main() {
    std::vector<int> unsortedArray = {5, 2, 9, 1, 5, 6};
    int numThreads = 2;

    std::vector<int> sortedArray = parallelMergeSort(unsortedArray, numThreads);

    // Print sorted array
    for (int num : sortedArray) {
        std::cout << num << " ";
    }

    return 0;
}

