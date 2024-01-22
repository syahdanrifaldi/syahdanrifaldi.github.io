#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct KnapsackItem {
    int value;
    int weight;
};

struct Node {
    int level;
    int value;
    int weight;
    double bound;

    Node(int l, int v, int w, double b) : level(l), value(v), weight(w), bound(b) {}
};

bool compareKnapsackItems(const KnapsackItem& item1, const KnapsackItem& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double knapsackBranchAndBound(std::vector<KnapsackItem>& items, int capacity) {
    std::sort(items.begin(), items.end(), compareKnapsackItems);

    std::queue<Node> q;
    Node u(-1, 0, 0, 0.0);
    Node v(0, 0, 0, 0.0);
    double maxValue = 0.0;

    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        // Jika level sama dengan jumlah item, cabang ini selesai
        if (u.level == static_cast<int>(items.size()) - 1) {
            continue;
        }

        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.value = u.value + items[v.level].value;

        // Jika kapasitas masih cukup dan nilai yang dihasilkan lebih besar dari nilai saat ini
        if (v.weight <= capacity && v.value > maxValue) {
            maxValue = v.value;
        }

        v.bound = v.value + (capacity - v.weight) * (items[v.level + 1].value / static_cast<double>(items[v.level + 1].weight));

        // Jika upper bound lebih besar dari nilai saat ini, tambahkan ke antrian
        if (v.bound > maxValue) {
            q.push(v);
        }

        // Lanjutkan tanpa menambahkan item ke dalam knapsack
        v.weight = u.weight;
        v.value = u.value;
        v.bound = v.value + (capacity - v.weight) * (items[v.level + 1].value / static_cast<double>(items[v.level + 1].weight));

        // Jika upper bound lebih besar dari nilai saat ini, tambahkan ke antrian
        if (v.bound > maxValue) {
            q.push(v);
        }
    }

    return maxValue;
}

int main() {
    std::vector<KnapsackItem> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    double maxValue = knapsackBranchAndBound(items, capacity);

    std::cout << "Maximum value in Knapsack: " << maxValue << std::endl;

    return 0;
}


