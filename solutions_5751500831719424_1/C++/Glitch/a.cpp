#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d: ", t+1);

        int n;
        scanf("%d\n", &n);

        vector<string> s(n);
        vector<vector<pair<char, int > > > st(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];

            char cur = s[i][0];
            int cnt = 1;
            for (int j = 1; j < size(s[i]); j++)
            {
                if (s[i][j] == cur)
                {
                    cnt++;
                }
                else
                {
                    st[i].push_back(make_pair(cur, cnt));
                    cur = s[i][j];
                    cnt = 1;
                }
            }

            st[i].push_back(make_pair(cur, cnt));
        }

        bool ok = true;
        for (int i = 0; i < n; i++)
            ok = ok && size(st[i]) == size(st[0]);

        int m = size(st[0]);
        if (ok)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    ok = ok && st[i][j].first == st[0][j].first;
                }
            }
        }

        if (ok)
        {
            int sm = 0;
            for (int i = 0; i < m; i++)
            {
                int mn = INF;
                for (int cnt = 1; cnt <= 200; cnt++)
                {
                    int cur = 0;
                    for (int j = 0; j < n; j++)
                        cur += abs(cnt - st[j][i].second);

                    mn = min(mn, cur);
                }

                sm += mn;
            }

            printf("%d\n", sm);
        }
        else
        {
            printf("Fegla Won\n");
        }
    }

    return 0;
}

