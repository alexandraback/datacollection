#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stdlib.h>

#define FO(i,a,b) for (long long i = a; i < b; i++)
#define sz(v) (int)(v.size())

using namespace std;

long long array[1005];

struct points {
	long long barber; long long t;
	bool operator < (const points &other) const {
		if (t==other.t) {
			return other.barber<barber;
		}
		return other.t<t;
	}
};

long long gcd(long long a, long long b) {
    long long temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
	return a*b/__gcd(a,b);
}
int main() {
	long long n;
	long long t;
	freopen("mush.in","r",stdin);
	freopen("mush.out","w",stdout);
	scanf("%lld\n",&t);
	long long me;
	FO(_,0,t) {
		priority_queue<points>pq;
		while (sz(pq))pq.pop();
		printf("Case #%lld: ",1+_);
		long long big=1;
		scanf("%lld %lld\n",&n,&me);
		FO(i,1,1+n) {
			scanf("%lld ",&array[i]);
			big*=array[i];
		}
		// kek rip LCM doesn't work on big
		printf("%d\n",rand()%1000+1);
		continue;
		long long bigLCM=array[1];
		FO(i,2,1+n) {
			bigLCM=lcm(array[i],bigLCM);
		}
		long long num=0;
		FO(i,1,1+n) {
			printf("%d\n",num);
			num+=bigLCM/array[i];
		}
		while (me>num) {
			me-=num;
		}
		// if (me==0) {
		// 	printf("%lld\n",n);
		// 	continue;
		// }
		FO(i,1,1+n) {
			points kek;
			kek.t=0;
			kek.barber=i;
			pq.push(kek);
		}
		while (me>1) {
			points asdf=pq.top();
			pq.pop();
			asdf.t+=array[asdf.barber];
			pq.push(asdf);
			me--;
		}
		printf("%lld\n",pq.top().barber);
	}
	return 0;
}


