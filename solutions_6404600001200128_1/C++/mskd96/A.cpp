#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int T, final;
	cin >> T;
	final = T;
	while(T>0) {
		T--;
		long long int N;
		cin >> N;
		std::vector<long long int> num;
		long long int prev;
		long long int ans1 = 0, ans2 = 0;
		long long int max=0;
		for (long long int i = 0; i < N; ++i)
		{
			long long int temp;
			cin >> temp;
			num.push_back(temp);
			if(i!=0) {
				if(temp - prev < 0) {
					ans1 += prev - temp;
					if(prev - temp > max) max = prev - temp;
				}
			}
			prev = temp;
		}
		// cout << max << endl;
		for (long long int i = 0; i < N-1; ++i)
		{
			if(num[i]<=max) 
				ans2+=num[i];
			else 
				ans2+=max;
		}

		cout << "Case #" << final-T << ": " << ans1 << " " << ans2 << endl;
	}
}