/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN();

struct pt
{
    long long x,y;
    int id;
};

bool cmp (pt a, pt b) {
     return a.x<b.x || a.x==b.x && a.y<b.y;
}

bool cw (pt a, pt b, pt c) {
    //return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
     return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) <= 0;
}

bool ccw (pt a, pt b, pt c) {
    //return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
     return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) >= 0;
}

void convex_hull (vector <pt> & a) {
    if (a.sz == 1) return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector <pt> u, d;
    u.push_back (p1);
    d.push_back (p1);
    for (int i=1; i<a.sz; ++i) {
        if (i == a.sz-1 || cw (p1, a[i], p2)) {
            while (u.sz >= 2 && !cw (u[u.sz-2], u[u.sz-1], a[i]))
	         u.pop_back ();
	     u.push_back (a[i]);
	 }
	 if (i == a.sz-1 || ccw (p1, a[i], p2)) {
	     while (d.sz >= 2 && !ccw (d[d.sz-2], d[d.sz-1], a[i]))
                d.pop_back ();
            d.push_back (a[i]);
        }
    }
    a.clear ();
    for (int i=0; i<u.sz; ++i)
        a.push_back (u[i]);
    for (int i=d.sz-2; i>0; --i)
        a.push_back (d[i]);
}

int ans[25];

void solve(int test){

    int n;
    S("%d",&n);

    vector<pt>a;

    REP(i,n)
    {
        pt t;
        int x,y;
        S("%d%d",&x,&y);
        t.x = x;
        t.y = y;
        t.id = i;
        a.pb(t);
    }

    REP(i,n)
        ans[i] = n;

    FOR(i,1,(1<<n)-1)
    {
        vector<pt>b;

        int cut = 0;

        REP(j,n)
        {
            if(i&(1<<j))
                b.pb(a[j]);
            else
                cut++;
        }

        convex_hull(b);

        REP(j,b.sz)
            ans[b[j].id] = min(ans[b[j].id], cut);
    }

    P("Case #%d:\n",test);
    REP(i,n)
        P("%d\n",ans[i]);

}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}
