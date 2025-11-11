#include <bits/stdc++.h>
using namespace std;

// Struct for Customer Order using 'this' keyword in constructor
struct Order {
    int orderId;
    long long timestamp; // Using long long to store large timestamps
    string customerName;
    string productName;

    // Constructor
    Order(int orderId, long long timestamp, string customerName, string productName) {
        this->orderId = orderId;
        this->timestamp = timestamp;
        this->customerName = customerName;
        this->productName = productName;
    }
};

// Merge function to merge two sorted halves
void merge(vector<Order> &orders, int low, int mid, int high) {
    vector<Order> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (orders[left].timestamp <= orders[right].timestamp) { // Sorting by timestamp
            temp.push_back(orders[left]);
            left++;
        } else {
            temp.push_back(orders[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(orders[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(orders[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        orders[i] = temp[i - low];
    }
}

// Merge Sort function
void mergeSort(vector<Order> &orders, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(orders, low, mid);
    mergeSort(orders, mid + 1, high);
    merge(orders, low, mid, high);
}

int main() {
    int n;
    cout << "Enter number of customer orders: ";
    cin >> n;

    vector<Order> orders;
    orders.reserve(n); // Reserve memory to handle large dataset efficiently

    for (int i = 0; i < n; i++) {
        int id;
        long long timestamp;
        string customer, product;

        cout << "\nEnter details of Order " << i + 1 << ":\n";
        cout << "Order ID: ";
        cin >> id;
        cout << "Timestamp: ";
        cin >> timestamp;
        cout << "Customer Name: ";
        cin >> customer;
        cout << "Product Name: ";
        cin >> product;

        orders.push_back(Order(id, timestamp, customer, product));
    }

    cout << "\nOrders Before Sorting By Timestamp:\n";
    for (auto &o : orders) {
        cout << "ID:" << o.orderId << " Timestamp:" << o.timestamp
             << " Customer:" << o.customerName << " Product:" << o.productName << endl;
    }

    mergeSort(orders, 0, n - 1);

    cout << "\nOrders After Sorting By Timestamp:\n";
    for (auto &o : orders) {
        cout << "ID:" << o.orderId << " Timestamp:" << o.timestamp
             << " Customer:" << o.customerName << " Product:" << o.productName << endl;
    }

    return 0;
}




// OUTPUT:

// Enter number of customer orders: 4

// Enter details of Order 1:
// Order ID: 101
// Timestamp: 1710045600
// Customer Name: Rahul
// Product Name: Laptop

// Enter details of Order 2:
// Order ID: 102
// Timestamp: 1710023000
// Customer Name: Priya
// Product Name: Mobile

// Enter details of Order 3:
// Order ID: 103
// Timestamp: 1710089000
// Customer Name: Arjun
// Product Name: Headphones

// Enter details of Order 4:
// Order ID: 104
// Timestamp: 1710010000
// Customer Name: Sneha
// Product Name: Smartwatch

// Orders Before Sorting By Timestamp:
// ID:101 Timestamp:1710045600 Customer:Rahul Product:Laptop
// ID:102 Timestamp:1710023000 Customer:Priya Product:Mobile
// ID:103 Timestamp:1710089000 Customer:Arjun Product:Headphones
// ID:104 Timestamp:1710010000 Customer:Sneha Product:Smartwatch

// Orders After Sorting By Timestamp:  
// ID:104 Timestamp:1710010000 Customer:Sneha Product:Smartwatch
// ID:102 Timestamp:1710023000 Customer:Priya Product:Mobile
// ID:101 Timestamp:1710045600 Customer:Rahul Product:Laptop
// ID:103 Timestamp:1710089000 Customer:Arjun Product:Headphones
