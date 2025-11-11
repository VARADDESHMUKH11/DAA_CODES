#include <bits/stdc++.h>
using namespace std;

void greedyColoring(vector<vector<int>> &graph, int numCourses) {
    vector<int> result(numCourses, -1);
    result[0] = 0;

    vector<bool> available(numCourses, true);

    for (int u = 1; u < numCourses; u++) {
        fill(available.begin(), available.end(), true);

        for (int adj : graph[u]) {
            if (result[adj] != -1)
                available[result[adj]] = false;
        }

        int color;
        for (color = 0; color < numCourses; color++) {
            if (available[color])
                break;
        }
        result[u] = color;
    }

    cout << "Exam Slot Assignment (Greedy Coloring):\n";
    for (int u = 0; u < numCourses; u++) {
        cout << "Course " << u << " → Slot " << result[u] << endl;
    }

    int maxColor = *max_element(result.begin(), result.end());
    cout << "\nTotal Exam Slots Used: " << (maxColor + 1) << endl;
}

int main() {
    int numCourses, edges;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of edges (conflicts): ";
    cin >> edges;

    vector<vector<int>> graph(numCourses);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    greedyColoring(graph, numCourses);
    return 0;
}


// OUTPUT:

// Enter number of courses: 5
// Enter number of edges (conflicts): 6
// Enter edges (u v):
// 0 1
// 0 2
// 1 2
// 1 3
// 2 4
// 3 4

// Exam Slot Assignment (Greedy Coloring):
// Course 0 → Slot 0
// Course 1 → Slot 1
// Course 2 → Slot 2
// Course 3 → Slot 0
// Course 4 → Slot 1

// Total Exam Slots Used: 3


// EXPLAINATION:

// ✅ Header & Namespace

// #include <bits/stdc++.h>
// → Includes all standard C++ libraries in one header (commonly used in competitive programming).

// using namespace std;
// → Allows using standard library names without writing std:: prefix.

// ✅ Greedy Coloring Function Definition

// void greedyColoring(vector<vector<int>> &graph, int numCourses) {
// → Function that performs greedy graph coloring to assign exam slots to courses.

// vector<int> result(numCourses, -1);
// → Creates result array to store assigned color/slot for each course; initializes all to -1 (meaning unassigned).

// result[0] = 0;
// → Assigns first course with color 0 (first slot).

// vector<bool> available(numCourses, true);
// → Boolean array that tracks which colors are available for the current course.

// ✅ Loop Through Each Course

// for (int u = 1; u < numCourses; u++) {
// → Loop starts from course 1 since course 0 is already colored.

// fill(available.begin(), available.end(), true);
// → Reset the availability array to true for every iteration.

// ✅ Checking Adjacent Courses

// for (int adj : graph[u]) {
// → Loop through all neighbors (conflict courses) of course u.

// if (result[adj] != -1)
// → Check if adjacent course has color assigned.

// available[result[adj]] = false;
// → Mark that color as unavailable because adjacent course is using it.

// ✅ Assigning the First Available Color

// int color;
// → Variable to store color assigned.

// for (color = 0; color < numCourses; color++) {
// → Loop through all possible colors.

// if (available[color])
// → If this color is not used by adjacent courses…

// break;
// → …choose this color and exit loop.

// result[u] = color;
// → Assign that color to current course.

// ✅ Printing Assigned Slots

// cout << "Exam Slot Assignment (Greedy Coloring):\n";
// → Print heading for result.

// for (int u = 0; u < numCourses; u++) {
// → Loop through all courses.

// cout << "Course " << u << " → Slot " << result[u] << endl;
// → Print each course and its assigned color/slot.

// ✅ Calculating Total Slots

// int maxColor = *max_element(result.begin(), result.end());
// → Finds highest slot value used.

// cout << "\nTotal Exam Slots Used: " << (maxColor + 1) << endl;
// → Prints total number of slots (adding 1 because slots start at 0).

// ✅ Main Function

// int main() {
// → Program starts here.

// int numCourses, edges;
// → Variables to store number of courses and number of conflict edges.

// cout << "Enter number of courses: ";
// → Prompt user.

// cin >> numCourses;
// → Read number of courses.

// cout << "Enter number of edges (conflicts): ";
// → Prompt user for number of conflicts.

// cin >> edges;
// → Read number of conflict edges.

// ✅ Graph Initialization

// vector<vector<int>> graph(numCourses);
// → Create adjacency list for graph with numCourses nodes.

// ✅ Reading Conflict Edges

// cout << "Enter edges (u v):\n";
// → Instruction for user input.

// for (int i = 0; i < edges; i++) {
// → Loop to read all edges.

// int u, v;
// → Variables for edge endpoints.

// cin >> u >> v;
// → Input of conflicting course pair.

// graph[u].push_back(v);
// → Add edge u → v.

// graph[v].push_back(u);
// → Add edge v → u (undirected graph).

// ✅ Calling Function

// greedyColoring(graph, numCourses);
// → Calls function to assign slots.

// ✅ Return Statement

// return 0;
// → End program successfully.

// }
// → End of main function.
