#include <bits/stdc++.h>

#define MAXN 5000
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int n,sum1,sum2,last,maxi;
int a[MAXN];
int main(){
	int test;
	cin >> test;
	for(int ti=1;ti<=test;++ti){

		cin >> n;
		last=0;
		sum1=0;
		maxi=0;
		for(int i=0;i<n;++i) {
			cin >> a[i];
			if(a[i]<last) {sum1+=last-a[i];}
			last=a[i];
		}

		sum2=0;
		for(int i=1;i<n;++i){

			if(a[i]<a[i-1]) {maxi=max(maxi,a[i-1]-a[i]);}	
			}
		for(int i=0;i<n-1;++i){
			sum2+=min(a[i],maxi);
		}

		printf("Case #%d: %d %d\n",ti,sum1,sum2);
	}
	return 0;}
