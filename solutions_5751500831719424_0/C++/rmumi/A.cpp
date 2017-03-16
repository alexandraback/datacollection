#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
char s[200][200];
char p[200][200];
int t,n;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d ",&n);
        for(int i=0;i<n;i++)
        {
            scanf(" %s",s[i]);
            int pis=1;
            p[i][0]=s[i][0];
            for(int j=1;s[i][j];j++)
            {
                if(s[i][j]==s[i][j-1])continue;
                else {p[i][pis]=s[i][j];pis++;}
            }
            p[i][pis]=0;
          //  printf("AA");puts(p[i]);
        }
        bool no=0;
        for(int i=1;i<n;i++)
        {
            if(strcmp(p[0],p[i])){no=1;break;}
        }
        if(!no)
        {
            int I=0,J=0,minio=0;
            if(n==2)
            {

                for(int i=0;p[0][i];i++)
                {
                    int c=0,d=0;
                    while(s[0][I] && s[0][I]==p[0][i]){c++;I++;}
                    while(s[1][J] && s[1][J]==p[0][i]){d++;J++;}
                    minio+=abs(c-d);
                }
            }
            printf("Case #%d: %d\n",CASE,minio);
        }
        else printf("Case #%d: Fegla Won\n",CASE);
    }
}
