#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, vector<vector<pair<int,int>>> &graph, vector<int> &dist) {
    int V = graph.size();
    dist.assign(V, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) 
            continue;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of intersections (vertices): ";
    cin >> V;

    cout << "Enter number of roads (edges): ";
    cin >> E;

    vector<vector<pair<int,int>>> graph(V);

    cout << "Enter edges in format: u v w\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter ambulance start location: ";
    cin >> source;

    int H;
    cout << "Enter number of hospitals: ";
    cin >> H;

    vector<int> hospitals(H);
    cout << "Enter hospital nodes: ";
    for (int i = 0; i < H; i++) {
        cin >> hospitals[i];
    }

    vector<int> dist;
    dijkstra(source, graph, dist);

    int minTime = INT_MAX;
    int nearestHospital = -1;

    for (int h : hospitals) {
        if (dist[h] < minTime) {
            minTime = dist[h];
            nearestHospital = h;
        }
    }

    if (nearestHospital == -1)
        cout << "No hospital is reachable.\n";
    else
        cout << "Nearest hospital is at node " << nearestHospital
             << " with travel time " << minTime << " minutes.\n";

    return 0;
}






// OUTPUT:
// Enter number of intersections (vertices): 6
// Enter number of roads (edges): 7
// Enter edges in format: u v w
// 0 1 4
// 0 2 2
// 1 2 1
// 1 3 5
// 2 3 8
// 2 4 10
// 3 5 2
// Enter ambulance start location: 0
// Enter number of hospitals: 2
// Enter hospital nodes: 3 5


// Nearest hospital is at node 3 with travel time 6 minutes.



// EXPLAINATION:

// ✅ Header files and namespaces
// #include <bits/stdc++.h>
// using namespace std;


// #include <bits/stdc++.h> – includes all standard C++ libraries.

// using namespace std; – allows using standard library names without std::.

// ✅ Dijkstra function declaration
// void dijkstra(int source, vector<vector<pair<int,int>>> &graph, vector<int> &dist)


// Takes:

// source → starting node

// graph → adjacency list storing roads

// dist → output array storing shortest distance to every node

// Purpose:

// Finds shortest travel time from ambulance location to all intersections.

// ✅ Initialization
// int V = graph.size();
// dist.assign(V, INT_MAX);
// dist[source] = 0;


// Get number of vertices.

// Set all distances to infinity.

// Distance to source is set to 0.

// ✅ Min-heap priority queue setup
// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// pq.push({0, source});


// Uses a min-priority queue storing {distance, node}.

// Starts by pushing source with distance 0.

// ✅ Main Dijkstra loop
// while (!pq.empty()) {


// Process nodes until queue becomes empty.

// ✅ Extract node with minimum distance
// int u = pq.top().second;
// int d = pq.top().first;
// pq.pop();


// u = node number

// d = shortest known distance to u

// ✅ Skip if outdated
// if (d > dist[u])
//     continue;


// Ignore outdated entries (not optimal anymore).

// ✅ Relax all adjacent edges
// for (auto &edge : graph[u]) {
//     int v = edge.first;
//     int w = edge.second;


// For each neighbor v of u:

// w is weight (travel time)

// ✅ Check and update distance
// if (dist[v] > dist[u] + w) {
//     dist[v] = dist[u] + w;
//     pq.push({dist[v], v});
// }


// If shorter path found, update distance.

// Push new distance into priority queue.

// ✅ Main function

// Handles input/output and finds nearest hospital.

// ✅ Input number of intersections and roads
// cin >> V;
// cin >> E;


// Read:

// V = number of intersections (vertices)

// E = number of roads (edges)

// ✅ Build graph
// vector<vector<pair<int,int>>> graph(V);


// Create adjacency list for V nodes.

// ✅ Read edges
// cin >> u >> v >> w;
// graph[u].push_back({v, w});
// graph[v].push_back({u, w});


// For each road:

// u, v → endpoints

// w → travel time

// Add both directions (road is bidirectional).

// ✅ Input ambulance start location
// cin >> source;


// Read starting node of ambulance.

// ✅ Input hospital locations
// cin >> H;
// cin >> hospitals[i];


// Read number of hospitals.

// Read each hospital node.

// ✅ Run Dijkstra algorithm
// dijkstra(source, graph, dist);


// Compute shortest travel time from ambulance to all nodes.

// ✅ Find the nearest hospital
// int minTime = INT_MAX;
// int nearestHospital = -1;

// for (int h : hospitals) {
//     if (dist[h] < minTime) {
//         minTime = dist[h];
//         nearestHospital = h;
//     }
// }


// Check each hospital.

// Find one with minimum distance.

// ✅ Output the result
// if (nearestHospital == -1)
//     cout << "No hospital is reachable.\n";
// else
//     cout << "Nearest hospital is at node " << nearestHospital
//          << " with travel time " << minTime << " minutes.\n";


// If unreachable → display message.

// Else print nearest hospital number and time.

// ✅ Finish program
// return 0;
