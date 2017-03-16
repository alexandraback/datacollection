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

LL a[1123];//, f[1123];

LL b, n;

int poss(LL t){
    LL ans = 0, i, x;
    for(i = 1; i <= b; i++){
        x = 0;
        x += (t / a[i]);
        x++;
        //f[i] = a[i] * x;
        ans += x;
    }
    if(ans >= n) return 1;
    return 0;
}

int solve(){
    LL l, r, mid, i;
    cin>>b>>n;
    for(i = 1; i <= b; i++){
        cin>>a[i];
    }
    if(n <= b){
        cout<<n<<endl;
        return 0;
    }
    l = 1; r = 1000000000000000LL;
    while(l <= r){
        if(l == r || l == r - 1){
            if(!poss(l)){
                l = r;
            }
            break;
        }
        LL mid = (l + r) / 2;
        if(poss(mid)){
            r = mid;
        }
        else l = mid + 1;
    }
    //cout<<l<<endl;
    //poss(l);
    LL ans = n;
    //cout<<l<<" "<<n<<" ";
    for(i = 1; i <= b; i++){
        ans -= (l / a[i]);
        if( (l % a[i]) != 0){
            ans--;
        }
    }

    for(i = 1; i <= b; i++){
        if(l % a[i] == 0) ans--;
        if(ans <= 0 && l % a[i] == 0){
            cout<<i<<endl;
            return 0;
        }
    }
    //cout<<1<<" "<<ans<<endl;
    return 0;
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
