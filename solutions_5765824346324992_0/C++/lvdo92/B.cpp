/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 5000000000000LL
#define N 100111
#define MAX_LOG 20
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int64 gcd(int64 a, int64 b) { if (a % b) return gcd(b, a % b); else return b; }
inline int64 lcm(int64 a, int64 b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int cases, n, b, k;
int64 m[N], d, bcnn, sl, f[N];
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseNo = 0;
	scanf("%d", &cases);
	while (cases--) {
        scanf("%d %d", &b, &n);
        for (int i = 1;i <= b;i++) scanf("%lld", &m[i]);
        printf("Case #%d: ", ++caseNo);
        if (b == 1) {
            printf("1\n");
            continue;
        }
        d = gcd(m[1], m[2]);
        bcnn = (m[1] * m[2]) / d;
        for (int i = 3;i <= b;i++) {
            d = gcd(bcnn, m[i]);
            bcnn = (bcnn * m[i]) / d;
        }
        for (int i = 1;i <= b;i++) f[i] = 0;
        sl = 0;
        for (int i = 1;i <= b;i++)
            sl += (bcnn / m[i]);
        //cout<<bcnn<<endl;
        if (sl < n) {
            k = n % sl;
            if (k == 0) n = sl;
            else n = k;
        }
        //else { // sl >= n*/
            for (int i = 1;i <= n;i++) {
                int64 mi = INF;
                for (int j = 1;j <= b;j++)
                    if (mi > f[j]) {
                        mi = f[j];
                        k = j;
                    }
                for (int j = 1;j <= b;j++)
                    if (mi == f[j]) {
                        f[j] += m[j];
                        break;
                    }
            }
            printf("%d\n", k);
        //}
	}
	return 0;
}
