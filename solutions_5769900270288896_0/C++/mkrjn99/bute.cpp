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

bool next(vector<int> &v){
    int i=v.size()-1;
    while(i>=0){
        if(v[i])
            v[i]=0;
        else{
            v[i]=1;
            break;
        }
        i--;
    }
    if(i==-1)
        return false;
    else
        return true;
}

int main() {
    static int T,N,i,j,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    rep(k,1,T+1) {
        int R,C,M;
        cin>>R>>C>>N;
        M=R*C;
        vector<int> per(M,0);
        int ans=hell;
        do{
            int c=0,unhap=0;
            rep(i,0,M)
                if(per[i])
                    c++;
            if(c==N){
                rep(i,0,M){
                    if(per[i]){
                        int pre1=i-1,pre2=i-C;
                        if(pre1/C == i/C && pre1>=0 && per[pre1]){
                            unhap++;
//                            cerr<<i<<' '<<pre1<<endl;
                        }
                        if(pre2>=0 && per[pre2]){
                            unhap++;
//                            cerr<<i<<' '<<pre2<<endl;
                        }
                    }
                }
                ans=min(ans,unhap);
            }
        }while(next(per));
        static char ans_string[100];
        sprintf(ans_string, "Case #%d: %d\n",k,ans);
        cout<<ans_string;
    }
    return 0;
}

