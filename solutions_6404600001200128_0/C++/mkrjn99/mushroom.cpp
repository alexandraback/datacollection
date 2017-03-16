#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

int main() {
    static int T,N,i,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    rep(k,1,T+1){
        get(N);
        vector<ll> v(N);
        ll m=0;
        rep(i,0,N){
            get(v[i]);
            m=max(m,v[i]);
        }
        ll ans1=0,ans2=0;
        rep(i,1,N){
            if(v[i]<v[i-1])
                ans1+=v[i-1]-v[i];
        }
        
        double l=0;
        rep(i,1,N){
            if(v[i]<v[i-1]){
                double t=double(v[i-1]-v[i])/10;
                if(k==4 && t==10){
                    cerr<<"DEB:"<<t<<' '<<i<<endl;
                }
                l=max(t,l);
            }
        }

//        cerr<<"Rate:"<<l<<endl;
        
        rep(i,0,N-1){
            if(v[i]>10*l){
                ans2+=10*l;
//                if(i+1<N)
//                    v[i+1]+=v[i]-10*l;
            }
            else
                ans2+=v[i];
        }
        
        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %lld %lld",k,ans1,ans2);
        cout<<ans_string<<'\n';
    }
    return 0;
}

