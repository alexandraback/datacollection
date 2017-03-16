#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <math.h>
using namespace std;

const string file = "file";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 
const int MODN = 666013;
const double EPS = 0.0000001;

//#define ONLINE_JUDGE


vector<int> compute(string& str)
{
	vector<int> res;

	char prev = str[0];
	res.push_back(1);

	for(int i = 1; i < str.size(); i++)
	{
		if(str[i] == prev)
		{
			res[res.size() -1]++;
		}
		else
		{
			res.push_back(1);
			prev = str[i];
		}
	}
	return res;
}

int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in | ios::binary);
	fstream fout(outfile.c_str(), ios::out);
#endif	
	

	int T;
	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N;
		fin >> N;
		vector<string> A(N);
		for(int i = 0; i < N; i++)
		{
			fin >> A[i];
		}


		vector<string> B = A;
		for(int i = 0; i < N; i++)
		{
			
			B[i].erase(unique(B[i].begin(), B[i].end()), B[i].end());
		}

		bool found = true;
		
		for(int i = 0; i < N; i++)
		{
			if(found == false)
				break;
			for(int j = i + 1; j < N; j++)
			{
				if(B[i] != B[j])
				{
					found = false;
					break;
				}
			}
		}

		if(found == false)
		{
			fout << "Case #" << t <<": ";
			fout << "Fegla Won";
			fout << "\n";
			continue;
		}

		vector<vector<int> > C;
		for(int i = 0; i < N; i++)
		{
			C.push_back(compute(A[i]));
		}


		vector<int> X;
		for(int i = 0; i < C[0].size(); i++)
		{
			double sum = 0;
			for(int j = 0; j < N; j++)
			{
				sum += C[j][i];
			}
			
			sum /= N;
			X.push_back(floor(sum + 0.5));
		}
		
		int Sol = 0;

		for(int i = 0; i < N; i++)
		{
			
			for(int j = 0; j < C[i].size(); j++)
			{
				int dif = 0;
				dif = C[i][j] - X[j];
				if(dif < 0)
					dif = -dif;
				Sol += dif;
			}
			
		}

		fout << "Case #" << t <<": ";
		fout << Sol;
		fout << "\n";
		
	}


#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
