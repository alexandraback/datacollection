#include "stdafx.h"

void SovleA(char * input)
{

	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int rn;
		READ(rn); NL;
		set<Int> firstSet;
		for(Int r = 1; r <=4; r++)
		{
			Int tmp;
			if (rn != r) 
			{
				READ(tmp);READ(tmp);READ(tmp);READ(tmp);NL;
			}
			else
			{
				READ(tmp);firstSet.insert(tmp);
				READ(tmp);firstSet.insert(tmp);
				READ(tmp);firstSet.insert(tmp);
				READ(tmp);firstSet.insert(tmp);
				NL;
			}
		}
		Int cnt = 0;
		Int num = -1;
		READ(rn); NL;
		for(Int r = 1; r <=4; r++)
		{
			Int tmp;
			if (rn != r) 
			{
				READ(tmp);READ(tmp);READ(tmp);READ(tmp);NL;
			}
			else
			{
				READ(tmp);if (firstSet.find(tmp) != firstSet.end()) {cnt++; num=tmp;}
				READ(tmp);if (firstSet.find(tmp) != firstSet.end()) {cnt++; num=tmp;}
				READ(tmp);if (firstSet.find(tmp) != firstSet.end()) {cnt++; num=tmp;}
				READ(tmp);if (firstSet.find(tmp) != firstSet.end()) {cnt++; num=tmp;}
				NL;
			}
		}
		if (cnt == 1)
			PRINT("Case #%I64d: %I64d\n", i + 1, num);
		else if (cnt == 0)
			PRINT("Case #%I64d: Volunteer cheated!\n", i + 1);
		else
			PRINT("Case #%I64d: Bad magician!\n", i + 1);
	}
	TRACE("ended.");
}