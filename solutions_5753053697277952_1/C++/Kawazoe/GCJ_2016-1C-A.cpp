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

struct S {
	char c;
	s32 p;
};
bool operator < (const S &s1, const S &s2) {
	return s1.p < s2.p;
};

s32 N;
vector<S> P;

s64 Smart()
{
	return 0;
}
bool End() {
	FOR(i, 0, N) {
		if (P[i].p > 0) return false;
	}
	return true;
}

bool Check() {
	s32 sum = 0;
	FOR(i, 0, N) sum += P[i].p;
	FOR(i, 0, N) {
		if (2 * P[i].p > sum) return false;
	}
	return true;
}

s64 Naive()
{
	s32 m1, m2;
	while (true) {
		if (End()) break;
		sort(P.begin(), P.end());
		P[N - 1].p--;
		P[N - 2].p--;
		if (Check()) {
			cout << P[N - 1].c << P[N - 2].c << " ";
			continue;
		}
		P[N - 2].p++;
		if (Check()) {
			cout << P[N - 1].c << " ";
			continue;
		}
		cout << "!" << endl;
	}
	return 0;
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
		cin >> N;
		P.clear();
		FOR(i, 0, N) {
			S s;
			cin >> s.p;
			s.c = 'A' + i;
			P.push_back(s);
		}
		s64 ans = Naive();
		cout << endl;
	}

	return 0;
}
