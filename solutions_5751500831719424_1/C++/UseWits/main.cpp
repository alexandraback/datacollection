#include <iostream>
#include <string>
#include <vector>

using namespace std;

void run() {
	int n;
	cin >> n;
	vector<string> s;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	int result=0;
	while(s[0].size() > 0) {
		vector<int> numFreqs=vector<int>(102,0);
		
		char chr=s[0].back();
		for(int i=0; i<n; i++) {
			int c=0;
			if(s[i].size() == 0) {
				cout << "Fegla Won" << endl;
				return;
			}
			if(s[i].back() != chr) {
				cout << "Fegla Won" << endl;
				return;
			}
			for(int j=s[i].size()-1; j>=0; j--, c++) {
				if(chr != s[i][j]) break;
				s[i].pop_back();
			}
			numFreqs[c]++;
		}

		int bestcur=-1;
		for(int target=1; target <= 101; target++) {
			int cur=0;
			for(int i=0; i<=101; i++) {
				cur+=abs(target-i)*numFreqs[i];
			}
			if(bestcur == -1 || cur < bestcur)
				bestcur=cur;
		}
		result+=bestcur;
	}

	for(int i=0; i<n; i++)
		if(s[i].size() != 0) {
			cout << "Fegla Won" << endl;
			return;
		}
	cout << result << endl;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << "Case #" << (i+1) << ": ";
		run();
	}
}