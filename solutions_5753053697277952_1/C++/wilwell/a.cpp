#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> & a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        ans += a[i];
    }
    return ans;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a.ans", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        int n;
        cin >> n;
        vector<int> num(n, 0 );
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }
        printf("Case #%d:", test);
        while (sum(num) > 0)
        {
            int best_i = -1;
            int max_num = -1;
            int best_2_i = -1;
            int best_3_i = -1;
            for (int i = 0; i < n; ++i)
            {
                if (num[i] > max_num)
                {
                    max_num = num[i];
                    best_i = i;
                    best_2_i = -1;
                    best_3_i = -1;
                }
                else
                {
                    if (num[i] == max_num)
                    {
                        if (best_2_i != -1)
                        {
                            best_3_i = i;
                        }
                        else
                        {
                            best_2_i = i;
                        }
                    }
                }
            }
            if (best_2_i == -1 || best_3_i != -1)
            {
                cout << " " << char('A' + best_i);
                num[best_i] -= 1;
            }
            else
            {
                cout << " " << char('A' + best_i) << char('A' + best_2_i);
                num[best_i] -= 1;
                num[best_2_i] -= 1;
            }
        }
        cout << "\n";
    }
}
