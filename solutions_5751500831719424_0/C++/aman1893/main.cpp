#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <ctime>
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
#define R freopen("in","r",stdin)
#define W freopen("out","w",stdout)
using namespace std;
string str[101];
int main()
{
    R;W;
    int t;cin>>t;
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d: ",kase);
        int n;cin>>n;
        
        for(int i=0;i<n;i++)cin>>str[i];
        vector<string> s(n);
        vector<int> arr[101];
        for(int i=0;i<n;i++)s[i]="";
        for(int i=0;i<n;i++)
        {
            s[i]+=str[i][0];
            char c=str[i][0];
            int temp=1;
            for(int j=1;j<str[i].length();j++)
            {
                if(str[i][j]==c)temp++;
                else
                {
                    s[i]+=str[i][j];
                    arr[i].pb(temp);
                    c=str[i][j];
                    temp=1;
                }
            }
            arr[i].pb(temp);
        }
        int flag=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[0])flag=0;
        }
        
        
        
        if(!flag)cout<<"Fegla Won"<<endl;
        else
        {
            int ans=0;
            int k=arr[0].size();
            for(int i=0;i<k;i++)
            {
                int mm=-1;
                int h;
                for(int j=0;j<n;j++)mm=max(arr[j][i],mm);
                
                h=INT_MAX;
                int temp=0;
                for(int j=1;j<=mm;j++)
                {
                    temp=0;
                    for(int k=0;k<n;k++)
                    {
                        temp+=abs(arr[k][i]-j);
                    }
            
                    h=min(temp,h);
                }
                
                ans+=h;
            }
            cout<<ans<<endl;
        }
        
        
        
    }
}
