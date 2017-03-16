#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< ll, ll >
set< pii > s;
set< pii > :: iterator it;
ll t, i, n, m, sum, a[100005], ans1, ans2, _t, f;
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>n;
        sum = 0;
        for(i = 0; i < n; i++) {
            cin>>a[i];
            if(a[i] > 0)
                s.insert(pii(-a[i], i));
            sum += a[i];
        }
        printf("Case #%lld: ", _t);
        while(!s.empty()) {
            it = s.begin();
            s.erase(it);
            pii p = *it;
            ans1 = p.second;
            if(p.first + 1 < 0)
                s.insert(pii(p.first+1, p.second));
            sum--;
            cout<<char(ans1+'A');
            it = s.begin();
            p = *it;
            f = abs(p.first);
            if(f > sum/2) {
                s.erase(it);
                ans2 = p.second;
                if(p.first + 1 < 0)
                    s.insert(pii(p.first+1, p.second));
                sum--;
                cout<<char(ans2+'A');
            }
            cout<<" ";
        }
        s.clear();
        cout<<endl;
    }


    return 0;
}
