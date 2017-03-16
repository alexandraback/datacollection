#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("output.txt");

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		////////////////////////////////////////////////////

		int B, N;
		vector<long long> M;
		long long under=0, over=100000000900000LL;

		fin >> B >> N;
		M.resize(B);
		for(long long &m : M)
			fin >> m;

		if(N<=B)
		{
			fout << N << endl;
			continue;
		}

		while(over-under > 1LL)
		{
			long long mid = (under+over)/2;
			long long done=0;

			for(int i=0; i<B; i++)
				done += mid/M[i]+1LL;

			if(done>=(long long)N)
				over = mid;
			else
				under = mid;
		}

		
		long long count=0;
		for(int i=0; i<B; i++)
			count += under/M[i]+1LL;
		count = N-count;


		int ans=0;
		for(ans=0; ans<B; ans++)
			if(over%M[ans]==0LL)
			{
				if((--count)==0LL)
					break;
			}

		fout << ans+1 << endl;
	}

	return 0;
}