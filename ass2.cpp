#include <bits/stdc++.h>
using namespace std;

struct Movie {
    string title;
    double rating;
    int year;
    int popularity;
};

string sortBy; // chosen sorting parameter

// partition function for quicksort
int partition(vector<Movie> &arr, int low, int high) {
    Movie pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        bool condition = false;

        // directly check based on chosen sort parameter
        if (sortBy == "rating")
            condition = (arr[j].rating < pivot.rating);
        else if (sortBy == "year")
            condition = (arr[j].year < pivot.year);
        else if (sortBy == "popularity")
            condition = (arr[j].popularity < pivot.popularity);
        else
            condition = (arr[j].title < pivot.title);

        if (condition) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// quicksort function
void quickSort(vector<Movie> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of movies: ";
    cin >> n;

    vector<Movie> movies(n);
    cin.ignore(); // clear buffer

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of movie " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, movies[i].title);
        cout << "Rating: ";
        cin >> movies[i].rating;
        cout << "Year: ";
        cin >> movies[i].year;
        cout << "Popularity: ";
        cin >> movies[i].popularity;
        cin.ignore();
    }

    cout << "\nSort movies by (rating/year/popularity/title): ";
    cin >> sortBy;

    quickSort(movies, 0, n - 1);

    cout << "\nMovies sorted by " << sortBy << ":\n";
    for (int i = 0; i < n; i++) {
        cout << movies[i].title
             << " | Rating: " << movies[i].rating
             << " | Year: " << movies[i].year
             << " | Popularity: " << movies[i].popularity << endl;
    }

    return 0;
}
