#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int count(string s, int c, int startInd) {
	int ind = startInd;
	while (ind < s.size() && s[ind] == c) ind++;
	return ind - startInd;
}

int match(vector<int>& len, int num) {
	int count = 0;
	for(int i = 0; i < len.size(); i++) {
		count += abs(len[i] - num);
	}
	return count;
}

int minel(vector<int>& vec) {
	int m = vec[0];
	for(int i = 0; i < vec.size(); i++) m = min(m, vec[i]);
	return m;
}

int maxel(vector<int>& vec) {
	int min = vec[0];
	for(int i = 0; i < vec.size(); i++) min = max(min, vec[i]);
	return min;
}

int closestMatch(vector<int>& len) {
	int minimum = minel(len);
	int maximum = maxel(len);
	int bestMatch = match(len, minimum);
	for(int i = minimum; i <= maximum; i++) {
		bestMatch = min(match(len,i), bestMatch);
	}
	return bestMatch;
}

void doit() {
	int N;
	cin >> N;
	vector<string> strs;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		strs.push_back(s);
	}
	vector<int> inds;
	vector<int> len;
	for (int i = 0; i < N; i++) {
		inds.push_back(0);
		len.push_back(0);
	}
	int sum = 0;
	int c;
	while (inds[0] < strs[0].length()) {
		c = strs[0][inds[0]];
		for (int i = 0; i < N; i++) {
			len[i] = count(strs[i], c, inds[i]);
			if(len[i] == 0) {
				cout << "Fegla Won" << endl;
				cerr << (char) c << endl << i << endl << strs[i] << endl;
				return;
			}
			inds[i] += len[i];
		}
		sum += closestMatch(len);
	}
	for (int i = 0; i < N; i++) {
		if(inds[i] != strs[i].size()) {
			cout << "Fegla Won" << endl;
			return;
		}
	}
	cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        doit();
    }
}
