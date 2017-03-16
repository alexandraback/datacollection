
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
int arr[10000];
int main(){
    int t;
    cin>>t;
    for(int e=1;e<=t;e++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans1=0,ans2=0,mx=0;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<0){
                ans1+=(arr[i-1]-arr[i]);
            }
            mx=max(mx,arr[i-1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>=mx)ans2+=mx;
            else ans2+=arr[i];
        }
        cout<<"Case #"<<e<<": "<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}
