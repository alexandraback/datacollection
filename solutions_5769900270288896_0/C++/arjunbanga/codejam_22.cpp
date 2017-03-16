#include<bits/stdc++.h>
using namespace std;
int arr[20][20];
int r,c;

int ans = 100000000;
int calc()
{
	int ret = 0;
	for(int i =0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(arr[i][j] == 1) {
				if(i+1 < r) ret += (arr[i+1][j] == 1);
				if(j+1 < c) ret += (arr[i][j+1]==1);	
			}	
		}
	}
	return ret;
}
			
void func(int i, int n)
{
	if(i == r*c) {
		if(n!=0) return;
		ans = min(ans, calc());
		return;
	}
	arr[i/c][i%c] = 0;
	func(i+1, n);
	if(n > 0) {
		arr[i/c][i%c] = 1;
		func(i+1, n-1);
	}
	return;
}
	
	
int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int ca = 1; ca <= t; ca++) {
		int n;
		ans = 100000000;
		cin>>r>>c>>n;
		func(0, n);
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	return 0;
}
