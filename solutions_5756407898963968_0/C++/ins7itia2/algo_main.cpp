#include <cstdio>
#include <algorithm>
#include <vector>

int decide(int* rowFirst, int* rowSecond)
{
	int numFound = -1;
	int countFound = 0;
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if(rowFirst[i] == rowSecond[j])
			{
				++countFound;
				numFound = rowFirst[i];
			}
		}
	}

	if(countFound == 1) return numFound;
	else if(countFound > 1) return -1;
	else if(countFound == 0) return 0;
}

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	int numCase = 1;
	while(T-- > 0)
	{
		int answer = 0;
		int rowFirst[4] = {0, };
		int rowSecond[4] = {0, };

		// first answer
		scanf("%d", &answer);
		for(int i = 1; i <= 4; ++i)
		{
			int row[4];
			scanf("%d", &(row[0]));
			scanf("%d", &(row[1]));
			scanf("%d", &(row[2]));
			scanf("%d", &(row[3]));

			if(i == answer)
			{
				rowFirst[0] = row[0];
				rowFirst[1] = row[1];
				rowFirst[2] = row[2];
				rowFirst[3] = row[3];
			}
		}

		// second answer
		scanf("%d", &answer);
		for(int i = 1; i <= 4; ++i)
		{
			int row[4];
			scanf("%d", &(row[0]));
			scanf("%d", &(row[1]));
			scanf("%d", &(row[2]));
			scanf("%d", &(row[3]));

			if(i == answer)
			{
				rowSecond[0] = row[0];
				rowSecond[1] = row[1];
				rowSecond[2] = row[2];
				rowSecond[3] = row[3];
			}
		}

		/*printf("%d %d %d %d\n", rowFirst[0], rowFirst[1], rowFirst[2], rowFirst[3]);
		printf("%d %d %d %d\n", rowFirst[0], rowFirst[1], rowFirst[2], rowFirst[3]);
		printf("%d %d %d %d\n", rowFirst[0], rowFirst[1], rowFirst[2], rowFirst[3]);*/

		int ret = decide(rowFirst, rowSecond);

		if(ret > 0)
			printf("Case #%d: %d\n", numCase, ret);
		else if(ret == 0)
			printf("Case #%d: Volunteer cheated!\n", numCase);
		else if(ret < 0)
			printf("Case #%d: Bad magician!\n", numCase);

		++numCase;

	}

	return 0;
}



#if 0
int run(char *pStr);
bool isGameEnded(char *pMat);

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	int numCase = 1;
	while(T-- > 0)
	{
		char mat[20] = {0,};
		char *pRow = mat;
		char *pCol = mat;
		scanf("%s", pRow);  pRow += 4;
		scanf("%s", pRow);  pRow += 4;
		scanf("%s", pRow);  pRow += 4;
		scanf("%s", pRow);  pRow = mat;

		int ret = 0;

		for(int i = 0; i < 4; ++i)
		{
			char strRow[4] = {pRow[0], pRow[1], pRow[2], pRow[3]};
			char strCol[4] = {pCol[0], pCol[4], pCol[8], pCol[12]};
			

			if(ret = run(strRow))
			{
				goto printWinner;
			}

			if(ret = run(strCol))
			{
				goto printWinner;
			}


			++pCol;
			pRow += 4;
		}

		// diag
		char str1[4] = {mat[0], mat[5], mat[10], mat[15]};
		char str2[4] = {mat[3], mat[6], mat[9], mat[12]};
		if(ret = run(str1))
		{
			goto printWinner;
		}
		else if(ret = run(str2))
		{
			goto printWinner;
		}

	printWinner:
		if(ret > 0)
			printf("Case #%d: X won\n", numCase);
		else if(ret < 0)
			printf("Case #%d: O won\n", numCase);
		else
		{
			if(isGameEnded(mat))
			{
				printf("Case #%d: Draw\n", numCase);
			}
			else
			{
				printf("Case #%d: Game has not completed\n", numCase);
			}
		}


		++numCase;
	}

	return 0;
}

bool isGameEnded(char *pMat)
{
	for(int i = 0; i < 16; ++i)
	{
		if(pMat[i] == '.')
			return false;
	}
	
	return true;
}

int run(char *pStr)
{
	int countX = 0;
	int countO = 0;
	int countT = 0;

	for(int i = 0; i < 4; ++i)
	{
		if(pStr[i] == 'X') ++countX;
		else if(pStr[i] == 'O') ++countO;
		else if(pStr[i] == 'T') ++countT;
	}

	if(countX >= 3 && ((countX + countT) == 4)) return 1;
	else if(countO >= 3 && ((countO + countT) == 4)) return -1;
	else return 0;
}
#endif /* code jam practice 2013 */