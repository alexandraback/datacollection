#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char str[101][101];
int que[101];
int maxz[101];
int minz[101];
int o[101][101];
int main()
{
    int n,cas = 1,t,len,flag,i,num,z,k,j;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(i = 0;i < n;i ++)
        scanf("%s",str[i]);
        len = strlen(str[0]);
        que[0] = str[0][0];
        memset(o,0,sizeof(o));
        num = 1;
        flag = 1;
        for(i = 1;i < len;i ++)
        {
            if(que[num-1] != str[0][i])
            {
                maxz[num-1] = flag;
                minz[num-1] = flag;
                o[0][num-1] = flag;
                flag = 1;
                que[num++] = str[0][i];
            }
            else
            flag ++;
        }
        maxz[num-1] = flag;
        minz[num-1] = flag;
        o[0][num-1] = flag;
        z =  0;
        for(i = 1;i < n;i ++)
        {
            len = strlen(str[i]);
            k = 0;
            flag = 0;
            for(j = 0;j < len;j ++)
            {
                if(que[k] == str[i][j])
                flag ++;
                else
                {
                    if(k == 0&&j == 0)
                    {
                        z = 1;
                    }
                    maxz[k] = max(flag,maxz[k]);
                    minz[k] = min(flag,minz[k]);
                    o[i][k] = flag;
                    k ++;
                    if(que[k] == str[i][j])
                    flag = 1;
                    else
                    z = 1;
                }
            }
            if(k != num-1) z = 1;
            maxz[k] = max(flag,maxz[k]);
            minz[k] = min(flag,minz[k]);
            o[i][k] = flag;
            if(z) break;
        }
//        for(i = 0;i < n;i ++)
//        {
//            for(j = 0;j < num;j ++)
//            printf("%d ",o[i][j]);
//            printf("\n");
//        }
        for(i = 0;i < n;i ++)
        {
            for(j = 0;j < num;j ++)
            {
                int mid = (maxz[j] + minz[j])/2;
                int temp = o[i][j] - mid;
                if(temp < 0)
                temp = - temp;
                ans += temp;
            }
        }
        printf("Case #%d: ",cas++);
        if(z)
        printf("Fegla Won\n");
        else
        printf("%d\n",ans);

    }
    return 0;
}
