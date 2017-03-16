#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

long long getMoves(MI &counts) {
	long long res = 0;
	for(int i = 0; i < counts[0].size(); ++i) {
		long long mmax = 0;
		for(int j = 0; j < counts.size(); ++j) {
			mmax = max((long long)counts[j][i], mmax);
		}
		long long min = -1;
		for(long long k = 1; k <= mmax; ++k) {
			long long rres = 0;
			for(int j = 0; j < counts.size(); ++j) {
				rres += abs(counts[j][i]-k);
			}
			if(min == -1 or min > rres) min = rres;
		}
		if(min != -1) res += min;
	}
	return res;
}

VI getCounts(string &s) {
	VI res;
	char c = s[0];
	int count = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] != c) {
			c = s[i];
			res.push_back(count);
			count = 1;
		} else {
			count++;
		}
	}
	res.push_back(count);
	return res;
}

string minify(string &s) {
	char c = s[0];
	string res = "";
	res.push_back(c);
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] != c) {
			c = s[i];
			res.push_back(c);
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for(int tcas = 0; tcas < t; ++tcas) {
		int n;
		cin >> n;
		string s, mins;
		cin >> s;
		mins = minify(s);
		bool fail = false;
		MI counts;
		counts.push_back(getCounts(s));
		for(int i = 1; i < n; ++i) {
			string ns;
			cin >> ns;
			if(mins != minify(ns)) fail = true;
			else {
				counts.push_back(getCounts(ns));
			}
		}
		cout << "Case #" << tcas+1 << ": ";
		if(fail) {
			cout << "Fegla Won";
		} else {
			cout << getMoves(counts);
		}
		cout << endl;
	}
}