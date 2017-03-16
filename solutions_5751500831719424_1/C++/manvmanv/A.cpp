#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int nArray[MAXN][MAXN];

int main(void) {
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    freopen_s(&fp, "A-small-attempt0.in", "r", stdin);
    freopen_s(&fp2, "A.out", "w", stdout);
    int T;
    while (cin >> T) {
        for (int cas = 1; cas <= T; ++cas) {
            int N;
            cin >> N;
            vector<string> vec;
            vector<string> single;
            for (int i = 0; i < N; ++i) {
                string tmp;
                cin >> tmp;
                vec.push_back(tmp);
                string ans;
                ans.push_back(tmp[0]);
                for (int j = 1; j < tmp.length(); ++j) {
                    if (tmp[j] != tmp[j - 1]) {
                        ans.push_back(tmp[j]);
                    }
                }
                single.push_back(ans);
            }

            bool bFlag = true;
            for (int i = 1; i < N; ++i) {
                if (single[i] != single[i - 1]) {
                    bFlag = false;
                    break;
                }
            }

            printf("Case #%d: ", cas);
            if (!bFlag) {
                printf("Fegla Won\n");
                continue;
            }

            memset(nArray, 0, sizeof(nArray));
            for (int i = 0; i < single.size(); ++i) {
                for (int k = 0, j = 0; j < single[i].length() && k < vec[i].length(); ++k) {
                    if (single[i][j] == vec[i][k]) {
                        ++nArray[i][j];
                    }
                    else {
                        ++j;
                        --k;
                    }
                }
            }

            int nSize = single[0].length();
            int nSum = 0;
            for (int j = 0; j < nSize; ++j) {
                int mn = nArray[0][j];
                int mx = nArray[0][j];
                for (int i = 1; i < N; ++i) {
                    mn = min(mn, nArray[i][j]);
                    mx = max(mx, nArray[i][j]);
                }
                int nMin = INF;
                for (int k = mn; k <= mx; ++k) {
                    int tmp = 0;
                    for (int i = 0; i < N; ++i) {
                        tmp += abs(k - nArray[i][j]);
                    }
                    nMin = min(nMin, tmp);
                }
                nSum += nMin;
            }

            printf("%d\n", nSum);
        }
    }
    return 0;
}