#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int a1,a2;
		cin>>a1;
		int c[16]={};
		for(int i=0;i<4;i++)
			for(int k=0;k<4;k++)
			{
				int h;
				cin>>h;
				if(i==a1-1)
					c[h-1]++;
			}
		cin>>a2;
		for(int i=0;i<4;i++)
			for(int k=0;k<4;k++)
			{
				int h;
				cin>>h;
				if(i==a2-1)
					c[h-1]++;
			}	
		int f=0;
		int ans=0;
		for(int i=0;i<16;i++)
		{
			if(c[i]==2)	
			{
				f++;
				ans=i+1;
			}
		}
		if(f==0)
		{
			cout<<"Case #"<<j<<": "<<"Volunteer cheated!"<<endl;
		}
		else if(f>1)
		{
			cout<<"Case #"<<j<<": "<<"Bad magician!"<<endl;
		}
		else
		{
			cout<<"Case #"<<j<<": "<<ans<<endl;
		}
	}
	return 0;
}
