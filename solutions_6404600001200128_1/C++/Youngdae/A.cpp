#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("output.txt");

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		////////////////////////////////////////////////////

		int N, m[1000];

		fin >> N;
		for(int i=0; i<N; i++)
			fin >> m[i];

		int y=0, z=0, rate=0;

		for(int i=1; i<N; i++)
		{
			if(m[i-1] > m[i])
			{
				int diff = m[i-1]-m[i];
				y += diff;
				if(diff>rate)
					rate = diff;
			}
		}

		for(int i=0; i<N-1; i++)
		{
			if(m[i]<rate)
				z+=m[i];
			else
				z+=rate;
		}

		fout << y << ' ' << z << endl;
	}

	return 0;
}