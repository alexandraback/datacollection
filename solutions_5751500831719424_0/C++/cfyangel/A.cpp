#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

int t,id,n;
int i,j,len[110],tt[110][110],ans;
char st[110][110];

int cmp(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
int check()
{
    int i,j,flag[110],m;
    memset(flag,0,sizeof(flag));
    m=0;
    for (flag[0]=0;flag[0]<len[0];flag[0]++)
    {
        for (j=1;j<n;j++)
        {
  //  printf("%d ok %d %d ,",flag[0],j,flag[j]);
            if (st[0][flag[0]]!=st[j][flag[j]])return 0;
            tt[m][j]=1;
            while(st[j][flag[j]+1]==st[0][flag[0]])
            {
                tt[m][j]++;
                flag[j]++;
            }
            flag[j]++;
        }
        tt[m][0]=1;
        while(st[0][flag[0]]==st[0][flag[0]+1])
        {
            tt[m][0]++;
            flag[0]++;
        }
        qsort(tt[m],n,sizeof(tt[m][0]),cmp);
        m++;
    }
    for (i=0;i<n;i++)
        if (flag[i]!=len[i])return 0;
    ans=0;
    for (j=0;j<m;j++)
    {
        for (i=0;i<n;i++)
        {
            ans+=abs(tt[j][n/2]-tt[j][i]);
  //          printf("%d ",tt[j][i]);
        }
 //       printf("\n");
    }
    return 1;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("a.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        memset(tt,0,sizeof(tt));
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%s",st[i]);
            len[i]=strlen(st[i]);
        }
        printf("Case #%d: ",id);
        if (check()==0) printf("Fegla Won\n");
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
