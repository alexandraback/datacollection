#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

int g[20];
int x;

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int cas = 1;
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(g,0,sizeof(g));
        scanf("%d",&x);
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++) {
                int y;
                scanf("%d",&y);
                if (i != x) g[y] = true;
            }
        scanf("%d",&x);
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++) {
                int y;
                scanf("%d",&y);
                if (i != x) g[y] = true;
            }
        int cnt = 0,ans;
        for (int i = 1; i <= 16; i++) if(!g[i]) cnt++,ans = i;
        if (cnt == 0) printf("Case #%d: Volunteer cheated!\n",cas++);
        else
        if (cnt >= 2) printf("Case #%d: Bad magician!\n",cas++);
        else printf("Case #%d: %d\n",cas++,ans);


    }
}
