#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

#define MP make_pair
#define PB push_back
#define PL printf("\n")
#define CENDL "\n"
#define CDOT "."
#define CSP " "
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define bug(x) printf("Bug tester #%d\n", x)
#define cbug(x) { cout << "Bug tester #" << x << CENDL; }
#define PI(x) printf("%d\n", x)


typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long LL;

// ios_base::sync_with_stdio(false);
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int __builtin_popcount (unsigned int x);

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return a * (b / gcd(a, b)); }

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    int tc, b, n; scanf("%d", &tc);
    int a[1005];
    LL asmall[1005];
    priority_queue<ii> pq;
    REP(casenum, tc) {
        pq = priority_queue<ii>();
        scanf("%d %d", &b, &n);
        REP(i, b) scanf("%d", &a[i]);

        LL thelcm = 1;
        REP(i, b) {
            thelcm = lcm(thelcm, (LL) a[i]);
            pq.push(MP(0, -i));
        }

        REP(i, b) asmall[i] = thelcm / a[i];
        int sum = 0;
        REP(i, b) sum += (int) asmall[i];

        if (n % sum > 0) n = n % sum;
        else n = sum;
        //int time = 0;
        REP(i, n-1) {
//            printf("top is %d.%d\n", pq.top().first, pq.top().second);
            ii temp = pq.top(); pq.pop();
            int time = -temp.first;
            int barber = -temp.second;
            time += a[barber];
            pq.push(MP(-time, -barber));
        }

        printf("Case #%d: %d\n", casenum+1, (-pq.top().second) + 1);
    }//end while
    return 0;
} //end main
