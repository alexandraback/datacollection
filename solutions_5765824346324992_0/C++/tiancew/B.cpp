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
		int B, N;
		vector<int> M;
		int tmp;
		vector<int> minutes;
		
		vector<int>::iterator it;
		int P = 0;	//period
		int index;

		infile >> B >> N;
		for (int i = 0; i < B; i++) minutes.push_back(0);
		for (int i = 0; i < B; i++)
		{
			infile >> tmp;
			M.push_back(tmp);
		}

		while (P< N)
		{
			it = min_element(minutes.begin(), minutes.end());
			index = it - minutes.begin();
			minutes[index] += M[index];
			P++;
			if (*min_element(minutes.begin(), minutes.end()) == *max_element(minutes.begin(), minutes.end()))
				break;

		}

		if (P == N || (N%P == 0))
			outfile << "Case #" << casenum << ": " << index + 1 << endl;
		else
		{
			N = N % P;
			for (int i = 0; i < B; i++) minutes[i] = 0;

			P = 0;
			while (P < N)
			{
				it = min_element(minutes.begin(), minutes.end());
				index = it - minutes.begin();
				minutes[index] += M[index];
				P++;

				if (*min_element(minutes.begin(), minutes.end()) == *max_element(minutes.begin(), minutes.end()))
					break;

			}

			outfile << "Case #" << casenum << ": " << index + 1 << endl;
		}


	}


	infile.close();
	outfile.close();
	return 0;
}
