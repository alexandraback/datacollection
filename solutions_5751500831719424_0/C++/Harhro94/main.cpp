// Author: Harhro94 [Harutyunyan Hrayr]
#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int N = 107;
char st[N][N];

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define task "london"
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%s", st[i]);
        vector<char> ch;
        int l = strlen(st[0]);
        for (int i = 0; i < l;)
        {
            int j = i;
            while (j < l && st[0][i] == st[0][j]) ++j;
            ch.pb(st[0][i]);
            i = j;
        }
        vector<vector<int> > cnt(sz(ch), vector<int>());
        bool ok = true;
        for (int u = 0; u < n; ++u)
        {
            string cur(st[u], st[u] + strlen(st[u]));
            vector<char> tmp;
            for (int i = 0, p = 0; i < cur.size(); ++p)
            {
                int j = i;
                while (j < cur.size() && cur[j] == cur[i]) ++j;
                tmp.pb(cur[i]);
                if (p < sz(ch)) cnt[p].pb(j - i);
                i = j;
            }
            if (sz(tmp) != sz(ch))
            {
                ok = false;
                break;
            }
            for (int i = 0; i < sz(ch); ++i)
            {
                if (tmp[i] != ch[i])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) puts("Fegla Won");
        else
        {
            int ans = 0;
            int n = sz(ch);
            for (int i = 0; i < n; ++i)
            {
                vector<int> &v = cnt[i];
                sort(all(v));
                int med = v[sz(v) / 2];
                for (int j = 0; j < sz(v); ++j) ans += abs(v[j] - med);
            }
            printf("%d\n", ans);
        }
    }


#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}