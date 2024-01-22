#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double knapsackGreedy(std::vector<Item>& items, int capacity) {
    // Urutkan item berdasarkan nilai-to-weight ratio secara menurun
    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Loop melalui item untuk memasukkannya ke dalam knapsack
    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Masukkan seluruh item ke dalam knapsack
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Bagian dari item dimasukkan ke dalam knapsack
            double fraction = static_cast<double>(capacity - currentWeight) / item.weight;
            totalValue += fraction * item.value;
            break; // Knapsack sudah penuh
        }
    }

    return totalValue;
}

int main() {
    std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    double maxValue = knapsackGreedy(items, capacity);

    std::cout << "Maximum value in Knapsack: " << maxValue << std::endl;

    return 0;
}

