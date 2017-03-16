#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
int const N = 100;
int const L = 100;
int n;
char s[N][L + 10];
int res;
void readin()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s[i]);
    }
}
int gao(vector <size_t> const &l)
{
    int ret = INT_MAX;
    size_t lo = *min_element(l.begin(), l.end());
    size_t hi = *max_element(l.begin(), l.end());
    for (size_t v = lo; v <= hi; ++v)
    {
        int cur = 0;
        for (vector <size_t>::size_type i = 0; i < l.size(); ++i)
        {
            cur += max(v, l[i]) - min(v, l[i]);
        }
        ret = min(ret, cur);
    }
    return ret;
}
int solve()
{
    int ret = 0;
    vector <size_t> pos(n, 0);
    vector <size_t> l(n, 0);
    while (pos[0] < strlen(s[0]))
    {
        fill(l.begin(), l.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            if (s[i][pos[i]] != s[0][pos[0]])
            {
                return -1;
            }
            while (pos[i] + l[i] < strlen(s[i]) && s[i][pos[i] + l[i]] == s[0][pos[0]])
            {
                ++l[i];
            }
        }
        ret += gao(l);
        for (int i = 0; i < n; ++i)
        {
            pos[i] += l[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (pos[i] != strlen(s[i]))
        {
            return -1;
        }
    }
    return ret;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    for (int cc = 1; cc <= tc; ++cc)
    {
        readin();
        if ((res = solve()) >= 0)
        {
            printf("Case #%d: %d\n", cc, res);
        }
        else
        {
            printf("Case #%d: Fegla Won\n", cc);
        }
    }
    return 0;
}
