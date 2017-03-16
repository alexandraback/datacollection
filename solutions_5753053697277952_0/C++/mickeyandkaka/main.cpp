#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); puts("");}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}

#define pb push_back
#define mp make_pair
#define all(x)  (x).begin(),(x).end()
#define tr(c, it)   for(auto it=c.begin(); it!=c.end(); it++)
#define clr(a, b)   memset(a, b, sizeof(a))

int T;

int n;
struct E{
    int cnt;
    int idx;
}p[33];

bool cmp(const E&a, const E & b){
    if(a.cnt == b.cnt) return a.idx < b.idx;
    return a.cnt > b.cnt;
}

int main()
{
#ifdef LOCAL
    //freopen("in", "r", stdin);

    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt2.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d: ", cas++);

        scanf("%d",&n);
        int total = 0;
        for(int i=0; i<n; i++)
        {
            p[i].idx = i;
            scanf("%d",&p[i].cnt);
            total += p[i].cnt;
        }

        vector<string> ans;
        int fg = 0;

        while(total > 0)
        {
            int maxni, maxn=0;
            for(int i=0; i<n; i++)
                if(p[i].cnt > maxn)
                    maxn = p[i].cnt, maxni=i;

            putchar(maxni+'A');
            p[maxni].cnt--;
            total--;
            fg ^= 1;

            if(total == 2) fg =0;
            if(fg ==0 && total!=0) putchar(' ');
       }
       cout << endl;

    }
    return 0;
}
