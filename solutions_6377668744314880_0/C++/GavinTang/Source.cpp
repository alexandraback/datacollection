#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int T;
int N;
long long X[3005], Y[3005], res[3005];

int sig(long long a)
{
	if (a == 0)
		return 0;
	if (a > 0)
		return 1;
	else return -1;
}
void getres(int N)
{
	for (int i = 0; i < N; i++)
	{
		int temp = N - 1;
		for (int j = 0; j < N; j++)
		{
			if (j == i)
				continue;
			int pos = 0;
			int neg = 0;
			for (int k = 0; k < N; k++)
			{
				if (sig((Y[i] - Y[j])*(X[k] - X[j]) - (X[i] - X[j])*(Y[k] - Y[j])) == 1)
					pos++;
				else if (sig((Y[i] - Y[j])*(X[k] - X[j]) - (X[i] - X[j])*(Y[k] - Y[j])) == -1)
					neg++;
			}
			temp = min(temp, pos);
			temp = min(temp, neg);
		}
		res[i] = temp;
	}
}

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("C-small-attempt3.in");
	ofile.open("tzh.txt");

	ifile >> T;
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> N;
		for (int i = 0; i < N; i++)
			ifile >> X[i] >> Y[i];
		getres(N);
		ofile << "Case #" << casenum << ":" << endl;
		for (int i = 0; i < N; i++)
		{
			ofile << res[i] << endl;
		}
	}
}