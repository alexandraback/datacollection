#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[4][4], b[4][4];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_amo; cin >> test_amo;
    for (int test_num = 1; test_num <= test_amo; test_num++) {
        int row_1; cin >> row_1; --row_1;
        for (int i = 0; i < 4; i++) {
            for (int j=0; j<4; j++) cin >> a[i][j];
        }
        int row_2; cin >> row_2; --row_2;
        for (int i = 0; i < 4; i++) {
            for (int j=0; j<4; j++) cin >> b[i][j];
        }
        sort(a[row_1], a[row_1] + 4);
        sort(b[row_2], b[row_2] + 4);
        vector<int> v(10);
        vector<int>::iterator it = set_intersection(a[row_1], a[row_1] + 4, b[row_2], b[row_2] + 4, v.begin());
        printf("Case #%d: ", test_num);
        //printf("%d ", *it);
        if (it - v.begin() == 0) {
            printf("Volunteer cheated!\n");
        } else if (it - v.begin() == 1) {
            it--;
            printf("%d\n", *it);
        } else {
            printf("Bad magician!\n");
        }

    }
    return 0;
}
