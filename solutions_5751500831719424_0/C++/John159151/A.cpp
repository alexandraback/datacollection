#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char ch1[1000],ch2[1000];
int cal()
{
    int num=0;
    //if(strlen(ch1)>=strlen(ch2))
    {
        int j=0;
        int i=0;
        while(i<strlen(ch2)&&j<strlen(ch1))
        {
            if(ch2[i]==ch1[j])
            {
                j++;
                i++;
            }
            else
            {
                if(i>0&&ch2[i-1]==ch1[j])
                {
                    num++;
                    j++;
                }
                else if(j>0&&ch1[j-1]==ch2[i])
                {
                    num++;
                    i++;
                }
                else
                {
                    return -1;
                }
            }
        }
        while(j<strlen(ch1))
        {
            if(ch1[j]==ch2[i-1])
            {
                num++;
                j++;
            }
            else return -1;
        }
        while(i<strlen(ch2))
        {
            if(ch2[i]==ch1[j-1])
            {
                num++;
                i++;
            }
            else return -1;
        }
    }/*
    else
    {
        int j=0;
        int i=0;
        while(i<strlen(ch1))
        {
            if(ch1[i]==ch2[j])
            {
                j++;
                i++;
            }
            else
            {
                if(i>0&&ch1[i-1]==ch2[j])
                {
                    num++;
                    j++;
                }
                else
                {
                    return -1;
                }
            }
        }
        while(j<strlen(ch2))
        {
            if(ch2[j]==ch1[i-1])
            {
                num++;
                j++;
            }
            else return -1;
        }
    }*/
    return num;
}
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("A-small-attempt1.in","r",stdin);    freopen("A-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&n);
        scanf("%s%s",ch1,ch2);
        int get=cal();
        if(get==-1) printf("Case #%d: Fegla Won\n",tcase);
        else
        printf("Case #%d: %d\n",tcase,get);
    }
    fclose(stdin);    fclose(stdout);
}
