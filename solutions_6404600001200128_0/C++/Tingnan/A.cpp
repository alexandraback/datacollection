#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int solve1(const vector<int>& seq)
{
	// first method
	const int N = seq.size();
	int sum = 0;
	for (int i = 1; i < N; ++i)
	{
		sum += min(0, seq[i] - seq[i - 1]);
	}
	return -sum;
}

int solve2(const vector<int>& seq)
{
	const int N = seq.size();
	int rate = 0;
	for (int i = 1; i < N; ++i)
	{
		rate = max(rate, max(seq[i - 1] - seq[i], 0));
	}
	// now we have the minimum eating rate
	int sum = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		sum += min(seq[i], rate);

	} 
	return sum;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "no input file\n";
		return 0;
	}

	string fname(argv[1]);
	ifstream ifile(fname);
	ofstream ofile(fname + ".out");

	int T;
	ifile >> T;
	for (int i = 0; i < T; ++i)
	{
		// get the specific format 
		int N;
		ifile >> N;
		vector<int> seq(N);
		for (int j = 0; j < N; ++j)
			ifile >> seq[j];
		int result1 = solve1(seq);
		int result2 = solve2(seq);
		ofile << "Case #" << i + 1 << ": " << result1 << " " << result2 << "\n";
 	}
	return 0;
}