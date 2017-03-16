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

s32 N;
string s,t;

void Smart()
{
}

void Conv(string &x, vector<char> &v, vector<s32> &u) {
    char c=x[0];
    s32 k=1;
    FOR (i,1,x.size()) {
        if (c != x[i]) {
            v.push_back(c);
            u.push_back(k);
            c = x[i];
            k = 1;
        } else {
            k ++;
        }
    }
    v.push_back(c);
    u.push_back(k);
}

void Naive()
{
    vector<char> x, y;
    vector<s32> v, u;
    Conv(s, x, v);
    Conv(t, y, u);
    if (x != y) {
        cout << "Fegla Won";
        return;
    }
    s32 a=0;
    FOR (i,0,x.size()) {
        a += abs(v[i]-u[i]);
    }
    cout << a;
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
        cin >> N >> s >> t;
		Naive();
		cout << endl;
	}

	return 0;
}
