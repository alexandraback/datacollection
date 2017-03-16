#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1222
int m[MAX], b, n;

class Comp {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
};

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (!y) return x;
    return gcd(y, x % y);
}

int solve() {
    int g = m[0];
    for (int i = 1; i < b; i++) g = gcd(g, m[i]);
    int s = 1;
    for (int i = 0; i < b; i++) s *= (m[i] / g);
    s *= g;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Comp> q;
    for (int i = 0; i < b; i++) {
        int j = 0;
        while (j < s) {
            q.push(make_pair(j, i + 1));
            j += m[i];
        }
    }
    int tmp = n % (q.size());
    if (!tmp) tmp = q.size();
    while (!q.empty()) {
        tmp--;
        if (!tmp) return q.top().second;
        q.pop();
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &b, &n);
        for (int j = 0; j < b; j++) scanf("%d", &m[j]);
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
