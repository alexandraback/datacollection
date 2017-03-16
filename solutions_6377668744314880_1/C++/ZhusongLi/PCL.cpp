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

double Pi = acos(-1.0);
ll N;
vector<ll> X,Y,Z;

struct node {
    ll x;
    ll y;
    double ang;
};

bool operator < (node a,node b) {
    return a.ang < b.ang;
}

void solve() {
    ll i,j,k,n,m,x,y,z,n1,n2,x1,y1,x2,y2,x0,y0,q,ze = 0;
    double a;
    if (N <= 3) {
        for (i = 0;i < N;i++) Z[i] = 0;
        return;
    }
    for (i = 0;i < N;i++) Z[i] = N;
    vector<node> Q(N - 1);
    for (i = 0;i < N;i++) {
        x1 = X[i];
        y1 = Y[i];
        k = 0;
        for (j = 0;j < N;j++) {
            if (i == j) continue;
            x2 = X[j];
            y2 = Y[j];
            if (x1 == x2) {
                if (y2 > y1) a = Pi / 2.0;
                else a = Pi * 3.0 / 2.0;
            }
            else {
                x0 = x2 - x1;
                y0 = y2 - y1;
                a = atan(double(y0) / double(x0));
                if (x0 < 0) a += Pi;
                if (a < 0.0) a += 2.0 * Pi;
            }
            Q[k].x = x2;
            Q[k].y = y2;
            Q[k].ang = a;
            k++;
        }
        sort(Q.begin(),Q.end());
        ll mc = N - 2,md = 0,ma = 0,mb = 0;
        ll res = N - 1;
        for (j = 0;j < N - 1;j++) {
            x2 = Q[j].x;
            y2 = Q[j].y;
            ma = max(ma,j + 1);
            mb = max(mb,j);
            while ((y1 - y2) * (Q[ma % (N - 1)].x - x1) + (x1 - x2) * (y1 - Q[ma % (N - 1)].y) > 0) ma++;
            while ((y1 - y2) * (Q[mb % (N - 1)].x - x1) + (x1 - x2) * (y1 - Q[mb % (N - 1)].y) >= 0 && mb < j + N - 1) mb++;
            while ((y1 - y2) * (Q[mc % (N - 1)].x - x1) + (x1 - x2) * (y1 - Q[mc % (N - 1)].y) < 0) mc++;
            while ((y1 - y2) * (Q[md % (N - 1)].x - x1) + (x1 - x2) * (y1 - Q[md % (N - 1)].y) <= 0 && md < j + N - 1) md++;
            n1 = max(ze,ma - md);
            n2 = max(ze,mc - mb);
            res = min(res,n1);
            res = min(res,n2);
            if (mb == j + N - 1 || md == j + N - 1) res = 0;
        }
        Z[i] = res;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("C-small-attempt1.in.txt","r",stdin);
    freopen("C-large.in.txt","r",stdin);
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
