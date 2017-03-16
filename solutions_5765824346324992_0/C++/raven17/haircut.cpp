//
//  haircut.cpp
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

typedef vector<long> VL;

struct Info {
    Info(int r = 0, int id = 0) : r(r), id(id) { }
    
    bool operator<(const Info& i) const {
        if (r != i.r)
            return r < i.r;
        return id < i.id;
    }
    
    int r;
    int id;
};

int who(const VL& m, long n) {
    int b = m.size();
    long lo = 0, hi = n * 100000;
    while (lo < hi) {
        long mid = (lo + hi) / 2;
        long qty = 0, bd = 0;
        for (int i = 0; i < b; ++i) {
            qty += (mid + m[i] - 1) / m[i];
            bd += 1 + mid / m[i];
        }
        
//        cerr << "qty = " << qty << "\tmid = " << mid << '\n';
        
        if (qty >= n)
            hi = mid;
        else if (bd < n)
            lo = mid;
        else {
            vector<Info> v(b);
            for (int i = 0; i < b; ++i)
                if (mid % m[i] == 0 && ++qty == n)
                    return i;
        }
    }
}

int main() {
    int n_cases;
    cin >> n_cases;
    for (int c = 1; c <= n_cases; ++c) {
        int b;
        long n;
        cin >> b >> n;
        VL m(b);
        for (int i = 0; i < b; ++i)
            cin >> m[i];
        int w = who(m, n);
        cout << "Case #" << c << ": "<< w + 1 << '\n';
    }
    return 0;
}