
//Author : Ujjawal Dixit  , ABV-IIITM
//Task : test

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1e9
#define MIN -1e9
using namespace std;
typedef double ld;
typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define FOR(i,n,m) for(int i=0;i<n;i+=m)
#define For(i,n,m) for(int i=1;i<=n;i+=m)
#define max(a,b)    (a>=b?a:b)
#define min(a,b)    (a<b?a:b)
#define countbits(num)   __builtin_popcount(num)
#define countbitsll(num)   __builtin_popcountll(num)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define p(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define pln()  printf("\n")
#define getstr(in) getline(cin,in)
#define getc() getchar()
#define uj() int t; scanf("%d",&t); while(t--)
ll mpow(ll a, ll n) 
{ll ret=1;ll b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
    return (ll)ret;}
template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
struct bb {
    long long tt,ii;
    bb() {}
    bb(long long _tt,long long _ii) {
        tt=_tt,ii=_ii;
    }
    bool operator<(const bb&p)const {
        return (tt>p.tt || (tt==p.tt && ii>p.ii));
    }
};
int main() {
    int t;
    cin>>t;
    for(int z=1; z<=t; z++) {
        int b,n,x,y=-1,mx=1,gcd;
        cin>>b>>n;
        priority_queue<bb>q;
        long long int m[b+1];
        vector<int>v;
        for(int i=0; i<b; i++) {
            cin>>x;
            q.push(bb(x,i+1));
            v.push_back(i+1);
            m[i+1]=x;
            mx=(mx*x)/(__gcd(mx,x));
        }
        int ii=0;
        while(ii<=mx) {
            bb w=q.top();
            //cout<<w.ii<<endl;
            q.pop();
            v.push_back(w.ii);
            w.tt+=m[w.ii];
            q.push(w);
            ii=w.tt;
        }
        v.pop_back();
        int sz=v.size();
        n--;
        n%=sz;
        cout<<"Case #"<<z<<": "<<v[n]<<"\n";
    }
    return 0;
}