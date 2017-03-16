#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,i,y,a[1002],p;
    double x,g;
    long int k;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>t;
    for(y=1;y<=t;y++)
    {
        out<<"Case #"<<y<<": ";
        in>>n;
        for(i=0;i<n;i++)
            in>>a[i];
        k=0;
        x=0;
        for(i=0;i<n-1;i++)
        {
            p=a[i]-a[i+1];
            if(p>0)
                k+=a[i]-a[i+1];
            if(p>x)
                x=p;
        }
        out<<k<<" ";
        g=0;
        for(i=0;i<n-1;i++)
        {
            if(x>a[i])
                g+=a[i];
            else
                g+=x;
        }
        k=g;
        out<<k<<endl;
    }
    return 0;
}
