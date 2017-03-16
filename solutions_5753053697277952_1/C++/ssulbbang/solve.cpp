#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++) {
		int n;
		vector<int> count;
		int total = 0;
		cin >> n;
		count.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> count[i];
			total += count[i];
		}
		cout << "Case #" << iter + 1 << ": ";
		while(total > 0) {
			if(total == 2) {
				for(int i = 0; i < n; i++) {
					if(count[i] > 0) {
						cout << (char)('A' + i);
						count[i]--;
					}
				}
				total -= 2;
			} else {
				int max = 0;
				int max_count = 0;
				for(int i = 0; i < n; i++) {
					if(max < count[i]) {
						max = count[i];
						max_count = 1;
					} else if(max == count[i]) {
						max_count++;
					}
				}


				int removed = 0;
				for(int i = 0; i < n; i++) {
					if(max == count[i]) {
						cout << (char)('A' + i);
						removed++;
						count[i]--;
						total--;
						if(max_count > 2 || removed >= 2) break;
					}
				}
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
