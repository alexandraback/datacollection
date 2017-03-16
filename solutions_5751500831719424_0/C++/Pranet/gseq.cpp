#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#define pii pair<int,int>
using namespace std;
int infinity =1000000;
string skeleton(string s)
{

    string ans;
    int n=s.size();
    char prev='A';
    for(int i=0;i<s.size();++i)
    {
       if(s[i]!=prev)
            {
                ans+=s[i];
            }
        else
        {

        }
        prev=s[i];
    }


    return ans;
}
vector<int> rep(string s)
{
    int n=s.size();
    char prev='A';
    int cur=0;
    vector<int> ans;
    for(int i=0;i<n;++i)
    {

        if(s[i]!=prev)
        {
            ans.push_back(cur);
            cur=1;
        }
        else
        {
            ++cur;
        }
        prev=s[i];
    }
    if(cur)
        ans.push_back(cur);
    return ans;
}
main(void)
{
    int t,n;
    scanf("%d",&t);

    for(int tt=1;tt<=t;++tt)
    {
        printf("Case #%d: ",tt);
        scanf("%d",&n);
        vector<string> s(n);
        vector<string> skel(n);
        for(int i=0;i<n;++i)
        {
            cin>>s[i];
            skel[i]=skeleton(s[i]);
            // cout<<skel[i]<<endl;
        }
        if(skeleton(s[0])!=skeleton(s[1]) )
            printf("Fegla Won\n");
        else
        {
            vector<int> n1,n2;
            n1=rep(s[0]);
            n2=rep(s[1]);
            int ans=0;
            for(int i=0;i<n1.size();++i)
            {   
                ans+= abs( n1[i]-n2[i] );
            }
            //     cout<<n1[i] ;
            // }
            // cout<<endl;
            // for(int i=0;i<n1.size();++i)
            // {   
            //     cout<<n2[i];
            //     // ans+= abs( n1[i]-n2[i] );
            // }
            // cout<<endl;
            printf("%d\n",ans);
        }
    }
}
