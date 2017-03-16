#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define EPS (1e-8)

using namespace std;
/*
LL dis[1000010];

queue<LL> q;

int num[20];

LL Cal(LL x)
{
    int i;
    LL tmp = 1;
    memset(num,0,sizeof(num));
    for(i = 1;x;i++,x/= 10)
        num[i] = x%10;
    LL anw = 0;
    while(num[i] == 0)
        --i;
    for(tmp = 1;i >= 1; --i,tmp *= 10)
        anw += num[i]*tmp;
    return anw;
}

LL bfs(LL n)
{
    while(q.empty() == false)
        q.pop();

    memset(dis,INF,sizeof(dis));

    q.push(1);
    dis[1] = 1;

    while(q.empty() == false)
    {
        LL f = q.front();
        q.pop();

        if(f == n)
            return dis[f];

        if(dis[f+1] > dis[f]+1)
            q.push(f+1),dis[f+1] = dis[f]+1;
        LL t = Cal(f);
        if(dis[t] > dis[f]+1)
            q.push(t),dis[t] = dis[f]+1;
    }
}

int main()
{
    int T,icase = 1;

    scanf("%d",&T);

    LL n;

    while(T--)
    {
        scanf("%lld",&n);

        printf("Case #%d: %lld\n",icase++,bfs(n));
    }

    return 0;
}

*/

int Cal(int sta)
{
    int ans = 0;
    while(sta)
        ans += (sta&1),sta >>= 1;
    return ans;
}

int Map[20][20];
int jx[] = {-1, 0, 1, 0};
int jy[] = { 0,-1, 0, 1};
int Cal(int sta,int R,int C)
{
    memset(Map,0,sizeof(Map));
    int i,j;
    for(i = 0;i < R; ++i)
    {
        for(j = 0;j < C; ++j)
        {
            if((1<<(i*C+j))&sta)
                Map[i][j] = 1;
        }
    }
    int ans = 0;
    for(i = 0;i < R; ++i)
    {
        for(j = 0;j < C; ++j)
        {
            if(Map[i][j] == 0)
                continue;
            for(int k = 0;k < 4; ++k)
            {
                int tx = i+jx[k],ty = j+jy[k];

                if(tx>= 0 &&tx < R && ty >= 0 && ty <= C)
                {
                    if(Map[tx][ty] == 1)
                    ans++;
                }
            }
        }
    }

    return ans/2;
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("data1.out","w",stdout);
   int R,C,n;
    int T,icase = 1;
  scanf("%d",&T);

    int i,j,k;

    while(T--)
    {
        scanf("%d %d %d",&R,&C,&n);

        int Max = (1<<(R*C));
        int Min = 1000000;
        for(i = 0;i < Max; ++i)
        {
            if(Cal(i) == n)
                Min = min(Min,Cal(i,R,C));
        }

        printf("Case #%d: %d\n",icase++,Min);
    }


    return 0;
}

/*
vector<int> vec[10010];

struct N
{
    int x,y,z;

    bool operator < (const N &a)const{
        return z < a.z;
    }
};

priority_queue<N> q;



int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
  //  freopen("data1.out","w",stdout);
    int R,C,n;
    int T,icase = 1;

    scanf("%d",&T);

    int i,j,k;

    while(T--)
    {
        scanf("%d %d %d",&R,&C,&n);
        printf("R = %3d C = %3d n = %5d\n",R,C,n);
        for(i = 1;i <= R; ++i)
            vec[i].clear();

        for(i = 1;i <= R; ++i)
            for(j = 0;j <= C; ++j)
                vec[i].push_back(0);

        int ans;
        while(q.empty() == false)
            q.pop();
        for(i = 1;i <= R; ++i)
        {
            for(j = 1;j <= C; ++j)
            {
                ans = 4;

                if(i == 1)
                    ans--;
                if(i == R)
                    ans--;
                if(j == 1)
                    ans--;
                if(j == C)
                    ans--;

                vec[i][j] = ans;
                q.push((N){i,j,ans});
            }
        }

        ans = (R-1)*(C-1)*2 + R-1 + C-1;

        n = R*C-n;

        while(n--)
        {
            N Max = q.top(),tmp;
            q.pop();

            if(vec[Max.x][Max.y] == Max.z)
            {
                ans -= Max.z;
                for(i = 0;i < 4; ++i)
                {
                    tmp.x = Max.x + jx[i];
                    tmp.y = Max.y + jy[i];

                    if(1 <= tmp.x && tmp.x <= R && 1 <= tmp.y && tmp.y <= C)
                    {
                        vec[tmp.x][tmp.y]--;
                    }
                }
                cout<<"x = "<<Max.x<<" y = "<<Max.y<<" z = "<<Max.z<<endl;
            }
            else
            {
                Max.z = vec[Max.x][Max.y];
                q.push(Max);
                n++;
            }
        }
        printf("Case #%d: %d\n",icase++,ans);
    }

    return 0;
}
*/








