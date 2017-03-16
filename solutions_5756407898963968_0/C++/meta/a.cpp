#include <set>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

set<int> read_set() {
    set<int> result;
    int r;
    scanf("%d", &r);
    r--;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int v;
            scanf("%d", &v);
            if (i != r) continue;
            result.insert(v);
        }
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++) {
        set<int> first = read_set();
        set<int> second = read_set();
        vector<int> intersection(4);
        auto it = set_intersection(first.begin(), first.end(),
                        second.begin(), second.end(),
                        intersection.begin());
        intersection.resize(it - intersection.begin());
        printf("Case #%d: ", tc+1);
        switch (intersection.size()) {
            case 0: printf("Volunteer cheated!\n"); break;
            case 1: printf("%d\n", intersection[0]); break;
            default: printf("Bad magician!\n"); break;
        }
    }
    return 0;
}
