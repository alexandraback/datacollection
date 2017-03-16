#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

const char* INPUT_FILE_NAME  = "A-large.in";
const char* OUTPUT_FILE_NAME = "A-large.out";
//const char* INPUT_FILE_NAME  = "A-small-attempt0.in";
//const char* OUTPUT_FILE_NAME = "A-small-attempt0.out";
//const char* INPUT_FILE_NAME  = "A-small.in";
//const char* OUTPUT_FILE_NAME = "A-small.out";

int main()
{
	int T;
	string strOutput;
	string strInput;

	fstream inputFileStream(INPUT_FILE_NAME, ios_base::in);
	fstream outputFileStream(OUTPUT_FILE_NAME, ios_base::out|ios_base::trunc);
	outputFileStream.setf(ios_base::floatfield, ios_base::fixed);
	outputFileStream.precision(7);
	cout.setf(ios_base::floatfield, ios_base::fixed);
	cout.precision(7);

	inputFileStream >> T;

	
	for (int i = 0; i < T; ++i)
	{
		int N;
		inputFileStream >> N;

		std::vector<int> m(N);
		std::vector<int> diff(N);

		for (int j = 0; j < N; ++j)
		{
			inputFileStream >> m[j];
		}
		

		int eaten1 = 0;
		int eaten2 = 0;
		int max_rate = 0;
		int rate = 0;

		for (int j = 1; j < N; ++j)
		{
			diff[j] = m[j - 1] - m[j];
			if (diff[j] > 0)
			{
				eaten1 += diff[j];
				rate = diff[j];
				if (rate > max_rate)
					max_rate = rate;
			}
		}

		//max_rate
		for (int j = 0; j < N - 1; ++j)
		{
			eaten2 += std::min(max_rate, m[j]);
		}

		cout << "Case #" << i + 1 << ": " << eaten1 << " " << eaten2 << endl;
		outputFileStream << "Case #" << i + 1 << ": " << eaten1 << " " << eaten2 << endl;
	}

	inputFileStream.close();
	outputFileStream.flush();
	outputFileStream.close();

	return 0;
}
