#include <iostream>
#include<stdio.h>
using namespace std;
int ns[262154];
int a, b, n;
int cal(int i)
{
	int ans = 0;
	for (int r = 0; r < a; r++)
	{
		for (int c = 0; c < b; c++)
		{
			if (c > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b+ c - 1))))
				ans++;
			if (r > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b + c - b))))
				ans++;
		}
	}
	return ans;
}
 
int main() 
{
	int t;
	cin >> t;
	for (int p = 1;p <= t; p++)
	{
		cin>>a>>b>>n;
		int maxi = a*b*n*100;
		for (int i = 1; i < (1 << (a * b)); i++)
		{
			ns[i] = ns[i - (i & -i)] + 1;
			if (ns[i]==n)
				maxi = min(maxi, cal(i));
		}
		cout<<"Case #"<<p<<": "<<maxi<<endl;
	}
}
