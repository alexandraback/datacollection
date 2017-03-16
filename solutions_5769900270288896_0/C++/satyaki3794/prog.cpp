//satyaki3794
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <cassert>
#include <bitset>
#include <iomanip>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define PI (3.14159265)
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define INF (100000005)
#define SIZE (2)
#define TREESIZE (302144)
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define epsilon 1e-8 //add to double before casting to integer
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
 
 
// #define matrix vector<vector<ll> >
// matrix identityMatrix;
// matrix mul(const matrix &a,const matrix &b)
// {
//   int n=a.size();
//   matrix ans(n,vector<ll> (n, 0) );
//   for (int i = 0; i < n; ++i)
//   {
//     for (int j = 0; j < n; ++j)
//     {
//       for (int k = 0; k < n; ++k)
//       {
//         ans[i][j]+= ((long long)a[i][k]*b[k][j])%MOD;
//         ans[i][j]%=MOD;
//       }
//     }
//   }
//   return ans;
// }
 
 
// matrix matpwr(const matrix &a,long long n)
// {
//     if(n==0)
//     {
//       /*define identity */
//       assert(false);
//       return identityMatrix;
//     }
//     if(n==1)
//      return a;
//     matrix tmp=matpwr(a,n/2);
//     tmp=mul(tmp,tmp);
//     if(n&1)
//       tmp=mul(a,tmp);
//     return tmp;
// }
 
 
ll pwr(ll base, ll p, ll mod = MOD){
    ll ans = 1;
    while(p){
        if(p & 1)   ans = (ans * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return ans;
}
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}
 
 
ll lcm(ll a, ll b){
    return (a*b) / gcd(a, b);
}
 
 
ll invMod(ll n){
    return pwr(n, MOD-2);
}




int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

        cout<<"Case #"<<x++<<": ";

        int r, c, n;
        cin>>r>>c>>n;

        if(n == 0){
            cout<<"0\n";
            continue;
        }

        int ans = 10000;
        for(int mask=0;mask<(1<<(r*c));mask++){

            if(__builtin_popcount(mask) != n)   continue;

            int temp = 0;
            for(int i=0;i<(r*c);i++){

                if((mask & (1<<i)) == 0)    continue;

                int row = i/c, col = i%c;
                int pos = (row+1)*c + col;
                if(row < r-1 && ( (mask>>pos)&1 ))  temp++;

                pos = row*c + col+1;
                if(col < c-1 && ( (mask>>pos)&1 ))  temp++;
            }

            ans = min(ans, temp);
        }

        cout<<ans<<endl;
    }

    return 0;
}















    