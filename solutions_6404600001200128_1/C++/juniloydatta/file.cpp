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
int ar[1111];

int main(){
    freopen("fileIN.in","r",stdin);
    freopen("fileOUT.out","w",stdout);
    int test;
    cin>>test;
    for(int kase=1;kase<=test;kase++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>ar[i];
        int a=0,b=0,mx=0;
        for(int i=1;i<n;i++){
            if(ar[i-1]>ar[i])
                a+=abs(ar[i-1]-ar[i]),mx=max(mx,abs(ar[i-1]-ar[i]));
        }
        if(mx>0){

            for(int i=0;i<n-1;i++){
                  b+=min(ar[i],mx);
            }
        }
        cout<<"Case #"<<kase<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}
