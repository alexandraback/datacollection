#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

char buf[1000001];

vector< vector< pair<char, int> > > v(101);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++)
    {
        int N;
        scanf("%d\n", &N);
        for (int i = 0; i < N; i++)
        {
            v[i].clear();

            scanf("%s", buf);
            string s = buf;
            //cout << s << endl;

            int cnt = 0;
            char c = '@';

            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] != c)
                {
                    if (j > 0)
                    {
                        v[i].push_back( make_pair(c, cnt));
                        //cout << "(" << c << ", " << cnt << ") ";
                    }
                    c = s[j];
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }
            }
            v[i].push_back( make_pair(c, cnt));
            //cout << "(" << c << ", " << cnt << ") ";
            //cout << endl << endl;
        }

        bool ok = true;
        int block_cnt = v[0].size();
        for (int i = 0; i < N; i++)
        {
            if (v[i].size() != block_cnt)
            {
                ok = false;
            }
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j].first != v[0][j].first)
                {
                    ok = false;
                }
            }
        }

        if (!ok)
        {
            cout << "Case #" << tc << ": Fegla Won" << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < v[0].size(); i++)
        {
            vector<int> f;
            for (int j = 0; j < N; j++)
            {
                f.push_back(v[j][i].second);
            }

            sort(f.begin(), f.end());
            int mid = f[f.size() / 2];
            for (int j = 0; j < f.size(); j++)
            {
                ans += abs(mid - f[j]);
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;

    }


}
