#include <bits/stdc++.h>
#define MAX_B 1010
#define ll long long
#define MVAL 100000000000000000LL
using namespace std;

int t;
ll b, m[MAX_B], n;

ll calculate(ll min) {
    ll ret=0;
    for (int i=0; i<b; i++) {
        ret+=min/m[i]+1;
    }
    return ret;
}

int main(void) {
    if (fopen("b.in","r")) {
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        cin >> b >> n;
        for (int i=0; i<b; i++) cin >> m[i];
        ll low=0, high=MVAL;
        while (low<high) {
            ll mid=(low+high)/2;
            ll val=calculate(mid);
            if (val>=n) high=mid;
            else low=mid+1;
        }
        ll v2=calculate(low-1);
        set<int> possible;
        for (int i=0; i<b; i++) if (low % m[i]==0) possible.insert(i);
        ll v3=n-v2;
        auto it=possible.begin();
        for (int i=0; i<v3-1; i++, it++);
        cout << "Case #" << ii << ": " << (*it+1) << "\n";
    }
    return 0;
}
