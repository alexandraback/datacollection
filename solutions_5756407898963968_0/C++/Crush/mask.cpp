#pragma warning(disable:4786)

#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <sstream>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
typedef pair<int,int> PII;
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz size()

ifstream ifs;
ofstream ofs;

typedef long long ll;

void testcase(int tst)
{
	int r1, r2;
	ifs >> r1;

	VVI a1(4, VI(4, 0)), a2(4, VI(4, 0));

	REP(j, 4)
		REP(i, 4)
			ifs >> a1[j][i];

	ifs >> r2;

	REP(j, 4)
		REP(i, 4)
			ifs >> a2[j][i];

	VI b(17, 0);
	REP(i, 4) {
		b[a1[r1-1][i]]++;
		b[a2[r2-1][i]]++;
	}

	int res = -1;
	int cnt = 0;
	REP(i, 17)
		if (b[i] > 1) {
			cnt++;
			res = i;
		}
	

	if (cnt > 1) {
		ofs << "Case #" << tst+1 << ": " << "Bad magician!" << endl;
	} else {
		if (cnt == 1)
			ofs << "Case #" << tst+1 << ": " << res << endl;
		else
			ofs << "Case #" << tst+1 << ": " << "Volunteer cheated!" << endl;
	}
}

int main()
{
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	int t;
	ifs >> t;
	REP(tn, t)
	{
		testcase(tn);
	}

	return 0;
} 
