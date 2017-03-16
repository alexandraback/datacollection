#include <bits/stdc++.h>

using namespace std;
long int gcd(long int a, long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
vector<long int> x,y;
int main()
{
    int t,i,n,b;
    long int m,p;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>t;
    for(int z=1;z<=t;z++)
    {
        out<<"Case #"<<z<<": ";
        in>>b>>n;
        x.resize(b);
        for(i=0;i<b;i++)
            in>>x[i];
        y.resize(b);
        y=x;
        if(n<=b)
            out<<n<<endl;
        else
        {
            n=n-b;
            m=x[0];
            for(i=0;i<b;i++)
            {
                p=gcd(m,x[i]);
                m=(m*x[i])/p;
            }
            p=0;
            for(i=0;i<b;i++)
                p=p+(m/x[i]);
            n=n%p;
            if(n==0)
                n=p;
            while(n!=0)
            {m=100001;
            for(i=0;i<b;i++)
                if(x[i]<m)
                    m=x[i];
            for(i=0;i<b;i++)
            {
                x[i]-=m;
                if(x[i]==0)
                {
                    x[i]=y[i];
                    n--;
                    if(n==0)
                        break;
                }
            }
            }
            out<<i+1<<endl;
        }
    }
    return 0;
}
