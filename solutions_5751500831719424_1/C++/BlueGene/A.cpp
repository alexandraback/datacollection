#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 110;

int n;
string a[MaxN];
vector<pair<char, int> > s[MaxN];
int d[MaxN];

inline bool Check1()
{
    for (int i = 1; i < n; ++i)
        if (s[i].size() != s[i+1].size())
            return 0;
    return 1;
}

inline bool Check2()
{
    vector<int> t;
    for (int i = 0; i < (int)s[1].size(); ++i)
    {
        t.clear();
        t.push_back(s[n][i].second);
        for (int j = 1; j < n; ++j)
            if (s[j][i].first != s[j+1][i].first)
                return 0;
            else
                t.push_back(s[j][i].second);
        sort(t.begin(), t.end());
        d[i] = t[t.size() >> 1];
    }
    return 1;
}

int main()
{
    //freopen("A-small-attempt0.in.txt", "r", stdin);
    //freopen("A-small-attempt0.out.txt", "w", stdout);
    freopen("A-large.in.txt", "r", stdin);
    freopen("A-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            s[i].clear();
            for (int j = 0, k = 0; a[i][j]; j = k)
            {
                for (; a[i][j] == a[i][k]; ++k);
                s[i].push_back(make_pair(a[i][j], k-j));
            }
        }
        if (! Check1() || ! Check2())
            cout << "Fegla Won" << endl;
        else
        {
            int Ans = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 0; j < (int)s[1].size(); ++j)
                    Ans += abs(d[j]-s[i][j].second);
            cout << Ans << endl;
        }
    }
    return 0;
}
