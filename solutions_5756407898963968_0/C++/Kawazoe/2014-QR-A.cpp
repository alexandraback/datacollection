#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "windows.h"
//#include "../../gmp_int.h"
//#include "../../common.h"
#define MAX(a, b)		((a)>(b)?(a):(b))
#define MAX3(a, b, c)	(MAX((a),MAX((b),(c))))
#define FOR(a,b,c)		for (s32(a)=(b);(a)<(s32)(c);(a)++)
#define BL				{char bl[10];cin.getline(bl, 10);}
#define GL(c)			cin.getline(c, sizeof(c))
typedef char					s8;
typedef unsigned char			u8;
typedef short					s16;
typedef unsigned short			u16;
typedef int						s32;
typedef unsigned int			u32;
typedef long long int			s64;
typedef unsigned long long int	u64;
using namespace std;

ifstream test_input;
#define cin test_input

void Smart()
{
}

void Naive()
{
    s32 a, c[4][4], b=0, m;
    vector<s32> v, u;
    cin >> a;
    FOR (i,0,4) FOR (j,0,4) cin >> c[i][j];
    FOR (i,0,4) v.push_back(c[a-1][i]);
    cin >> a;
    FOR (i,0,4) FOR (j,0,4) cin >> c[i][j];
    FOR (i,0,4) u.push_back(c[a-1][i]);
    FOR (i,0,4) FOR (j,0,4) if (v[i]==u[j]) { m = v[i]; b ++; }
    if (b == 1) cout << m;
    else if (b == 0) cout << "Volunteer cheated!";
    else cout << "Bad magician!";
}

int main(int argc, char* argv[])
{
	cout.precision(15);
	if (argc!=2) {
		cout << "Need input file name." << endl;
		return 0;
	}
	test_input.open(argv[1]);
	if (test_input.fail()) {
		cout << "Cannot open input file " << argv[1] << "." << endl;
		return 0;
	}

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
