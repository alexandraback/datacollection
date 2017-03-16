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
        int m[b];
        REP(i,b) cin>>m[i];
        int lcm=m[0];
        REP(i,b-1){
            lcm=lcm*m[i+1]/(lcm>m[i+1]?gcd(lcm,m[i+1]):gcd(m[i+1],lcm));
        }
        int lcm_cnt=0;
        REP(i,b){
            lcm_cnt+=lcm/m[i];
        }
        n=(n%lcm_cnt);
        if(n==0) n=lcm_cnt;
        int tg[b];
        CLR(tg);
        int ret=-1;
        int ii=0;
        while(ret==-1){
            int minind=INT_MAX;
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
