#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct A
{
    char let;
    int cnt;
}AA;
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    char s1[1000], s2[1000];
    vector<AA> v1, v2;
    for(int caseno=1; caseno<=t; caseno++)
    {
        v1.clear(), v2.clear();
        int i,j,k;
        scanf("%*d%*c");

        gets(s1);
        gets(s2);

        AA tmp;
        tmp.let = s1[0], tmp.cnt = 1;
        v1.push_back(tmp);
        for(i=1; i<strlen(s1); i++)
        {
            if(v1[v1.size()-1].let == s1[i]) v1[v1.size()-1].cnt++;
            else{
                tmp.let = s1[i], tmp.cnt = 1;
                v1.push_back(tmp);
            }
        }
        tmp.let = s2[0], tmp.cnt = 1;
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
            printf("Fegla Won\n");


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



