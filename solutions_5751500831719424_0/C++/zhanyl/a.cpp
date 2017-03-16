#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn=105;

int n;
string s[maxn];
int l[maxn],now[maxn],f[maxn];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a-ans.txt","w",stdout);
    int t;
    int ans;
    char x;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            l[i]=s[i].size();
            now[i]=0;
        }
        ans=0;
        while(1)
        {
            if(ans==-1)break;
            if(now[0]==l[0])
            {
                for(int i=0;i<n;i++)
                    if(now[i]!=l[i])ans=-1;
                break;
            }
            for(int i=0;i<n;i++)
                if(now[i]==l[i])
                {
                    ans=-1;
                    break;
                }
                else if(s[i][now[i]]!=s[0][now[0]])
                {
                    ans=-1;
                    break;
                }
            if(ans==-1)break;
            x=s[0][now[0]];
            for(int i=0;i<n;i++)
            {
                f[i]=0;
                while(now[i]<l[i]&&s[i][now[i]]==x)
                {
                    f[i]++;
                    now[i]++;
                }
            }
            sort(f,f+n);
            for(int i=0;i<n;i++)
                ans+=abs(f[i]-f[n/2]);
        }
        if(ans!=-1)printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: Fegla Won\n",cas);
    }
    return 0;
}
