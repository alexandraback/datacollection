#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[100010], d[100010];
int b, n;
int task, maxm;

int doit(){
	long long s=0, t= (long long)maxm*(n+1), h;
	while (s<=t){
		h = (s+t)>>1;

		long long sum=0, num=0;
		for (int i=0; i<b; i++){
			sum += h/a[i];
			if (h % a[i] == 0){
				d[num++] = i;
			}else sum++;
		}

		//cout<<s<<' '<<t<<' '<<h<<' '<<sum<<' '<<num<<endl;
		
		if ( sum < n && n <= sum+num ) 
			return d[n-sum-1];

		if ( sum < n ){
			s = h + 1;
		}else{
			t = h - 1;
		}
	}
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	//freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		scanf("%d%d", &b, &n);
		maxm = 1;
		for (int i=0; i<b; i++){
			scanf("%d", a+i);
			maxm = max(maxm, a[i]);
		}

		printf("Case #%d: %d\n", CASE, doit() + 1);
	}

	return 0;
}
