#include<bits/stdc++.h>
using namespace std;
int n,ans,num[105],l[105],len[105];
char s[105][1000];

int main()
{
    int t,tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        for(int i=0;i<n;i++)
            len[i]=strlen(s[i]);
        ans=0;
        bool flag=true;
        printf("Case #%d: ",++tcase);
        memset(l,0,sizeof(l));
        while(1)
        {
            int cnt=1;
            while(l[0]<len[0]&&s[0][l[0]]==s[0][l[0]+1])
                cnt++,l[0]++;
            num[0]=cnt;
            for(int i=1;i<n;i++)
            {
                if(s[i][l[i]]!=s[0][l[0]])
                {
                    flag=false;
                    break;
                }
                int cnt=1;
                while(l[i]<len[i]&&s[i][l[i]]==s[i][l[i]+1])
                    cnt++,l[i]++;
                num[i]=cnt;
            }
            if(!flag)
                break;
            sort(num,num+n);
            for(int i=0;i<n;i++)
                ans+=abs(num[i]-num[n/2]);
            bool out=true;
            for(int i=0;i<n;i++)
            {
                l[i]++;
                if(l[i]!=len[i])
                    out=false;
            }
            if(out) break;
        }
        if(flag) printf("%d\n",ans);
        else puts("Fegla Won");
    }
    return 0;
}
