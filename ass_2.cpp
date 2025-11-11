#include <bits/stdc++.h>
using namespace std;

// Struct for Movie using 'this' keyword in constructor
struct Movie {
    string title;
    double rating;
    int year;
    int popularity;

    // Constructor
    Movie(string title, double rating, int year, int popularity) {
        this->title = title;
        this->rating = rating;
        this->year = year;
        this->popularity = popularity;
    }
};

// Global variable for sorting criterion
string sortBy;

// Partition function for Quick Sort
int partition(vector<Movie> &movies, int low, int high) {
    Movie pivot = movies[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        bool condition = false;

        if (sortBy == "rating")
            condition = (movies[j].rating < pivot.rating);
        else if (sortBy == "year")
            condition = (movies[j].year < pivot.year);
        else if (sortBy == "popularity")
            condition = (movies[j].popularity < pivot.popularity);
        else
            condition = (movies[j].title < pivot.title);

        if (condition) {
            i++;
            swap(movies[i], movies[j]);
        }
    }

    swap(movies[i + 1], movies[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<Movie> &movies, int low, int high) {
    if (low < high) {
        int pi = partition(movies, low, high);
        quickSort(movies, low, pi - 1);
        quickSort(movies, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of movies: ";
    cin >> n;

    vector<Movie> movies;
    movies.reserve(n);
    cin.ignore(); // clear input buffer

    for (int i = 0; i < n; i++) {
        string title;
        double rating;
        int year, popularity;

        cout << "\nEnter details of Movie " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, title);
        cout << "Rating: ";
        cin >> rating;
        cout << "Year: ";
        cin >> year;
        cout << "Popularity: ";
        cin >> popularity;
        cin.ignore();

        movies.push_back(Movie(title, rating, year, popularity));
    }

    cout << "\nMovies Before Sorting:\n";
    for (auto &m : movies) {
        cout << m.title << " | Rating: " << m.rating
             << " | Year: " << m.year
             << " | Popularity: " << m.popularity << endl;
    }

    cout << "\nSort movies by (rating/year/popularity/title): ";
    cin >> sortBy;

    quickSort(movies, 0, n - 1);

    cout << "\nMovies After Sorting by " << sortBy << ":\n";
    for (auto &m : movies) {
        cout << m.title << " | Rating: " << m.rating
             << " | Year: " << m.year
             << " | Popularity: " << m.popularity << endl;
    }

    return 0;
}


/* 
OUTPUT EXAMPLE:

Enter number of movies: 4

Enter details of Movie 1:
Title: Inception
Rating: 8.8
Year: 2010
Popularity: 95

Enter details of Movie 2:
Title: Interstellar
Rating: 8.6
Year: 2014
Popularity: 98

Enter details of Movie 3:
Title: Tenet
Rating: 7.5
Year: 2020
Popularity: 85

Enter details of Movie 4:
Title: Dunkirk
Rating: 7.9
Year: 2017
Popularity: 90

Movies Before Sorting:
Inception | Rating: 8.8 | Year: 2010 | Popularity: 95
Interstellar | Rating: 8.6 | Year: 2014 | Popularity: 98
Tenet | Rating: 7.5 | Year: 2020 | Popularity: 85
Dunkirk | Rating: 7.9 | Year: 2017 | Popularity: 90

Sort movies by (rating/year/popularity/title): rating

Movies After Sorting by rating:
Tenet | Rating: 7.5 | Year: 2020 | Popularity: 85
Dunkirk | Rating: 7.9 | Year: 2017 | Popularity: 90
Interstellar | Rating: 8.6 | Year: 2014 | Popularity: 98
Inception | Rating: 8.8 | Year: 2010 | Popularity: 95
*/
