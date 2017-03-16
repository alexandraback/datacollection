#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

#define min(a,b) (a<b?a:b)

int dist(int a, int b) {
    int tmp;
    if(a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    return a - b;
}

int main() {
    int T, Ts, N, i, j, slen, nseq[100], ans, m1, m2, p1, p2;
    char strs[100][101];
    vector<int> ordr;
    bool feglawon;
    pair<char,int> seq[100][100];
    scanf("%d", &T);
    for(Ts = 0; Ts < T; ++Ts) {
        memset(nseq, 0, sizeof(nseq));
        feglawon = false;
        scanf("%d", &N);
        for(i = 0; i < N; ++i) {
            scanf(" %s", strs[i]);
            seq[i][nseq[i]].first = strs[i][0];
            seq[i][nseq[i]++].second = 1;
            slen = strlen(strs[i]);
            for(j = 1; j < slen; ++j) {
                if(strs[i][j] == strs[i][j-1]) {
                    ++seq[i][nseq[i]-1].second;
                } else {
                    seq[i][nseq[i]].first = strs[i][j];
                    seq[i][nseq[i]++].second = 1;
                }
            }
        }
        for(i = 1; i < N; ++i) {
            if(nseq[i] != nseq[i-1]) {
                feglawon = true;
                break;
            }
            for(j = 0; j < nseq[i]; ++j) {
                if(seq[i][j].first != seq[i-1][j].first) {
                    feglawon = true;
                    break;
                }
            }
            if(feglawon) break;
        }
        if(feglawon) {
            printf("Case #%d: Fegla Won\n", Ts+1);
        } else {
            ans = 0;
            m1 = N >> 1;
            if(N & 1) {
                m2 = -1;
            } else {
                m2 = (N >> 1) - 1;
            }
            for(j = 0; j < nseq[0]; ++j) {
                ordr.clear();
                p1 = p2 = 0;
                for(i = 0; i < N; ++i) {
                    ordr.push_back(seq[i][j].second);
                }
                sort(ordr.begin(), ordr.end());
                for(i = 0; i < N; ++i) {
                    if(m2 != -1) {
                        p2 += dist(ordr[m2], ordr[i]);
                    }
                    p1 += dist(ordr[m1], ordr[i]);
                }
                if(m2 != -1) {
                    ans += min(p1, p2);
                } else {
                    ans += p1;
                }
            }
            printf("Case #%d: %d\n", Ts+1, ans);
        }
    }
    return 0;
}
