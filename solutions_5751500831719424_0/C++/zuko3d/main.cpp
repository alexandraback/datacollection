#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

string del_eq(const string &str){
	string ret;
	ret = "";
	ret.reserve(str.size());
	REP(i, str.size() - 1){
		if(str[i] != str[i+1]){
			ret += str[i];
		}
	} 
	ret += str[str.size() - 1];
	return ret;
}

int strip(string &str){
	int i;
	i=1;
	while(i < str.size()){
		if(str[i] != str[i-1]){
			break;
		}
		i++;
	}
	str.erase(0,i);

	return i;
}

double round(double x){
	double y;
	y = x - floor(x);
	if(y >= 0.5) return floor(x) + 1.0;
	return floor(x);
}

int main(void){
	int T, N;
	vector<string> s, ns;
	vector<int> shift;
	int actions;
	int avg, cur;

	ifstream fin("A-small-attempt0 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		
		fin >> N;
		s.resize(N);
		ns.resize(N);
		shift.resize(N);

		REP(i,N) {
			fin >> s[i];
			ns[i] = del_eq(s[i]);
		}
		int good;
		good = 1;
		REP(i, N-1){
			if(ns[i] != ns[i+1]){
				good = 0;
				break;
			}
		}
		if(!good) {
			fout << "Fegla Won\n";
			continue;
		}
		
		actions = 0;
		while(s[0].size() > 0){
			cur = 0;
			REP(i, N){
				shift[i] = strip(s[i]);
				cur += shift[i];
			}
			avg = (int) round ((double) cur / (double) N);

			REP(i, N){
				actions += abs(avg - shift[i]);
			}
		}

		fout << actions << endl;
	}

	fout.close();
	return 0;
}
