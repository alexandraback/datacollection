#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int task;
int n, a[20000];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", a+i);

		int ret1=0, maxd = 0;
		for (int i=1; i<n; i++){
			if (a[i-1] > a[i]){
				ret1 += a[i-1] - a[i];
				maxd = max(maxd, a[i-1] - a[i]);
			}
		}

		int ret2 = 0;
		for (int i=0; i<n-1; i++){
			ret2 += min(a[i], maxd);
		}

		printf("Case #%d: %d %d\n", CASE, ret1, ret2);
	}

	return 0;
}
