#include <bits/stdc++.h>

using namespace std;

static const int dx[] = {1,-1,0,0};
static const int dy[] = {0,0,1,-1};
int main(int argc,char *argv[])
{
    int T;
    cin >> T;
    char grid[512];
    for (int t=0;t<T;t++)
    {
        int R,C,N;
        cin >> R >> C >> N;
        int ans = 1<<30;
        int RC = R*C;
        for (int i=0;i<(1<<RC);i++)
        {
            int cnt = 0;
            for (int j=0;j<RC;j++)
                if ((i&(1<<j))!=0)
                {
                    grid[j] = 1;
                    cnt++;
                } else
                {
                    grid[j] = 0;
                }
            if (cnt!=N) continue;
            int happy = 0;
            for (int y=0;y<R;y++)
                for (int x=0;x<C;x++)
                {
                    int idx = x+y*C;
                    if (grid[idx]==0) continue;
                    for (int d=0;d<4;d++)
                    {
                        int ox = x+dx[d];
                        int oy = y+dy[d];
                        if (ox>=0 && ox<C && oy>=0 && oy<R && grid[ox+oy*C]==1)
                        {
                            happy++;
                        }
                    }
                }
            ans = min(ans, happy);
        }
        cout << "Case #" << t+1 << ": " << ans/2 << endl;
    }

    return 0;
}
