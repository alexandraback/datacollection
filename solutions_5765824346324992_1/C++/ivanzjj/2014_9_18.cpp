#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long LL;
LL MAX (LL a, LL b){ return (a) > (b) ? (a) : (b); }
LL MIN (LL a, LL b){ return a < b ? a : b; }

int B,N;
int a[1010];
int num[100000+10];

int main (){
//	freopen ("F:\\C++\\B-large.in","r",stdin);
//	freopen ("F:\\C++\\B-large.out","w",stdout);
	
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf ("%d%d",&B,&N);
		memset (num, 0, sizeof(num));
		
		for (int i=0;i<B;i++)	{scanf ("%d", &a[i]), num[a[i]]++;}
		if (N <= B){
			printf ("Case #%d: %d\n",cas, N);
			continue;
		}
		N -= B;
		LL low = 1, high = 100000LL*N, mid;
		
		while (low < high){
			mid = (low + high) >> 1;
			
			LL sum = 0;
			for (int i=1;i<=100000;i++) if (num[i] != 0){
				sum += (mid / i * num[i]);
				if (sum >= N)	break;
			}
			if (sum >= N)	high = mid;
			else			low = mid + 1;
		}
		
		LL n = low - 1;
		for (int i=1;i<=100000;i++) if (num[i] != 0){
			N -= (n / i * num[i]);
		}
		
		for (int i=0;i<B;i++) if (low % a[i] == 0){
			N-- ;
			if (N == 0) {
				printf ("Case #%d: %d\n", cas, i+1); break;
			}	
		}
	}
	return 0;
}
