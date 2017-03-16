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

// ios_base::sync_with_stdio(false);
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int __builtin_popcount (unsigned int x);

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    int a[1005];
    int n;
    REP(casenum, tc) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", &a[i]);
        int ans1 = 0, ans2 = 0;
        int big = 0;
        REP(i, n-1) {
            int temp = a[i] - a[i+1];
            if (temp > 0) ans1 += temp;
            big = max(big, temp);
        }

//        double rate = big / 10.0;
        REP(i, n-1) {
            if (a[i] <= big) ans2 += a[i];
            else ans2 += big;
        }
        printf("Case #%d: %d %d\n", casenum+1, ans1, ans2);


    }//end while
    return 0;
} //end main
