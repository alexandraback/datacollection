#include <bits/stdc++.h>
using namespace std;

#define clr(x,c) memset(x, c, sizeof(x))
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define psi pair<string, int>
#define inf 0x3f3f3f3f
typedef long long lld;

static unsigned int g_seed = 0;
inline void fastsrand()
{
    g_seed = (unsigned int)time(0);
}
inline int fastrand()
{
    g_seed = (214013 * g_seed + 2531011);
	return (g_seed >> 16) & 0x7FFF;
}

struct node {
    int idx, sum;
    bool operator< (const node & node2) const
    {
        return sum > node2.sum;
    }
};

bool check(vector<node> & vec)
{
    int s = 0;
    for (node x : vec) {
        s += x.sum;
    }
    for (node x : vec) {
        if (x.sum * 2 > s) return false;
    }
    return true;
}

bool help1(vector<node> & vec)
{
    node & x = vec[0];
    x.sum -= 1;
    bool rc = check(vec);
    x.sum += 1;
    return rc;
}

bool help2(vector<node> & vec)
{
    node & x = vec[0];
    node & y = vec[1];
    bool rc;
    if (x.sum - y.sum >= 2) {
        x.sum -= 2;
        rc = check(vec);
        x.sum += 2;
    } else {
        x.sum -= 1;
        y.sum -= 1;
        rc = check(vec);
        x.sum += 1;
        y.sum += 1;
    }
    return rc;
}

int main ()
{
    freopen("C:/Users/ywy/Desktop/large.in", "r", stdin);
//    freopen("C:/Users/ywy/Desktop/in.txt", "r", stdin);
    freopen("C:/Users/ywy/Desktop/large-out.txt", "w", stdout);
//    freopen("C:/Users/ywy/Desktop/out.txt", "w", stdout);
    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--) {
        vector<string> ret;
        vector<node> vec;
        scanf("%d", &n);
        for (int i = 0, s; i < n; ++i) {
            scanf("%d", &s);
            vec.push_back({i, s});
        }
        int cnt = 0;
        while (cnt < n) {
            sort(vec.begin(), vec.end());
            bool h1 = help1(vec);
            bool h2 = help2(vec);
            string tmp;
            if (h2) {
                node & x = vec[0];
                node & y = vec[1];
                if (x.sum - y.sum >= 2) {
                    x.sum -= 2;
                    if (x.sum == 0) cnt += 1;
                    tmp.push_back('A' + x.idx);
                    tmp.push_back('A' + x.idx);
                } else {
                    x.sum -= 1;
                    if (x.sum == 0) cnt += 1;
                    y.sum -= 1;
                    if (y.sum == 0) cnt += 1;
                    tmp.push_back('A' + x.idx);
                    tmp.push_back('A' + y.idx);
                }
            } else if (h1) {
                node & x = vec[0];
                x.sum -= 1;
                if (x.sum == 0) cnt += 1;
                tmp.push_back('A' + x.idx);
            }
            ret.push_back(tmp);
//            printf(" %s", tmp.c_str());
        }
        printf("Case #%d:", ++cas);
        for (string r : ret) {
            printf(" %s", r.c_str());
        }
        printf("\n");
    }
    return 0;
}
