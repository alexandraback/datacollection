#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

vector<pair<char,int> > v[200];
string st;
int d[200];
int l;
int n;
int T;
vector<int> cc;
bool res;

int process(){
    if (res == false) return -1;
    int sum = 0;
    memset(d,0,sizeof(d));
    for (int j = 0; j < l; j++)
    {
        cc.clear();
        for (int i = 1; i <= n; i++)
        {
            if (v[i][j].first == v[1][j].first)
                cc.push_back(v[i][j].second);
            else
                return -1;
        }
        sort(cc.begin(),cc.end());
        for (int i = 0; i < n; i++)
        {
            sum+=abs(cc[i]-cc[((int)cc.size()-1)/2]);
        }
    }
    return sum;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("ACJR1.out","w",stdout);
    scanf("%d",&T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d",&n);
        getline(cin,st);
        res = true;
        l = -1;
        for (int i = 1; i <= n; i++)
        {
            getline(cin,st);
            //cout<<st<<endl;
            v[i].clear();
            for (int j = 0; j < st.length(); j++)
            {
                if (((int)v[i].size() == 0) || (st[j] != v[i][(int)v[i].size() - 1].first))
                    {
                        v[i].push_back(make_pair(st[j],0));
                    }
                v[i][(int)v[i].size() - 1].second++;
                //cout<<v[i][(int)v[i].size() - 1].first<<' '<<v[i][(int)v[i].size() - 1].second<<endl;
            }
            if (l == -1)
                l = v[i].size();
            else
            if (v[i].size() != l)
                res = false;
        }
        int sres = process();
        if (sres == -1)
        {
            printf("Case #%d: Fegla Won\n",x);
        }
        else
        {
            printf("Case #%d: %d\n",x,sres);
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

