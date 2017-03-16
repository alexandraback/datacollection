#include <iostream>
#include <cstdio>
#include<string.h>
#include<string>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1000000000+7;
double eps=1e-9;
const int inf=0x3f3f3f3f;
const int maxn=100+10;
const int maxm=2000000+10;
char a[maxn];
int sum[maxn][maxn][2];
int cnt[maxn];
int index;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        tcase++;
        printf("Case #%d: ",tcase);
        //memset(cnt,0,sizeof cnt);
        int n;
        scanf("%d",&n);
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            int len=strlen(a);
            int num=0;
            sum[i][0][0]=a[0];
            sum[i][0][1]=1;
            for(int j=1;j<len;j++)
            {
               if(a[j]!=a[j-1])
               {
                   num++;
                   sum[i][num][0]=a[j];
                   sum[i][num][1]=1;
               }
               else
               {
                   sum[i][num][1]++;
               }
            }
            if(i==0) index=num;
            if(i!=0)
            {
                if(num!=index) flag=0;
                else
                {
                    for(int k=0;k<=num;k++)
                    {
                        if(sum[i][k][0]!=sum[i-1][k][0])
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("Fegla Won\n");
        }
        else
        {
            int tot=0;
            for(int i=0;i<=index;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cnt[j]=sum[j][i][1];
                }
                sort(cnt,cnt+n);
                int ave=cnt[n/2];
                for(int j=0;j<n;j++)
                {
                    tot+=abs(cnt[j]-ave);
                }
            }
            printf("%d\n",tot);
        }
    }
    return 0;
}
