#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cs = 1;
	while(t--)
	{
		int arr[17];
		for(int i=0; i<17; i++)
			arr[i]=0;
		int c1;
		cin>>c1;
		c1--;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				int temp=0;
				cin>>temp;
				if(i==c1)
				{
					arr[temp]++;
				}
			}
		}
		
		int c2;
		cin>>c2;
		c2--;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				int temp=0;
				cin>>temp;
				if(i==c2)
				{
					arr[temp]++;
				}
			}
		}
		
		int count=0;
		int num=0;
		for(int i=0; i<17; i++)
		{
			if(arr[i]==2)
			{
				num=i;
				count++;
			}
		}
		
		cout<<"Case #"<<cs<<": ";
		if(count==0)
		{
			cout<<"Volunteer cheated!"<<endl;
		}
		else if(count==1)
		{
			cout<<num<<endl;
		}
		else
		{
			cout<<"Bad magician!"<<endl;
		}
		
		cs++;
	}
}
