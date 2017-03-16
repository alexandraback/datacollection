#include<iostream>
using namespace std;
int main()
{
	int t,ans1,ans2,row1[4],row2[4],i,j,k,data,cn;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cn=0;
		cin>>ans1;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				cin>>data;
				if(j==ans1-1)
					row1[k]=data;
			}				
		}
		// for(j=0;j<4;j++)
// 			cout<<row1[j]<<" ";
// 		cout<<endl;
		cin>>ans2;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				cin>>data;
				if(j==ans2-1)
					row2[k]=data;
			}				
		}
		// for(j=0;j<4;j++)
// 			cout<<row2[j]<<" ";
// 		cout<<endl;
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
		{
			if(row1[j]==row2[k])
				{data=row1[j];cn++;}
		}
		if(cn==0)
			cout<<"Case #"<<i<<": Volunteer cheated!\n";
		else if(cn==1)
			cout<<"Case #"<<i<<": "<<data<<endl;
		else
			cout<<"Case #"<<i<<": Bad magician!"<<endl;
	}
}