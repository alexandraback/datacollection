#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	freopen("A-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++){
		long long n, m[12345];
		cin >> n;

		long long method1 = 0, method2 = 0, method2ans = 0;
		for (int i = 0; i < n; i++){
			cin >> m[i];
			if (i)method1 += max((long long) 0, m[i - 1] - m[i]);
			if (i)method2 = max (max((long long)0, m[i - 1] - m[i]), method2 );
		}

		for (int i = 0; i < n - 1; i++){
			method2ans += min(method2, m[i]);
		}

		cout << "Case #" << t << ": " << method1 << " " << method2ans << endl;
	}




}




