#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <array>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int case_num = 1; q; q--, case_num++)
    {
        cout << "Case #" << case_num << ": ";
        int n;
        cin >> n;
        vector<string> V(n), Z(n);
        for (int i = 0; i < n; i++)
        {
            cin >> V[i];
            Z[i] = V[i];
            Z[i].resize(distance(Z[i].begin(), unique(Z[i].begin(), Z[i].end())));
        }
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
            ok &= Z[i] == Z[i + 1];
        if (!ok)
            cout << "Fegla Won";
        else
        {
            vector<vector<int> > A(Z[0].size());
            for (auto S : V)
            {
                int it = 0, num = 0, cur = 0;
                while (it < S.size())
                {
                    while (num < S.size() && S[num] == S[it])
                        num++;
                    A[cur++].push_back(num - it);
                    it = num;
                }
            }
            long long ans = 0;
            for (auto X : A)
            {
                sort(X.begin(), X.end());
                int now_ans = 0, it1 = 0, it2 = 0, prevans;
                while (it2 < X.size() && X[it1] == X[it2])
                    it2++;
                for (auto i : X)
                    now_ans += i - X[it1];
                prevans = now_ans;
                while (it2 < X.size())
                {
                    int ansans = prevans;
                    ansans += it2 * (X[it2] - X[it2 - 1]);
                    it1 = it2;
                    while (it2 < X.size() && X[it1] == X[it2])
                        it2++;
                    ansans -= (X.size() - it1) * (X[it1] - X[it1 - 1]);
                    prevans = ansans;
                    now_ans = min(now_ans, ansans);
                }
                ans += now_ans;
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
