#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define p 1000000007
#define pb push_back
#define mp make_pair
typedef long long Int;
typedef pair<Int,char> pii;
typedef vector<Int> vi;
typedef vector<pii> vii;
struct cmp
{
    bool operator()(pii a,pii b)
    {
        return a.fs<b.fs;
    }
};
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    Int T;
    cin>>T;
    for (Int k=1;k<=T;++k)
    {
        pii P;
        Int N,x,sum=0;
        char a,b;
        cin>>N;
        cout<<"Case #"<<k<<": ";
        priority_queue<pii,vii,cmp>pq;
        for (Int i=0;i<N;++i)
        {
            cin>>x;
            sum+=x;
            pq.push(mp(x,'A'+i));
        }
        if (sum%2==1)
        {
            P=pq.top();
            a=P.sc;
            pq.pop();
            pq.push(mp(P.fs-1,P.sc));
            sum-=1;
            cout<<a<<" ";
        }
        while (sum!=0)
        {
            P=pq.top();
            a=P.sc;
            pq.pop();
            pq.push(mp(P.fs-1,P.sc));
            sum-=1;
            P=pq.top();
            b=P.sc;
            pq.pop();
            pq.push(mp(P.fs-1,P.sc));
            sum-=1;
            cout<<a<<b<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
