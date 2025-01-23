#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> coins;
    int idx = -1;
    long long currNum = 1;
    long long currSum = 0;
    for (int i = 0; i < n; ++i){
        long long x;
        cin >> x;
        coins.push_back(x);

    }
    sort(coins.begin(), coins.end());
    while (idx + 1 < coins.size() && currNum - coins[++idx] >= 0){
        currNum += coins[idx];
    }

    cout << currNum << endl;
    return 0;
}
