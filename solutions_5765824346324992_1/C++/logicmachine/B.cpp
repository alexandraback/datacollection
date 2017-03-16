#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

static inline ll solve(ll t, const vector<ll> &a){
	if(t < 0){ return 0; }
	const int m = a.size();
	ll sum = m;
	for(int i = 0; i < m; ++i){ sum += t / a[i]; }
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int m, n;
		cin >> m >> n;
		vector<ll> a(m);
		for(int i = 0; i < m; ++i){ cin >> a[i]; }
		ll left = 0, right = 1000000000000000000ll;
		while(left < right){
			const ll center = left + (right - left) / 2;
			if(solve(center, a) >= n){
				right = center;
			}else{
				left = center + 1;
			}
		}
		int answer = 0, count = n - solve(left - 1, a);
		for(int i = 0; i < m; ++i){
			if(left % a[i] == 0 && --count == 0){
				answer = i + 1;
				break;
			}
		}
		cout << "Case #" << case_num << ": " << answer << endl;
	}
	return 0;
}

