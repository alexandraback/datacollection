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

const int MAXN = 1010;
int m[MAXN];

int T, N;

int main() {
    scanf("%d", &T);

    for (int test = 0; test < T; test++) {
        // remember to reset structures
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &m[i]);

        LL res1 = 0LL; int maxdec = 0;

        for (int i = 1; i < N; i++) {
            if (m[i] < m[i-1]) {
                res1 += m[i-1] - m[i];
                maxdec = max(maxdec, m[i-1] - m[i]);
            }
        }

        LL res2 = 0LL; 

        for (int i = 0; i < N - 1; i++) {
            res2 += min(m[i], maxdec);
        }

        cout << "Case #" << (test+1) << ": " << res1 << " " << res2 << "\n";
    }
    
    return 0; 
}
