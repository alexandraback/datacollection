#include<bits/stdc++.h>
using namespace std;

int t,n,p[10000];
set<pair<int,int> >s;

void prnt(vector<pair<int,int> > a,int t)
{
    cout<<"Case #"<<t<<": ";
    for(int i=0;i<a.size();i++)
    {
        cout<<char('A'+a[i].first-1);
        if(a[i].second>0)
            cout<<char('A'+a[i].second-1);
        cout<<' ';
    }
    cout<<"\n";
}

bool big(int x,int y)
{
    return x+x>y;
}

int main()
{
    freopen("Asmall.in","r",stdin);
    freopen("Asmall.out","w",stdout);
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        int all=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            all+=p[i];
            s.insert(make_pair(-p[i],i));
        }
        vector<pair<int,int> >ans;
        while(!s.empty())
        {
            ans.push_back(make_pair(-1,-1));
            pair<int,int> cur1=(*s.begin());
            s.erase(s.begin());
            pair<int,int> cur2=(*s.begin());
            s.erase(s.begin());
            ++cur1.first;
            ans.back().first=cur1.second;
            --all;
            if(big(-cur2.first,all) || all==1)
            {
                ++cur2.first;
                --all;
                ans.back().second=cur2.second;
            }
            ///cout<<cur1.first<<' '<<cur2.first<<"\n";
            if(cur1.first)
                s.insert(cur1);
            if(cur2.first)
                s.insert(cur2);
        }
        prnt(ans,t1);
    }
}
