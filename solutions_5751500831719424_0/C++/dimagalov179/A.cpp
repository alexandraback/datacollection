#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    ifstream cin("input");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int n;
        cin >> n;
        vector<string> A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        vector<int> S(n, 0), E(n, 0);
        int answer = 0;
        bool bad = false;
        while (S[0] < A[0].size())
        {
            char current = A[0][S[0]];
            // cout << current << endl;
            for (int i = 0; i < n; ++i)
            {
                while (E[i] < A[i].size() && A[i][E[i]] == current)
                    ++E[i];
                // cout << E[i] << endl;
                if (S[i] == E[i])
                {
                    bad = true;
                    break;
                }
            }
            if (bad)
                break;

            int max_len = 0;
            for (int i = 0; i < n; ++i)
                max_len = max(max_len, E[i] - S[i]);

            int current_min = 1000 * 1000 * 1000;
            for (int i = 0; i <= max_len; ++i)
            {
                int summ = 0;
                for (int j = 0; j < n; ++j)
                    summ += abs(i - (E[j] - S[j]));
                current_min = min(current_min, summ);
            }
            answer += current_min;
            for (int i = 0; i < n; ++i)
                S[i] = E[i];
        }
        for (int i = 0; i < n; ++i)
            if (S[i] != A[i].size())
                bad = true;
        cout << "Case #" << q + 1 << ": ";
        if (bad)
            cout << "Fegla Won" << endl;
        else
            cout << answer << endl;
    }
}