#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum subarray sum
int main() {
    long long n;
    cin >> n;
    long long res;
    long long maxEnding;
    for (int i = 0; i < n; ++i){
        long long x;
        cin >> x;
        if (i == 0){
            res = x;
            maxEnding = x;
        }
        else {
            maxEnding = max(maxEnding + x, x);
            res = max(res, maxEnding);
        }
    }

    cout << res << endl;
}
