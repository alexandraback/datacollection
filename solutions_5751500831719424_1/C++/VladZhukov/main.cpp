#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    int t;
    in >> t;
    for (int i = 0; i < t; i++) {
        int n;
        in >> n;
        vector<string> a = vector<string>(n);
        vector<int> id = vector<int>(n, 0);
        for (int j = 0; j < n; j++) {
            in >> a[j];
        }
        bool notEnd = true;
        int res = 0;
        int cntEnd;
        bool caseComplete = false;
        while (notEnd) {
            bool isInd = true;
            for (int k = 0; k < n - 1; k++)
                isInd = isInd && (a[k][id[k]] == a[k + 1][id[k + 1]]);
            if (!isInd) {
                out << "Case #" << i + 1 << ": Fegla Won" << endl;
//                cerr << "need breal" << endl;
                caseComplete = true;
            }
            if (caseComplete)
                break;
            cntEnd = 0;
            vector<int> cnt = vector<int>(n, 0);
            for (int j = 0; j < n; j++) {
                id[j]++;
                cnt[j]++;
//                cerr << a[j][id[j]] << " " << a[j][id[j] - 1] << endl;
                while (id[j] < a[j].size() && a[j][id[j]] == a[j][id[j] - 1]) {
                    id[j]++;
                    cnt[j]++;
                }
                if (id[j] == a[j].size())
                    cntEnd++;
            }
            int mn = 99999999;
            for (int j = 1; j <= 100; j++) {
                int now = 0;
                for (int k = 0; k < n; k++)
                    now += abs(j - cnt[k]);
                if (now < mn)
                    mn = now;
            }
            res += mn;
            notEnd = !(cntEnd == n || (cntEnd > 0 && cntEnd < n));
        }
        if (caseComplete)
            continue;
        if (cntEnd != n)
            out << "Case #" << i + 1 << ": Fegla Won" << endl;
        else {
            out << "Case #" << i + 1 << ": " << res << endl;
        }
    }

    in.close();
    out.close();
    return 0;
}
