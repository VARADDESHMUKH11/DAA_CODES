#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Structure for each item
struct Item {
    string name;
    double weight;
    double value;
    bool divisible;
    int priority;

    Item(string n, double w, double v, bool d, int p) {
        name = n;
        weight = w;
        value = v;
        divisible = d;
        priority = p;
    }

    // Value per unit weight
    double valuePerWeight() const {
        return value / weight;
    }
};

// Custom sorting: Priority first, then value/weight
bool sortItems(const Item &a, const Item &b) {
    if (a.priority == b.priority)
        return a.valuePerWeight() > b.valuePerWeight();
    return a.priority < b.priority; // smaller number = higher priority
}

// Fractional Knapsack function
double fractionalKnapsack(vector<Item> &items, double capacity, double &totalWeightCarried) {
    // Sort items by priority and then by value per weight
    sort(items.begin(), items.end(), sortItems);

    double totalValue = 0;
    totalWeightCarried = 0;

    cout << "\nItems selected:\n";

    for (auto &item : items) {
        if (capacity <= 0) break; // boat is full

        if (item.divisible) {
            // Take as much as possible
            double take = min(item.weight, capacity);
            totalValue += take * item.valuePerWeight();
            totalWeightCarried += take;
            capacity -= take;

            cout << " - " << item.name << ": " << take << " kg | Value = " << take * item.valuePerWeight()
                 << " | Priority " << item.priority << " | Divisible\n";
        } else {
            // Take only if whole item fits
            if (item.weight <= capacity) {
                totalValue += item.value;
                totalWeightCarried += item.weight;
                capacity -= item.weight;

                cout << " - " << item.name << ": " << item.weight << " kg | Value = " << item.value
                     << " | Priority " << item.priority << " | Indivisible\n";
            }
        }
    }

    return totalValue;
}

// Main program
int main() {
    // Predefined relief items
    vector<Item> items = {
        Item("Medical Kits",   10, 100, false, 1),
        Item("Food Packets",   20,  60, true,  3),
        Item("Drinking Water", 30,  90, true,  2),
        Item("Blankets",       15,  45, false, 3),
        Item("Infant Formula",  5,  50, false, 1)
    };

    double capacity;
    cout << "Enter boat capacity (kg): ";
    cin >> capacity;

    double totalWeight, maxValue;
    maxValue = fractionalKnapsack(items, capacity, totalWeight);

    cout << "\n===== Final Report =====\n";
    cout << "Total weight carried: " << totalWeight << " kg\n";
    cout << "Total value carried: " << maxValue << " units\n";

    return 0;
}


// OUTPUT

// Items selected:
//  - Medical Kits: 10 kg | Value = 100 | Priority 1 | Indivisible
//  - Infant Formula: 5 kg | Value = 50 | Priority 1 | Indivisible
//  - Drinking Water: 30 kg | Value = 90 | Priority 2 | Divisible
//  - Food Packets: 5 kg | Value = 15 | Priority 3 | Divisible

// ===== Final Report =====
// Total weight carried: 50 kg
// Total value carried: 255 units
