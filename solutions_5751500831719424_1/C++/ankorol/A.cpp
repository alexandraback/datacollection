#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int ans = 0;
        bool poss = true;
        int N;
        vector<string> vs;
        cin >> N;
        vs.resize(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> vs[i];
        }
        vector<vector<pair<char, int> > > vp;
        vp.resize(N);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < vs[i].size(); ++j)
            {
                if ((j == 0) || (vs[i][j - 1] != vs[i][j]))
                {
                    vp[i].push_back(make_pair(vs[i][j], 1));
                    continue;
                }
                vp[i][vp[i].size() - 1].second++;
            }
            if (i != 0)
            {
                if (vp[i].size() != vp[0].size())
                {
                    poss = false;
                    break;
                }
            }
        }
        if (poss)
        {
            vector<vector<int> > vi;
            vector<int> summ;
            vi.resize(vp[0].size());
            summ.resize(vp[0].size());
            for (int i = 0; (i < vp[0].size()) && poss; ++i)
            {
                vi[i].push_back(vp[0][i].second);
                summ[i] = vp[0][i].second;
                for (int j = 1; j < N; ++j)
                {
                    if (vp[j][i].first != vp[0][i].first)
                    {
                        poss = false;
                        break;
                    }
                    vi[i].push_back(vp[j][i].second);
                    summ[i] += vp[j][i].second;
                }
            }
            if (poss)
            {
                int K = vi.size();
                for (int i = 0; i < K; ++i)
                {
                    sort(vi[i].begin(), vi[i].end());
                    int mini = summ[i] - vi[i][0] * N;
                    int curr = mini;
                    for (int j = 1; j < N; ++j)
                    {
                        int x = vi[i][j] - vi[i][j - 1];
                        curr = curr + j * x - (N - j) * x;
                        if (curr  < mini)
                        {
                            mini = curr;
                        }
                    }
                    ans += mini;
                }
            }
        }
        if (poss)
        {
            cout << "Case #" << t << ": " << ans << endl;
        }
        else
        {
            cout << "Case #" << t << ": Fegla Won" << endl;
        }
    }
    return 0;
}