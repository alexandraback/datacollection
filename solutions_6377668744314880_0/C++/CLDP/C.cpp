#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 3010;

long long x[MAXN], y[MAXN];
int ans[MAXN];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
            ans[i] = N;
        }
        for (int k = 1; k < (1 << N); ++k) {
            vector<int> S;
            for (int i = 0; i < N; ++i) {
                if (k & (1 << i)) S.push_back(i);
            }
            for (int i = 0; i < S.size(); ++i) {
                for (int j = 0; j < S.size(); ++j) {
                    if (j == i) continue;
                    int pos = 0, neg = 0;
                    for (int l = 0; l < S.size(); ++l) {
                        if ((x[S[l]] - x[S[i]]) * (y[S[i]] - y[S[j]]) - (y[S[l]] - y[S[i]]) * (x[S[i]] - x[S[j]]) > 0) ++pos;
                        if ((x[S[l]] - x[S[i]]) * (y[S[i]] - y[S[j]]) - (y[S[l]] - y[S[i]]) * (x[S[i]] - x[S[j]]) < 0) ++neg;
                    }
                
                    if (pos == 0 || neg == 0) {
                        for (int l = 0; l < S.size(); ++l) 
                         if ((x[S[l]] - x[S[i]]) * (y[S[i]] - y[S[j]]) - (y[S[l]] - y[S[i]]) * (x[S[i]] - x[S[j]]) == 0) {
                             ans[S[l]] = min(ans[S[l]], N - (int)S.size());
                         }
                    }
                }
            }
        }
        if (N == 1) ans[0] = 0;
        cout << "Case #" << times << ":" << endl;
        for (int i = 0; i < N; ++i) cout << ans[i] << endl;
    }
    return 0;
}
