#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;


Int m[1080];

Int cnt(Int x, Int b){
	Int res = 0;
	for(Int i = 0;i < b;i++){
		res += x / m[i];
		if(x % m[i] != 0)res++;
	}
	return res;
}

void solve(){
	vector<Int> ans;
	Int b, n;
	cin >> b >> n;
	for(Int i = 0;i < b;i++){
		cin >> m[i];
	}
	Int bottom = 0, top = 1LL << 60;
	while(top - bottom > 1){
		Int mid = (top + bottom) / 2;
		if(n <= cnt(mid, b))top = mid;
		else bottom = mid;
	}
	Int tmp = cnt(bottom, b);
	for(Int i = 0;i < b;i++){
		if(bottom % m[i] == 0)ans.push_back(i);
	}	
	cout << ans[n - tmp - 1] + 1;
}

int main(){
	Int t;
	cin >> t;
	for(Int i = 1;i <= t;i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
