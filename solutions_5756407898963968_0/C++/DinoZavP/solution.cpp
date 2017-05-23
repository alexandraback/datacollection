#include<iostream>
using namespace std;

void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, ans1, ans2, z, l;
	int A[4][4], B[4][4];
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		z=0;
		cin>>ans1;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>A[j][k];
		cin>>ans2;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>B[j][k];
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				if (A[ans1-1][j]==B[ans2-1][k]) {z++;l=A[ans1-1][j];}
		if (z==1) cout<<"Case #"<<i<<": "<<l<<endl;
		if (z>1) cout<<"Case #"<<i<<": Bad magician!"<<endl;
		if (z==0) cout<<"Case #"<<i<<": Volunteer cheated!"<<endl;
	}
}