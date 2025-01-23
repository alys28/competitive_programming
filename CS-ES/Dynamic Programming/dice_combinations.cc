#include <iostream>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;

int countCombinationsHelper(int n, map<int, int> &memo) {
    if (n == 0) {
        return 1;  // Base case: 1 way to form sum 0
    }
    if (n < 0) {
        return 0;  // No way to form negative sums
    }
    if (memo.count(n) > 0) {
        return memo[n];  // Return cached result
    }

    int result = 0;
    for (int i = 1; i <= 6; ++i) {  // Iterate over dice outcomes (1 to 6)
        result = (result + countCombinationsHelper(n - i, memo)) % MOD;
    }
    memo[n] = result;  // Store the result in the memoization map
    return result;
}


int countCombinations(int n){
    map<int, int> memo;
    return countCombinationsHelper(n, memo);
}

int main(){
    int n;
    cin >> n;
    cout << countCombinations(n) << endl;
    return 0;
}
