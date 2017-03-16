#include<bits/stdc++.h>

#define MOD 1000000007
#define MODSET(d) if ((d) >= MOD) d %= MOD;

using namespace std;

int main()
{
    #ifdef VSP4
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // VSP4

    int t, T, i, j, n, k, d, remaining;
    priority_queue< pair<int, char> > evacuate;

    cin >> T;

    for (t = 1; t <= T; t++)
    {
        cin >> n;

        remaining = 0;

        for (i = 0; i < n; i++)
        {
            cin >> d;
            remaining += d;
            evacuate.push({d, 'A' + i});
        }

        string ans = "";

        while (!evacuate.empty())
        {
            auto p = evacuate.top();
            evacuate.pop();

            if (!evacuate.empty() && remaining != 3 && (evacuate.top().first == p.first || remaining == 2))
            {
                //evacuate both of them
                auto z = evacuate.top();
                evacuate.pop();

                ans.push_back(p.second);
                ans.push_back(z.second);
                ans.push_back(' ');

                remaining -= 2;

                if (p.first - 1 >= 1)
                {
                    evacuate.push({p.first - 1, p.second});
                    evacuate.push({z.first - 1, z.second});
                }
            }
            else
            {
                ans.push_back(p.second);
                ans.push_back(' ');

                remaining--;

                if (p.first - 1 >= 1)
                {
                    evacuate.push({p.first - 1, p.second});
                }
            }
        }

        ans.pop_back();

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
