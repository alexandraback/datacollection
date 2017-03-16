#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int a[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(a, 0, sizeof(a));
		int N, sum = 0; cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
			sum += a[i];
		}
		string s = "";
		while(sum > 0) {
			s += " ";
			int mx = -1, mxi = 0;
			for (int i = 0; i < N; i++) {
				if (a[i] > mx) {
					mxi = i;
					mx = a[i];
				}
			}
			s += string(1, 'A' + mxi);
			a[mxi]--; sum--;
            
			for (int i = 0; i < N; i++) {
				if (a[i] > sum/2) {
					s += string(1, 'A'+i);
					a[i]--; sum--;
					break;
				}
			}
		}
		cout << "Case #"<< t <<":" << s << "\n";
	}

	return 0;
}
