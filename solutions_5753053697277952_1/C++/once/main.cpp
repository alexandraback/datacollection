#include <bits/stdc++.h>
using namespace std;
int a[30],n;
int main()
{
    freopen("A1.in","r",stdin);
    freopen("A1.out","w",stdout);
    int cas;
    cin>>cas;
    for (int run=1;run<=cas;++run)
    {
        cin>>n;
        for (int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        cout<<"Case #"<<run<<":";
        while (1)
        {
            int x=0;
            for (int i=1;i<n;++i)
                if (a[i]>a[x])
                    x=i;
            if (a[x]==0) break;
            int cnt=1,y=x;
            for (int i=0;i<n;++i)
                if (a[i]==a[x]&&i!=x)
                {
                    ++cnt;
                    y=i;
                }
            putwchar(' ');
            if (cnt==2)
            {
                putwchar('A'+x);
                putwchar('A'+y);
                --a[x],--a[y];
            }
            else
            {
                putwchar('A'+x);
                --a[x];
            }

        }
        putwchar('\n');
    }
    return 0;
}
