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
typedef pair<int, ii> iii;
typedef pair<ll, int> pli;


#define matrix vector< vector<ll> >

matrix matmul(matrix &a, matrix &b){
    int i, j, k, n = a.size();
    matrix ans (n, vector<ll>(n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            ll temp = 0;
            for(k=0;k<n;k++)    temp = (temp + a[i][k] * b[k][j]) % MOD;
            ans[i][j] = temp;
        }
    return ans;
}

matrix matpwr(matrix &a, ll p){
    int n = a.size();
    matrix ans(n, vector<ll> (n));
    for(int i=0;i<n;i++)    ans[i][i] = 1;

    while(p){
        if(p&1) ans = matmul(ans, a);

        a = matmul(a, a);
        p >>= 1;
    }
    return ans;
}


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


ll invMod(ll n, ll mod = MOD){
    return pwr(n, mod-2, mod);
}




int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    freopen("A-small-attempt0 (1).in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
// t=1;
    while(t--){

        cout<<"Case #"<<x++<<": ";
        int n;
        cin>>n;
        priority_queue<ii> pq;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            pq.push(ii (a, i));
        }

        while(pq.size() > 2){

            if(pq.top().ff == 1)    break;

            ii a = pq.top();    pq.pop();
            ii b = pq.top();    pq.pop();

            a.ff--;
            b.ff--;
            cout<<" "<<(char)('A'+a.ss)<<(char)('A'+b.ss);
            if(a.ff > 0)    pq.push(a);
            if(b.ff > 0)    pq.push(b);
        }

        if(!pq.empty() && pq.top().ff == 1){
            if(pq.size() % 2 == 1){
                cout<<" "<<(char)(pq.top().ss+'A');
                pq.pop();
            }


            while(!pq.empty()){
                ii a = pq.top();    pq.pop();
                ii b = pq.top();    pq.pop();
                cout<<" "<<(char)('A'+a.ss)<<(char)('A'+b.ss);
            }
        }
        else if(!pq.empty()){

            assert(pq.size() == 2);
            while(pq.size() > 0){

                ii a = pq.top();    pq.pop();
                ii b = pq.top();    pq.pop();

                a.ff--;
                b.ff--;
                cout<<" "<<(char)('A'+a.ss)<<(char)('A'+b.ss);
                if(a.ff > 0)    pq.push(a);
                if(b.ff > 0)    pq.push(b);
            }
        }

        cout<<endl;
    }
    return 0;
}










