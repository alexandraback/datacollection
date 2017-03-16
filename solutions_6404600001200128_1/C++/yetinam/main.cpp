#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		int n;
		vector <int> steps;
		scanf("%d",&n);
		steps.reserve(n);
		int maxv=0;
		int last=0;
		long long int sum1=0;
		long long int sum2=0;
		for (int i=0;i<n;i++) {
			int tmp;
			scanf("%d",&tmp);
			steps.push_back(tmp);
			sum1=sum1+max(0,last-tmp);
			maxv=max(maxv,last-tmp);
			last=tmp;
		}
		for (int i=1;i<n;i++) {
			sum2+=min(steps[i-1],maxv);
		}
		printf("Case #%d: %lld %lld\n",r,sum1,sum2);
	}
	return 0;
}
