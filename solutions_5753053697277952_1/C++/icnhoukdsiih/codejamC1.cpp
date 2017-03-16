#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int t,n,p[30],mi;
char ch='A';
FILE *f=freopen("input.in","rt",stdin);
FILE *f1=freopen("output.ou","wt",stdout);
int main()
{
    cin>>t;
    for (int c=1;c<=t;c++)
    {
        cin>>n;
        mi=1001;
        for (int i=0;i<n;i++)
        {
            cin>>p[i];
            if (p[i]<mi) mi=p[i];
        }
        cout<<"Case #"<<c<<": ";
        do
        {
            int pos=0;
            for (int i=1;i<n;i++)
                if (p[i]>p[pos]) pos=i;
            if (p[pos]==mi) break;
            cout<<(char)(ch+pos)<<' ';
            p[pos]--;
        } while (1);
        if (n%2!=0)
            for (int i=0;i<p[0];i++) cout<<ch<<' ';
        int i=n%2;
        while (i<n)
        {
            for (int j=0;j<p[i];j++) cout<<(char)(ch+i)<<(char)(ch+i+1)<<' ';
            i+=2;
        }
        cout<<endl;
    }
    return 0;
}
