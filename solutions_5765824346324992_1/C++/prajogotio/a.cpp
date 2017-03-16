#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int M[1003];
int N;
int B;

int main(){
	int TC;
	scanf("%d",&TC);
	for(int tt=1;tt<=TC;++tt){
		printf("Case #%d: ", tt);
		scanf("%d%d",&B,&N);
		for(int i=0;i<B;++i){
			scanf("%d",&M[i]);
		}
		long long lo = 0, hi = (long long) 1.1e13, mid;
		while (lo <= hi) {
			mid = (lo+hi)/2LL;
			long long tot = 0;
			for (int i = 0; i < B; ++i){
				tot += (mid / (long long) M[i]) + 1LL;
			}
			if (tot < N) {
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		int ans = 12345678;
		long long t = (long long) 1.1e13;
		long long tot = 0;
		long long prev = 0;
		for (int i = 0; i < B; ++i){
			tot += (lo / (long long) M[i]) + 1LL;
		}
		for (int i = 0; i < B; ++i) {
			prev += (hi / (long long) M[i]) + 1LL; 
		}
		if (tot < prev) {
			swap(tot, prev);
			swap(lo, hi);
		}
		vector<pair<long long, int> > st;
		for(int i = 0; i < B; ++i) {
			t = (lo/M[i])*M[i];
			long long ex = (hi/M[i])*M[i];
			if (t == ex) continue;
			st.push_back(make_pair(t,i));
		}
		sort(st.begin(), st.end());
		for (int i =0; i < B; ++i){
			++prev;
			if (prev == N) {
				ans = st[i].second;
				break;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}