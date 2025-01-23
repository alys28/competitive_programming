#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    map<int, int> ints;
    for (int i = 0; i < n; ++i){
        int y;
        cin >> y;
        int key = x - y;
        if (ints.find(key) == ints.end()){ // create new entry
            ints[y] = i;
        } else {
            cout << ints[key] + 1 << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}