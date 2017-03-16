#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Google Code Jam 2015 Round 1A, Problem A code.google.com/codejam
//Disable warning messages C4996.
#pragma warning(disable:4996)

#define INPUT_FROM 0
#if INPUT_FROM
#define fromc from
#else
#define fromc cin
#endif



//long long fr(vector<long long>&, long long);

int main(int argc, char **argv)
{
	//ifstream from;
	const int nmin=1, nmax=1000, INF = (1LL<<31) - 1;
	//const long double pi = acos(-1.0);
	int test, cases, n, m, mt, res, rt, i, j, k, t, ax, r, q;
	int r0, r1, bx;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<int> v;
	//vector<string> vs0, vs1, vs;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	scanf("%d\n", &cases);
	//fromc>>cases;
	for(int test=1;test<=cases;++test){
		scanf("%d\n", &n);
		v.resize(n);

		for(int i=0;i<n;++i) scanf("%d", &v[i]);
		
		r0 = 0;
		for(int i=1;i<n;++i){
			rt = v[i-1] - v[i];
			if(rt > 0) r0 += rt;
		}

		ax = 0;
		for(int i=1;i<n;++i){
			rt = v[i-1] - v[i];
			if((rt > 0)&&(ax < rt)) ax = rt;
		}
		r1 = 0;
		for(int i=1;i<n;++i){
			rt = v[i-1];
			r1 += (rt > ax) ? ax : rt;
		}

		printf("Case #%d: %d %d\n", test, r0, r1);
		//cout << "Case #" << test << ": " << r0 <<' ' << r1 <<endl;
		//else cout<<"Case #"<<test<<": "<<r<<endl;

		//cout.setf(ios::fixed);
		//cout.precision(6);
		//cout<<"Case #"<<test<<": "<<res<<endl;

		v.clear();
	}

	return 0;
}

