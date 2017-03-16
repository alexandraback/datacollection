#include <iostream>
#include <algorithm>
using namespace std;
struct arr{
	int x,i;
};
bool comp(arr &a,arr &b)
{
	return a.x>b.x;
}
int main()
{
	int t;cin>>t;
	int iter=1;
	while(t--)
	{
		int n;cin>>n;
		arr d[27];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>d[i].x;
			d[i].i=i;
			sum+=d[i].x;
		}
		cout<<"Case #"<<iter<<": ";
		iter++;
		sort(d,d+n,comp);
		while(d[0].x!=0)
		{
			
			sum-=1;
			d[0].x-=1;
			if(d[1].x>sum/2)
			{
				d[1].x-=1;
				sum-=1;
				cout<<char(d[0].i+'A')<<""<<char(d[1].i+'A')<<" ";
			}
			else
			{
				cout<<char(d[0].i+'A')<<" ";
			}
			sort(d,d+n,comp);	
		}
		cout<<endl;
	}
}