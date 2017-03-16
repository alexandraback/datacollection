#include <iostream>
#include <stdio.h>
#define N 100

using namespace std;

string b[N];
int a[N][N], c[N];

int get(int n)
{
    sort(c, c + n);
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += abs(c[i] - c[n / 2]);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        int n;
        scanf("%d", &n);
        bool fail = false;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (fail)
            {
                continue;
            }
            b[i] = "";
            int sz = s.size();
            for (int j = 0; j < sz; j++)
            {
                if (j == 0 || s[j] != s[j - 1])
                {
                    a[i][b[i].size()] = 1;
                    b[i] += s[j];
                }
                else
                {
                    a[i][b[i].size() - 1]++;
                }
            }
            if (i > 0 && b[i] != b[i - 1])
            {
                fail = true;
            }
        }
        if (fail)
        {
            printf("Case #%d: Fegla Won\n", cases);
            continue;
        }
        int ans = 0;
        for (int i = 0, sz = b[0].size(); i < sz; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[j] = a[j][i];
            }
            ans += get(n);
        }
        printf("Case #%d: %d\n", cases, ans);
    }
    return 0;
}
