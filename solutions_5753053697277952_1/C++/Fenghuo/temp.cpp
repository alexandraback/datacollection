#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int n;
int p[27];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,TT;
    long long i,j,k;

    cin>>T;
    for(TT=1;TT<=T;TT++)
    {
        cin>>n;
        for (i=0;i<n;i++)
            cin>>p[i];

        cout<<"Case #"<<TT<<":";
        while(1)
        {
            int a1=0;
            int a2=0;
            int ma=0;
            int cnt=0;
            for (i=0;i<n;i++)
            {
                if (p[i]>ma) {ma=p[i];a1=i;}
            }

            for (i=0;i<n;i++)
            {
                if (p[i]==ma)
                {
                    cnt++;
                    if (i!=a1) a2=i;
                }
            }

            if (ma==0) break;

            if (cnt==2)
            {
                p[a1]--;
                p[a2]--;
                cout<<" "<<(char)(a1+'A')<<(char)(a2+'A');
            }
            else
            {
                p[a1]--;
                cout<<" "<<(char)(a1+'A');
            }

        }
        cout<<endl;
    }


    return 0;
}
