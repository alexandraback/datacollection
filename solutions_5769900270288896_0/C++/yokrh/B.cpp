#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using P = complex<int>;


int calc(vector<int> aa, int r, int c){
	vector<vector<int>> a(r, vector<int>(c));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j] = aa[i*c+j];
		}
	}
	int res = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j] == 0) continue;
			if(j+1 < c && a[i][j+1] == 1) res++;
			if(i+1 < r && a[i+1][j] == 1) res++;
		}
	}
	return res;
}

void dfs(int i, vector<int> a, int n, int r, int c, int k, int& ans){
	if(i == n){
		int sum = 0;
		for(int i=0;i<n;i++) sum += a[i];
		if(sum != k) return;

		ans = min(ans, calc(a, r, c));
		return;
	}
	dfs(i+1, a, n, r, c, k, ans);
	a[i] = 1;
	dfs(i+1, a, n, r, c, k, ans);
}

bool solve(){
	ll r, c, k;
	cin>> r>> c>> k;
	//cerr<< r<< " "<< c<< " "<< k<< endl;
	if(k == 0){
		cout<< 0<< endl;
		return true;
	}

	int ans = 1010;
	int n = r * c;
	vector<int> a(n);
	dfs(0, a, n, r, c, k, ans);

	cout<< ans<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed); cout.precision(10);
	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		cout<< "Case #"<< i+1<< ": ";
		solve();
	}
	return 0;
}
