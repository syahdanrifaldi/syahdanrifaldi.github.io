#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

bool parallelSearch(const std::vector<int>& arr, int target, int numThreads) {
    std::vector<std::thread> threads;
    std::vector<bool> results(numThreads, false);
    int chunkSize = arr.size() / numThreads;

    auto searchInChunk = [&](int threadId) {
        int start = threadId * chunkSize;
        int end = (threadId < numThreads - 1) ? start + chunkSize : arr.size();
        
        for (int i = start; i < end; ++i) {
            if (arr[i] == target) {
                results[threadId] = true;
                return;
            }
        }
    };

    // Membuat dan menjalankan thread-thread untuk pencarian
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(searchInChunk, i);
    }

    // Menunggu thread-thread selesai
    for (std::thread& thread : threads) {
        thread.join();
    }

    // Mengembalikan true jika target ditemukan di salah satu thread
    return std::any_of(results.begin(), results.end(), [](bool result) { return result; });
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int numThreads = 4;

    bool result = parallelSearch(array, target, numThreads);

    if (result) {
        std::cout << "Element found." << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}

