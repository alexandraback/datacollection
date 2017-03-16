#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


int main()
{
    int T, t;
    int N;
    vector<string> ss(100);
    vector<string> sa(100);
    vector<vector<int> > sc(100);

//    sleep(10);

    cin >> T;
    for (t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> ss[i];
            sc[i].clear();
            sa[i].clear();
            for (int j = 0; j < ss[i].length();) {
                int k;
                for (k = j + 1; k < ss[i].length() && ss[i][j] == ss[i][k]; k++);
                sa[i].push_back(ss[i][j]);
                sc[i].push_back(k - j);
                j = k;
            }
        }

        bool failed = false;
        for (int i = 1; i < N; i++) {
            if (sa[0] != sa[i]) {
                failed = true;
                break;
            }
        }
        if (failed) {
            cout << "Case #" << t << ": Fegla Won\n"; 
            continue;
        }

        int mm = 0;
        for (int j = 0; j < sa[0].length(); j++) {
            vector<int> s;
            for (int i = 0; i < N; i++)
                s.push_back(sc[i][j]);
            sort(s.begin(), s.end());
            int m1 = s[s.size() / 2];
            int m2 = s[s.size() / 2 + 1];
            int mm1 = 0;
            int mm2 = 0;
            for (int i = 0; i < N; i++) {
                mm1 += abs(sc[i][j] - m1);
                mm2 += abs(sc[i][j] - m2);
            }

            mm += (mm1 < mm2 ? mm1 : mm2);
        }

        cout << "Case #" << t << ": " << mm << "\n"; 
    }
    return 0;
}
