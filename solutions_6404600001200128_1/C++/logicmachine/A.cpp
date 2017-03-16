#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){ cin >> a[i]; }
		int first = 0;
		for(int i = 1; i < n; ++i){
			if(a[i - 1] > a[i]){ first += a[i - 1] - a[i]; }
		}
		int maxdiff = 0, second = 0;
		for(int i = 1; i < n; ++i){
			if(a[i - 1] > a[i]){ maxdiff = max(maxdiff, a[i - 1] - a[i]); }
		}
		for(int i = 0; i + 1 < n; ++i){
			second += min(a[i], maxdiff);
		}
		cout << "Case #" << case_num << ": " << first << " " << second << endl;
	}
	return 0;
}

