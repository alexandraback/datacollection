//
//  mushroom.cpp
//  
//
//  Created by John Nevard on 4/17/15.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int f0(const VI& q) {
    int n = q.size();
    int qty = 0;
    for (int i = 1; i < n; ++i) {
        if (q[i] < q[i - 1])
            qty += q[i - 1] - q[i];
    }
    return qty;
}

int f1(const VI& q) {
    int n = q.size();
    int md = 0;
    for (int i = 1; i < n; ++i)
        if (q[i - 1] - q[i] > md)
            md = q[i - 1] - q[i];
    int qty = 0;
    for (int i = 1; i < n; ++i) {
        if (q[i - 1] >= md)
            qty += md;
        else
            qty += q[i - 1];
    }
    return qty;
}

int main() {
    int n_cases;
    cin >> n_cases;
    for (int c = 1; c <= n_cases; ++c) {
        int n;
        cin >> n;
        VI a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int q0 = f0(a);
        int q1 = f1(a);
        cout << "Case #" << c << ": "<< q0 << ' ' << q1 << '\n';
    }
    return 0;
}