//#include "testlib.h"

#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <cassert>
#include <queue>

using namespace std;

int a[100010];

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int TT; cin >> TT;
    for(int t = 1; t <= TT; ++t) {
        int n; cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        
        int ans1 = 0, ans2 = 0, d = 0;
        for(int i = 1; i < n; ++i) {
            if (a[i] < a[i-1])
                ans1 += a[i-1] - a[i];
            
            if (a[i] < a[i-1])
                d = max(d, a[i-1]-a[i]);
        }
        
        for(int i = 0; i < n-1; ++i)
            ans2 += min(a[i], d);
    
        cout << "Case #" << t << ": ";
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}