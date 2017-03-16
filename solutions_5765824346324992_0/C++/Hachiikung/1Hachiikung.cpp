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
const int MAXN(1005);

int a[MAXN];

void solve(int test){

    int n,m;
    S("%d%d",&n,&m);
    REP(i,n)
        S("%d",&a[i]);

    long long low = 0, high = 1e15, mid, ans, sum;

    while(low <= high)
    {
        mid = (low+high)/2;

        long long num = 0;

        REP(i,n)
            num += (mid/a[i])+1;

        if(num >= m)
            ans = mid, sum = num, high = mid-1;
        else
            low = mid+1;
    }

    FORD(i,n-1,0)
    {
        if(ans%a[i] == 0)
        {
            if(sum == m)
            {
                P("Case #%d: %d\n",test,i+1);
                return;
            }
            else
            {
                sum--;
            }
        }
    }
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}
