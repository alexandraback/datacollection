#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
char a[100][200];
int N;
int cnt[100][100];
int num[100];
char ch[100][100];
int h[100];

void sort1()
{
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            if (h[i]>h[j])
    {
        int tmp = h[i];
        h[i] = h[j];
        h[j] = tmp;
    }
}

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cnt[i][j] = 0;
    for (int i = 0; i < 100; i++) num[i] = 0;
}

void solve()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < strlen(a[i]); j++)
            if (j == 0 || a[i][j] != a[i][j-1])
            {
                num[i]++;
                cnt[i][num[i] - 1]++;
                ch[i][num[i] - 1] = a[i][j];

            }
            else
                cnt[i][num[i]-1]++;
    bool check = true;
    for (int i = 1; i < N; i++)
    {
        if (num[i]!=num[0]){check = false; break;}
        for (int j = 0; j < num[i]; j++)
            if (ch[i][j] != ch[0][j]) {check = false; break;}
    }
    if (!check)
    {
        cout << "Fegla Won";
        return;
    }
    int ans = 0;
    for (int i = 0; i < num[0]; i++)
    {
        for (int j = 0; j < N; j++) h[j] = cnt[j][i];
        sort1();
        for (int j = 0; j < N; j++)
            ans += abs(h[j] - h[N/2]);
    }
    cout << ans;
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
