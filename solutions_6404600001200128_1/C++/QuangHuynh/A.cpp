#include <bits/stdc++.h>
using namespace std;

int a[1111111];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int test, res1= 0, res2 = 0, carry = 0, n;
	scanf("%d", &test);
	for (int i=1; i<= test; i++)
	{
		scanf("%d", &n);
		res1 = 0;
		res2 = 0; carry = 0;
		for (int j=1; j<= n; j++)
			scanf("%d", &a[j]);

		for (int j=1; j< n; j++)
			if (a[j] >= a[j+1]){
				res1+= (a[j] - a[j+1]);
			}

		for (int j=1; j< n; j++)
			carry = max(carry, a[j] - a[j+1]);

		for (int j=1; j< n; j++)
			res2+= min(a[j], carry);

		printf("Case #%d: %d %d\n", i, res1, res2 );
	}
}