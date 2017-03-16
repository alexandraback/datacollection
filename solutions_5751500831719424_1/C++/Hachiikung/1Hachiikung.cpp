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
const int MAXN(105);

string a[MAXN];

int n;

vector< pair<char,int> >b[MAXN];

int f(int num,int j){
    int ret = 0;
    REP(i,n)
        ret += abs(b[i][j].Y - num);
    return ret;
}

void solve(int test){

    S("%d",&n);
    REP(i,n)
        cin >> a[i];

    REP(i,n)
        b[i].clear();

    REP(i,n)
    {
        for(int j=0,k=0;j<a[i].sz;j=k)
        {
            while(k<a[i].sz && a[i][k]==a[i][j]) k++;

            b[i].pb(PII(a[i][j],k-j));
        }
    }

    bool fail = false;

    REP(i,n)
    {
        if(b[i].sz != b[0].sz)
        {
            fail = true;
            break;
        }
    }

    if(fail)
    {
        P("Case #%d: Fegla Won\n",test);
        return;
    }

    REP(j,b[0].sz)
    {
        REP(i,n)
        {
            if(b[i][j].X != b[0][j].X)
            {
                fail = true;
                break;
            }
        }
        if(fail) break;
    }

    if(fail)
    {
        P("Case #%d: Fegla Won\n",test);
        return;
    }

    int ans = 0;

    REP(j,b[0].sz)
    {
        int best = INF;
        FOR(num,1,100)
            best = min(best, f(num,j));
        ans += best;
    }

    P("Case #%d: %d\n",test,ans);
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}

