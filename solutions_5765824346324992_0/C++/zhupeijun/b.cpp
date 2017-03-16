#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int bt[1005];

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int bn, cur;
        scanf("%d %d", &bn, &cur);
        int lowest = 0;
        for(int i = 0; i < bn; i++) {
            scanf("%d", &bt[i]);
            lowest = max(lowest, bt[i]);
        }
        ll l = 0, r = 1LL * lowest * cur, mid, tot;
        while(l <= r) {
            mid = (l + r) / 2;
            tot = 0;
            for(int i = 0; i < bn; i++)
                tot += mid / bt[i] + 1;
            if(tot >= cur) r = mid - 1;
            else l = mid + 1;
        }
        ll t = r;
        tot = 0;
        if (r >= 0) {
            for(int i = 0; i < bn; i++)
                tot += t / bt[i] + 1;
        }
        int ans = 0;
        for(int i = 0; i < bn; i++) {
            if((t + 1) % bt[i] == 0) tot++;
            if(tot == cur) { ans = i + 1; break; }
        }
        printf("Case #%d: %d\n", ci, ans);
    }
    return 0;
}

