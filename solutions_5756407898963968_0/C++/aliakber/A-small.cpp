#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<string>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;


#define ri(N) scanf("%d",&N)


int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int i,j,k,l,m,n,t,kase=1;
    ri(t);
    while(t--)
    {
        ri(m);
        vector<int>state(20,0);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                ri(k);
                if(i==m)
                  state[k]=1;
            }
        }
        ri(m);
        int cnt=0;
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                ri(k);
                if(i==m)
                {
                    if(state[k])
                    {
                        cnt++;
                        n=k;
                    }
                }
            }
        }
        if(cnt==1)
            printf("Case #%d: %d\n",kase++,n);
        else if(cnt==0)
            printf("Case #%d: Volunteer cheated!\n",kase++);
        else
            printf("Case #%d: Bad magician!\n",kase++);
    }
return 0;
}
