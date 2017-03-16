#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define pil pair<int,ll>
#define pli pair<ll,int>
int a[100011];
int main()
{
    freopen("2.in","r",stdin);
    freopen("2-out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n;
        priority_queue< pii  >pq;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            pq.push(mp(a[i],i));
        }
        string ans="";
        while(!pq.empty())
        {
            pii p=pq.top();
            pq.pop();
            if(pq.size()!=1)
            {
                char ch='A'+p.s;
                ans+=ch;
                ans+=' ';
                if(p.f>1)
                    pq.push(mp(p.f-1,p.s));
            }
            else
            {
                pii p1=pq.top();
                pq.pop();
                char ch='A'+p.s;
                ans+=ch;
                ch='A'+p1.s;
                ans+=ch;
                ans+=' ';
                if(p1.f>1)
                    pq.push(mp(p1.f-1,p1.s));
                if(p.f>1)
                    pq.push(mp(p.f-1,p.s));
            }
        }
        printf("Case #%d: ",cs);
        cout<<ans<<endl;
        cs++;
    }
    return 0;
}

