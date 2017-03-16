#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef pair<int, char> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int loop = 1; loop <= T; loop++) {
		cout << "Case #" << loop << ": ";
		int N;
		cin >> N;
		vector<P> v(N);
		int sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> v[i].first;
			sum += v[i].first;
			v[i].second = 'A' + i;
		}

		sort(v.begin(), v.end());
		if(sum % 2) {
			cout << v.back().second << " ";
			v.back().first--;
			sum--;
		}

		while(sum) {
			sort(v.begin(), v.end());
			cout << v.back().second;
			v.back().first--;
			sort(v.begin(), v.end());
			cout << v.back().second << " ";
			v.back().first--;
			sum -= 2;
		}
		cout << endl;
	}

}