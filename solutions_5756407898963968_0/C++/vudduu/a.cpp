#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

void solve() {
    int a1, a2, x;
    cin >> a1;
    vector<int> v(17, 0);
    F(i, 4) {
        F(j, 4) {
            cin >> x;
            if(a1 == i+1) v[x]++;
        }
    }
    cin >> a2;
    F(i, 4) {
        F(j, 4) {
            cin >> x;
            if(a2 == i+1) v[x]++;
        }
    }
    int res = 0;
    F(i, 17) {
        if(v[i] == 2) {
            if(res) {
                cout << "Bad magician!" << endl;
                return;
            }
            res = i;
        }
    }
    if(res == 0) cout << "Volunteer cheated!" << endl;
    else cout << res << endl;
}

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
