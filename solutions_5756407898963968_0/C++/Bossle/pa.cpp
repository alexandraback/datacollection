#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int tc=1;tc<=t;++tc)
	{
		cout << "Case #" << tc << ": ";
		int n;
		int mat[4][4];
		cin >> n;
		for(int i=0;i<4;++i)for(int j=0;j<4;++j)
			cin >> mat[i][j];
		int possibs[4];
		for(int i=0;i<4;++i)
			possibs[i]=mat[n-1][i];
		cin >> n;
		for(int i=0;i<4;++i)for(int j=0;j<4;++j)
			cin >> mat[i][j];
		int resp=-1;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
			{
				if(possibs[i]==mat[n-1][j])
				{
					if(resp==-1)
						resp=possibs[i];
					else
						resp=-2;
				}
			}
		if(resp==-1)
			cout << "Volunteer cheated!" << endl;
		else if(resp==-2)
			cout << "Bad magician!" << endl;
		else
			cout << resp << endl;
	}
}
