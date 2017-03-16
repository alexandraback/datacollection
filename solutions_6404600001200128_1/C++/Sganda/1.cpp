#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LL long long
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define MOD 1000000007
#define SQ 112345
#define N 1123456
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = A; I <= B; ++I)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>

LL a[1123];

set<LL> s;
set<LL>::iterator it;

int solve(){
    s.clear();
    LL n, ans1 = 0, i;
    LL x = 0, ans = 0;
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(i = 1; i < n; i++){
        if(a[i] > a[i + 1]){
            ans1 += a[i] - a[i + 1];
        }
    }
    for(i = 1; i < n; i ++){
        s.insert(a[i] - a[i + 1]);
    }
    it = s.end(); it--;
    x = *it;
    if(x < 0){
        x = 0;
    }
    for(i = 1; i < n; i++){
         ans += min(a[i], x);
    }
    cout<<ans1<<" "<<ans<<endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1, o = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<o++<<": ";
        solve();
    }
    return 0;
}
