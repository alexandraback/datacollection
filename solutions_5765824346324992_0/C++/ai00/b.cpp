#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n;
int m;
long long a[1001];
long long gao(long long t){
	long long ret = 0;
	//cout<<t<<' '<<m<<endl;
	for (int i = 0; i < m; ++i)
		ret += t / a[i] + 1;
	return ret;
}
int gao(){
	long long s = 0, t = 1e14;
	//cout<<s<<' '<<t<<endl;
	long long h = t;
	while (s <= t){
		long long mid = (s + t) / 2;
		long long cnt = gao(mid);
		//cout<<' '<<mid<<' '<<cnt<<endl;
		if (cnt >= n){
			h = min(h, mid);
			t = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	long long cnt = gao(h);
	for (int i = m - 1; i >= 0; --i)
		if (h % a[i] == 0){
			if (cnt == n) return i + 1;
			--cnt;
		}
}
int main(){
	int t = 0, tt;
	for (scanf("%d ", &tt); t < tt; ++t){
		cin>>m>>n;
		for (int i = 0; i < m; ++i)
			cin>>a[i];
		cout<<"Case #"<<t + 1<<": "<<gao()<<endl;
	}
}