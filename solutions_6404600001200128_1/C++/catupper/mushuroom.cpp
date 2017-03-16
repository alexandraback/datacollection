#include<iostream>
#include<algorithm>

using namespace std;

int a[108000];

void solve(){
	int n, resa = 0, resb = 0, mb = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 1;i < n;i++){
		if(a[i-1] > a[i])resa += a[i-1] - a[i];
		mb = max(mb, a[i-1] - a[i]);
	}
	for(int i = 1;i < n;i++){
		if(a[i-1] < mb)resb += a[i-1];
		else resb += mb; 
	}
	cout << resa << " " << resb;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}