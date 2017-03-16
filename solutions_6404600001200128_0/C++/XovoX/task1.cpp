#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int func(unsigned long long t, int *M, int B)
{
	int res = 0;
	for (int j = 0; j < B; j++)
		res += (int)ceil((double)t / M[j]);
	return res;
}
int main()
{
	ifstream fin;
	fin.open("A-small-attempt0.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("A-small-attempt0.out");
		int T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int N;
			fin >>N;
			int* M = new int[N];
			int res1 = 0;
			int res2 = 0;
			int rate = 0;
			for (int j = 0; j < N; j++)
			{
				int cur;
				fin >> cur;
			//	cout << cur << " ";
				M[j]=cur;
				if (j >= 1)
				{
					if(cur<M[j-1]) res1 += -cur + M[j - 1];
					if(-cur + M[j - 1] > rate) rate = -cur + M[j - 1];
				}				
			}
			int rest = 0;
			for (int j = 0; j < N-1; j++)
			{
				res2 += min(rate,M[j]);

			}
			delete[] M;
			cout << "Case #" << i + 1 << ": " << res1 << endl;

			fout << "Case #" << i + 1 << ": " << res1<<" "<<res2 << endl;
		}
		fin.close();
		fout.close();
	}
	return 0;
}