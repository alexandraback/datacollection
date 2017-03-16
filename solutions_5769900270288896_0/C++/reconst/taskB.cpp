#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int r, c, n, ans = INF;
int pole[20][20];

void check()
{
    int curans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (pole[i][j] && pole[i+1][j])
                curans++;
            if (pole[i][j] && pole[i][j+1])
                curans++;
        }
    }
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cerr << pole[i][j];
//        }
//        cerr << endl;
//    }
//    cerr << endl;
    //cerr << curans << endl;
    ans = min(ans, INF-1);
    ans = min(ans, curans);
}

void gen(int pos, int prev)
{
    if (pos == n) {
        check();
        return;
    }
    int start = prev;
    while (start < r * c) {
        if (pole[start / c][start % c] == 0) {
            pole[start / c][start % c] = 1;
            gen(pos + 1, start + 1);
            pole[start / c][start % c] = 0;
        }
        start++;
    }

}

int solve()
{
    cin >> r >> c >> n;
    ans = INF;
    /*if (n == r * c) {
        ans = 2 * (r - 1) * (c - 1) + r + c - 1;
        return 0;
    }
    if (n + 1 == r * c) {
        ans = 2 * (r - 1) * (c - 1) + r + c - 1 - 2;
        return 0;
    }*/
    gen(0, 0);
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("???", "r", stdin);
     freopen("output.txt", "w", stdout);

    int test_number;
    scanf("%d", &test_number);

    for (int test_case = 0; test_case < test_number; test_case++) {
        // Reading
        solve();
        printf("Case #%d: %d\n", test_case + 1, ans);
    }
}