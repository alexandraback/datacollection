#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int main(){
    int test, testN, i, j, n, m, x, y;
    char s[200];
    scanf("%d\n", &testN);
    for (test = 1; test <= testN; test++)
    {
        scanf("%d", &n);
        vector<vector<pair<char, int> > > vv;
        for (i = 0; i < n; i++)
        {
            scanf("%s", s);
            vector<pair<char, int> > v;
            for (j = 0; s[j]; j++)
            {
                if (j == 0 || s[j] != s[j - 1])
                {
                    v.push_back(make_pair(s[j], 1));
                }
                else
                {
                    v[v.size() - 1].second++;
                }
            }
            vv.push_back(v);
        }
        bool ok = true;
        for (i = 1; (i < n) && ok; i++)
        {
            m = vv[i].size();
            if (m != vv[0].size())
            {
                ok = false;
                break;
            }
            for (j = 0; (j < m) && ok; j++)
            {
                if (vv[i][j].first != vv[0][j].first)
                {
                    ok = false;
                    break;
                }
            }
        }
        int r = 0, t, c, b;
        if (ok)
        {
            for (j = 0; j < m; j++)
            {
                b = 10000000;
                for (t = 1; t <= 100; t++)
                {
                    c = 0;
                    for (i = 0; i < n; i++)
                    {
                        c += abs(vv[i][j].second - t);
                    }
                    if (c < b) b = c;
                }
                r += b;
            }
            printf("Case #%d: %d\n", test, r);
        }
        else
        {
            printf("Case #%d: Fegla Won\n", test);
        }
        
    }
    return 0;
}
