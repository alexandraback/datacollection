#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
//#include<set>
//#include<climit>
//#include<cmath>
//#include<cstdlib>  rand()

using namespace std;

int main()
{
	ofstream outfile("D:\\codejam\\2015\\R1\\output.txt");
	ifstream infile("D:\\codejam\\2015\\R1\\testcase.txt");

	int T;
	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int N;
		int tmp;
		int maxgap = 0;
		int y = 0, z = 0;
		vector<int> mush;
		infile >> N;
		for (int i = 0; i < N; i++)
		{
			infile >> tmp;
			mush.push_back(tmp);
		}
		for (int i = 0; i < N - 1; i++)
		{
			if (mush[i] > mush[i + 1])
				y += (mush[i] - mush[i + 1]);
			maxgap = max(maxgap, mush[i] - mush[i + 1]);
		}

		for (int i = 0; i < N - 1; i++)
		{
			z += min(mush[i], maxgap);
		}

		outfile << "Case #" << casenum << ": " << y << " " << z <<endl;
	}


	infile.close();
	outfile.close();
	return 0;
}
