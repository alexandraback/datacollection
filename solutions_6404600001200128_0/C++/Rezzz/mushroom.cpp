#include <iostream>
#include <sstream>
#include <climits>

using namespace std;
#define MAXSIZE 1500

int main()
{
	int T;
	string line;
	getline(std::cin, line);
	std::istringstream stream1(line);
	stream1 >> T;

	for(int i = 1; i <= T; i++)
	{
		int N;
		int M[1000];

		getline(std::cin, line);
		std::istringstream stream2(line);
		stream2 >> N;

		int largestDiff = INT_MIN;
		
		getline(std::cin, line);
		std::istringstream stream(line);
		long totalY = 0;
		long totalZ = 0;
		for(int j = 0; j < N; j++)
		{
			stream >> M[j];
			if(j > 0)
			{
				if(M[j-1] - M[j] > largestDiff)
				{
					largestDiff = M[j-1] - M[j];
				}
				if(M[j] - M[j-1] < 0)
				{
					totalY += (M[j-1] - M[j]);
				}
			}
		}

		double rateZ = 0;
		if (largestDiff > 0)
		{
			rateZ = largestDiff;
		}
		for(int j = 0; j < N-1; j++)
		{
			if(rateZ > M[j])
			{
				totalZ += M[j];
			}
			else
			{
				totalZ += rateZ;
			}
		}

		cout << "Case #" << i << ": " << totalY << " " << totalZ << endl;

	}
}
	