#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define INF 0x3f3f3f3f

int a[1010];

int gcd(int a,int b){
	if(a % b == 0)
		return b;
	return gcd(b,a % b);
}

long long have[1010];

int main(){
	int T;
	scanf("%d",&T);
	for(int cas = 1;cas <= T;++cas){
		memset(have,0,sizeof(have));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		int mgcd = a[1];
		for(int i = 2;i <= n;++i)
			mgcd = gcd(mgcd,a[i]);
		int lcm = 1;
		for(int i = 1;i <= n;++i)
			lcm *= a[i];
		
		int idx = -1;
		int magic;
		for(int i = 1;i <= m;++i){
			long long minn = 0x3f3f3f3f;
			minn *= 0x3f3f3f3f;
			bool ok = true;
			for(int j = 1;j < n;++j)
				if(have[j] * a[j] != have[j + 1] * a[j + 1])
					ok = false;
			if(ok && i != 1){
				magic = i - 1;
				break;
			}


			for(int j = 1;j <= n;++j){
				long long tmp = have[j] * a[j];
				if(tmp < minn){
					minn = tmp;
					idx = j;
				}
			}
			++have[idx];
		}
		memset(have,0,sizeof(have));

		--m;
		m %= magic;
		++m;
		idx = -1;
		for(int i = 1;i <= m;++i){
			long long minn = 0x3f3f3f3f;
			minn *= 0x3f3f3f3f;
			for(int j = 1;j <= n;++j){
				long long tmp = have[j] * a[j];
				if(tmp < minn){
					minn = tmp;
					idx = j;
				}
			}
			++have[idx];
		}
		printf("Case #%d: %d\n",cas,idx);
	//	printf("%d\n",magic);
	}
	return 0;
}

