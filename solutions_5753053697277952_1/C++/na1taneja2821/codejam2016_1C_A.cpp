#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	int run;
	for(run = 1; run <= t; run++) {
		int n;
		cin >> n;
		int i;
		vector<int> input;
		int cnt = 0;
		for(i = 0; i < n; i++) {
			int x;
			cin >> x;
			input.push_back(x);
			cnt += x;
		}
		cout << "Case #" << run << ": ";
		while(cnt) {
			int maxim = INT_MIN;
			vector<int> indices;
			for(i = 0; i < input.size(); i++) {
				if(maxim < input[i]) {
					indices.clear();
					maxim = max(maxim, input[i]);
					indices.push_back(i);
				} else if(maxim == input[i]) {
 					indices.push_back(i);
				}
			}
			if(maxim != 1) {
				if(indices.size() == 1) {
					cnt -= 1;
					input[indices[0]]--;
					char ch = 'A' + indices[0];
					cout << ch << " ";
				} else if (indices.size() >= 2) {
					cnt -= 2;
					input[indices[0]]--;
					input[indices[1]]--;
					char ch = 'A' + indices[0];
					char ch1 = 'A' + indices[1];
					cout << ch << ch1 << " ";
				}	
			} else {
				cnt = 0;
				if(indices.size() % 2 == 0) {
					for(i = 0; i < indices.size(); i += 2) {
						char ch = 'A' + indices[i];
						char ch1 = 'A' + indices[i + 1];
						cout << ch << ch1 << " ";
					}
				} else {
					char ch = 'A' + indices[0];
					cout << ch << " ";
					for(i = 1; i < indices.size(); i += 2) {
						char ch = 'A' + indices[i];
						char ch1 = 'A' + indices[i + 1];
						cout << ch << ch1 << " ";
					}
				}
			}
			
		}
		cout << endl;
	}
	return 0;
}