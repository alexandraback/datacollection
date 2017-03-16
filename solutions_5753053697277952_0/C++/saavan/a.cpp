#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#include<cmath>

#define f(i,a,b) for(int i=a;i<b;i++)
#define b(i,a,b) for(int i=a;i>b;i--)
#define mpr(a,b) make_pair(a,b)
#define pr pair<int,int>
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define newline printf("\n")
#define ll long long 
using namespace std;
main()
{
    freopen("inp.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ch;
    priority_queue<pr> mp;
    int t;
    cin>>t;
    f(k,1,t+1)
    {
        int n;
        cin>>n;
        f(i,0,n)
        {
            cin>>ch;
            mp.push(mpr(ch,i));
        }
        cout<<"Case #"<<k<<": ";
        while(!mp.empty())
        {
            if(mp.size()==2)
            {
                cout<<char((mp.top().second)+'A');
                int val=mp.top().first-1;
                int v=mp.top().second;
                mp.pop();if(val!=0)
                mp.push(mpr(val,v));
                cout<<char((mp.top().second)+'A')<<" ";
                val=mp.top().first-1;
                v=mp.top().second;
                mp.pop();if(val!=0)
                mp.push(mpr(val,v));
            }
            else
            {
                cout<<char((mp.top().second)+'A')<<" ";
                int val=mp.top().first-1;
                int v=mp.top().second;
                mp.pop();
                if(val!=0)
                mp.push(mpr(val,v));
            }
        }
        cout<<"\n";
    }
}
        
    
