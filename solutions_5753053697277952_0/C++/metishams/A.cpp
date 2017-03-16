#include <iostream>


using namespace std;



int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		
		int n;
		cin >> n;

		int a[n];

		for(int j=0; j<n; j++)
			cin >> a[j];
	
		cout << "Case #" << i+1 << ": ";

		while(true)
		{
			int mx = 0;
			int mj = 0;
			int count = 0;
			for(int j = 0; j<n;j++)
			{
				if(a[j]>mx)
				{
					mx = a[j];
					mj = j;
				}

				if(a[j]>0)
					count++;
			}

			if(count<=2)
				break;
			cout << char(mj+'A') << " ";
			a[mj]--;
		}		

		while(true)
		{
			int count = 0;
			for(int j = 0; j<n;j++)
				if(a[j]>0)
				{
					cout << char(j+'A');
					a[j]--;
					count++;
				}
			if(count == 0)
				break;
			cout << " ";
		}
		
		cout << endl;
	}

	return 0;
}