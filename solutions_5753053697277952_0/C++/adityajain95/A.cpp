#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

int p[30];
vector<int> vec;
vector<int> sp;

int main()
{
    freopen("1.in","r",stdin);
    freopen("A-out.txt","w",stdout);
    int tt,t,j,n,m,i,num;
    si(tt);
    for(t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        priority_queue < pi, vector<pi> > pq;
        num=0;
        while(!pq.empty())
        {
            pq.pop();
        }
        vec.clear();
        for(i=0;i<n;i++)
        {
            si(p[i]);
            num+=p[i];
            pq.push(mp(p[i],i));
        }
        printf("Case #%d: ",t);
        while(!pq.empty())
        {
            if(pq.size()==2)
            {
                if((pq.top()).f==1)
                {
                    pi ele=pq.top();
                    //vec.pb(ele.s);
                    printf("%c",'A'+ele.s);
                    pq.pop();
                    printf("%c\n",'A'+(pq.top()).s);
                    //sp.pb(0);
                    //vec.pb((pq.top()).s);
                    //sp.pb(0);
                    break;
                }
            }
            pi ele=pq.top();
            pq.pop();
            //vec.pb(ele.s);
            printf("%c",'A'+ele.s);
            if(ele.f>1)
                pq.push(mp( (ele.f)-1 ,ele.s ));
            num--;
            if(!pq.empty())
            {
                int maj=(num/2)+1;
                if( (pq.top()).f>=maj )
                {
                    //debug(maj);
                    //sp.pb(0);
                    pi ele=pq.top();
                    pq.pop();
                    printf("%c",'A'+ele.s);
                    if(ele.f>1)
                        pq.push(mp( (ele.f)-1 ,ele.s ));
                    num--;
                }
            }
            printf(" ");
        }
    }
    return 0;
}
