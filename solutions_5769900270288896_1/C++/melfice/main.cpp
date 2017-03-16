#include <bits/stdc++.h>

using namespace std;

int r, c;

int get(int mask, int i, int j)
{
    return (mask >> (c * i + j)) & 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> r >> c >> n;
        int N = n;
        int Ans = 1e7;
        int tab[r][c];
        for(int z = 0; z < 2; z++){
        n = N;
        memset(tab, 0, sizeof(tab));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                tab[i][j] = (i + j) % 2 == z;
                n -= tab[i][j];
            }
        int ans = 0;
        if(n > 0 && !tab[0][0])
        {
            ans += min(2, min(r, c));
            n--;
            tab[0][0] = 1;
        }
        if(n > 0 && !tab[0][c - 1])
        {
            ans += min(2, min(r, c));
            n--;
            tab[0][c - 1] = 1;
        }
        if(n > 0 && !tab[r - 1][0])
        {
            ans += min(2, min(r, c));
            n--;
            tab[r - 1][0] = 1;
        }
        if(n > 0 && !tab[r - 1][c - 1])
        {
            ans += min(2, min(r, c));
            n--;
            tab[r - 1][c - 1] = 1;
        }
        for(int i = 0; i < r; i++)
        {

            if(n > 0 && !tab[i][0])
            {
                ans += min(3, c + 1);
                n--;
                tab[i][0] = 1;
            }
            if(n > 0 && !tab[i][c - 1])
            {
                ans += min(3, c + 1);
                n--;
                tab[i][c - 1] = 1;
            }
        }
        for(int i = 0; i < c; i++)
        {

            if(n > 0 && !tab[0][i])
            {
                ans += min(3, r + 1);
                n--;
                tab[0][i] = 1;
            }
            if(n > 0 && !tab[r - 1][i])
            {
                ans += min(3, r + 1);
                n--;
                tab[r - 1][i] = 1;
            }
        }
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++)
                if(n > 0 && tab[i][j])
        {
            n--;
            tab[i][j] = 1;
            ans += 4;
        }
        Ans = min(ans, Ans);}
        cout << Ans << "\n";
    }
}
