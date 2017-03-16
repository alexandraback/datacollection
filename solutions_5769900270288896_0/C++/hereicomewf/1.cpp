#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

/*
class bit
{

int tree[200007];
public:

void reset()
{
memset(tree,0,sizeof(tree));
}

void update(int idx,int vl)
{
    while(idx<=200000)
    {
        tree[idx]+=vl;
        idx+=(idx&-idx);
    }
}

int query(int x)
{
    int sum=0;
    while(x)
    {
        sum+=tree[x];
        x-=(x&-x);
    }
    return sum;
}
};
*/

#define cin(n) scanf("%d",&n)
int dp[1000008];
int req;
int ans;

int main()
{      
    int t,m,n,i,j,k,l;
    
    cin(t);
    int ct=1;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin(req); 
        
        
        queue<int>q;
        
        q.push(1);
        dp[1]=1;
        while(q.size())
        {
            int x=q.front();
            q.pop();
            if(x==req)
            break;
            
            if(dp[x+1]==-1)
            {
                dp[x+1]=dp[x]+1;
                q.push(x+1);
            }
            int vl=0,xx=x;
            while(xx>0)
            {
                vl=vl*10+xx%10;
                xx/=10;
            }
            if(dp[vl]==-1)
            {
                dp[vl]=dp[x]+1;
                q.push(vl);
            }
        
        }
        cout<<"Case #"<<ct++<<": ";
        cout<<dp[req]<<"\n";
    }
    return 0;
}