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
int cost(vector<int> a)
{
    int n=a.size();
    int best=100000;
    int cur;
    for(int final=0;final<=100;++final)
    {   
        cur=0;
        for(int i=0;i<n;++i)
            cur+=abs(final-a[i]);
        if(cur<best)
            best=cur;
    }
    return best;
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
        string skell;
        cin>>s[0];
        skell=skeleton(s[0]);
        bool flag=true;
        for(int i=1;i<n;++i)
        {
            cin>>s[i];
            skel[i]=skeleton(s[i]);
            if(skel[i]!=skell)
                flag=false;  

        }

        if(flag==false)
            printf("Fegla Won\n");
        else
        {
            vector<vector<int> > basic(n);
            
            for(int i=0;i<n;++i)
                basic[i]=rep(s[i]);
            int m=basic[0].size();
            int ans=0;
            vector<vector<int> > basicT(m,vector<int> (n));

            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    basicT[j][i]=basic[i][j];

            for(int i=0;i<m;++i)
            {   
                ans+= cost( basicT[i] );
            }
            
            printf("%d\n",ans);
        }
    }
}
