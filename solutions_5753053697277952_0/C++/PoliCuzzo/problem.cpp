#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<int> p(N, 0);

		int sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> p[i];
			sum += p[i];
		}

		cout << "Case #" << t << ": ";

		while(true) {
			int out1 = -1, out2 = -1;
			auto max = max_element(p.begin(), p.end());
			if(*max == 0) break;

			(*max)--;
			out1 = max - p.begin();
			sum--;
			
			max = max_element(p.begin(), p.end());
			(*max)--;
			out2 = max - p.begin();
			sum--;
			auto max2 = max_element(p.begin(), p.end());
			if(sum - *max2 < *max2) {
				(*max)++;
				sum++;
				out2 = -1;
			}

			cout << static_cast<char>('A' + out1);
			if(out2 != -1) cout << static_cast<char>('A' + out2);
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}