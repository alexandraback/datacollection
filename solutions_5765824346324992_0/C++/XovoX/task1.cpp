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
		res += ceil((double)t / M[j]);
	return res;
}
int main()
{
	ifstream fin;
	fin.open("B-small-attempt1.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("B-small-attempt1.out");
		int T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int B,N;
			fin >> B>>N;
			int time;
			double sum=0;
			int* M = new int[B];
			int res = 0;
			for (int j = 0; j < B; j++)
			{
				int cur;
				fin >> cur;
				cout << cur << " ";
				M[j]=cur;
				sum += (double)1 / cur;
			}
			unsigned long long t = 0;
			unsigned long long t2 = ceil((double)N/sum);
			cout << t2;
			while (true)
			{
				int f11 = func(t, M, B);
				int f12 = func(t+1, M, B);
				if (f11< N && f12 >= N) break;
				unsigned long long t3 = (t + t2) / 2;
				int f2 = func(t3, M, B);
				if (f2 >= N) t2 = t3; else t = t3;				
			}
			N = N - func(t, M, B);
			int z = 0;
			for (int j = 0; j < B; j++)
			{
				if (t%M[j] == 0)
				{
					z++;
					if (z == N)
					{
						res = j;
						break;
					}
				}
			}
			cout << "t=" << t<<" N="<<N;
			delete[] M;
//			sort(M.begin(), M.end());
			cout << endl;
			cout << "Case #" << i + 1 << ": " << (res+1) << endl;

			fout << "Case #" << i + 1 << ": " << (res+1) << endl;
		}
		fin.close();
		fout.close();
	}
	return 0;
}