#include<bits/stdc++.h>
using namespace std;
int arr[100009];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    cin>>test;
    for(int x=1;x<=test;x++)
    {
        int n,p;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        priority_queue<pair<int,int> >Q;
        int tot=0;
        for(int i=0;i<n;i++)
        {
            Q.push(make_pair(arr[i],i));
            tot+=arr[i];
        }
        cout<<"Case #"<<x<<":";
        while(!Q.empty())
        {
            cout<<" ";
            int tmp=Q.top().first;
            int ch=Q.top().second;
            Q.pop();
            tot--;
            tmp--;
            if(tmp!=0)
                Q.push(make_pair(tmp,ch));
            cout<<char(ch+'A');
            tmp=Q.top().first;
            ch=Q.top().second;
            if(tmp>tot/2)
            {
                tot--;
                tmp--;
                Q.pop();
                if(tmp!=0)
                    Q.push(make_pair(tmp,ch));
                cout<<char(ch+'A');
            }
        }
        cout<<endl;
    }
    fclose(stdout);
}
