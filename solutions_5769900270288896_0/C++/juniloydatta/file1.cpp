#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 10000000

using namespace std;

int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int t;
    cin>>t;
    for(int kase=1;kase<=t;kase++){
        int r,c,n;
        cin>>r>>c>>n;
        int lim=(1<<(r*c));
        int res=1000;
        for(int i=0;i<lim;i++){
            int bt=__builtin_popcount(i);
            if(bt==n){
                int cnt=0;
                for(int j=0;j<r*c;j++){
                    if(i&(1<<j)){
                        int L=j-1,U=j-c;
                        if(L>=0 && (j/c==L/c) && (i&(1<<L))) cnt++;
                        if(U>=0 && (i&(1<<U))) cnt++;
                    }
                }
                res=min(res,cnt);
            }
        }
        cout<<"Case #"<<kase<<": "<<res<<endl;
    }
    return 0;
}
