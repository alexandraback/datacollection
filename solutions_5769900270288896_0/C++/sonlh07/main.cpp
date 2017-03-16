#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define pp pair<int,int>
#define ppp pair<pp,pp>
#define st first
#define nd second
typedef long long ll;
using namespace std;
int R,C,N;
int a[50][50];
int Cal(int x,int y)
{
    int ans = 0;
    if (a[x - 1][y] == 1) ans++;
    if (a[x][y-1] == 1) ans++;
    return ans;
}

int main()
{

   freopen("A.in","r",stdin);
   freopen("A.out","w",stdout);

    int nTest;
    cin>>nTest;
    for (int kk = 1; kk<=nTest; kk++)
    {
        cin>>R>>C>>N;
        int res = 1000000000;
        int m = R*C;
        for (int i = 1; i<(1<<m); i++)
        {
            memset(a,0,sizeof(a));
            int dem = 0;
            for (int j = 0; j<m; j++)
                if ((i>>j)&1) dem++;
            if (dem == N)
            {
                for (int j = 0; j<m; j++)
                if (( i >> j) & 1)
                {
                    int x = j + 1;
                    int hang = (x/C) + (x%C != 0);
                    int cot = x - (hang - 1)*C;
                    a[hang][cot] = 1;
                }
                int ans = 0;
                for (int u = 1; u<=R; u++)
                for (int v = 1; v<=C; v++)
                     if (a[u][v] == 1)
                         ans+=Cal(u,v);
                res = min(res,ans);
            }
        }
        if (N == 0) res = 0;
        cout<<"Case #"<<kk<<": "<<res<<"\n";
    }
    return 0;
}
