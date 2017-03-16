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
        
        long long tm = 0;
        for(int i = 50; i >= 0; --i) {
            long long tm1 = tm + (1ll << i);
            long long cnt = 0;
            for(int i = 0; i < b; ++i)
                cnt += (tm1+m[i]-1) / m[i];
            
            if (cnt < n)
                tm = tm1;
        }
        
        tm++;
        
       
        
        int ans = 0, r = n;
        for(int i = 0; i < b; ++i) {
            //cout << tm-1 << " " << m[i] << "\n";
            r -= (tm-1+m[i]-1) / m[i];
            //if (r == 0)
              //  ans = i+1;
        }
        
        //cout << tm  << " " << r << " **\n";
        
        for(int i = 0; i < b; ++i)
            if ((tm-1) % m[i] == 0) {
                ans = i+1;
                r--;
                
                if (r <= 0)
                    break;
            }
        cout << "Case #" << t << ": ";
        cout << ans << "\n";
    }
    return 0;
}