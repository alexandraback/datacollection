#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define mp make_pair

using namespace std;

typedef long long ll;

vector<ll> v;
ll b, n;

ll count(ll t) {
    ll res=0;
    for(int i=0; i<b; ++i) {
        res += (t/v[i]) + (t%v[i] > 0);
    }
    return res;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, NT;
    cin>>NT;
    int i, j, m;
    for(T=1; T<=NT; ++T) {
        cin>>b>>n;
        v.clear();
        v.resize(b);
        for(i=0; i<b; ++i) {
            cin>>v[i];
        }
        ll st, en, mid;
        st = 0; en = 100000100000000LL / b;
        while(en-st > 1) {
            mid = (st+en) / 2;
            ll cur = count(mid);
            if (cur < n) st = mid;
            else en = mid;
        }
        ll t = st;
        ll passed = count(t);
        ll left = n - passed;
        ll res = -1;
        for(i=0; i<b; ++i) {
            if (t % v[i] == 0) {
                left--;
                if (left == 0) {
                    res = i+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", T, res);
    }
    return 0;
}

