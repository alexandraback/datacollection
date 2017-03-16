#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<utility>
#include<queue>
#include<stack>
#include<ctime>
#include<algorithm>
#define SZ 3005
using namespace std;
typedef pair<int,int> Pii;
int x[SZ],y[SZ];
int p,q;
bool mycmp(const Pii &a,const Pii &b)
{
    long long x1=a.first-p,x2=b.first-p,y1=a.second-q,y2=b.second-q;
    return y1*x2<=y2*x1;
}
bool lft_turn(const Pii &a,const Pii &b,const Pii &c)
{
    long long x1=b.first-a.first,x2=c.first-a.first,y1=b.second-a.second,y2=c.second-a.second;
    return y1*x2<=y2*x1;
}
bool between(long long a,long long b,long long c)
{
    return b>=min(a,c)&&b<=max(a,c);
}
bool inbetween(const Pii &a, const Pii &b, const Pii &c)
{
    long long x1=b.first-a.first,x2=c.first-b.first,y1=b.second-a.second,y2=c.second-b.second;
    //long long x3=c.first-a.first,y3=c.second-a.second;
    return y1*x2==y2*x1;
}
int findhull(const vector<Pii> &v1)
{
    vector<Pii> v=v1;
    if(v.size()<=3)
        return (1<<v.size())-1;
    int mnp=0;
    for(int i=0;i<v.size();i++)
        if(v[i].first<v[mnp].first)
            mnp=i;
    swap(v[0],v[mnp]);
    p=v[0].first;
    q=v[0].second;
    //vector<int> vv=vector<int> (v.begin()+1,v.end());
    sort(v.begin()+1,v.end(),mycmp);
    /*if(v1.size()==9)
    {
        cout<<endl;
        for(int i=0;i<9;i++)
            cout<<v[i].first<<" "<<v[i].second<<endl;
        cout<<endl;
    }*/
    vector<Pii> cur;
    cur.push_back(v[0]);
    for(int i=1;i<v.size();i++)
    {
        int l=cur.size();
        while(cur.size()>=2&&!lft_turn(cur[l-2],cur[l-1],v[i]))
        {
            /*if(v1.size()==9)
            {
                cout<<v[i].first<<" "<<v[i].second<<endl;
                cout<<"popping "<<cur.back().first<<" "<<cur.back().second<<endl;
                cout<<cur[l-2].first<<" "<<cur[l-2].second<<endl;
            }*/
            l--;
            cur.pop_back();
        }
        cur.push_back(v[i]);
    }
    //if(v1.size()==5)
        //cout<<"holla "<<cur.size()<<endl;
    int ret=0;
    for(int i=0;i<v1.size();i++)
    {
        bool found =false;
        for(int j=0;j<cur.size()-1;j++)
        {
            if(inbetween(cur[j],v1[i],cur[j+1]))
            {
                /*if(v1.size()==9)
                {
                    cout<<i<<" oria "<<j<<endl;
                    cout<<v1[i].first<<" "<<v1[i].second<<endl;
                    cout<<cur[j].first<<" "<<cur[j].second<<endl;
                }*/
                found=true;
                break;
            }
        }
        if(found)
            ret|=(1<<i);
    }
    return ret;
}
int countbit(int n)
{
    int cnt=0;
    while(n)
    {
        if(n&1)
            cnt++;
        n>>=1;
    }
    return cnt;
}
int main()
{
    freopen("Cin2.in","r",stdin);
    freopen("Cout.txt","w",stdout);
    int T,n;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        int ans[15];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            ans[i]=n;
        }
        for(int i=0;i<(1<<n);i++)
        {
            vector<Pii> v;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i)
                    v.push_back(Pii(x[j],y[j]));
            }
            //cout<<i<<" "<<countbit(i)<<endl;
            int r=findhull(v),cnt=0,rem=n-countbit(i);
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&i))
                {
                    if((1<<cnt)&r)
                    {
                        ans[j]=min(ans[j],rem);
                    }
                    cnt++;
                }
            }
        }
        printf("Case #%d:\n",cas);
        for(int i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}


