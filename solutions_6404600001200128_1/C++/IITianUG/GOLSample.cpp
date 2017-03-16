#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     ifstream IF;
     ofstream OF;
     int i,trm,t,sum1,sum2,n,a[1010],maxx;
     IF.open("input.txt");
     OF.open("output.txt");
IF>>t;
for(trm=1;trm<=t;trm++){
IF>>n;
sum1=0;
sum2=0;
for(i=0;i<n;i++)
    IF>>a[i];

    for(i=0;i<n-1;i++)
    {
        if(a[i]-a[i+1]>0)
            sum1+=a[i]-a[i+1];
    }
    maxx = a[0]-a[1];
    for(i=0;i<n-1;i++)
    {
        if(a[i]-a[i+1]>maxx)
            maxx = a[i]-a[i+1];
    }
    for(i=0;i<n-1;i++)
    {
        if(a[i]>=maxx)
            sum2+=maxx;
            else sum2+=a[i];
            }

    OF<<"Case #"<<trm<<": "<<sum1<<" "<<sum2<<endl;

}
IF.close();
OF.close();
return 0;
 }
