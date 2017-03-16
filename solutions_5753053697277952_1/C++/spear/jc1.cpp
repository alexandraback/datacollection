#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large (6).in","r",stdin);
    freopen("oc.txt","w",stdout);
    int t,z;
    cin>>t;
    for(z=1;z<=t;z++)
    {

        int n;
        cin>>n;
        int p[n],i;
        priority_queue<pair<int,int > >pq;
        pair<int,int> pr,temp;
        int sum=0;
        for(i=0;i<n;i++)
        {
            cin>>p[i];
            pr.first=p[i];
            pr.second=i;
            pq.push(pr);
            sum+=p[i];
        }
        cout<<"Case #"<<z<<": ";
        while((!pq.empty())&&sum)
        {
            pr=pq.top();
            pq.pop();
            if(!(pq.empty()))
                temp=pq.top();
            if(!(pq.empty()))
            {
                cout<<(char)('A'+pr.second);
                sum--;
                pr.first--;
                if(temp.first*2>sum)
                {
                    cout<<(char)('A'+temp.second);
                temp.first--;
                pq.pop();
                if(temp.first)
                    pq.push(temp);
                    sum--;
                }
                if(pr.first)
                pq.push(pr);
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
