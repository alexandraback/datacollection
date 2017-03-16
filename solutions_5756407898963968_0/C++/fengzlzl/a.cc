#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void Read(vector<int> &nums) {
    int row;
    scanf("%d", &row);
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j < 4; j++) {
            int x;
            scanf("%d", &x);
            if (row == i) nums.push_back(x);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        vector<int> a, b;
        Read(a);
        Read(b);
        int cnt = 0;
        int ans = 0;
        for (int num : a)
            if (find(b.begin(), b.end(), num) != b.end()) {
                    cnt++;
                    ans = num;
            }
        if (cnt == 0) printf("Case #%d: Volunteer cheated!\n", cas);
        else if (cnt == 1) printf("Case #%d: %d\n", cas, ans);
        else printf("Case #%d: Bad magician!\n", cas);
    }
    return 0;
}
