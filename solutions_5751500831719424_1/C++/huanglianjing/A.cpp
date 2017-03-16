#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
char str[107];
char c[107][107];
int a[107][107];
int num[107];
int tmp[107];

int cal()
{
	for (int i=1; i<n; ++i) {
		if (num[i] != num[0]) return -1;
		for (int j=0; j<num[0]; ++j) {
			if (c[0][j] != c[i][j]) return -1;
		}
	}
	int sum = 0;
	for (int j=0; j<num[0]; ++j) {
		for (int i=0; i<n; ++i) tmp[i] = a[i][j];
		sort(tmp,tmp+n);
		int aver = tmp[n/2];
		for (int k=0; k<n; ++k) sum += abs(tmp[k]-aver);
	}
	return sum;
}

int main()
{
	scanf("%d",&t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d",&n);
		for (int i=0; i<n; ++i) {
			scanf("%s",&str);
			int len = strlen(str);
			c[i][0]=str[0];
			a[i][0]=1;
			num[i] = 1;
			for (int j=1; j<len; ++j) {
				if (str[j] == c[i][num[i]-1]) ++a[i][num[i]-1];
				else {
					c[i][num[i]]=str[j];a[i][num[i]]=1;++num[i];
				}
			}
		}
		int res = cal();
		printf("Case #%d: ",cas);
		if (res>=0) printf("%d\n",res);
		else puts("Fegla Won");
	}
	return 0;
}
