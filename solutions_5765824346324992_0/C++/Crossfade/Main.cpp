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
		int B, N;
		in >> B >> N;
		vector<int> M;
		M.resize(B);
		for (int j = 0; j < B; ++j)
		{
			int tmp;
			in >> tmp;
			M[j] = tmp;
		}
		int result = 0;

		if (N <= B)
		{
			result = N;
		}
		else
		{
			/*double totalSpeed = 0;
			for (int j = 0; j < B; ++j)
			{
				totalSpeed += M[j] / 25.0f;
			}
			

			int n = N / 125;
			N = N % 125;

			*/
			vector<int> curM;
			int currentClient = 0;
			for (int j = 0; j < B; ++j)
			{
				currentClient++;
				curM.push_back(M[j]);
			}



			while (true)
			{
				bool isFound = false;
				int minValue = curM[0];
				for (int j = 1; j < curM.size(); ++j)
				{
					if (curM[j] < minValue)
					{
						minValue = curM[j];
					}
				}
				vector<int> indexList;
				for (int j = 0; j < curM.size(); ++j)
				{
					if (curM[j] == minValue)
					{
						indexList.push_back(j);
					}
				}
				for (int j = 0; j < curM.size(); ++j)
				{
					curM[j] -= minValue;
				}
				for (int j = 0; j < indexList.size(); ++j)
				{
					currentClient++;
					curM[indexList[j]] = M[indexList[j]];
					if (currentClient == N)
					{
						result = indexList[j] + 1;
						isFound = true;
						break;
					}
				}
				if (isFound)
				{
					break;
				}
				bool isMatch = true;
				for (int j = 0; j < M.size(); ++j)
				{
					if (M[j] != curM[j])
					{
						isMatch = false;
						break;
					}
				}
				if (isMatch)
				{
					int z = currentClient - B;
					int k = (N - B) / z - 1;
					if (k > 1)
					{
						k--;
						currentClient += z * k;
					}
					cout << "jump at " << i << endl;
				}
			}
		}

		out << "Case #" << (i + 1) << ": " << result << endl;
	}

	return 0;
}