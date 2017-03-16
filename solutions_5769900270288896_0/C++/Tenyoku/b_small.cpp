#include <cstdio>
#include <algorithm>
using namespace std;
#define INF (99999999)

int r, c, n;

bool obj[17][17];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dfs(int i, int j, int n)
{
    if(n==0)
    {
        int ans = 0;
        for(int i=1; i<=r; ++i) 
            for(int j=1; j<=c; ++j)
                if(obj[i][j])
                {
                    for(int k=0; k<4; ++k)
                        if(obj[i+dx[k]][j+dy[k]]) ++ans;
                }
        return ans/2;
    }
    if(i==r) return INF;
    int tmp = INF;
    obj[i+1][j+1] = true;
    tmp = min(tmp, dfs(i+(j+1)/c, (j+1)%c, n-1));
    obj[i+1][j+1] = false;
    tmp = min(tmp, dfs(i+(j+1)/c, (j+1)%c, n));
    return tmp;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d %d %d", &r, &c, &n);
        printf("Case #%d: %d\n", cas, dfs(0, 0, n));
    }
    return 0;
}
