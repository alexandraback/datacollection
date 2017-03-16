#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
    point() {}
    point(long long x, long long y) : x(x), y(y) {}
};

inline long long vect(const point a, const point b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TESTS;
    cin >> TESTS;
    for (int TEST = 1; TEST <= TESTS; TEST++)
    {
        cout << "Case #" << TEST << ":\n";
        int n;
        cin >> n;
        vector<point> V(n);
        for (auto & x : V)
            cin >> x.x >> x.y;
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        for (int now = 0; now < n; now++)
        {
            int ans = 10000;
            for (int i = 0; i < n; i++)
                if (i != now)
                {
                    int l = 0, r = 0;
                    for (int j = 0; j < n; j++)
                        if (j != now && j != i)
                        {
                            auto num = vect(point(V[i].x - V[j].x, V[i].y - V[j].y), point(V[now].x - V[j].x, V[now].y - V[j].y));
                            if (num > 0)
                                l++;
                            if (num < 0)
                                r++;
                        }
                    ans = min(ans, min(l, r));
                }
            cout << ans << '\n';
        }
    }
}
