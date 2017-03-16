/*************************************************************************
    > File Name: a.cpp
    > Author: 
    > Created Time: 六  4/18 09:07:40 2015
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;

int T, n, a[maxn], s;

bool check(int cur){
	for (int i=1; i<n; i++)
		if (a[i-1]>=cur && cur < a[i-1]-a[i])
			return 0;
	return 1;
}

int main(){
	scanf("%d", &T);
	for (int cT=0; cT<T; ){
		scanf("%d", &n);
		s=0;
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			s+=a[i];
		}
		int ans1 = 0;
		for (int i=1; i<n; i++)
			if (a[i]<a[i-1])
				ans1 += a[i-1]-a[i];
		printf("Case #%d: %d ", ++cT, ans1);
		int ans2 = 0, L=0, R=s;
		while (L<R){
			int mid = (L+R)/2;
			if (check(mid))
				R = mid;
			else
				L = mid+1;
		}
		for (int i=0; i+1<n; i++)
			if (a[i]<L)
				ans2 += a[i];
			else
				ans2 += L;
		printf("%d\n", ans2);
		//while (1){
		//	for (int i=1; i<n; i++)
		//		if (a[i-1]<)
		//}
	}
}

