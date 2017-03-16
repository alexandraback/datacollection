#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	int cases;
	fin >> cases;
	fin.ignore(1);

	for (int cas = 1; cas <= cases; cas++)
	{
		int A, B, K;
		fin >> A >> B >> K;
		int answer = 0;
		for (int a = 0; a < A; ++a)
		for (int b = 0; b < B; ++b)
		{
			if ((a & b) < K)
				++answer;
		}
		fout << "Case #" << cas << ": "  << answer;

		fout << "\n";
	}
	return 0;
}