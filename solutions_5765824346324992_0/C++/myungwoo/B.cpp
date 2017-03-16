#include <bits/stdc++.h>
using namespace std;

#define MAXN 1004
typedef long long lld;

int T, N, M;
int A[MAXN];

lld proc(lld m)
{
	lld ret = 0;
	for (int i=1;i<=N;i++){
		ret += m/A[i]+1;
	}
	return ret;
}

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d%d", &N, &M);
		int maxv = 0;
		for (int i=1;i<=N;i++) scanf("%d", A+i), maxv = max(maxv, A[i]);
		lld s = 0, e = (lld)maxv*M, t;
		while (s <= e){
			lld m = (s+e)>>1;
			if (proc(m) >= M) e = m-1, t = m;
			else s = m+1;
		}
		lld cnt = proc(t);
		vector <int> arr;
		for (int i=1;i<=N;i++){
			if (t%A[i] == 0) arr.push_back(i);
		}
		cnt -= arr.size();
		printf("%d\n", arr[M-cnt-1]);
	}
}
