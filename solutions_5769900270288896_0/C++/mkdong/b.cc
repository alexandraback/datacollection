#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;
int r, c;

int a[100001];

int ans;

int loc(int i, int j)
{
    return a[i * c + j];
}

int count()
{
    int ret = 0;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (loc(i, j)) {
                // see right
                if (j != c-1 && loc(i, j+1)) {
                    ret++;
                }
                // see bottom
                if (i != r-1 && loc(i+1, j)) {
                    ret++;
                }
            }
        }
    }
    return ret;
}

void dfs(int d, int left)
{
    if (left == 0) {
        int c = count();
        if (c < ans) ans = c;
        return;
    }
    if (r * c - d < left) return;
    a[d] = 1;
    dfs(d+1, left - 1);
    a[d] = 0;
    dfs(d+1, left);
}

int solve()
{
    ans = (r + 1) * (c + 1);
    dfs(0, n);
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> r >> c >> n;
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
