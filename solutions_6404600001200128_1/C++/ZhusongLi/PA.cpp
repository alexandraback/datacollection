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
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int main() {
    ios::sync_with_stdio(false);
    //freopen("A-small-attempt0.in.txt","r",stdin);
    freopen("A-large.in.txt","r",stdin);
    freopen("output","w",stdout);
    ll i,j,k,T,n,m,x,y,z,N,res1,res2,rk;
    cin >> T;
    for (x = 1;x <= T;x++) {
        cin >> N;
        vector<ll> res(N);
        for (y = 0;y < N;y++) cin >> res[y];
        res1 = 0;
        for (y = 1;y < N;y++) {
            if (res[y] < res[y - 1]) res1 += res[y - 1] - res[y];
        }
        rk = 0;
        for (y = 1;y < N;y++) {
            if (res[y] < res[y - 1]) rk = max(rk,res[y - 1] - res[y]);
        }
        res2 = 0;
        z = res[0];
        for (y = 0;y < N - 1;y++) {
            if (res[y] > z) z = res[y];
            if (z >= rk) res2 += rk;
            else res2 += z;
            z -= rk;
            if (z < 0) z = 0;
        }
        cout << "Case #" << x << ": " << res1 << ' ' << res2 << endl;
    }
    return 0;
}
