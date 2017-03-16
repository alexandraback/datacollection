#include<iostream>
#include<vector>
using namespace std;

int r,c,n;
int ans;
int cell[20][20] = { 0 };

int check(int m[20][20])
{
    int ret = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] == 1)
            {
                if (i != 0 && m[i - 1][j] == 1)
                    ret ++;
                if (j != 0 && m[i][j - 1] == 1)
                    ret ++;
            }
    return ret;
}

int dfs(int indx,int sum, vector<int> &p)
{
    if (indx > r*c)
        return 0;
    if (sum == n)
    {
        memset(cell,0,sizeof(cell));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cell[i][j] = p[i * c + j];
        ans = min(ans,check(cell));
    }
    else
    {
        if (r*c - indx > n - sum)
        {
            p[indx] = 0;
            dfs(indx + 1,sum,p);
        }
        p[indx] = 1;
        dfs(indx + 1,sum + 1,p);
        p[indx] = 0;
    }
    return 0;
}

int main()
{
    int tt;
    cin >> tt;
    for (int ii = 0; ii < tt; ii++)
    {
        cin >> r >> c >> n;
        ans = 2 * r * c - r - c;
        vector<int> p(r*c,0);
        dfs(0,0,p);
        cout << "Case #" << ii + 1 << ": " << ans << endl;
    }
    return 0;
}
