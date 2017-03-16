#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned int uint;

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");


	uint T;
	input >> T;
	uint N;
	string* s,*tmp;
	uint l;
	bool b;
	uint letters;
	uint* values , *pointers;
	uint ans;

	for (unsigned long long t = 0; t < T; ++t)
	{
		input >> N;
		b = 1;
		s = new string[N];
		tmp = new string[N];
		ans = 0;

		for (uint i = 0; i < N; i++)
		{
			input >> s[i];
			l = s[i].length();
			tmp[i].push_back(s[i][0]);
			for (uint j = 1; j < l; ++j)
			{
				if (s[i][j] != s[i][j - 1])
					tmp[i].push_back(s[i][j]);
			}
		}

		for (uint i = 1; i < N; ++i)
		{
			if (tmp[i] != tmp[i - 1])
			{
				b = 0;
				break;
			}
		}
		if (b)
		{
			values = new uint[N];
			pointers = new uint[N];
			letters = tmp[0].length();
			for (uint j = 0; j < N; ++j)
			{
				pointers[j] = 1;
			}

			for (uint i = 0; i < letters; ++i)
			{
				for (uint j = 0; j < N; ++j)
					values[j] = 1;


				for (uint k = 0; k < N; ++k)
				{
					while ((pointers[k]<s[k].length())&&(s[k][pointers[k]] == s[k][pointers[k] - 1]))
					{
						++(values[k]);
						++(pointers[k]);
					}
					++(pointers[k]);

				}
				sort(values, values + N);
				for (uint j = 0; j < N; ++j)
					ans += abs((int)values[j] - (int)values[N / 2]);
			}

			delete[] pointers;
			delete[] values;
		}

		output << "Case #" << t + 1 << ": ";
		if (b)
			output << ans;
		else
			output << "Fegla Won";


		output << "\n";

		delete[] s;
		delete[] tmp;

	}




	input.close();
	output.close();
	//	system("pause");
	return 0;
}
