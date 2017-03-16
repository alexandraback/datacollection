#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;

set<int> getCandidates() {
	int row;
	cin >> row;
	set<int> c;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int aux;
			cin >> aux;
			if (i == row) {
				c.insert(aux);
			}
		}
	}
	return c;
}

void solve() {
	set<int> s1 = getCandidates();
	set<int> s2 = getCandidates();
	set<int> ans;
	for(set<int>::iterator it=s1.begin(); it!=s1.end(); it++) {
		if (s2.count(*it)) {
			ans.insert(*it);
		}
	}
	if (ans.size() == 0) {
		cout << "Volunteer cheated!";
	} else if (ans.size() > 1) {
		cout << "Bad magician!";
	} else {
		cout << *ans.begin();
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
