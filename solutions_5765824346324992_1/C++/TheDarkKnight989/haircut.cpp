#include<stdio.h>
#include<string.h>
#include<iostream>
#define N 1500
#define ll long long
using namespace std;
int b , m[N + 20];
long long cal(long long t){
	if(t < 0) return 0;
	long long res = 0;
	for(int i = 1 ; i <= b ; i++)	res+=(t / m[i] + 1);
	return res;
}
long long n;
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	cin>>T;
	for(int c = 1 ; c <= T ; c++){
		cin>>b>>n;
		for(int i = 1 ; i <= b ; i++)	cin>>m[i];
		long long lo = 0;
		long long hi = 5*1e14;
		while(lo < hi){
			long long mid = (lo + hi)/2;
			if(cal(mid) >= n) hi = mid;
			else lo = mid + 1;
		}
		long long t = lo;
		long long pos = n - cal(t - 1);
		long long cnt = 0;
		for(int i = 1 ; i <= b ; i++){
			if(t%m[i] == 0){
				cnt++;
				if(cnt == pos) {
					cout<<"Case #"<<c<<": "<<i<<'\n';
				}
			}
		}
	}
}
