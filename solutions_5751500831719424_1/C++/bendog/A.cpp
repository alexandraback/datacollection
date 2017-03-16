#include<iostream>
#include<cstdio>
#include<cstring>
#define SIZE 128
using namespace std;
char s[SIZE][SIZE];
int len[SIZE];
int f[SIZE];
int tt[SIZE];
bool isEnd(int n)
{
    for(int i=0;i<n;i++)
    {
        if(f[i] == len[i])return true;
    }
    return false;
}
bool NowIsChar(char ch,int n)
{
    for(int i=0;i<n;i++)
    if( ch != s[i][f[i] ])return false;
    return true;
}
int main()
{
   // freopen("A-large.in","r",stdin);
   // freopen("A-large.txt","w",stdout);
    int cas;cin>>cas;
    for(int q=1;q<=cas;q++)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            f[i] = 0;
            len[i] = strlen(s[i]);
        }
        int sol = 0;
        bool has = true;
        while(has && (!isEnd(n)))
        {
            char ch = s[0][f[0]];
            if(!NowIsChar(ch,n))has = false;
            else
            {
                int sum=0;
                for(int i=0;i<n;i++)
                {
                    int t = f[i];
                    while(t<len[i] && ch == s[i][t])t++;
                    sum+=(t-f[i]);
                    tt[i] = t;
                }
                int avg = ((double)sum)/n + 0.5;

                for(int i=0;i<n;i++)
                {
                    int v = tt[i] - f[i];
                    v = v- avg;
                    if(v<0)v=-v;
                sol+=v;
                }
                for(int i=0;i<n;i++)
                    f[i] = tt[i];
            }
        }
        for(int i=0;i<n;i++)
            if(f[i]<len[i])has = false;
        if(has)
        cout<<"Case #"<<q<<": "<<sol<<endl;
        else
        cout<<"Case #"<<q<<": Fegla Won"<<endl;

    }

    return 0;
}
