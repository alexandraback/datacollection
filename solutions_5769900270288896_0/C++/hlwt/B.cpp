#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int g[20][20];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        int ans=10000;
        int tot=1<<(n*m);
        for(int i=0;i<tot;i++) {
            int num=0;
            for(int j=0;j<n*m;j++) {
                if(i&(1<<j))
                    num++;
            }
            if(num!=c)
                continue;
            for(int j=1;j<=n;j++) {
                for(int k=1;k<=m;k++) {
                    int id=(j-1)*m+k-1;
                    if(i&(1<<id))
                        g[j][k]=1;
                    else
                        g[j][k]=0;
                }
            }
            int temp=0;
            for(int j=1;j<n;j++) {
                for(int k=1;k<=m;k++) {
                    if(g[j][k]&&g[j+1][k])
                        temp++;
                }
            }
            for(int j=1;j<=n;j++) {
                for(int k=1;k<m;k++) {
                    if(g[j][k]&&g[j][k+1])
                        temp++;
                }
            }
            ans=min(ans,temp);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
