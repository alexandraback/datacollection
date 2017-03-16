#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int t,cs,n,i,in;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        pair<int,int> p;
        pair<int,int> p2;
        priority_queue < pair<int,int> > qu;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&in);
            qu.push(make_pair(in,i+65));
        }
        printf("Case #%d: ",cs);
        while(!qu.empty())
        {
            p=qu.top();
            qu.pop();
            if(!qu.empty())
            {
                p2=qu.top();

                if(p2.first==p.first)
                {
                    qu.pop();
                    if(p.first==1&&!qu.empty())
                    {
                        printf("%c ",p.second);
                        qu.push(p2);
                    }
                    else{
                        printf("%c%c ",p.second,p2.second);
                        p.first--;
                        p2.first--;
                        if(p.first!=0)
                        {
                            qu.push(p);
                            qu.push(p2);
                        }

                    }

                }
                else{
                    printf("%c ",p.second);
                    p.first--;
                    if(p.first!=0)
                    {
                        qu.push(p);
                    }
                }

            }
            else{
                    printf("%c ",p.second);
                    p.first--;
                    if(p.first!=0)
                    {
                        qu.push(p);
                    }

            }

        }
        printf("\n");

    }
    return 0;
}
