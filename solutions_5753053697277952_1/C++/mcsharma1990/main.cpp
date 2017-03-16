
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>
#include <sstream>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof(a.begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

pair<int, char> p[26];

int main() {
    freopen("/Users/mahesh/Desktop/codejam/codejam/in.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/codejam/codejam/out.txt", "w", stdout);
    int t = SS;
    rep(_, t) {
        int n = SS;
        int t=  0;
        rep(i, n) {
            int x = SS;
            t += x;
            p[i] = mp(x, 'A'+i);
        }
        printf("Case #%d: ", _+1);
        if (t % 2) {
            sort(p, p+n);
            reverse(p, p+n);
            cout<<p[0].YY<<" ";
            p[0].XX--;
        }
        while (1) {
            sort(p, p+n);
            reverse(p, p+n);
            if (p[0].XX == 0) {
                break;
            }
            S yo = "";
            yo += p[0].YY;
            p[0].XX--;
            if (p[1].XX > 0) {
                yo += p[1].YY;
                p[1].XX--;
            }
            printf("%s ", yo.c_str());
        }
        puts("");
    }
}






