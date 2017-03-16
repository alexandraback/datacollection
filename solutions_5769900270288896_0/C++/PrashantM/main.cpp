#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <map>

using namespace std;

int occ[20][20];

void solve(int t) {
    int r,c,n; cin>>r>>c>>n;
    int ans = 10000000;
    for(int i = 0;i < (1<<(r * c));i++) {
        int cnt = 0;
        for(int j = 0;j < (r * c);j++) if((1<<j) & i) cnt++;
        
        if(cnt != n) continue;
        for(int j = 0;j < (r * c);j++) {
            if((1<<j) & i) {
                occ[j/c][j % c] = 1;
            }
            else {
                occ[j/c][j % c] = 0;
            }
        }
        int un = 0;
        for(int j = 0;j < r;j++) {
            for(int k = 0;k < c;k++) {
                if(!occ[j][k]) continue;
                if(j < (r - 1) && occ[j + 1][k]) un++;
                if(k < (c - 1) && occ[j][k + 1]) un++;
            }
        }
        ans = min(ans,un);
    }
    printf("Case #%d: %d\n",t,ans);
    
}

int main() {
    freopen("/Users/administrator/Desktop/B-small-attempt0.in","r",stdin);
    freopen("/Users/administrator/Desktop/gcjoutput.txt","w",stdout);
    int t; cin>>t;
    for(int i = 1;i <= t;i++) {
        solve(i);
    }
    
}