#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int cnt[26];

int main()
{
#ifdef gh546
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
#endif // gh546
    int tc; scanf("%d",&tc);
    int T_T=0;
    while(tc--)
    {
        memset(cnt,0,sizeof(cnt));
        int n; scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&cnt[i]);
        printf("Case #%d: ",++T_T);
        bool flag=1;
        while(flag)
        {
            int tt=0;
            for(int i=0;i<26;i++) tt+=cnt[i];
            if(tt==0) break;
            else if(tt==1)
            {
                int mx=0;
                for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
                printf(" %c",'A'+mx);
                break;
            }

            int mx=0;
            for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
            cnt[mx]--;
            tt--;
//            for(int i=0;i<26;i++) tt+=cnt[i]; cout <<" tt : " <<tt <<" " ;
            if(tt>2 || tt==1)
            {
//                cout <<"!" <<endl;
                int a=mx;
                for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
                cnt[mx]--;
                printf(" %c%c",'A'+mx,'A'+a);
            }
            else
            {
                printf(" %c",'A'+mx);
            }
        }
        puts("");
    }
    return 0;
}
