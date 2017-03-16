#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible[20];

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
	{
		for(int i=1; i<=16; i++)
			possible[i] = true;

		for(int k=0; k<2; k++)
		{
			int R, x;
			cin>>R;
			for(int i=1; i<=4; i++)
			{
				for(int j=1; j<=4; j++)
				{
					cin>>x;
					if(i != R)possible[x] = false;
				}
			}
		}

		int res = -1;
		for(int i=1; i<=16; i++)
		{
			if(possible[i])
			{
				if(res == -1)
					res = i;
				else
					res = 100;
			}
		}

		cout<<"Case #"<<t<<": ";
		if(res==-1)
			cout<<"Volunteer cheated!";
		else if(res==100)
			cout<<"Bad magician!";
		else
			cout<<res;
		cout<<endl;
	}


    return 0;
}
