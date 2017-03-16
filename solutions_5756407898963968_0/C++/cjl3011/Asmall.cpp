#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int main(int argc,char *argv[])
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,a,b,q[5][5],w[5][5];
    int z[5],x[5];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&a);
        int cnt1=1,cnt2=1;
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&q[i][j]);
            if(i==a)
                z[cnt1++]=q[i][j];
        }
        scanf("%d",&b);
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&w[i][j]);
            if(i==b)
                x[cnt2++]=w[i][j];
        }
        int f=0,tmp;
        for(int i=1;i<=cnt1-1;i++)
        {
            for(int j=1;j<=cnt2-1;j++)
            {
                if(z[i]==x[j])
                {
                    tmp=z[i];
                    f++;
                }
            }
        }
        printf("Case #%d: ",cas);
        if(f==1)
            printf("%d\n",tmp);
        else if(f>=2)
            printf("Bad magician!\n");
        else
            printf("Volunteer cheated!\n");
    }
    return 0;
}

