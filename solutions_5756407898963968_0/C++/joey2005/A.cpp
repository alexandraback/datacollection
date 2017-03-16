#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 20;

int posA[maxn], posB[maxn];

void prepare(int pos[]) {
    int row;
    scanf("%d", &row);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int n;
            scanf("%d", &n);
            pos[n] = i + 1 == row;
        }
    }
}

void solve() {
    prepare(posA);
    prepare(posB);
    vector<int> ret;
    for (int n = 1; n <= 16; ++n) {
        if (posA[n] && posB[n]) {
            ret.push_back(n);
        }
    }
    if (ret.size() > 1) {
        puts("Bad magician!");
    } else if (ret.size() == 0) {
        puts("Volunteer cheated!");
    } else {
        printf("%d\n", ret[0]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int caseId = 1; caseId <= T; ++caseId) {
        printf("Case #%d: ", caseId);
        solve();
    }
}
