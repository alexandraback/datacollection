#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": ";
        int N;
        cin >> N;
        vector<string> strs(N);
        for (int i = 0; i < N; i++)
            cin >> strs[i];

        bool bad = false;
        vector<int> idxs(N, 0);
        int changed = 0;
        while(true) {
            int cntend = 0;
            for (int i = 0; i < N; i++)
                if (idxs[i] == strs[i].size())
                    cntend++;
            if (cntend == N)
                break;
            else if (cntend > 0 && cntend < N) {
                bad = true;
                break;
            }
            vector<int> num(N, 0);
            char c = strs[0][idxs[0]];
            for (int i = 0; i < N; i++) {
                if (strs[i][idxs[i]] != c) {
                    bad = true;
                    break;
                }
                while(idxs[i] < strs[i].size() && strs[i][idxs[i]] == c) {
                    idxs[i]++;
                    num[i]++;
                }
            }
            if (bad) break;

            sort(num.begin(), num.end());
            int median = (N%2 == 1 ? num[N/2] : (num[N/2-1] + num[N/2])/2);
            for (int i = 0; i < N; i++)
                changed += abs(num[i] - median);
        }

        if (bad)
            cout << "Fegla Won";
        else
            cout << changed;
        
        cout << endl;
    }
    return 0;
}
