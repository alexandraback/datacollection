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
#define INF 500000000
#define N 100111
#define MAX_LOG 20
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int cases, n;
int a[N], x, y;
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseNo = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
        printf("Case #%d: ", ++caseNo);
        x = y = 0;
        for (int i = 1;i <= n - 1;i++)
            if (a[i] > a[i + 1]) x += (a[i] - a[i + 1]);
        int t = 0;
        for (int i = 1;i <= n - 1;i++)
            t = max(t, a[i] - a[i + 1]);
        for (int i = 1;i <= n - 1;i++)
            if (a[i] <= t) y += a[i];
            else y += t;
        printf("%d %d\n", x, y);
    }
	return 0;
}
