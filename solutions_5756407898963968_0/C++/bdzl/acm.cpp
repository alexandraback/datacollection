#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

#define double long double

const double eps = (double) 1e-16;

const int max_n = 111;

int go[max_n * max_n];
int pos[max_n * max_n];
int d[max_n * max_n];
queue<int> q;
int n, m, s, l;

int main()
{
        freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
        
        while (scanf("%d%d%d%d", &n, &m, &s, &l) != EOF) {
            for (int i = 0; i <= n * m; ++i)
                go[i] = -1;
            for (int i = 0; i < s; ++i) {
                int h, t;
                scanf("%d%d", &h, &t);
                go[h] = t;
            }
            for (int i = 0; i < l; ++i) {
                int p, q;
                scanf("%d%d", &p, &q);
                go[p] = q;
            }
            for (int i = 0; i <= n * m; ++i) {
                pos[i] = i;
                while (go[pos[i]] != -1) pos[i] = go[pos[i]];
            }
            for (int i = 0; i <= n * m; ++i)
                d[i] = -1;
            d[0] = 0;
            q.push(0);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int dx = 1; dx <= 6; ++dx)
                    if (v + dx <= n * m) {
                        int u = pos[v + dx];
                        if (d[u] == -1) {
                            d[u] = d[v] + 1;
                            q.push(u);
                        }
                    }
            }
            printf("%d\n", d[n * m]);
        }
    

    return 0;
}

