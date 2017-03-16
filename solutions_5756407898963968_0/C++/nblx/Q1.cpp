#include <iostream>
#include <iomanip>		// setprecision
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>		// sort, stable_sort
#include <cstdlib>			// atoi, atof, etc.
using namespace std;

typedef unsigned long long ull_int;

int solve(int a1, vector<vector<int>> &M1, int a2, vector<vector<int>> &M2)
{	// 0: bad magician;  -1: cheat
	unordered_set<int> S;
	int i;
	for (i=0; i<4; i++)
		S.emplace(M1[a1-1][i]);
	int res = -1;
	for (i=0; i<4; i++)
	{	if (S.count(M2[a2-1][i])>0)
		{	if (res==-1)		res = M2[a2-1][i];
			else if (res>0)	res = 0;
		}
	}
	return res;
}


int main()
{
	ifstream infile;
	infile.open("A-small-attempt0.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int a1, a2;
		vector<vector<int>> M1(4, vector<int>(4)), M2(4, vector<int>(4));
		
		infile >> a1;
		infile.ignore(10,'\n');
		for (int i=0; i<4; i++)
		{	for (int j=0; j<4; j++)
				infile >> M1[i][j];
			infile.ignore(10,'\n');
		}
		infile >> a2;
		infile.ignore(10,'\n');
		for (int i=0; i<4; i++)
		{	for (int j=0; j<4; j++)
				infile >> M2[i][j];
			infile.ignore(10,'\n');
		}

		int res = solve(a1, M1, a2, M2);
		
		outfile << "Case #" << t << ": ";
		if (res==0)	outfile << "Bad magician!" << endl;
		else if (res==-1)		outfile << "Volunteer cheated!" << endl;
		else		outfile << res << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
//	char c;
//	cin >> c;
	return 0;
}