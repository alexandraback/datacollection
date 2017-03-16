#include<iostream>
using namespace std;
int main()
{
	int T,i,j,R1,R2,ans,ansmark,a1[5][5],a2[5][5];
	freopen("QR_A.in","r",stdin);
	freopen("QR_A.out","w",stdout);
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cin>>R1;
		R1--;
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				cin>>a1[i][j];
		cin>>R2;
		R2--;
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				cin>>a2[i][j];
		ans=0;
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				if (a1[R1][i]==a2[R2][j])
				{
					ans++;
					ansmark=i;
				}
		cout<<"Case #"<<k+1<<": ";
		if (ans<1) cout<<"Volunteer cheated!";
		if (ans==1) cout<<a1[R1][ansmark];
		if (ans>1) cout<<"Bad magician!";
		cout<<endl;
	}
}