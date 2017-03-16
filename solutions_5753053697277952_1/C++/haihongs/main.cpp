#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const int inf=1e9+9;

struct II
{
    int v,cnt;
} num[maxn];;

int cmp(II x,II y);

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cass=1;
    while(t--)
    {
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i].cnt);
            num[i].v=i;
        }
        printf("Case #%d: ",cass++);
        sort(num,num+n,cmp);
        int maxx=num[0].cnt;
        int pp=0;
        for(; num[0].cnt>num[1].cnt;)
        {
            if(pp==0)
            {
                printf("%c",num[0].v+'A');
                pp=1;
            }
            else printf(" %c",num[0].v+'A');
            num[0].cnt--;
        }
        for(int i=2; i<n; i++)
        {
            for(int j=0; j<num[i].cnt; j++)
            {
                if(pp==0)
                {
                    printf("%c",num[i].v+'A');
                    pp=1;
                }
                else printf(" %c",num[i].v+'A');
            }
        }
        for(int i=0;i<num[0].cnt;i++)
        {
            if(pp==0)
            {
                printf("%c%c",num[0].v+'A',num[1].v+'A');pp=1;
            }
            else printf(" %c%c",num[0].v+'A',num[1].v+'A');
        }
        printf("\n");
    }
    return 0;
}

int cmp(II x,II y)
{
    return x.cnt>y.cnt;
}
