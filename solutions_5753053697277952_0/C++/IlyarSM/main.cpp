#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <memory>
#include <bitset>
#include <functional>
using namespace std;

#define fori(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(x, y) make_pair((x), (y))

using ll = long long;
using ldb = long double;

set<pair<int, char>, greater<pair<int, char> > > st;

void solve(int n)
{
    st.clear();
    int f;
    for (int i = 0; i < n; i++)
    {
        cin >> f;
        st.insert(mp(f, 'A' + i));
    }
    pair<int, char> tp, tp2;
    while (!st.empty())
    {
        if (st.size() == 2 && st.begin()->first == st.rbegin()->first)
        {
            cout << st.begin()->second << st.rbegin()->second << ' ';
            tp = *st.begin();
            tp2 = *st.rbegin();
            st.clear();
            tp.first--;
            tp2.first--;
            if (tp.first == 0)
            {
                cout << endl;
                return;
            }
            else
            {
                st.insert(tp);
                st.insert(tp2);
            }
        }
        else
        {
            tp = *st.begin();
            st.erase(st.begin());

            cout << tp.second;
            tp.first--;
            if (tp.first == 0 && st.size() == 1)
            {
                cout << st.begin()->second << endl;
                return;
            }
            if (tp.first != 0)
                st.insert(tp);
            cout << ' ';
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int tests, n;
    cin >> tests;

    fori(i, tests)
    {
        cin >> n;
        cout << "Case #" << to_string(i + 1) << ": ";
        solve(n);
    }

    return 0;
}