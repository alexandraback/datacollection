#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int main()
{
	int t,n;
	string s[100];
	char b[100];
	int a[100][100],z,y,f,c[100][100],r;
	in >> t;
	for(int i=1;i<=t;i++)
	{
		in >> n;
		for (int j=0;j<n;j++)
		{
			in >> s[j];
		}
		for (int j=0;j<100;j++) for (int k=0;k<100;k++) a[j][k]=0;
		b[0]=s[0][0];
		a[0][0]=1;
		z=0;
		for (int j=1;j<s[0].size();j++)
		{
			if (s[0][j]==s[0][j-1])
			{
				a[0][z]++;
			}
			else
			{
				z++;
				a[0][z]=1;
				b[z]=s[0][j];
			}
		}
		f=0;
		for (int j=1;f==0 && j<n;j++)
		{
			if (s[j][0]!=b[0]) f=-1;
			else
			{
				a[j][0]=1;
				y=0;
			}
			for (int k=1;f==0 && k<s[j].size();k++)
			{
				if (s[j][k]==b[y])
				{
					a[j][y]++;
				}
				else
				{
					y++;
					if (y>z || s[j][k]!=b[y]) f=-1;
					else a[j][y]=1;
					
				}
			}
		}
		for (int j=0;j<n;j++) for (int k=0;k<=z;k++) if (a[j][k]==0) f=-1;
		if (f==-1)
		{
			out << "Case #" << i << ": Fegla Won" << "\n";
		}
		else
		{
			for (int j=0;j<n;j++) for (int k=0;k<=z;k++) c[k][j]=a[j][k];
			for (int k=0;k<=z;k++) sort(c[k],c[k]+n);
			r=0;
			for (int j=0;j<n;j++) for (int k=0;k<=z;k++) r+=abs(c[k][j]-c[k][n/2]);
			out << "Case #" << i << ": " << r << "\n";
		}
	}
	return 0;
}
