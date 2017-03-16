#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    int t,ans,x,a[20],card,Case = 0;
    cin>>t;
    while (t--)
    {
        memset(a,0,sizeof(a));
        cin>>ans;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
            {
                cin>>x;
                if (i == ans) a[x] = 2;
            }
        cin>>ans;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
            {
                cin>>x;
                if (i == ans) a[x]--;
            }
        int s = 0;
        for (int i = 1; i <= 16; i++)
            if (a[i]==1)
            {
                card=i;
                s++;
            }
        if (s==1) cout<<"Case #"<<++Case<<": "<<card<<endl;
        else if (s==0) cout<<"Case #"<<++Case<<": Volunteer cheated!"<<endl;
        else cout<<"Case #"<<++Case<<": Bad magician!"<<endl;
    }
    return 0;
}