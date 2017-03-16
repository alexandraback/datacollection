#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct A
{
    char let;
    int cnt;
}AA;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    char s1[1000];
    vector<AA> v[200];
    for(int caseno=1; caseno<=t; caseno++)
    {
        int n,i,j,k;
        scanf("%d%*c", &n);
        for(i=0; i<n; i++)
            v[i].clear();
        for(j=0; j<n; j++)
        {
            gets(s1);
            AA tmp;
            tmp.let = s1[0], tmp.cnt = 1;
            v[j].push_back(tmp);
            for(i=1; i<strlen(s1); i++)
            {
                if(v[j][v[j].size()-1].let == s1[i]) v[j][v[j].size()-1].cnt++;
                else{
                    tmp.let = s1[i], tmp.cnt = 1;
                    v[j].push_back(tmp);
                }
            }
            /*for(i=0; i<v[j].size(); i++)
                printf("%c:%d ",v[j][i].let, v[j][i].cnt);
            puts("");*/

        }
        bool flag = 1;
        int ans = 0;

        for(i=1; i<n; i++){//檢查區塊數
            if(v[i].size() != v[i-1].size()){
                flag = 0; break;
            }
        }
        for(j=0; j<v[0].size(); j++)
        {//檢查種類是否相同
            for(i=1; i<n; i++)
            if(v[i][j].let != v[i-1][j].let){
                flag = 0;  break;
            }
        }
        for(j=0; j<v[0].size(); j++)
        {//算步數
            vector<int> cc;
            for(i=0; i<n; i++)
            {
                cc.push_back(v[i][j].cnt);
            }
            sort(cc.begin(), cc.end());
            int mid = cc[cc.size()/2];
            for(i=0; i<n; i++)
                ans += abs(v[i][j].cnt - mid);
        }

        printf("Case #%d: ",caseno);
        if(flag)
            printf("%d\n",ans);
        else
            printf("Fegla Won\n");




        /*tmp.let = s2[0], tmp.cnt = 1;
        v2.push_back(tmp);
        for(i=1; i<strlen(s2); i++)
        {
            if(v2[v2.size()-1].let == s2[i]) v2[v2.size()-1].cnt++;
            else{
                tmp.let = s2[i], tmp.cnt = 1;
                v2.push_back(tmp);
            }
        }

        bool flag = 1;
        int ans = 0;
        if(v1.size() != v2.size()) flag = 0;
        else{
            for(i=0; i<v1.size(); i++)
            {
                if(v1[i].let != v2[i].let){
                    flag = 0; break;
                }

                ans +=  abs(v1[i].cnt - v2[i].cnt);
            }

        }


        printf("Case #%d: ",caseno);
        if(flag)
            printf("%d\n",ans);
        else
            printf("Fegla Won\n");*/


        /*for(i=0; i<v1.size(); i++)
        {
            printf("%c:%d ",v1[i].let, v1[i].cnt);
        }puts("");
        for(i=0; i<v2.size(); i++)
        {
            printf("%c:%d ",v2[i].let, v2[i].cnt);
        }*/





    }


    return 0;
}



