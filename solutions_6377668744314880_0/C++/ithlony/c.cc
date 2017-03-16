#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 10010;

pair<int, int> pos[MAXN];
int n;

int cross(int a, int b, int c)
{
    long long x1 = pos[c].first - pos[a].first, x2 = pos[b].first - pos[a].first;
    long long y1 = pos[c].second - pos[a].second, y2 = pos[b].second - pos[a].second;

    long long tmp = x1 * y2 - x2 * y1;
    //cout << tmp << endl;
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

int try_cut(int a, int b)
{
    int ret = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
        if (cross(a, b, i) < 0)
            ++cnt;

    //cout << cnt << endl;

    if (cnt > n / 2)
        ret = n - cnt;
    else {
        ret = cnt;
    }

    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &pos[i].first, &pos[i].second);
        }
        printf("Case #%d:\n", t);
        for (int i = 0; i < n; ++i) {
            //cout << "aaa " << i << endl;
            int ans = n - 1;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                int tmp = try_cut(i, j);
                if (tmp < ans)
                    ans = tmp;
            }
            printf("%d\n", ans);
        }
        //break;
    }
    return 0;
}
