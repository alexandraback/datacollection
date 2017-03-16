#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

const int MAXN = 1005;
int a[MAXN];

void work()
{
    int N;
    scanf("%d", &N);
    int i;
    REP(i, N)   scanf("%d", a + i);
    int res1 = 0, res2 = 0;
    REP(i, N - 1) {
        res1 += max(0, a[i] - a[i + 1]);
    }
    int eat = 0;
    REP(i, N - 1) {
        eat = max(eat, a[i] - a[i + 1]);
    }
    REP(i, N - 1) {
        if (a[i] != 0)  res2 += min(a[i], eat);
    }
    printf("%d %d\n", res1, res2);
}

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T --) {
        printf("Case #%d: ", kase ++);
        work();
    }
    return 0;
}