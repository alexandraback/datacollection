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

int m[100010];
int T[100010];

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int TT; cin >> TT;
    for(int t = 1; t <= TT; ++t) {
        int b, n;
        cin >> b >> n;
        for(int i = 0; i < b; ++i)
            cin >> m[i];
        
        int ans = 0;
        
        int cl = m[0];
        for(int i = 1; i < b; ++i)
            cl = (cl * m[i]) / __gcd(cl, m[i]);
        
        int ddd = 0;
        for(int i = 0; i < b; ++i)
            ddd += cl / m[i];
        
        n %= ddd; if(n == 0) n += ddd;
        
        //cout << cl << " " << n << " " << ddd << "\n";
        //cout << n << "\n";
        
        for(int i = 0; i < b; ++i)
            T[i] = 0;
        for(int i = 1; i < n; ++i) {
            int pos = min_element(T, T+b) - T;
            //cout << pos << " " ;
            T[pos] += m[pos];
        }
        //cout << "\n";
        ans = min_element(T, T+b) - T;
        
        cout << "Case #" << t << ": ";
        cout << ans+1 << "\n";
    }
    return 0;
}