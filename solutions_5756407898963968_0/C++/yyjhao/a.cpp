#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int ca = 0; ca < t; ca++) {
        set<int> nums;
        int r1, r2;
        scanf("%d", &r1);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int n;
                scanf("%d", &n);
                if (i + 1 == r1) {
                    nums.insert(n);
                }
            }
        }
        scanf("%d", &r2);
        vector<int> ans;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int n;
                scanf("%d", &n);
                if (i + 1 == r2 && nums.count(n)) {
                    ans.push_back(n);
                }
            }
        }
        printf("Case #%d: ", ca + 1);
        if (ans.size() > 1) {
            printf("Bad magician!\n");
        } else if (ans.size() == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("%d\n", ans[0]);
        }
    }
    return 0;
}