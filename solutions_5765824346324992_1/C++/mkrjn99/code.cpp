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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,K,N;
    int i,k;
    get(T);
    rep(k,1,T+1){
        cin>>K>>N;

        int ans=-1;
        ll f=0,m,l=1e15;
        vector<int> t(K);
        rep(i,0,K)
            get(t[i]);
        
        if(N<=K){
            ans=N-1;
            goto printans;
        }
        N-=K;

//        cerr<<"\t"<<N<<' '<<K<<endl;

        while(l-f>1){
            m=f+(l-f)/2;
            ll count=0,justFinished=0;
            rep(i,0,K){
                if(m%t[i]==0){
                    justFinished++;
                }
                count+=(m-1)/t[i];
            }
//            cerr<<m<<' '<<count<<' '<<justFinished<<endl;
            if(justFinished && (count<N && N<=count+justFinished)){
//                cerr<<"Here at "<<m<<"\n";
                rep(i,0,K){
                    if(m%t[i]==0){
                        count++;
                        if(count==N){
//                            cerr<<"SET ans"<<endl;
                            ans=i;
                        }
                    }
                }
            }
            if(count+justFinished>=N)
                l=m;
            else
                f=m;
        }
        printans:
        assert(ans!=-1);
        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %d",k,ans+1);
        cout<<ans_string<<'\n';
//        if(k==3){
//            cerr<<ans_string<<'\n';
//        }
    }
    return 0;
}

