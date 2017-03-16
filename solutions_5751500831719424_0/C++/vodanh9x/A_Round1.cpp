#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define length(x) (int)x.size()
const double pi=acos(-1);

int N;
int sc[200], con[200][200];
char kitu[200][200];

void khoitao()
{
    scanf("%d\n", &N);
    for(int i=1; i<=N; i++)
    {
        string st;
        getline(cin,st);
        sc[i] = 0;
        int dem = 1; char ch = st[0];
        for(int j=1; j<length(st); j++)
            if (ch==st[j]) dem++;
            else
            {
                sc[i]++; con[i][sc[i]] = dem;  dem = 1;
                kitu[i][sc[i]] = ch;  ch = st[j];
            }
        sc[i]++; con[i][sc[i]] = dem; kitu[i][sc[i]] = ch;
    }
}
void xuli()
{
    khoitao();
    for(int i=1; i<=N; i++)
        if (sc[i]!=sc[1])
    {
        cout<<"Fegla Won"<<endl; return;
    }
    for(int i=1; i<=sc[1]; i++)
        for(int j=1; j<=N; j++)
            if (kitu[j][i]!=kitu[1][i])
        {
            cout<<"Fegla Won"<<endl; return;
        }
    int res = 0;
    for(int i=1; i<=sc[1]; i++)
        {
            int minn = 1000000, maxn = 0;
            for(int j=1; j<=N; j++)
            {
                minn = min(minn, con[j][i]);
                maxn = max(maxn, con[j][i]);
            }
            int giatri = 1000000000;
            for(int k=minn; k<=maxn; k++)
            {
                int sum = 0;
                for(int h=1; h<=N; h++)
                    sum = sum + abs(con[h][i]-k);
                giatri = min(giatri, sum);
            }
            res = res + giatri;
        }
    cout<<res<<endl;
}

int main()
{
     freopen("input.inp","r",stdin);
     freopen("output.out","w",stdout);
     int test;
     scanf("%d\n", &test);
     for(int t=1; t<=test; t++)
     {
         cout<<"Case #"<<t<<": ";
         xuli();
     }
     return 0;
}
