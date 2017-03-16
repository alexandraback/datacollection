#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0 ; i< n ; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    while (sum > 0) {
        string s = "";
        for(int i=0 ; i< n ; i++) {
            if (a[i]*2 > sum - 1) {
                s+=('A'+i);
                a[i] --;
                sum--;
            }
        }
        if (s=="") {
            int mx = 0;
            for(int i=1 ; i< n ; i++) {
                if (a[i] > a[mx]) {
                    mx= i;
                }
            }
            s+= 'A'+mx;
            sum -- ;
            a[mx]--;
        }
        cout<<s<<" ";
    }
    cout<<endl;
}

int main(int argc, const char **argv) {
    if(argc>=2) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    int T;
    cin>>T;
    for(int t=1 ; t<=T ; t++) {
        printf("Case #%d: ",t);
        solve();
        cerr<<"DONE CASE "<<t<<endl;
    }
}

