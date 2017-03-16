#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char ch[105][105];
char ch2[105][105];
int cal[105][105];
void change(int now)
{
    ch2[now][0]=ch[now][0];
    cal[now][0]=1;
    int j=0;
    for(int i=1;i<strlen(ch[now]);i++)
    {
        if(ch[now][i]==ch[now][i-1])
        {
            cal[now][j]++;
        }
        else
        {
            j++;
            ch2[now][j]=ch[now][i];
            cal[now][j]=1;
        }
    }
    ch2[now][j+1]=0;
}
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("A-large.in","r",stdin);    freopen("A-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
        memset(cal,0,sizeof(cal));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",ch[i]);
            change(i);
        }
        int pan=0;
        for(i=2;i<=n;i++)
        {
            if(strcmp(ch2[i],ch2[1])!=0)
            {
                pan=1;
                break;
            }
        }
        if(pan==1)
        {
            printf("Case #%d: Fegla Won\n",tcase);
            continue;
        }
        int numA=0;
        int all[105];
        for(j=0;j<strlen(ch2[1]);j++){int num=0;
        for(i=1;i<=n;i++)
        {
            num+=cal[i][j];
        }
        num/=n;
        for(i=1;i<=n;i++)
        {
            numA+=abs(num-cal[i][j]);
        }
        }
        printf("Case #%d: %d\n",tcase,numA);
        /*
        int get=cal();
        if(get==-1) printf("Case #%d: Fegla Won\n",tcase);
        else
        printf("Case #%d: %d\n",tcase,get);*/
    }
    fclose(stdin);    fclose(stdout);
}
