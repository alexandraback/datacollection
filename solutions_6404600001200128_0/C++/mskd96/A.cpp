#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, final;
	cin >> T;
	final = T;
	while(T>0) {
		T--;
		int N;
		cin >> N;
		std::vector<int> num;
		int prev;
		int ans1 = 0, ans2 = 0;
		int max=0;
		for (int i = 0; i < N; ++i)
		{
			int temp;
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
		for (int i = 0; i < N-1; ++i)
		{
			if(num[i]<=max) 
				ans2+=num[i];
			else 
				ans2+=max;
		}

		cout << "Case #" << final-T << ": " << ans1 << " " << ans2 << endl;
	}
}