#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10000 + 10;
int n;
int a[maxn];
int main()
{
	int T; cin>>T;
	freopen("1.out","w",stdout);
	for (int ii = 1;ii <= T;ii++){
		scanf("%d",&n); int ans1 = 0,ans2 = 0;
		int MAX = 0;
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		for (int i = 1;i <  n;i++)
			if (a[i] > a[i + 1]){
				ans1 += a[i] - a[i + 1];
				MAX = max(MAX,a[i] - a[i + 1]);
			}
		for (int i = 1;i < n;i++)
			if (a[i] >= MAX) ans2 += MAX;
			else ans2 += a[i];
		cout << "Case #"<<ii<<": "<<ans1<<" "<<ans2<<endl;
	}

	return 0;
}
