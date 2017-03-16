#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
char s[110][110];
int indexx[110];
int abs(int x)
{
    if(x<0)return -x;
    return x;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,no=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,sol=0;
        bool finish=false;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        int i=0,j=0;
        int len1=strlen(s[0]),len2=strlen(s[1]);
        while(i<len1&&j<len2)
        {
            if(s[0][i]!=s[1][j])
            {
                finish=true;
                printf("Case #%d: Fegla Won\n",no++);
                break;
            }
            int check=s[0][i];
            int cnt1=0,cnt2=0;
            while(i<len1&&s[0][i]==check)
            {
                i++;
                cnt1++;
            }
            while(j<len2&&s[1][j]==check)
            {

                j++;
                cnt2++;
            }
            sol+=abs(cnt1-cnt2);
        }
        if(i<len1||j<len2)
        {
                      if(!finish)printf("Case #%d: Fegla Won\n",no++);
        }

       else if(!finish) printf("Case #%d: %d\n",no++,sol);
    }
    return 0;
}
