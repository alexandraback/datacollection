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

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


        struct Comp {
          bool operator()(PII const& lhs, PII const& rhs) {
            if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first < rhs.first;
          }
        };
int main() {
    freopen("/Users/knaresh/codechef/codechef/codechef/in.txt", "r", stdin);
    freopen("/Users/knaresh/codechef/codechef/codechef/out.txt", "w", stdout);
    int t = SS;
    int pn = 1;
    while(t--) {
        int b = SS;
        int n = SS;
        set<PII, Comp> ss;
        VI v;
        v.push_back(0);
        LL lcm = 1;
        int best = 0;
        int min  = INT_MAX;
        REP(i, b) {
            int k = SS;
            v.push_back(k);
            ss.insert(make_pair(0, i+1));
            if(k < min) {min = k; best= i+1;}
            lcm = lcm*k/gcd(lcm, k);
        }
        int persons = 0;
        FOR(i, 1, b+1) persons+= lcm/v[i];
        n = n%persons;
        int ser = 0;
        REP(i, n){
            auto curr = ss.begin();
            int time = curr->first;
            ser = curr->second;
            ss.erase(*curr);
            ss.insert(make_pair(time+v[ser], ser));
        }
        ser = ser ? ser : best;
        printf("Case #%d: %d\n", pn++, ser);
    }
    return 0;
}