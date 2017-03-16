#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 1000 + 5;
int n, mush[MAXN];
int main() {
    int ts;
    cin >> ts;
    for (int cas = 1; cas <= ts; cas++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> mush[i];
        }
        int sum1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (mush[i] > mush[i + 1]) sum1 += mush[i] - mush[i + 1];
        }

        int v = 0;
        for (int i = 0; i < n - 1; i++) {
            if (mush[i] > mush[i + 1]) {
                int temp = mush[i] - mush[i + 1];
                v = max(v, temp);
            }
        }
        int sum2 = 0;
        for (int i = 0; i < n - 1; i++) {
            sum2 += min(mush[i], v);
        }
        printf("Case #%d: %d %d\n", cas, sum1, sum2);
    }
	return 0;
}

