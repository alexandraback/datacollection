#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int MAX = 1000 + 10;

int n;
long long m;
long long rec[MAX], arr[MAX];
pair<long long, long long> pr[MAX];

long long cnt(long long x){
	long long sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += (x+rec[i]-1) / rec[i];
	}
	return sum;
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		scanf("%d %I64d", &n, &m);
		for(int i = 0 ; i < n ; i++)
			scanf("%I64d", &rec[i]);
		long long l = 0, r = 100000000000000LL;
		while(l < r){
			long long mid = (l+r+1)/2LL;
			if(cnt(mid) < m){
				l = mid;
			}else{
				r = mid-1;
			}
		}
		m -= cnt(l);

		for(int i = 0 ; i < n ; i++){
			arr[i] = rec[i] - l % rec[i];
			if(arr[i] == rec[i]) arr[i] = 0;
			pr[i] = make_pair(arr[i], i);
		}
		sort(pr, pr+n);
		printf("Case #%d: %d\n", casen, pr[m-1].second+1);
	}
	return 0;
}
