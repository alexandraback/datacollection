#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdio>

using namespace std;


int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	cin >> T;

	for (int i=0;i<T;i++)
	{
		int n,iter;
		cin >>n;
		string arr[n],brr[n];
		for (int j=0;j<n;j++)
			cin >> arr[j];

		for (int j=0;j<n;j++)
		{
			brr[j]+=arr[j][0];
			iter=0;

			for (int h=1;h<arr[j].length();h++)
			{
				if (arr[j][h]!=brr[j][iter])
				{
					iter++;
					brr[j]+=arr[j][h];
				}
			}
		}


		int num[n][brr[0].length()];
		memset(num,0,sizeof(int)*n*brr[0].length());
		int flag=1;
		for (int j=0;j<n-1;j++)
			if (brr[j]!=brr[j+1])
				flag=0;

		if (flag==0)
		{
			cout<<"Case #"<<i+1<<": "<<"Fegla Won"<<'\n';
		}
		
		else
		{
			for (int j=0;j<n;j++)
			{
				int k=0;
				for (int h=0;h<brr[0].length();h++)
				{
					while (brr[j][h]==arr[j][k])
					{
						k++;
						num[j][h]++;
					}
					
				}
			}

		
			int ans=0;
			for (int j=0;j<brr[0].length();j++)	
			{
				int tmp;
				int tmpres=10000000;
				for (tmp=1;tmp<=100;tmp++)				
				{
					int th=0;
					for (int h=0;h<n;h++)
						th+=abs(num[h][j]-tmp);
					if (th<tmpres)
						tmpres=th;
				}
			
				ans+=tmpres;
			}
			cout<<"Case #"<<i+1<<": "<<ans<<'\n';
		}
	}



	return 0;
}
