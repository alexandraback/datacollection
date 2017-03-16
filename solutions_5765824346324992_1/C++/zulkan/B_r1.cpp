#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> li;

ll wkt_org_ke_k_dilayani(ll k) {
    ll l = 0, r = 1000*1000*1000;
    r*=r;

    while(l<=r) {
        ll mid = (l+r)/2;

        ll jml_dilayani = 0;

        for(int i =0 ; i < (int)li.size(); i++) {
            jml_dilayani++;
            jml_dilayani += mid/li[i];
        }

        if(jml_dilayani<k) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    return l;
}

void solve() {
    int b,n;
    scanf("%d %d", &b, &n);

    li.clear();
    for(int i =0 ; i < b; i++) {
        int v;
        scanf("%d", &v);
        li.push_back(v);
    }

    if(n <= b) {
        printf("%d\n", n);
        return;
    }


    ll wkt = wkt_org_ke_k_dilayani(n);


    //cout << "DILAYANI PADA " << wkt << '\n';


    ll l = 0, r = n;

    while(l<=r) {
        ll mid = (l+r)/2;
        ll wkt2 = wkt_org_ke_k_dilayani(mid);

        if(wkt2 >= wkt) {
            r = mid-1;
        } else {
            l = mid+1;
        }

    }

    //cout << "ORG " << l << ' ' << r << '\n';

    int tbh = n-l+1;

    int ct =0 ;
    for(int i =0 ; i < b; i++) {
        if(wkt%li[i] == 0) {
            ct++;
            if(ct == tbh) {
                cout << i+1 << '\n';
                return;
            }
        }
    }


}



int main() {
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++) {
        printf("Case #%d: ",i);
        solve();
    }
}