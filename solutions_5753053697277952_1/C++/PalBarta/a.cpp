#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <queue>
#include <map>
using namespace std;

vector<int> a(100000);

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		// Problem starts here
		int N, sum = 0	;
		cin >> N;

		for (int i=0; i < N; i++) {
			cin >> a[i];
			sum += a[i];
		} 

		while (sum > 0) {
			int num = sum % 2 == 0 ? 2 : 1;
			for (int m=0; m < num; m++) {
				int maxi = -1;
				int maxn = -1;
				for (int i=0; i < N; i++) {
					if (a[i] > maxn) {
						maxn = a[i];
						maxi = i;
					}
				}
				a[maxi]--;	
				sum--;
				char c = 'A' + maxi;
				cout << c;
			}
			cout << ' ';
		}


		// Problem ends here
		cout << endl;
	}

	return 0;
}