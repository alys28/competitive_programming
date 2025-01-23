#include <iostream>
#include <map>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1;
    map<int, int> nums;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        nums[x] = i;
    }
    for (int i = 1; i < n; ++i){
        if (nums[i] > nums[i + 1]){
                ++count;
        }
    }
    cout << count << endl;
}
