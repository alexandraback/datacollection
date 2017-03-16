#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<time.h>
#include<cmath>
#include<vector>
#include <iomanip>
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
using namespace std ;
#define MAX  130
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

int p[MAX];

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n ;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
            sum+=p[i];
        }
        int Max1,id1 ;
        printf("Case #%d:",cas++);
        while(sum>0)
        {
            Max1=0;
            id1=0;
            for(int i=0; i<n; i++)
            {
                if(p[i]>Max1)
                {
                    Max1=p[i];
                    id1=i;
                }
            }
            p[id1]--;
            sum--;
            bool ok=true ;
            for(int i=0; i<n; i++)
            {
                if(p[i]*2>sum)
                    ok=false ;
            }
            int Max2=0,id2=0;
            if(!ok)
            {
                for(int i=0; i<n; i++)
                {
                    if(p[i]>Max2)
                    {
                        Max2=p[i];
                        id2=i;
                    }
                }
                printf(" %c%c",'A'+id1,'A'+id2);
                sum--;
            }
            else
            {
                printf(" %c",'A'+id1);
            }
        }
        printf("\n");
    }
    return 0 ;
}
