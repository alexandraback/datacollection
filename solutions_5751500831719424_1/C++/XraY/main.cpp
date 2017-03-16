#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
    return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
    return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxn = 100 + 10;
char strs[maxn][maxn + 1];
int lens[maxn];
int its[maxn];

int val[maxn];

bool solve(int testCase) {
    printf("Case #%d: ", testCase);
    int n;
    if (scanf("%d", &n) < 1)
        return 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", strs[i]);
        lens[i] = strlen(strs[i]);
    }
    
    for (int i = 0; i < n; ++i)
        its[i] = 0;
    
    int ans = 0;
    while (1) {
        char ch = strs[0][its[0]];
        for (int i = 0; i < n; ++i) {
            char cur = strs[i][its[i]];
            if (cur != ch) {
                printf("Fegla Won\n");
                return 1;
            }
        }

        if (!ch)
            break;

        for (int i = 0; i < n; ++i)
            for (val[i] = 0; strs[i][its[i]] == ch; ++its[i], ++val[i]) ;

        int value = 0;
        for (int i = 0; i < n; ++i)
            value += val[i];
        value = (value + n / 2) / n;    
        for (int i = 0; i < n; ++i)
            ans += abs(val[i] - value);
    }

    printf("%d\n", ans);
    return 1;
}

int main() {
    srand(rdtsc());
#ifdef DEBUG
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
#endif
    
    int maxt;
    while (scanf("%d", &maxt) == 1) {
        for (int t = 0; t < maxt; ++t)
            assert(solve(t + 1));
        
        #ifdef DEBUG
            eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
        #endif
    }
    return 0;
}
