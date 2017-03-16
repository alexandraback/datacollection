#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define sqr(x)      (x)*(x)
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define pf          printf
#define VI          vector <int>
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define mp          make_pair
#define pi          acos(-1.00)
#define DBG         pf("Hi\n")
#define sz          size()
#define ins         insert
#define fi          first
#define se          second
#define xx          first
#define yy          second
#define inf         (1<<29)
#define MOD         100007
#define eps         1e-9
#define MAX         1440

typedef long long int LL;
typedef double db;

//int dx[] = {+0,+1,+0,-1};
//int dy[] = {+1,+0,-1,+0};
//int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
//int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
//bool check(int n, int pos) {return (bool) (n & (1<<pos));}
//int on(int n, int pos) {return n | (1<<pos); }
//int off(int n, int pos) {return n & ~(1<<pos); }

int A[1010];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int i,j,k,cs,t;
    sf(t);
    FRE(cs , 1, t)
    {
        int n, diff = 0, ans1 = 0, ans2 = 0;
        sf(n);
        FRE(i,1,n)
            sf(A[i]);
        FRE(i,2,n)
            diff = max(diff,A[i-1] - A[i]);
        FRE(i, 1, n-1)
        {
            if(A[i+1] < A[i])
                ans1 += A[i] - A[i+1];
        }
        FRE(i, 1, n-1)
        {
            ans2 += min(A[i], diff);
        }
        pf("Case #%d: %d %d\n",cs,ans1,ans2);
    }
    return 0;
}

