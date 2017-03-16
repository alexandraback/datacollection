/*************************************************************************
    > File Name: b.cpp
    > Author: 
    > Created Time: 六  4/18 09:28:25 2015
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxB = 2000;

int T, N, B, a[maxB], b[maxB], q[maxB];

int cmp(int x, int y){
	return b[x]!=b[y] ? b[x]>b[y] : x<y;
}

int main(){
	scanf("%d", &T);
	for (int cT=0; cT<T; ){
		scanf("%d%d", &B, &N);
		for (int i=0; i<B; i++)
			scanf("%d", a+i);
		long long L=0, R=N;
		R*=a[0];
		while (L<R){
			long long mid = (L+R+1)/2, cur=0;
			for (int i=0; i<B; i++)
				cur += (mid+a[i]-1) / a[i];
			if (cur >= N)
				R = mid - 1;
			else
				L = mid;
		}
		long long cur=0;	
		for (int i=0; i<B; i++)
			cur += (L+a[i]-1) / a[i]-1;
		for (int i=0; i<B; i++){
			q[i]=i;
			b[i]= ((L+a[i]-1)/a[i]-1)*a[i];
		}
		int ans;
		while (cur<N){
			ans = 0;
			for (int i=0; i<B; i++)
				if (b[i]<b[ans])
					ans=i;
			cur ++;
			b[ans]+=a[ans];
		}
		printf("Case #%d: %d\n", ++cT, ans+1);
	}
	return 0;
}
