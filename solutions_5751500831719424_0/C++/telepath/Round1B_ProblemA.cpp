#include "include\preCompile\KL_PreCompile.hpp"

#define INPUT_FILE_PATH "D:\\DUMP\\input.in"
#define OUTPUT_FILE_PATH "D:\\DUMP\\output.out"


void init()
{
}

char s[101][101];

int main()
{
	clock_t time1;
	time1 = clock();

#if 1
	freopen(INPUT_FILE_PATH, "r", stdin);
	freopen(OUTPUT_FILE_PATH, "w", stdout);
#endif	

	int T;
	cin >> T;

	int N;
	for (long long int caseNum = 1; caseNum <= T; caseNum++)
	{
		int count[101][101] = {0};

		read1(N);

		string strFirst, strCurr;
		strFirst.clear();

		bool flag = true;

		KL_FOR_DEF(i, N)
		{
			strCurr.clear();
			read1(s[i]);

			// Save order of items

			char c = s[i][0];

			if (0 == i)
			{
				strFirst += c;
			}
			strCurr += c;


			char end = '\0';
			// int uniqueCharCount = 1;
			// KL_FOR_DEF(j, 101)
			int j = 0;
			while (j < 100 && s[i][++j] != end)
			{
				if (s[i][j] == c)
				{
					count[strCurr.length()-1][i]++;
				}
				else
				{
					// uniqueCharCount++;
					c = s[i][j];
					if (0 == i)
					{
						strFirst += c;
					}

					strCurr += c;
				}
			}
			if ( 0 != strcmp(strFirst.c_str(), strCurr.c_str()) )
			{
				flag = false;
				break;
			}

		}
		cout << "Case #" << caseNum << ": ";

		if (false == flag)
		{
			cout << "Fegla Won" << endl;
		}
		else
		{
			int conversions = 0;
			// Find the number of converts
			KL_FOR_DEF(i, strFirst.length())
			{
				sort ( count[i], count[i] + N);
				int median = count[i][(N-1)/2];

				KL_FOR_DEF(j, N)
				{
					conversions += abs (median - count[i][j]);
				}
			}

			cout << conversions << endl;
		}

	}

#if 0
	clock_t time2, timeTaken;
	time2 = clock();
	timeTaken = time2 - time1;
	long long int seconds = timeTaken/CLOCKS_PER_SEC;
	long long int minutes = seconds/60;
	seconds %= 60;

	/*	-------- BEWARE - DON'T cout while doing freopen()	-------- 	*/
	cout << minutes << "min" << seconds << "sec";
#endif
}
