#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;


int n;
string s[MAX_N];
int index[MAX_N];

bool finished(int sNr) {
	return index[sNr] == s[sNr].length();
}

int getChar(int sNr, char &c) {
	if (index[sNr] == s[sNr].length())
		return -1;
	c = s[sNr][index[sNr]];
	int count = 0;
	while (index[sNr] < s[sNr].length() && s[sNr][index[sNr]] == c) {
		index[sNr]++;
		count++;
	}
	return count;
}

int solve() {
	for (int i = 0; i < n; ++i)
		index[i] = 0;
	int moves = 0;
	while (!finished(0)) {
		vector<int> pos;

		char letter;
		int count;
		count = getChar(0, letter);
		//cout << "char " << letter << endl;
		//cout << count;
		pos.push_back(count);
		for (int i = 1; i < n; ++i) {
			char cLetter;
			int cCount = getChar(i, cLetter);
			if (cLetter != letter)
				return -1;
			pos.push_back(cCount);
			//cout << " " << cCount;
			
		}
		sort(pos.begin(), pos.end());
		int middle = pos[n / 2];
		for (int i = 0; i < n; ++i) {
			moves += abs(middle - pos[i]);
			//cout << pos[i] << " ";
		}
		//cout << endl;
	}
	
	for (int i = 1; i < n; ++i)
		if (!finished(i))
			return -1;
	return moves;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> s[j];
		int a = solve();
		cout << "Case #" << i << ": ";
		if (a == -1)
			cout << "Fegla Won";
		else
			cout << a;
		cout << endl;
	}
}
