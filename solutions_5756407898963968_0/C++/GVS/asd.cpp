#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int i , j , n, m , k , t ;
int u[100];
int main()
{
	freopen("c:/input.txt" , "r" ,stdin);
	freopen("c:/output.txt" , "w" , stdout);

	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n;

		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
			{
				cin>>k;
				if (i == n)
					u[k]++;
			}

		cin>>m;

		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
			{
				cin>>k;
				if (i == m)
					u[k]++;
			}

		int ucnt = 0;
		int ans = 0;
		for (i = 1; i <= 16; i++)
		{
			if (u[i] == 2)
			{
				ucnt++;
				ans = i;
			}
			u[i] = 0;
		}

		cout<<"Case #"<<tt<<": ";
		
		if (ucnt == 0)
		{
			cout<<"Volunteer cheated!\n";
		} else
		if (ucnt == 1)
		{
			cout<<ans<<endl;
		}  else
			cout<<"Bad magician!\n";

	}

	return 0;
}
