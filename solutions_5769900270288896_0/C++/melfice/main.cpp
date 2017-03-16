#include <bits/stdc++.h>

using namespace std;

int r, c;

int get(int mask, int i, int j)
{
    return (mask >> (c * i + j)) & 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> r >> c >> n;
        int ans = 1e5;
        for(int mask = 0; mask < (1 << (r * c)); mask++)
        {
            if(__builtin_popcount(mask) != n)
                continue;
            int cur = 0;
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                    if(!i && !j)
                        continue;
                    else if(!i)
                        cur += get(mask, i, j) * (get(mask, i, j - 1));
                    else if(!j)
                        cur += get(mask, i, j) * (get(mask, i - 1, j));
                    else
                        cur += get(mask, i, j) * (get(mask, i - 1, j) + get(mask, i, j - 1));
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}
