#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int get(int a)
{
	vector <int> z;
	int x=a;
	while (x!=0)
	{
		z.push_back(x%10);
		x/=10;
	}
	//reverse(z.begin(),z.end());
	int y=0;
	for (int i=0;i<z.size();i++)
	{
		y*=10;
		y+=z[i];
	}
	return y;
}


vector <int> duo(int k,int sz)
{
	vector <int> z;
	int x=k;
	while (x!=0)
	{
		z.push_back(x%2);
		x/=2;
	}
	while (z.size()<sz)
		z.push_back(0);
	return z;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++)
	{
		cout<<"Case #"<<qq+1<<": ";
		int r,c;
		int n;
		cin>>r>>c>>n;
		int ans=2e9;
		int k=r*c;
		int y=1;
		for (int i=0;i<k;i++)
			y*=2;
		for (int i=0;i<y;i++)
		{
			vector <int> s=duo(i,k);
			int gg=0;
			gg++;
			int a[100][100];
			for (int i=0;i<100;i++)
				for (int j=0;j<100;j++)
					a[i][j]=0;
			int f=0;
			for (int i=1;i<=r;i++)
				for (int j=1;j<=c;j++)
				{
					a[i][j]=s[f];
					f++;
				}
			int ans1=0;
			int z=0;
			for (int i=1;i<=r;i++)
				for (int j=1;j<=c;j++)
				{
					if (a[i][j]==1)
						z++;
					if ((a[i][j]==1)&&(a[i-1][j]==1))
						ans1++;
					if ((a[i][j]==1)&&(a[i][j-1]==1))
						ans1++;
				}
				if (z==n)
				{
					ans=min(ans,ans1);
				}
		}
		cout<<ans<<endl;

	}
		
	return 0;
}



