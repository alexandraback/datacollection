#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=1010;
int num[maxn];
int main()
{
    int T,cas=1;
    num[0]=-1;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&num[i]);
        printf("Case #%d: ",cas++);
        int sum=0;
        for(int i=2;i<=n;i++)
            if(num[i]<num[i-1])
                sum+=num[i]-num[i-1];
        printf("%d",-sum);
        int Ma=0;
        for(int i=2;i<=n;i++)
            Ma=max(Ma,num[i-1]-num[i]);
        double  rate=Ma/10.0;
        //if(Ma&&Ma%10!=0)    ++rate;
        //printf(" %d\n",rate);
        sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=min((int)(rate*10),num[i]);
            //printf("%d\n",min(rate*10,num[i]));
        }
        printf(" %d\n",sum);
    }
    return 0;
}
