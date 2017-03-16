#include <iostream>
#include <stdio.h>
using namespace std;
int x, y, z, ans;
//void DFS(int r, int c, int a, int adj[][16])
//{
//    int temp[16][16] = {0};
//    for(int i = 0; i < x; i++)
//        for(int j = 0; j < y; j++)
//            temp[i][j] = adj[i][j];
//    temp[r][c] = 1;
//    if(a == z)
//    {
//        int cnt = 0;
//        for(int i = 0; i < x; i++)
//            for(int j = 0; j < y; j++)
//            {
//                if(temp[i][j] != 1)
//                    continue;
//                if(i + 1 < x)
//                    cnt += temp[i+1][j];
//                if(j + 1 < y)
//                    cnt += temp[i][j+1];
//            }
//        ans = min(cnt, ans);
//    }
//    else
//    {
//        for(int i = 0; i < x; i++)
//            for(int j = 0; j < y; j++)
//                if(temp[i][j] != 1)
//                    DFS(i, j, a + 1, temp);
//    }
//}
int main()
{
    freopen("stuff.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, r, c, n, adj[32][32] = {0}, temp[32][32] = {0};
    cin >> t;
    for(int f = 1; f <= t; f++)
    {
        cin >> r >> c >> n;
        for(int i = 0; i < 32; i++)
            for(int j = 0; j < 32; j++)
            {
                adj[i][j] = 0;
                temp[i][j] = 0;
            }
//        x = r;
//        y = c;
//        z = n;
//        ans = 999999999;
        //DFS (0, 0, 1, adj);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                adj[i][j] = 1;
        int cnt = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if(i + 1 < r)
                    cnt += adj[i+1][j];
                if(j + 1 < c)
                    cnt += adj[i][j+1];
            }
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                if(i - 1 >= 0)
                    temp[i-1][j]++;
                if(i + 1 < r)
                    temp[i+1][j]++;
                if(j - 1 >= 0)
                    temp[i][j-1]++;
                if(j + 1 < c)
                    temp[i][j+1]++;
            }
        for(int i = 0; i < r*c - n; i++)
        {
            int m = -1;
            for(int j = 0; j < r; j++)
                for(int k = 0; k < c; k++)
                {
                    if(temp[j][k] > m)
                    {
                        m = temp[j][k];
                        x = j;
                        y = k;
                    }
                }
            cnt -= m;
            temp[x][y] = -1;
            if(x - 1 >= 0)
                temp[x-1][y]--;
            if(x + 1 < r)
                temp[x+1][y]--;
            if(y - 1 >= 0)
                temp[x][y-1]--;
            if(y + 1 < c)
                temp[x][y+1]--;
        }
        if(n == 0 || n <= r * c / 2)
            cnt = 0;
        cout << "Case #" << f << ": " << cnt << "\n";
    }
    return 0;
}
