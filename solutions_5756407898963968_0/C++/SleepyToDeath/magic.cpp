#include<iostream>
#include<cstring>
using namespace std;

void work( int n )
{
	bool v[17];
	int m[5][5];
	int r1,r2;
	memset( v , 0 , sizeof( v ) );
	cin>>r1;
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			cin>>m[i][j];

	for (int i=1;i<=4;i++)
		v[ m[r1][i] ] = true;

	cin>>r2;
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			cin>>m[i][j];

	int ans = 0;

	for (int i=1;i<=4;i++)
		if ( v[ m[r2][i] ] )
		{
			if ( ans )
			{
				cout<<"Case #"<<n<<": "
				<<"Bad magician!"
				<<endl;
				return;
			}
			else
			{
				ans = m[r2][i];
			}
		}
	if ( ans )
		cout<<"Case #"<<n<<": "
		<<ans<<endl;
	else
		cout<<"Case #"<<n<<": "
		<<"Volunteer cheated!"
		<<endl;
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		work( i );
}

