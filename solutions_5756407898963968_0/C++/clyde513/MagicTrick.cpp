// MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

const char cszInputFileLocation[] = "c:\\temp\\GoogleCodeJam\\MagicTrick\\A-small-attempt0.in";
const char cszOutputFileLocation[] = "c:\\temp\\GoogleCodeJam\\MagicTrick\\GoogleOutput.txt";

const int kCardsPerRowCol=4;

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, nCaseNum, nMatch;
	int nNumTestCases=0;
	bool bMatchFound, bTwoMatches;
	int nAnswer1=0; int nAnswer2=0;
	int anSet1[kCardsPerRowCol][kCardsPerRowCol];
	int anSet2[kCardsPerRowCol][kCardsPerRowCol];
	FILE *pInputFile = NULL;
	FILE *pOutputFile = NULL;

	if (fopen_s( &pOutputFile, cszOutputFileLocation, "w") != 0)
		return false;
	if (fopen_s( &pInputFile, cszInputFileLocation, "r") != 0)
		return false;
	fscanf(pInputFile, "%d\n", &nNumTestCases);

	for (nCaseNum=1; nCaseNum<=nNumTestCases; nCaseNum++)
	{
		fscanf(pInputFile, "%d\n", &nAnswer1);
		int a,b,c,d;
		for (i=0; i<kCardsPerRowCol; i++)
			fscanf(pInputFile, "%d %d %d %d\n", &anSet1[i][0], &anSet1[i][1], &anSet1[i][2], &anSet1[i][3]);
		fscanf(pInputFile, "%d\n", &nAnswer2);
		for (i=0; i<kCardsPerRowCol; i++)
			fscanf(pInputFile, "%d %d %d %d\n", &anSet2[i][0], &anSet2[i][1], &anSet2[i][2], &anSet2[i][3]);
		nAnswer1--; nAnswer2--; // arrays are zero based

		bMatchFound=false; bTwoMatches=false; nMatch=0;
		for (i=0; i<kCardsPerRowCol; i++)
		{
			for (j=0; j<kCardsPerRowCol; j++)
			{
				if (anSet1[nAnswer1][i] == anSet2[nAnswer2][j])
				{
					if (bMatchFound)
						bTwoMatches=true;
					bMatchFound=true;
					nMatch=anSet1[nAnswer1][i];
				}
			}
		}
		if (bTwoMatches)
			fprintf( pOutputFile, "Case #%u: Bad magician!\n", nCaseNum);
		else if (!bMatchFound)
			fprintf( pOutputFile, "Case #%u: Volunteer cheated!\n", nCaseNum);
		else
			fprintf( pOutputFile, "Case #%u: %u\n", nCaseNum, nMatch);
	}

	fclose( pInputFile);
	fclose( pOutputFile);
	return 0;
}