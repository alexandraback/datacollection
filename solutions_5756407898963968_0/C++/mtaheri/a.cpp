#include<iostream>
using namespace std;

void main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		int dr;
		cin>>dr;
		int arr[4];
		for(int r=0;r<4;r++)
		{
			for(int c=0;c<4;c++)
			{
				int d;
				cin>>d;
				if(r+1==dr)
					arr[c]=d;
			}
		}
		cin>>dr;
		int arr2[4];
		for(int r=0;r<4;r++)
		{
			for(int c=0;c<4;c++)
			{
				int d;
				cin>>d;
				if(r+1==dr)
					arr2[c]=d;
			}
		}

		int n=0;
		int num=-1;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(arr[i]==arr2[j])
				{
					n++;
					num=arr[i];
					break;
				}
			}
			if(n>1)break;
		}
		if(n==0)
			cout<<"Volunteer cheated!"<<endl;
		if(n==1)
			cout<<num<<endl;
		if(n>1)
			cout<<"Bad magician!"<<endl;

	}
}