#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		string inputs[100];
		char reduced_input[100][100];
		int count[100];
		int idx[100];
		
		int n;
		cin >> n;
		for(int j = 0; j < n; ++j) {
			idx[j] = 0;
			cin >> inputs[j];
			char temp = '\0';
			int c = 0;
			for(int k = 0; k < inputs[j].length(); ++k) {
				if(inputs[j][k] != temp) {
					reduced_input[j][c] = inputs[j][k];
					c++;
					temp = inputs[j][k];
				}
			}
			reduced_input[j][c] = '\0';
		}
		for(int j = 0; j < n; ++j) {
		//	cout << inputs[j] << "; " << reduced_input[j] << endl;
		}
		int j;
		for(j = 1; j < n && strcmp(reduced_input[j],reduced_input[0]) == 0; ++j)
			;
		if(j < n) {
			cout << "Case #" << i+1 << ": " << "Fegla Won" << endl;
			continue;
		}

		int ans = 0;
		for(j = 0; j < strlen(reduced_input[0]); ++j) {
			for(int k = 0; k < n; ++k) {
				count[k] = 0;
			}
			char cur_char = reduced_input[0][j];
			for(int k = 0; k < n; ++k) {
				while(inputs[k][idx[k]] == cur_char) {
					idx[k]++;
					count[k]++;
				}
			}
			sort(count, count+n);
			if(n % 2 == 1) {
				int mid = count[(n-1)/2];
				for(int k = 0; k < n; ++k) {
					ans += abs(count[k] - mid);
				}
			} else {
				int ans1 = 0;
				int ans2 = 0;
				int mid = count[n/2];
				for(int k = 0; k < n; ++k) {
					ans1 += abs(count[k] - mid);
				}
				mid = count[n/2 - 1];
				for(int k = 0; k < n; ++k) {
					ans2 += abs(count[k] - mid);
				}
				ans += max(ans1, ans2);
			}
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}