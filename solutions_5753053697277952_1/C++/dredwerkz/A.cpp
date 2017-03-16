#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

struct s_ {
    int c;
    char a;
};

bool myfunction (s_ i,s_ j) { return (i.c>j.c); }

#define SINGLELINE 1
void solve() {
    int n = gi();
    vector<s_> v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        s_ s;
        s.c = gi();
        s.a = 'A' + i;
        v.push_back(s);
        sum += s.c;
    }

    while (sum) {
        sort(v.begin(), v.end(), myfunction);
        for (int i = 0; i < v.size(); i++) {
            if (!v[i].c) {
                v.resize(i);
                break;
            }
        }
        if (v.size() > 2) {
            if (sum == 3) {
                printf(" %c", v[0].a);
                v[0].c--;
                sum--;
            } else {
                printf(" %c%c", v[0].a, v[1].a);
                sum -= 2;
                v[0].c--;
                v[1].c--;
            }
        } else if (v[0].c == v[1].c) {
            printf(" %c%c", v[0].a, v[1].a);
            sum -= 2;
            v[0].c--;
            v[1].c--;
        } else {
            printf(" %c", v[0].a);
            sum--;
            v[0].c--;
        }
    }
    printf("\n");
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:", i);
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
