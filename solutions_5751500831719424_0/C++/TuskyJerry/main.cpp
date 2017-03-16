#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>

using namespace std;

char s[101];
int a[101];
int b[101];
int p[101];
char ch[101][101];
char num[101][101];

int compare(const void *a,const void *b)
{
     return *(int*)b-*(int*)a;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios :: sync_with_stdio(false);
    int t,n;
    scanf("%d",&t);
    for (int k=1;k<=t;k++)
    {
        scanf("%d",&n);

        for (int i=1;i<=n;i++)
        {
        scanf("%s",s);
        a[i]=strlen(s);
      //  cout<<a[i];
        b[i]=0;

            int nn=1;
            char c=s[0];
            ch[i][nn]=c;
            num[i][nn]=1;
            for (int j=1;j<=a[i]-1;j++)
            {
                if (s[j]==c)
                {
                    num[i][nn]++;
                }
                else
                {
                    nn++;
                    ch[i][nn]=s[j];
                    num[i][nn]=1;
                    c=s[j];
                }
            }
            b[i]=nn;
        }
        int flag=1;
        for (int i=1;i<=n-1;i++)
        if (b[i]!=b[i+1])
        {
            flag=0;
            break;
        }
        cout<<"Case #"<<k<<": ";
        if (flag==0)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }
        int ss=0;
        for (int j=1;j<=b[1];j++)
        {
            for (int i=1;i<=n-1;i++)
            {
                if (ch[i][j]!=ch[i+1][j])
                {
                    flag=0;
                    break;
                }
            }
            if (flag==0) break;
            for (int i=1;i<=n;i++) p[i]=num[i][j];
            //for (int i=1;i<=n;i++) cout<<p[i]<<endl;
        //    qsort((void *)p,n,sizeof(int),compare);
            for (int i=1;i<=n-1;i++)
            for (int j=i+1;j<=n;j++)
            if (p[i]>p[j])
            {
                int x=p[i];
                p[i]=p[j];
                p[j]=x;
            }
          //  for (int i=1;i<=n;i++) cout<<p[i]<<endl;
            for (int i=1;i<=n;i++) ss=ss+abs(p[i]-p[(n+1)/2]);
        }
        if (flag==0)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }
        cout<<ss<<endl;
    }

    return 0;
}
