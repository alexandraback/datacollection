#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <hash_set>
#include <array>
#include <vector>

#define FILE_BUF_SIZE 10000
#define MAX_BARBER 5
#define MAX_TIME 25

using namespace std;

int gcd(int a, int b) 
{
	while (b != 0) 
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return abs(a);
}

int lcm(int a, int b) 
{
	int gcdValue = gcd(a, b);

	if (gcdValue == 0)
	{
		return 0;
	}

	return abs((a * b) / gcdValue);
}

unsigned __int64 lcm64(__int64 a, __int64 b) 
{
	int gcdValue = gcd((int)a, (int)b);

	if (gcdValue == 0) 
		return 0;

	return _abs64((a * b) / gcdValue);
}



int main()
{
	// Prepare file
	FILE* inputFile;
	fopen_s(&inputFile, "B-small-attempt1.in", "r");
	if (inputFile == nullptr)
	{
		printf("Input file open error!\n");
	}

	FILE* outputFile;
	fopen_s(&outputFile, "Small-Output.txt", "w");
	if (outputFile == nullptr)
	{
		printf("Output file open error!\n");
	}

	// Read count of test case
	char fileBuf[FILE_BUF_SIZE + 1];
	fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
	int countOfTestCase = atoi(fileBuf);

	int barberAbility[MAX_BARBER];	
	std::vector<int> pattern;
	for (int caseNo = 1; caseNo <= countOfTestCase; caseNo++)
	{	
		pattern.clear();

		// Read countOfBarber and n
		int countOfBarber = 0;
		__int64 n = 0;
		fscanf(inputFile, "%d %I64d", &countOfBarber, &n);
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);

		// Read barberAbility and calculate maxTime
		unsigned __int64 lcmTime = 1;
		for (int i = 0; i < countOfBarber; i++)
		{
			fscanf(inputFile, "%d", &barberAbility[i]);
			lcmTime = lcm64(lcmTime, barberAbility[i]);
		}
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
				
		for (unsigned __int64 time = 0; time < lcmTime; time++)
		{
			for (int i = 0; i < countOfBarber; i++)
			{
				if (time % barberAbility[i] == 0)
				{
					pattern.push_back(i + 1);
				}
			}		
		}		

		int index = ((n - 1) % pattern.size());
		index = max(0, index);
		fprintf(outputFile, "Case #%d: %d\n", caseNo, pattern[index]);
	}

	return 1;
}
