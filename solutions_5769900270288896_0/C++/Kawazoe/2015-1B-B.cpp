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

s64 R, C, N;

void Smart()
{
}

void Naive()
{
	bool b[20][20];
	s32 c_min = 10000000;
	for (s64 k = 0; k < (1LL << R*C); k++) {
		s32 n = 0;
		FOR(i, 0, R*C) {
			if (k&(1LL << i)) n++;
		}
		if (n != N) continue;
		memset(b, 0, 20 * 20);
		FOR(i, 0, R*C) {
			s32 x = i%C, y = i/C;
			b[x][y] = k&(1LL << i) ? true : false;
		}
		//FOR(y, 0, R) {
		//	FOR(x, 0, C) cout << b[x][y] ? "O" : ".";
		//	cout << endl;
		//}
		//cout << endl;
		s32 c = 0;
		FOR(x, 0, C - 1) FOR(y, 0, R) {
			if (b[x][y] && b[x + 1][y]) c++;
		}
		FOR(x, 0, C) FOR(y, 0, R - 1) {
			if (b[x][y] && b[x][y + 1]) c++;
		}
		c_min = min(c_min, c);
	}
	cout << c_min;
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
		cin >> R >> C >> N;
		Naive();
		cout << endl;
	}

	return 0;
}
