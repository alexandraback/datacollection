#include<bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define LL long long int
#define LD long double
#define D double
#define pii pair<int,int>
#define V vector

vector<string> vs;
vector< vector<int> > vvi;
vector<int> vi;

inline void solve(){
    int n;
    string s, p;
    int i, j, k, l;
    cin>>n;
    vs.clear();
    vvi.clear();
    for(i = 0; i < n; i++){
        vi.clear();
        cin>>s;
        p = "";
        l = s.length();
        j = 0;
        while(j < l){
            k = j + 1;
            while(k < l){
                if(s[k] != s[j]){
                    break;
                }
                k++;
            }
            vi.PB(k - j);
            p = p + s[j];
            j = k;
        }
        vs.PB(p);
        vvi.PB(vi);
    }
    for(i = 1; i < n; i++){
        if(vs[i] != vs[0]){
            cout<<"Fegla Won"<<endl;
            return;
        }
    }
    l = vvi[0].size();
    int ans = 0, tmp, tmp2;
    while(l--){
        k = 0;
        tmp = 10000;
        for(i = 0; i < n; i++){
            k = max(k, vvi[i][l]);
        }
        for(j = 1; j <= k; j++){
            tmp2 = 0;
            for(i = 0; i < n; i++){
                if(vvi[i][l] >= j){
                    tmp2 += vvi[i][l] - j;
                }
                else{
                    tmp2 -= vvi[i][l] - j;
                }
            }
            tmp = min(tmp, tmp2);
        }
        ans += tmp;
    }
    cout<<ans<<endl;
    return;
}

int main(){
#if 1
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    cin>>t;
    for(int i = 0; i < t; i++){
        cout<<"Case #"<<i + 1<<": ";
        solve();
    }
    return 0;
}
