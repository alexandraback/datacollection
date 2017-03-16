#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int T;
int N;
int mush[10005];


int res_1(int *mush, int length)
{
	int res = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (mush[i] >= mush[i + 1])
			res += mush[i] - mush[i + 1];
	}
	return res;
}

int res_2(int *mush, int length)
{
	int temp = 0;
	int res = 0;
	for (int i = 0; i < length - 1; i++)
		temp = max(mush[i] - mush[i + 1], temp);

	for (int i = 0; i < length - 1; i++)
	{
		res += min(temp, mush[i]);
	}
	return res;
}

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("A-large.in");
	ofile.open("output.txt");

	ifile >> T;
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> N;
		for (int i = 0; i < N; i++)
			ifile >> mush[i];
		ofile << "Case #" << casenum << ": " << res_1(mush, N) << " " << res_2(mush, N) << endl;
	}
}