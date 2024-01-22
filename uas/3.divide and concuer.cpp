#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t leftIndex = 0, rightIndex = 0;

    // Merge dua array yang sudah terurut
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // Tambahkan sisa elemen dari array kiri
    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    // Tambahkan sisa elemen dari array kanan
    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

std::vector<int> mergeSort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Panggil fungsi rekursif untuk kedua setengah array
    std::vector<int> sortedLeft = mergeSort(left);
    std::vector<int> sortedRight = mergeSort(right);

    // Gabungkan dua array yang sudah terurut
    return merge(sortedLeft, sortedRight);
}

int main() {
    std::vector<int> unsortedArray;
    unsortedArray.push_back(5);
    unsortedArray.push_back(2);
    unsortedArray.push_back(9);
    unsortedArray.push_back(1);
    unsortedArray.push_back(5);
    unsortedArray.push_back(6);

    std::vector<int> sortedArray = mergeSort(unsortedArray);

    // Cetak array yang sudah terurut
  for (size_t i = 0; i < sortedArray.size(); ++i) {
    std::cout << sortedArray[i] << " ";
}


    return 0;
}

