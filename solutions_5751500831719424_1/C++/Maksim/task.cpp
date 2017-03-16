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

const int MAX_N = 110;
const int MAX_L = 110;
string a[MAX_N];
int b[MAX_N][MAX_L];

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

void FillB(const int n){
	FOR(i, MAX_N) FOR(j, MAX_L) b[i][j] = 0;

	FOR(i, n){
		const string& s = a[i];
		const int len = s.size();
		int k = 0;
		for(int j = 1; j < len; ++j){
			if(s[j]!=s[j-1]) k++;
			if(s[j]==s[j-1]) b[i][k]++;
		}
	}

	//FOR(i,n){FOR(j, 5) cout << b[i][j]; cout << endl;}
}

void Do(const int n){
	long long res = 0;
	FOR(j, MAX_L){
		vector<int> v(n);
		FOR(i, n) v[i] = b[i][j];
		sort(v.begin(), v.end());
		int mn = v.front();
		int mx = v.back();

		int mn_sum = -1;
		for(int k = mn; k <= mx; ++k){
			int sum = 0;
			for(int t = 0; t < v.size(); ++t){
				sum += abs(k - v[t]);
			}
			if(mn_sum == -1){
				mn_sum = sum;
			}
			mn_sum = min(mn_sum, sum);
		}
		res += mn_sum;
	}
	cout << res;
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

	FillB(n);
	Do(n);

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
