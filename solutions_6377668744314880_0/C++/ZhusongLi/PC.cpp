#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

vector<ll> X,Y,Z;
ll N;

void solve() {
    ll i,j,k,n,m,x,y,z,n1,n2,x1,y1,x2,y2,x0,y0,q;
    if (N <= 3) {
        for (i = 0;i < N;i++) Z[i] = 0;
        return;
    }
    for (i = 0;i < N;i++) Z[i] = N;
    for (i = 0;i < N;i++) {
        x1 = X[i];
        y1 = Y[i];
        for (j = 0;j < N;j++) {
            if (i == j) continue;
            x2 = X[j];
            y2 = Y[j];
            n1 = 0;
            n2 = 0;
            for (k = 0;k < N;k++) {
                x0 = X[k];
                y0 = Y[k];
                z = (y1 - y2) * (x0 - x1) + (x1 - x2) * (y1 - y0);
                if (z > 0) n1++;
                if (z < 0) n2++;
            }
            q = min(n1,n2);
            Z[i] = min(Z[i],q);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("C-small-attempt1.in.txt","r",stdin);
    //freopen("C-large.in.txt","r",stdin);
    freopen("output","w",stdout);
    ll i,j,k,M,T,x,y,z,r;
    cin >> T;
    for (r = 1;r <= T;r++) {
        cin >> N;
        X.clear();
        Y.clear();
        X.resize(N);
        Y.resize(N);
        Z.clear();
        Z.resize(N);
        for (i = 0;i < N;i++) cin >> X[i] >> Y[i];
        solve();
        cout << "Case #" << r << ": " << endl;
        for (i = 0;i < N;i++) cout << Z[i] << endl;
    }
    
    return 0;
}
