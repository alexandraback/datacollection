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

int row1[20], row2[20];

void solve(int test){

    int x,y;

    S("%d",&x);
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            int num;
            S("%d",&num);
            row1[num] = i;
        }
    }

    S("%d",&y);
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            int num;
            S("%d",&num);
            row2[num] = i;
        }
    }

    vector<int>ans;

    FOR(i,1,16)
    {
        if(row1[i] == x && row2[i] == y)
            ans.pb(i);
    }

    P("Case #%d: ",test);

    if(ans.sz == 1) P("%d\n",ans[0]);

    else if(ans.sz >= 1) P("Bad magician!\n");

    else P("Volunteer cheated!\n");
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}

