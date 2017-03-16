// Using libUtil from libGlov (Game Library of Victory) available at http://bigscreensmallgames.com/libGlov
// Some solutions may use BigInteger from http://mattmccutchen.net/bigint/
#include "bigint/BigIntegerAlgorithms.hh"
#include "bigint/BigIntegerUtils.hh"
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include "assert.h"
#include "utilArray.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include "utilRand.h"
#include "utilHashTable2.h"
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4018)
extern void doneParsingArgs(char **&toks);

char *doC(char **&toks)
{
	int N = atoi(*toks++);
	S64 pts[3000][2];
	for (int i = 0; i < N; ++i)
	{
		pts[i][0] = atoi(*toks++);
		pts[i][1] = atoi(*toks++);
	}
	doneParsingArgs(toks);

	static char buf[16384];
	strcpy(buf, "\n");
	for (int i = 0; i < N; ++i) {
		S64 i0 = pts[i][0];
		S64 i1 = pts[i][1];
		int best = N-1;
		for (int j = 0; j < N && best; ++j) {
			if (i == j)
				continue;
			S64 j0 = pts[j][0];
			S64 j1 = pts[j][1];
			int left = 0;
			int right = 0;
			S64 f0 = (j0 - i0);
			S64 f1 = (j1 - i1);
			for (int k = 0; k < N; ++k) {
				S64 det = f0*(pts[k][1] - i1) - f1*(pts[k][0] - i0);
				if (det < 0) {
					++left;
				} else if (det > 0) {
					++right;
				}
			}
			int v = MIN(right, left);
			if (v < best) {
				best = v;
			}
		}
		strcatf_s(buf, ARRAY_SIZE(buf), "%d\n", best);
	}
	buf[strlen(buf) - 1] = 0;
	return buf;
}

