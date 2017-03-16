#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<map>
#include<string.h>
#include<cstdlib>
using namespace std;

#define DEBUG
set<char> it;
string tmpstring;
int mpcnt[110],n,ans;
char str[110];
char strsv[110][1100];
char strsimple[110][110];
char strkick[110][110];
set<char> st;
bool checkall()
{
    int len = strlen(strsv[0]);
    for(int i=1;i<n;i++)
        if(strlen(strsv[i])!=len)return false;
        else
        {
            for(int j=0;j<len;j++)
                if(strsv[0][j]!=strsv[i][j])
                    return false;
        }
    return true;
}
int main()
{
    #ifdef DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int t,casecnt=1;
    scanf("%d",&t);
    while( t-- )
    {
        ans = 0;
        printf("Case #%d: ",casecnt++);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",strsv[i]);
        for(int i=0;i<n;i++)
        {
            strcpy(str,strsv[i]);
            mpcnt[i]=0;
            int len = strlen(str);
            for(int j=0;j<len;j++)
            {
                if(str[j]==str[j+1])
                {
                    while(str[j]==str[j+1])
                    {
                        strkick[i][mpcnt[i]++]=str[j];
                        for(int k=j+1;k<len;k++)
                            str[k]=str[k+1];
                        len--;

                    }
                }
            }
            strcpy(strsimple[i],str);
        }
        bool check=true;
        int alllen = strlen(strsimple[0]);
        for(int i=1;i<n;i++)
            if(strlen(strsimple[i])!=alllen)
            {
                check = false;
                break;
            }
            else
            {
                for(int j=0;j<alllen;j++)
                    if(strsimple[i][j]!=strsimple[0][j])
                    {
                        check = false;
                        break;
                    }
                if(!check) break;
            }
        if( !check ) puts("Fegla Won");
        else
        {
            //printf("have ans\n");
            int cnt = 0;
            while(true)
            {
                char tmpc = strsv[0][cnt],tmpn;
                char targetc;
                st.clear();
                st.insert(tmpc);
                int cnttmpc=0,cnttmpn=0;
                bool innercheck = true;
                for(int j=1;j<n;j++)
                    if(strsv[j][cnt]!=tmpc)
                    {
                        innercheck = false;
                        cnttmpn++;
                        tmpn = strsv[j][cnt];
                    }
                    else cnttmpc++;
                if(innercheck)
                {
                    if(checkall()) break;
                    cnt++;
                }
                else
                {
                    if(cnttmpc < cnttmpn ) tmpc=tmpn;
                    for(int j=0;j<n;j++)
                    {
                        if(strsv[j][cnt]!=tmpc)
                        {
                            int len = strlen(strsv[j]);
                            if(strsv[j][cnt-1]==tmpc)
                            {
                                for(int k = len ;k>=cnt;k--)
                                    strsv[j][k]=strsv[j][k-1];
                                strsv[j][len+1]='\0';
                                ans++;
                            }
                            else
                            {
                                for(int k=cnt;k<len;k++)
                                    strsv[j][k]=strsv[j][k+1];
                                ans++;
                            }
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
