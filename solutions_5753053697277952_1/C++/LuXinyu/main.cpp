#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

int t;
int n;
int arr[26];

void clear() {
	memset(arr, 0, sizeof(arr));
}

string find_next() {
	int fst = -1, snd = -1;
	int fval = 0, sval = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > fval) {
			sval = fval;
			snd = fst;
			fval = arr[i];
			fst = i;
		}
		else if (arr[i] > sval) {
			sval = arr[i];
			snd = i;
		}
	}
	//cout << "fst: " << fst << ", snd: " << snd << endl;
	string ret = "";
	if (fst >= 0) {
		char c = 'A' + fst;
		ret += c;
		arr[fst]--;
		//cout << "append " << c << endl;
		if (snd >= 0) {
			c = 'A' + snd;
			ret += c;
			arr[snd]--;
			//cout << "append " << c << endl;
		}
	}
	//cout << "ret : " << ret << endl;
	return ret;
}

int main() {
	ifstream fin("A-large.in", ifstream::in);  // TODO
	ofstream fout("result.out", ofstream::out);
	fin >> t;
	//cin >> t;
	for (int i = 0; i < t; ++i) {
		clear();
		//cin >> n;
		fin >> n;
		int p;
		for (int j = 0; j < n; ++j) {
			//cin >> p;
			fin >> p;
			arr[j] = p;
			//cout << "arr " << j << " assign to " << p << endl;
		}
		vector<string> res;
		string s = find_next();
		while (s.size() != 0) {
			res.push_back(s);
			s = find_next();
		}

		cout << "Case #" << (i + 1) << ": ";
		fout << "Case #" << (i + 1) << ": ";
		for (int j = res.size() - 1; j >= 0; --j) {
			cout << res[j] << " ";
			fout << res[j] << " ";
		}
		cout << endl;
		fout << endl;
	}
	return 0;
}
