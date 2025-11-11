#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int utility;
};

int knapsack(const vector<Item>& items, int W, vector<int>& selectedItems) {
    int N = items.size();
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                int includeItem = dp[i - 1][w - items[i - 1].weight] + items[i - 1].utility;
                dp[i][w] = max(includeItem, dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int remainingWeight = W;
    for (int i = N; i > 0; --i) {
        if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {
            selectedItems.push_back(i - 1);
            remainingWeight -= items[i - 1].weight;
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cout << "Enter the number of items: ";
    cin >> N;

    cout << "Enter the truck capacity: ";
    cin >> W;

    vector<Item> items(N);

    cout << "Enter the weight and utility of each item:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Utility: ";
        cin >> items[i].utility;
    }

    vector<int> selectedItems;
    int maxUtility = knapsack(items, W, selectedItems);

    cout << "\nMaximum utility that can be carried: " << maxUtility << endl;
    cout << "Items chosen:\n";

    for (int i : selectedItems) {
        cout << "Item " << i + 1
             << " - Weight: " << items[i].weight
             << " Utility: " << items[i].utility << endl;
    }

    return 0;
}




// OUTPUT:

// Enter the number of items: 4
// Enter the truck capacity: 7
// Enter the weight and utility of each item:
// Item 1 - Weight: 1
// Item 1 - Utility: 1
// Item 2 - Weight: 3
// Item 2 - Utility: 4
// Item 3 - Weight: 4
// Item 3 - Utility: 5
// Item 4 - Weight: 5
// Item 4 - Utility: 7


// Maximum utility that can be carried: 9
// Items chosen:
// Item 2 - Weight: 3 Utility: 4
// Item 3 - Weight: 4 Utility: 5



// EXPLAINATION:

// ✅ Header files and namespaces
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;


// #include <iostream> – allows using cout, cin.

// #include <vector> – allows using dynamic arrays (vector).

// #include <algorithm> – includes max() function.

// using namespace std; – allows using standard library names without std::.

// ✅ Item structure
// struct Item {
//     int weight;
//     int utility;
// };


// Defines a structure Item.

// Each item has:

// weight → weight of item

// utility → value/benefit you get from the item

// ✅ Knapsack function declaration
// int knapsack(const vector<Item>& items, int W, vector<int>& selectedItems)


// Takes:

// items – list of all items

// W – total capacity of the knapsack/truck

// selectedItems – output list storing which items were chosen

// Returns:

// maximum utility achievable

// ✅ Initialization
// int N = items.size();


// Get number of items

// vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));


// Create DP table of size (N+1) × (W+1)

// dp[i][w] means → maximum utility using first i items with weight capacity w

// Initialize with 0

// ✅ DP table filling
// for (int i = 1; i <= N; ++i) {
//     for (int w = 0; w <= W; ++w) {


// Loop over all items

// Loop over all possible weights from 0 to W

// ✅ Check if current item can be included
// if (items[i - 1].weight <= w) {


// If item is light enough to fit in weight w

// ✅ Option 1: include the item
// int includeItem = dp[i - 1][w - items[i - 1].weight] + items[i - 1].utility;


// If you include item i-1, add its utility

// Reduce weight capacity by the item's weight

// Add maximum utility achievable with remaining weight

// ✅ Option 2: exclude the item and choose the best
// dp[i][w] = max(includeItem, dp[i - 1][w]);


// Compare:

// including the item

// excluding the item (dp[i-1][w])

// Store maximum

// ✅ If the item cannot be included
// } else {
//     dp[i][w] = dp[i - 1][w];
// }


// Keep same value as without the item

// ✅ Backtracking to find selected items
// int remainingWeight = W;


// Start with full capacity

// for (int i = N; i > 0; --i) {


// Traverse backwards through items

// ✅ Check if item was included in optimal solution
// if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {


// If value changed → item was included

// ✅ Store selected item and reduce remaining weight
// selectedItems.push_back(i - 1);
// remainingWeight -= items[i - 1].weight;


// Add the item index to result

// Reduce remaining capacity

// ✅ Return maximum utility
// return dp[N][W];


// Final cell has max utility

// ✅ Main function
// Take inputs
// int N, W;
// cout << "Enter the number of items: ";
// cin >> N;


// Read number of items

// cout << "Enter the truck capacity: ";
// cin >> W;


// Read total capacity

// ✅ Create vector of items
// vector<Item> items(N);


// Create vector with N items

// ✅ Input each item’s weight and utility
// cout << "Enter the weight and utility of each item:\n";
// for (int i = 0; i < N; ++i) {
//     cout << "Item " << i + 1 << " - Weight: ";
//     cin >> items[i].weight;
//     cout << "Item " << i + 1 << " - Utility: ";
//     cin >> items[i].utility;
// }


// For each item, read its weight and utility

// ✅ Call knapsack function
// vector<int> selectedItems;
// int maxUtility = knapsack(items, W, selectedItems);


// Calls the DP knapsack

// selectedItems will be filled

// ✅ Print result
// cout << "\nMaximum utility that can be carried: " << maxUtility << endl;


// Prints maximum utility

// ✅ Print chosen items
// cout << "Items chosen:\n";

// for (int i : selectedItems) {
//     cout << "Item " << i + 1
//          << " - Weight: " << items[i].weight
//          << " Utility: " << items[i].utility << endl;
// }


// Loops through selected items and prints details

// ✅ Finish program
// return 0;
