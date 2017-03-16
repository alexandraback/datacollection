#include <iostream>
using namespace std;

int main() 
{
	int t,arr[17],r,x,c,ans,cas=0;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		for(int i=0;i<17;i++)
			arr[i]=0;
		cin>>r;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				cin>>x;
				if(i==r)
					arr[x]++;
			}
		}
		cin>>r;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				cin>>x;
				if(i==r)
					arr[x]++;
			}
		}
		c=0;
		for(int i=1;i<=16;i++)
		{
			if(arr[i]==2)
			{
				c++;
				ans=i;
			}
		}
		if(c==0)
			cout<<"Volunteer cheated!"<<endl;
		else if(c==1)
			cout<<ans<<endl;
		else
			cout<<"Bad magician!"<<endl;
	}
	return 0;
}