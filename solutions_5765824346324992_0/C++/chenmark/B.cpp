#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define MOD 1000000007
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MAXN = INF;
const int MAXM = 100010;
const int MAXB = 1010;

LL minutes[MAXB];

int T, B, N;

int main() {
    scanf("%d", &T);

    for (int test = 0; test < T; test++) {
        // remember to reset structures
        scanf("%d%d", &B, &N);

        for (int i = 0; i < B; i++) cin >> minutes[i];

        LL lo = 0; LL hi = 1LL * MAXM * MAXN;

        while (lo < hi) {
            LL mid = (lo + hi) / 2; // minutes

            LL done = 0LL;
            for (int i = 0; i < B; i++) done += (mid / minutes[i]) + 1;

            if (done < N) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        LL done = 0LL;
        for (int i = 0; i < B; i++) {
            done += (lo / minutes[i]) + (lo % minutes[i] != 0);
        }

        LL res = 0LL;

        for (int i = 0; i < B; i++) {
            if (lo % minutes[i] == 0) done++;
            if (done == N) { res = i+1; break; }
        }

        cout << "Case #" << (test+1) << ": " << res << "\n";
    }
    
    return 0; 
}
