#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N,B;

int cek(long long n) {
	long long jum=0;
	for (int i=0;i<B;++i) {
		if (jum>N) return N+3;
		if (n%arr[i]==0) jum+=n/arr[i];
		else jum+=n/arr[i]+1;
	}
	return jum;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		arr.clear();
		scanf("%d %d",&B,&N);
		for (int i=0;i<B;++i) {
			int d;
			scanf("%d",&d);
			arr.push_back(d);
		}
		if (N<=B) {printf("Case #%d: %d\n",z,N);continue;}
		long long l=1,r=1000000000000000;
		long long jwb;
		int jwb2;
		while (l<=r) {
			long long mid=(l+r)/2;
			int jum=cek(mid);
			int jum2=cek(mid+1);
			if (jum<=N-1 && jum2>=N) {jwb=mid;jwb2=jum;break;}
			if (jum>=N) {
				r=mid;
			}
			else if (jum<=N-1) {
				l=mid+1;
			}
		}
		int jwb3;
		for (int i=0;i<B;++i) {
			if (jwb%arr[i]==0) {++jwb2;if(jwb2==N) {jwb3=i+1;break;}}
		}
		printf("Case #%d: %d\n",z,jwb3);
	}
}
