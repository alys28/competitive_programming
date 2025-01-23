#include <iostream>
#include <vector>
using namespace std;
struct timeSlot {
    int start;
    int end;
};

int main(){
    int m;
    cin >> m;
    int currentTime = 0;
    int moviesWatched = 0;
    vector<timeSlot> movies(0);
    for (int i = 0; i < m; ++i){
        int start;
        int end;
        cin >> start >> end;
        movies.push_back(timeSlot{start, end});
    }
    sort(movies.begin(), movies.end(), [](const timeSlot& a, const timeSlot& b) {
        return a.end < b.end;
    });
    for (auto movie: movies){
        if (currentTime <= movie.start){
            ++moviesWatched;
            currentTime = movie.end;
        }
    }
    cout << moviesWatched << endl;
}
