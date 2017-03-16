#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,int> >q;
void solve()
{
    int a,n,i,l;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a;
        q.push({a,i});
        l+=a;
    }
    l&=1;
    pair<int,int>p;
    if(l)
    {
        p=q.top();
        q.pop();
        cout<<char('A'+p.second);
        --p.first;
        if(p.first)q.push(p);
    }
    while(q.size())
    {
        if(l)cout<<" ";
        p=q.top();
        q.pop();
        cout<<char('A'+p.second);
        --p.first;
        if(p.first)q.push(p);
        p=q.top();
        q.pop();
        cout<<char('A'+p.second);
        --p.first;
        if(p.first)q.push(p);
        l=1;
    }
    cout<<endl;
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
