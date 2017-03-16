#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

string get(string s)
{
    s.erase(unique(ALL(s)), s.end());
    return s;
}

int f(vector<int> const & a)
{
    int res = 100500, n = SZ(a);
    FOR(cnt,1,111)
    {
        int r = 0;
        REP(i,n)r+=abs(a[i]-cnt);
        if(r<res)res=r;
    }
    return res;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w+", stdout);
    
    int TTT;
    scanf("%d", &TTT);
    FOR(ttt,1,TTT+1)
    {
        int n;
        scanf("%d", &n);

        vector<string> ss(n);
        REP(i,n)cin>>ss[i];

        char ok = 1;
        string red = get(ss[0]);
        FOR(i,1,n)
        {
            string r = get(ss[i]);
            if (r != red)
            {
                ok=0;
                break;
            }
        }

        if (!ok)
        {
            printf("Case #%d: Fegla Won\n", ttt);
            continue;
        }

        vector<vector<int> > szs(SZ(red));
        REP(i,n)
        {
            string const & s = ss[i];
            int m = SZ(s), k=0, cnt=0;
            REP(j,m)
            {
                if(s[j]==red[k])++cnt;
                else
                {
                    szs[k].push_back(cnt);
                    ++k;
                    cnt=1;
                }
            }
            szs[k].push_back(cnt);
        }

        int res = 0;
        REP(i,SZ(szs))res+=f(szs[i]);

        printf("Case #%d: %d\n", ttt, res);
    }

    return 0;
}


