#include <bits/stdc++.h>

using namespace std;

int J, P, S, K;
bool b[5][5][5];
struct Result{
	int i, j, k;
	Result(int i, int j, int k) : i(i), j(j), k(k) {}	
};
bool found;
int cntA[5][5], cntB[5][5], cntC[5][5];
list<Result> cur, best;

void solve(){
	int n; cin >> n;	
	vector<int> cur;
	vector<char> res;
	for(int i = 0; i < n; ++i){
		int k; cin >> k;
		while (k--) res.push_back('A' + i);
	}
	
	if (res.size()%2 == 1){
		cout << res.back() << " ";
		res.pop_back();
	}
	
	for(int i = 0, j = res.size()/2; j < (int)res.size(); i++, j++){
		cout << res[i] << res[j] << " ";
	}
	cout << endl;
		
		
}

int main(){
	int test; cin >> test;
	for(int t = 1; t<= test; ++t){
		printf("Case #%d: ", t);
		solve();
	}
	
}