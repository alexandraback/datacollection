#include "Precomp.h"
using namespace std;

int main()
{
	ifstream  src("Output.txt");
	string currentDate = currentDateTime();
	replace(currentDate.begin(), currentDate.end(), ':', '.');
	ofstream dst((string("Output") + currentDate + string(".txt")).c_str());
	dst << src.rdbuf();
	src.close();
	dst.close();

	ifstream in("Input.txt");
	ofstream out("Output.txt");

	int T;
	in >> T;

	for (int i = 0; i < T; ++i)
	{
		int N;
		in >> N;
		vector<int> m;
		m.resize(N);
		for (int j = 0; j < N; ++j)
		{
			int tmp;
			in >> tmp;
			m[j] = tmp;
		}

		// resA
		int resultA = 0;
		for (int j = 0; j < N - 1; ++j)
		{
			if (m[j] > m[j + 1])
			{
				resultA += m[j] - m[j + 1];
			}
		}

		// resB
		int resultB = 0;
		int speed = 0;
		for (int j = 0; j < N - 1; ++j)
		{
			if (m[j] - m[j + 1] > speed)
			{
				speed = m[j] - m[j + 1];
			}
		}

		for (int j = 0; j < N - 1; ++j)
		{
			if (m[j] > speed)
			{
				resultB += speed;
			}
			else
			{
				resultB += m[j];
			}
		}

		out << "Case #" << (i + 1) << ": " << resultA << " " << resultB << endl;
	}

	return 0;
}