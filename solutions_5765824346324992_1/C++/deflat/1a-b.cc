#include<iostream>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<climits>
#include<utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define FORB(i,s,e,st) for (int i = int(s); i < int(e); i+=(int(st)))
#define FOR(i,s,e) FORB(i,s,e,1)
#define REP(i,x) FOR(i,0,x)
#define CLR(a) memset((a), 0 ,sizeof(a))


const int MOD = 1000000007;
const double PI  = acos(-1.0);

int gcd(int a, int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(){

    int T;
    cin>>T;
    REP(t,T){
        cout<<"Case #"<<(t+1)<<": ";
        int b,n;
        cin>>b>>n;
        ll m[b];
        REP(i,b) cin>>m[i];
        if(n<=b){
            cout<<(n==b?b:(n%b))<<"\n";
            continue;
        }
        ll bd=0;
        for(int i=40;i>=0;i--){
                     ll ck=(1L<<i)+bd;
            ll cnt=0;
            REP(j,b){
                cnt+=ck/m[j]+1;
            }
            if(cnt<n)bd=ck;
        }

        ll tg[b];
        ll ii=LLONG_MAX;
        REP(i,b){
            n-=(bd/m[i])+1;
            tg[i]=(bd/m[i])*m[i];
            tg[i]+=m[i];
            
            ii=min(ii,tg[i]);

        }
        int ret=-1;

        while(ret==-1){
            ll minind=LLONG_MAX;
            REP(j,b){
                if(ii==tg[j]){
                    n--;
                    tg[j]+=m[j];
                    if(n==0){
                        ret=j;
                        break;
                    }
                }
                minind=min(minind,tg[j]);
            }
            ii=minind;
        }
        
        cout<<(ret+1)<<"\n";
        
    }
}
