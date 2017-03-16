#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
int a[16][16];
int N;
int ans;
int n,m,h;

void init()
{
    cin >> n >> m >> h;
    ans = 100000;
}

void checkans()
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (a[i][j] == 1)
        {

            if (j < m-1 && a[i][j+1] == 1) tmp++;
            if (i < n-1 && a[i+1][j] == 1) tmp++;
        }
    if (tmp < ans) ans = tmp;
}

void searcha(int i, int j, int k)
{
    if (k == 0) {checkans(); return;}
    if (i == n && j == 0) return;
    if (j == m-1)
    {
        searcha(i+1,0,k);
        a[i][j] = 1;
        searcha(i+1,0,k-1);
        a[i][j] = 0;
    }
    else
    {
        searcha(i,j+1,k);
        a[i][j] = 1;
        searcha(i,j+1,k-1);
        a[i][j] = 0;
    }

}

void solve()
{
    searcha(0,0,h);
    cout <<ans;
}

int main() {

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
