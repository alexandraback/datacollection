#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int row1, row2;
int a1[4][4], a2[4][4];

void solve() {
    set<int> s1, s2;
    for (int i = 0; i < 4; ++i)
        s1.insert(a1[row1 - 1][i]);
    for (int i = 0; i < 4; ++i)
        if (s1.count(a2[row2 - 1][i]) > 0) {
            s2.insert(a2[row2 - 1][i]);
        }
    if (s2.size() == 0) {
        printf("Volunteer cheated!\n");
    } else if (s2.size() > 1) {
        printf("Bad magician!\n");
    } else {
        printf("%d\n", *s2.begin());
    }
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 0; caseNo < numCases; ++caseNo) {
        scanf("%d", &row1);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &a1[i][j]);
        scanf("%d", &row2);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &a2[i][j]);
        printf("Case #%d: ", caseNo + 1);
        solve();
    }
    return 0;
}



