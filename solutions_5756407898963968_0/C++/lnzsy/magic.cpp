#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

int A[4][4];
int B[4][4];

int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		int a, b;
		fscanf (fin, "%d", &a);
		REP (j, 0, 4) REP (k, 0, 4) { int tmp; fscanf (fin, "%d", &tmp); A[j][k]=tmp; }
		fscanf (fin, "%d", &b);
		REP (j, 0, 4) REP (k, 0, 4) { int tmp; fscanf (fin, "%d", &tmp); B[j][k]=tmp; }

		int num=0;
		int card=0;
		REP (j, 0, 4) REP (k, 0, 4) {
//			cout << A[a][j] << " " << B[b][k] << endl;
			if (A[a-1][j] == B[b-1][k]) {
				++num;
				card = A[a-1][j];
			}
		}
		if (num == 0) {
			fprintf (fout, "Case #%i: Volunteer cheated!\n", i+1);
		} else if (num == 1) {
			fprintf (fout, "Case #%i: %d\n", i+1, card);
		} else {
			fprintf (fout, "Case #%i: Bad magician!\n", i+1);
		}
	}

	return 0;
}






