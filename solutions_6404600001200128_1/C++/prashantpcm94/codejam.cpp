#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int l=1;
	while(t--)
	{
		int m;
		cin>>m;
		long long y=0,z=0,a[m],diff=0,d;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
           if(i>0)
           {
            d=a[i-1]-a[i];
            diff=max(diff,d);
           }
		}
        long long int rate=diff;
		for(int i=1;i<m;i++)
		{
			if(a[i]<a[i-1])
			{
				y+=(a[i-1]-a[i]);
			}
		}
		for(int i=0;i<m-1;i++)
         {
           if(rate>a[i])
            z+=a[i];
           else z+=rate;
         }
		cout<<"Case #"<<l<<": ";l++;
		cout<<y<<" "<<z<<endl;
	}
}
