#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int t;
	cin >> t;
	for (int casei = 1; casei <= t; casei++) {
		long n;
		cin >> n;
		pair<long, char> data[26];
		long temp;
		long total = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			data[i] = make_pair (temp, (char)('A'+i));
			total += temp;
		}
		cout << "Case #" << casei << ": ";
		long max = 0, index = 0;
		for (int i = 0; i < n; i++) {
			if (data[i].first > max) {
				max = data[i].first;
				index = i;
			}
		}
		while (max > 1) {
			cout << data[index].second;
			data[index].first--;
			for (int i = 0; i < n; i++) {
				if (data[i].first == max) {
					cout << data[i].second;
					data[i].first--;
					break;
				}
			}
			cout << " ";
			max = 0;
			for (int i = 0; i < n; i++) {
				if (data[i].first > max) {
					max = data[i].first;
					index = i;
				}
			}
		}
		if (n % 2) {
			cout << data[0].second << " ";
			for (int i = 1; i < n; i += 2) {
				cout << data[i].second << data[i+1].second << " ";	
			}
		} else {
			for (int i = 0; i < n; i += 2) {
				cout << data[i].second << data[i+1].second << " ";	
			}
		}
		cout << endl;
	}
	return 0;
}