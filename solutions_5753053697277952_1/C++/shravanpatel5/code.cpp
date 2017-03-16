#include <iostream>
using namespace std;
int main() 
{
	int t,i,arr[30],i1,max,max1,j,n,x;
	cin>>t;
	for(i1=0;i1<t;i1++)
	{
		cin>>n;
		max=-1;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			arr[i]=x;
			if(max<x)
				max=x;
		}
		cout<<"Case #"<<i1+1<<": ";
		for(j=max;j>0;j--)
		{
			max1=0;
			for(i=1;i<=n;i++)
			{
				if(arr[i]==j)
					max1++;
			}
		//	if(max1>2)
		//	{
		//cout<<max1<<" ";
				for(i=1;i<=n&&max1>2;i++)
				{
					if(arr[i]==j)
					{
						arr[i]--;
						max1--;
						cout<<char(i+64)<<" ";
					}
				}
		//	}
			if(max1==2)
			{
		///		cout<<"hii";
				for(i=1;i<=n;i++)
				{
					if(arr[i]==j)
					{
						arr[i]--;
						max1--;
						cout<<char(i+64);
					}
				}
				cout<<" ";
			}
			if(max1==1)
			{
				for(i=1;i<=n;i++)
				{
					if(arr[i]==j)
					{
						arr[i]--;
						max1--;
						cout<<char(i+64)<<" ";
					}
				}
			}
			
		}
		cout<<endl;
	}
	return 0;
}
