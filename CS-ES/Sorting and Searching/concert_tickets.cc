#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m; // Read n and m
    multiset<int> tickets; 
    // Read ticket prices
    for (int i = 0; i < n; i++) {
        cin >> x;
        tickets.insert(x);
    }


    for (int i = 0; i < m; ++i) {
		cin >> x;
        // Find the greatest ticket less than or equal to the customer's budget
        auto it = tickets.upper_bound(x);
        if (it != tickets.begin()) {
            --it; // Move to the greatest element <= c
            cout << *it << endl;
            tickets.erase(it); // Remove the used ticket
        } else {
            cout << -1 << endl; // No ticket affordable
        }
    }

    return 0;
}
