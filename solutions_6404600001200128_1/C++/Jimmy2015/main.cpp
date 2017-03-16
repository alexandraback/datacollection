#include <fstream>
#include <algorithm>
using namespace std;
int m[1005];
int main()
{
	int t;
	ifstream infile("G:\\A-large.in");
	ofstream outfile("G:\\A-large.out");
	infile >> t;
	for (int i = 1; i <= t; i++)
	{
		
		int n;
		infile>>n;
		int maxgap=0;
		infile>>m[0];
		for(int j=1;j<n;j++)
		{
			infile>>m[j];
			if(m[j-1]-m[j]>maxgap)
				maxgap=m[j-1]-m[j];
		}
		int start=1;
		int r1=0;
		while(start<n)
		{
			if(m[start]<m[start-1])
				r1+=m[start-1]-m[start];
			start++;
		}
		int r2=0;
		start=0;
		while(start<n-1)
		{
			if(m[start]<maxgap)
			{
				r2+=m[start];
			}
			else
				r2+=maxgap;
			start++;
		}


		outfile << "Case #" << i << ": " <<r1<<" "<<r2<< endl;
	}
	infile.close();
	outfile.close();
	return 0;
}