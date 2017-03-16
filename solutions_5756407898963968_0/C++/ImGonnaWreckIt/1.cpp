#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	int i,j,k;
	int T,a[4][4];
	int N1,N2,count,ans;
	int flag[17];
	ifstream ip("A-small-attempt1.in");;
	ofstream op("output.txt");;
	ip>>T;
	for(k=1;k<=T;k++)
	{
		ip>>N1;
		count=0;
		ans=0;
		for(i=0;i<17;i++)
			flag[i]=0;		
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				ip>>a[i][j];
			}
		}
		
		
		for(i=0;i<4;i++)
		{
			flag[a[N1-1][i]]=1;
		}
		ip>>N2;
		
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				ip>>a[i][j];
			}
		}
		
		for(i=0;i<4;i++)
		{
			if(flag[a[N2-1][i]]==1)
			{
				count++;
				ans=a[N2-1][i];
			}
		}
		//cout<<count<<"\t"<<ans<<"\n";
		op<<"Case #"<<k<<": ";
		if(count==0)
			op<<"Volunteer cheated!\n";
		if(count==1)
			op<<ans<<"\n";
		if(count>1)
			op<<"Bad magician!\n";
	}
	return 0;
}

