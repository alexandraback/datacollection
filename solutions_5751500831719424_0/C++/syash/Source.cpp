#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T,N;
	inFile >> T;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		inFile >> N;
		int correctionsNum = 0;
		string* strings = new string[N];
		int* pos = new int[N];
		int* ends = new int[N];
		char lastChar;
		for (int i = 0; i < N; i++)
		{
			pos[i]=0;
			ends[i] = 0;
		}
		for (int n=0; n<N; n++)
		{
			inFile >> strings[n];
		}

		int goon=1;
		int badFlag = 0;
		int success = 0;


		if (caseNum == 2)
			caseNum = 2;


		while(!success)
		{
			if (goon)
			{
				lastChar = strings[0][pos[0]];
				for (int i = 0; i < N; i++)
				{
					if (strings[i][pos[i]] != lastChar)
					{
						badFlag = 1;
						break;
					}
					pos[i]++;
				}
			}
			if (badFlag)
				break;
			int count=0;
			for (int i = 0; i < N; i++)
			{
				if (pos[i] < strings[i].length() )
				{
					if (strings[i][pos[i]] == lastChar)
					{
						count++;
						pos[i]++;
					}
				}
				else
					ends[i]=1;
			}

			if ((count>0) && (count < N))
			{
				if (count < N-count)
					correctionsNum += count;
				else
					correctionsNum += N-count;
			}

			if (count == 0)
			{
				goon = 1;

				for (int i = 0; i < N-1; i++)
				{
					if (ends[i] != ends[i+1])
					{
						goon = 0;
						badFlag = 1;
						break;
					}

					if (!badFlag && ends[0] == 1)
						success=1;
				}
			}
			else
			{
				goon = 0;
			}

		}

		outFile << "Case #" << caseNum+1 << ": ";

		if (!badFlag)
			outFile << correctionsNum << endl;
		else
			outFile << "Fegla Won" << endl;




	}


	inFile.close();
	outFile.close();

	return 0;
}