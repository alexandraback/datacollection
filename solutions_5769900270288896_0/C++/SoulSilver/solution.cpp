#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int solve(int r, int c, int n) {
    int a[20][20], p = 1 << (r*c), res = 1000000000;
    for (int i = 0; i < p; ++i) {
        int cnt = 0;
        for (int j = 0; j < r*c; ++j)
            if (((1<<j)&i)!=0) cnt++;
        if (cnt!=n) continue;
        memset(a, 0, sizeof a);
        for (int j = 0; j < r*c; ++j) {
            if (((1<<j)&i) != 0)
                a[j/c][j%c] = 1;
        }
        cnt = 0;
        for (int j = 0; j < r; ++j)
        for (int k = 0; k < c; ++k) {
            if (a[j][k] && a[j+1][k])
                cnt++;
            if (a[j][k] && a[j][k+1])
                cnt++;
        }
        res = min(res,cnt);
    }
    return res;
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
    scanf("%d",&t); int tmp = t;
    while (t--) {
        int R, C, n;
        scanf("%d %d %d",&R,&C,&n);
        printf("Case #%d: %d\n",tmp-t,solve(R,C,n));
    }

	return 0;
}
