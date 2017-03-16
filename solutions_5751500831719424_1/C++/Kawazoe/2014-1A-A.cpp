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
vector<string> s;
string ss, t;

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

void Smart()
{
    vector<vector<char>> x;
    vector<vector<s32>> v;
    FOR (i,0,N) {
        vector<char> tc;
        vector<s32> ts;
        x.push_back(tc);
        v.push_back(ts);
        Conv(s[i], x[i], v[i]);
    }
    FOR (i,1,x.size()) {
        if (x[0] != x[i]) {
            cout << "Fegla Won";
            return;
        }
    }
    s32 r=0;
    FOR (i,0,x[0].size()) {
        s32 a_min = INT_MAX, a_max = 0;
        FOR (j,0,N) {
            a_min = min(a_min, v[j][i]);
            a_max = max(a_max, v[j][i]);
        }
        s32 b_min = INT_MAX;
        FOR (a,a_min,a_max+1) {
            s32 b=0;
            FOR (j,0,N) b += abs(v[j][i] - a);
            b_min = min(b_min, b);
        }
        //cout << "!" << b_min << " ";
        r += b_min;
    }
    cout << r;
}

void Naive()
{
    vector<char> x, y;
    vector<s32> v, u;
    Conv(ss, x, v);
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
        cin >> N;
        s.clear();
        FOR (i,0,N) {
            string t;
            cin >> t;
            s.push_back(t);
        }
        Smart();
		cout << endl;
	}

	return 0;
}
