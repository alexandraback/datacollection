#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

const int MAX_N = 200;
string a[MAX_N];

string Minimize(const string& s, int& steps){
	string r;
	const int n = s.size();
	r += s[0];
	for(int i = 1; i < n; ++i){
		string::const_iterator e = r.end();
		--e;
		if(*e != s[i]){
			r += s[i];
		}else{
			steps++;
		}
	}
	return r;
}

string Minimize(const string& s){
	int steps = 0;
	return Minimize(s, steps);
}


bool IsPossible(const int n){
	string mn = Minimize(a[0]);
	FOR(i, n) if(mn != Minimize(a[i])) return false;
	return true;
}

int Comp2(const string& s1, const string& s2){
	const int n1 = s1.size();
	const int n2 = s2.size();
	char prev = s1[0];
	int res = 0;
	int i1=1, i2=1;
	for(; i1<n1 && i2<n2;){
		if(s1[i1]==s2[i2]){
			prev = s1[i1];
			i1++;
			i2++;
		}else{
			if(s1[i1]==prev){
				i1++;
			}else{
				i2++;
			}
			res++;
		}
	}
	res += n1-i1;
	res += n2-i2;
	return res;
}

void Solve()
{
	int n; cin >> n;
	FOR(i, n) cin >> a[i];

	if(!IsPossible(n)){
		cout << "Fegla Won";
		return;
	}

	//cout << n << endl;
	if(n==2){
		cout << Comp2(a[0], a[1]);
		return;
	}

	return;
}

int main()
{
	int n; cin >> n;
	FOR(t, n){
		cout << "Case #" << t+1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}
