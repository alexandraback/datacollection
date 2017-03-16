#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

// template end

bool check(vector<int> &cnt)
{
    int maxv = *max_element(cnt.begin(), cnt.end());
    int sum = 0;
    for (int x : cnt)
    {
        sum += x;
    }

    return maxv * 2 <= sum;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> cnt;
    priority_queue<pair<int, char>> p;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt.push_back(x);
        p.push(mp(x, i + 'A'));
    }

    while (!p.empty())
    {
        pair<int, char> top = p.top();
        p.pop();

        string now = "";
        now += top.second;

        cnt[top.second - 'A']--;
        top.first--;
        if (top.first > 0)
        {
            p.push(top);
        }

        if (!check(cnt))
        {
            pair<int, char> top2 = p.top();
            p.pop();

            now += top2.second;

            cnt[top2.second - 'A']--;
            top2.first--;
            if (top2.first > 0)
            {
                p.push(top2);
            }
        }
        
        assert(check(cnt));
        
        cout << now << " ";
    }

    cout << endl;
}

int main()
{
#ifdef XXX
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif defined CONTEST
    freopen(CONTEST".in", "r", stdin);
    freopen(CONTEST".out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; ++tc)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}