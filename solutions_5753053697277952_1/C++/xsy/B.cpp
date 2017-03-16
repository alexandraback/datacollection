#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF=1000000007;
const double eps=0.00000001;

int a[27],s;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,t;
    cin>>t;
    for(int cas=1;cas<=t;++cas)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        int k=0;
        while(s>0)
        {
            int max=-1,chose;
            for(int i=1;i<=n;++i)
                if(a[i]>0 && a[i]>max)
                {
                    max=a[i];
                    chose=i;
                }
            ++k;
            --a[chose];
            --s;
            cout<<char('A'-1+chose);
            if(s==0)
                break;
            max=-1;
            for(int i=1;i<=n;++i)
                if(a[i]>0 && a[i]>max)
                    max=a[i];
            if(max*2<=s)
            {
                cout<<" ";
                k=0;
            }
            if(k>=2)
            {
                cout<<"-1";
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
