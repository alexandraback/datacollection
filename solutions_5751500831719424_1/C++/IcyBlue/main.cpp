#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int cc[100];
int pointer[100];
int abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    char dic[105][105];
     int times;
     scanf("%d",&times);
     for (int t= 0; t<times; t++)
     {
         int n;
         scanf("%d",&n);
         memset(dic,0,sizeof(dic));
         for (int i = 0; i< n; i++)
         {
             scanf("%s",dic[i]);
         }
         memset(pointer,0,sizeof(pointer));
         bool flag = false;
         int ans = 0;
         while (!flag)
         {
             char current = dic[0][pointer[0]];
             if (current == 0)
             {
                 for (int i = 0; i < n; i++)
                 {
                     if (dic[i][pointer[i]] != current){
                        flag = true;
                        break;
                     }
                 }
                 break;
             }
             memset(cc,0,sizeof(cc));
             for (int i = 0; i < n; i++)
             {
                 if (dic[i][pointer[i]] != current){
                    flag = true;
                    break;
                 }
                 while (dic[i][pointer[i]] == dic[i][pointer[i]+1]){
                        pointer[i] ++;
                        cc[i]++;
                 }
                 pointer[i]++;
             }
             if (flag) break;
             sort(cc,cc+n);
             for (int i = 0; i < n; i++)
                ans = ans + abs(cc[n/2]-cc[i]);
         }
         if (flag) printf("Case #%d: Fegla Won\n",t+1);
         else printf("Case #%d: %d\n",t+1,ans);
     }
}
