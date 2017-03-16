#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

string str[105], S;
int u[500];
vector<int>M[500];
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int CaseNo=1 , A, B , K, cnt, tCase;
    scanf("%d", &tCase);
    while(tCase--)
    {
        scanf("%d", &A);
            S="";

           cnt = 0;
           memset(u,0,sizeof(u));
            for(int i = 0; i<A; i++){
                cin>>str[i];
                M[i].clear();
            }

            S.push_back(str[0][0]);

           for(int j =1; j<str[0].size(); j++)
           {
               if(str[0][j]!=str[0][j-1]) S.push_back(str[0][j]);
//               if(u[str[0][j]] == 0){
//                    u[str[0][j]] = 1;
//                    S.push_back(str[0][j]);
//               }
           }
         //  cout<<S<<endl;
           string tem="";
           for(int i = 1; i<A; i++)
            {
                memset(u,0,sizeof(u));
                tem="";
                tem+=str[i][0];
                for(int j=1; j<str[i].size(); j++)
                {
                    if(str[i][j]!=str[i][j-1]) tem+=str[i][j];
//                    if(u[str[i][j]] == 0)
//                    {
//                        u[str[i][j]] = 1;
//                        tem.push_back(str[i][j]);
//                    }
                }
                if(tem != S){
                    cnt = 1;
                    break;
                }
           }
        if(cnt == 1)
        printf("Case #%d: Fegla Won\n", CaseNo++);
        else
        {
            int k = 0;
            for(int i = 0; i<A; i++)
            {
                cnt=1;
                for(int j = 1; j<str[i].size(); j++)
                {
                    if(str[i][j]==str[i][j-1]) cnt++;
                    else
                    {
                        M[i].push_back(cnt);
                        cnt = 1;
                    }
                }
                M[i].push_back(cnt);

            }
      /*  for(int i = 0; i<A; i++){
            for(int j = 0; j<M[i].size(); j++)
            cout<<M[i][j]<<" ";
            cout<<endl;
        }*/
         // cout<<"YES"<<endl;
            int cost = 0;
            for(int i = 0; i<M[0].size(); i++)
            {
                int mn = 99999999;
                for(int k = 1; k<=100; k++)
                {
                    int sum = 0;
                    for(int j = 0; j<A; j++)
                    {
                        sum+=abs(k-M[j][i]);
                    }
                    mn=min(sum,mn);
                }
                cost+=mn;
            }
             printf("Case #%d: %d\n", CaseNo++, cost);

        }
    }
    return 0;
}

