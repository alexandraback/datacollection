#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Google Code Jam 2015 Round 1A, Problem B code.google.com/codejam
//Disable warning messages C4996.
#pragma warning(disable:4996)

#define INPUT_FROM 0
#if INPUT_FROM
#define fromc from
#else
#define fromc cin
#endif


long long gcd(long long n, long long m);
//long long fr(vector<long long>&, long long);

int main(int argc, char **argv)
{
	//ifstream from;
	const int nmin=1, nmax=1000, INF = (1LL<<31) - 1;
	//const long double pi = acos(-1.0);
	int test, cases, n, m, mt, res, rt, i, j, k, t, ax, r, q;
	int r0, r1, bx, d;
	long long dd, qq;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<int> v, vt;
	//vector<string> vs0, vs1, vs;
	deque<int> dq;
	set<int, int> ss;
	set<int, int>::iterator it;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;
	pair<int, int> pr;

	scanf("%d\n", &cases);
	//fromc>>cases;
	for(int test=1;test<=cases;++test){
		scanf("%d %d\n", &n, &m);
		v.resize(n);

		for(int i=0;i<n;++i) scanf("%d", &v[i]);
		
		dd = 1;
		for(int i=0;i<n;++i){
			rt = gcd(dd, v[i]);
			dd = (dd*v[i])/rt;
		}

		qq = 0;
		for(int i=0;i<n;++i){
			qq += dd/v[i];
		}

		if(1LL*m > qq){
			rt = m/qq;
			m -= qq*rt;
		}

		//cout << qq << endl;

		if(m == 0) m = qq;

		vt.resize(n,0);
		q = 0;
		while(q < m){
			for(j=0;(j<n)&&(q < m);++j){
				if(vt[j] == 0){
					vt[j] = v[j] - 1, ++q;
					//cout << j + 1 << endl;
				}else --vt[j];
			}
			if(q == m) r = j;
		}

		printf("Case #%d: %d\n", test, r);
		//cout << "Case #" << test << ": " << r0 <<' ' << r1 <<endl;
		//else cout<<"Case #"<<test<<": "<<r<<endl;

		//cout.setf(ios::fixed);
		//cout.precision(6);
		//cout<<"Case #"<<test<<": "<<res<<endl;

		vt.clear();
		v.clear();
	}

	return 0;
}

long long gcd(long long n, long long m){
	long long r1, r2, r, res;
	if(n < 0) n = -n;
	if(m < 0) m = -m;
	if(n == 0) res = m;
	else if(m == 0) res = n;
	else{
		if(n < m) swap(n, m);
		r1 = n;
		r2 = m;
		r = r1%r2;
		while(r > 0){
			r1 = r2;
			r2 = r;
			r = r1%r2;
		}
		res = r2;
	}
	return res;
}