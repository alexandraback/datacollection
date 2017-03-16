//author Naresh
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define IFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define FORD(i, a, b, c) for(int i=(a); i<(b); i+=(c))

#define SI(x) ((int)x.size())
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a, b)
#define SORT(a) sort(a.begin(),a.end())
#define ITER(it,a) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define ALL(a) a.begin(),a.end()
#define INF 1000000000
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({long long int x;scanf("%lld", &x);x;})

#define V vector
#define S string
#define FST first
#define SEC second
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<S, int> PSI;
typedef pair<S, S> PSS;
typedef map<S, int> MSI;
typedef map<S, S> MSS;

int main() {
    freopen("/Users/knaresh/codechef/codechef/codechef/in.txt", "r", stdin);
    freopen("/Users/knaresh/codechef/codechef/codechef/out.txt", "w", stdout);
    int t = SS;
    int pn = 1;
    while(t--) {
        int n = SS;
        VI v;
        REP(i, n) {
            int k = SS;
            v.push_back(k);
        }
        int ans1 = 0;
        int last = 0;
        int max = 0;
        for (auto& i: v) {
            if(i < last) ans1 += last -i;
            if(last-i > max) max = last-i;
            last = i;
        }
        long long int ans2 = 0;
        for (int i = 0; i < n-1; i++) {
            ans2 += min(v[i], max);
        }
        printf("Case #%d: %d %lld\n", pn++, ans1, ans2);
    }
    return 0;
}