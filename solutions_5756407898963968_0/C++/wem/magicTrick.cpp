//Andrzej Golonka
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	for(int ti = 0; ti < t; ti++)
	{
		int data[16+1];
		for(int i = 0; i < 17; i++)
			data[i] = 0;
		int r = -1;
		
		for(int k = 0; k < 2; k++)
		{
			cin>>r;
		
			for(int i = 1; i <=4; i++)
			{
				for(int j = 0; j < 4; j++)
				{
					int x;
					cin>>x;
				
					if(i == r)
					{
						data[x]++;
					}
				}
			}
		}
		int status = -1; // cheated
		int c = -1;
		for(int i = 1; i <= 16; i++)
		{
			//cout<<i<<": "<<data[i]<<endl;
			if(data[i] == 2)
			{
				if(status == -1)
				{
					c = i;
					status = 0; // ok
				} else
				{
					status = 1; // bad magican
					break;
				}
			}
		}
		
		cout<<"Case #"<<ti+1<<": ";
		
		switch(status)
		{
			case 0:
				cout<<c<<endl;
			break;
			case -1:
				cout<<"Volunteer cheated!"<<endl;
			break;
			case 1:
				cout<<"Bad magician!"<<endl;
			break;
		}
	}

	return 0;
}
