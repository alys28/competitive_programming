#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> startTimes;
    vector<int> endTimes;
    int maxCount = 0;
    int currentCount = 0;
    int i = 0; // start
    int j = 0; // end
    for (int k = 0; k < m; ++k){
        int start;
        int end;
        cin >> start >> end;
        startTimes.push_back(start);
        endTimes.push_back(end);
    }
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());
    while (i < startTimes.size() && j < endTimes.size()){
        if (startTimes[i] < endTimes[j]){ // new customer comes in
            ++currentCount;
            ++i;
        } else { // customer leaves before a new one enters
            --currentCount;
            ++j;
        }
        if (currentCount > maxCount){
            maxCount = currentCount;
        }
    }
    cout << maxCount << endl;
}