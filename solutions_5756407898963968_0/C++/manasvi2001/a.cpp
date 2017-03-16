#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		int n1,n2,i,j;
		int A[4][4],B[4][4];
		cin>>n1;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				cin>>A[i][j];
		}
		cin>>n2;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				cin>>B[i][j];
		}
		int c=0,n;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(A[n1-1][i]==B[n2-1][j])
				{
					c++;
					n=A[n1-1][i];
				}
			}
		}
		cout<<"Case #"<<u-t<<": ";
		if(c==0)
			cout<<"Volunteer cheated!\n";
		else if(c==1)
			cout<<n<<endl;
		else
			cout<<"Bad magician!\n";
	}
	return 0;
}