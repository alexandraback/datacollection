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
LL A[100010];
struct barb{
    int num;
    int nxt;
   /* bool operator<(const barb& b)
    {
        if(b.nxt == nxt)
            return num<b.num;
        return nxt < b.nxt ;
    }*/
};
bool operator<(const barb& a, const barb& b)
{
    if(a.nxt == b.nxt)
        return a.num > b.num;
    return a.nxt > b.nxt;
}
priority_queue<barb> P;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int i,j,k,cs,t;
    sf(t);
    FRE(cs,1,t)
    {
        int B, n;
        sff(B,n);
        FRE(i,1,B)
            scanf("%lld",&A[i]);
        LL lcm = 1;
        FRE(i,1,B)
            lcm = (A[i] * lcm)/__gcd(A[i],lcm);
        LL total = 0, nw;
       // D(lcm);
        FRE(i,1,B)
            total+=lcm/A[i];
       // D(total);
        nw = (n-1)%total;
        nw++;
        //D(nw);
        while(!P.empty())
            P.pop();
        FRE(i,1,B)
            P.push({i,1});
        /*FRE(i,1,B)
        {
            D(P.top().num);
            P.pop();
        }*/
        FRL(i,1,nw)
        {
            barb tmp = P.top();
            P.pop();
            P.push({tmp.num, tmp.nxt+A[tmp.num]});
        }
        pf("Case #%d: %d\n",cs,P.top().num);
    }
    return 0;
}

