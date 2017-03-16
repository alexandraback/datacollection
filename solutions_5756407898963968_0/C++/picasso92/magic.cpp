#include<iostream>
using namespace std;

int main()
{
	int t;
	string str = "Bad magician!";
	string str2 ="Volunteer cheated!";
	cin>>t;
	int x = 1;
	while(t--)
	{
		int ar[5][5]={0};
		int b[5][5]={0};
		int ans1,ans2;
		cin>>ans1;

		for(int i =1;i<5;i++)
		{
			for(int j = 1;j<5;j++)
				cin>>ar[i][j];
		}
		
		cin>>ans2;

		for(int i =1;i<5;i++)
		{
			for(int j = 1;j<5;j++)
				cin>>b[i][j];
		}
		
		int count =0;
		int index;
		string st="";
	for(int i =1;i<5;i++)
	{
		for(int j =1;j<5;j++)
		{
			if(ar[ans1][i]==b[ans2][j])
			{
				count++;
				index = ar[ans1][i];
			}
		}
	}
		
	if(count > 1)
		st = str;

	else if(count == 0)
		st = str2;

	if(count ==1)
		cout<<"Case #"<<x<<": "<<index<<'\n';
	else
		cout<<"Case #"<<x<<": "<<st<<'\n';
		
		x++;

	}
}
