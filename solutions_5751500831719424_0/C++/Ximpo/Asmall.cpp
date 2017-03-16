#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

void rem_rep(const string &a, char *r) {
    int s = 0;
    for (int i = 0; i < (int)a.size(); ++i)
        if (i == 0 || a[i] != a[i-1])
            r[s++] = a[i];
    r[s] = '\0';
}

bool check(const string& a, const string& b) {
    char tmp1[1000], tmp2[1000];
    rem_rep(a, tmp1);
    rem_rep(b, tmp2);
    return string(tmp1) == string(tmp2);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; ++i)
            cin >> s[i];


        bool correct = true;
        for (int i = 1; i < N; ++i)
            if (!check(s[i-1], s[i])) {
                correct = false;
                break;
            }

        if (!correct)
            printf("Case #%d: Fegla Won\n", t);
        else {
            int r = 0;

            vector<vector<PII>> rle(N);
            for (int i = 0; i < N; ++i) {
                s[i] += '#';
                int cnt = 0;
                char c = '@';
                for (int j = 0; j < (int)s[i].size(); ++j) {
                    if (j > 0 && s[i][j] != c) {
                        rle[i].push_back(make_pair(c, cnt));
                        cnt = 0;
                    }
                    c = s[i][j];
                    cnt++;
                }
            }

            for (int i = 0; i < (int)rle[0].size(); ++i) {
                vector<int> values(N);
                for (int j = 0; j < N; ++j) {
                    values[j] = rle[j][i].second;
                }
                sort(values.begin(), values.end());

                int min_cost = 99999999;
                for (int j = 0; j < N; ++j) {
                    if (j == 0 || values[j] != values[j-1]) {
                        int mid = values[j];
                        int cost = 0;
                        for (int k = 0; k < N; ++k)
                            cost += abs(mid - values[k]);
                        min_cost = min(min_cost, cost);
                    }
                }

                r += min_cost;
            }


            printf("Case #%d: %d\n", t, r);
        }

    }

    return EXIT_SUCCESS;
}
