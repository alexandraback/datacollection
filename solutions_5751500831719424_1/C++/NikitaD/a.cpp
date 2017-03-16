#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(T x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int maxLen = 100 + 20;
const int maxN = 100 + 10;
const int INF = 1000000000;

char s[maxLen];
int n;
vector < vector< pair<char, int> > > cnt; 

int f(int j, int x)
{
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += abs(cnt[i][j].second - x);
    return result;
}

void solve()
{
    scanf("%d", &n);
    cnt.clear();
    cnt.resize(n);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", s);
        int k = strlen(s);
        for (int j = 0; j < k; ++j)
        {
            if (j == 0 || s[j] != s[j - 1])
            {
                cnt[i].push_back(make_pair(s[j], 1));
            }
            else
            {
                ++cnt[i].back().second;
            }
        }
    }

    int k = cnt[0].size();
    for (int i = 1; i < n; ++i)
    {
        if (cnt[i].size() != k)
        {
            puts("Fegla Won");
            return;
        }
        for (int j = 0; j < k; ++j)
            if (cnt[0][j].first != cnt[i][j].first)
            {
                puts("Fegla Won");
                return;
            }
    }

    int ans = 0;
    for (int j = 0; j < k; ++j)
    {
        int minX = INF;
        int maxX = -INF;
        for (int i = 0; i < n; ++i)
        {
            updMin(minX, cnt[i][j].second);
            updMax(maxX, cnt[i][j].second);
        }
        while (minX + 10 < maxX)
        {
            int x1 = (maxX - minX) / 3 + minX;
            int x2 = (maxX - minX) / 3 * 2 + minX;
            int f1 = f(j, x1);
            int f2 = f(j, x2);
            if (f1 < f2)
                maxX = x2;
            else
                minX = x1;
        }
        int best = f(j, minX);
        for (int x = minX + 1; x <= maxX; ++x)
            updMin(best, f(j, x));
        ans += best;
    }

    printf("%d\n", ans);
}


int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        printf("Case #%d: ", test);
        solve();
    }



    return 0;
}