#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int J1,J2,N;

int valid(int speed) {
	int jum=0;
	for (int i=0;i<N-1;++i) {
		int sisa=arr[i]-speed;
		if (sisa<0) sisa=0;
		if (arr[i+1]<sisa) return -1;
		else jum+=arr[i]-sisa;
	}
	return jum;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		arr.clear();
		scanf("%d",&N);
		J1=0;J2=2000000000;
		for (int i=0;i<N;++i) {
			int d;
			scanf("%d",&d);
			arr.push_back(d);
		}
		int maxi=0;
		for (int i=0;i<N-1;++i) {
			J1+=(arr[i+1]<arr[i]?arr[i]-arr[i+1]:0);
			if (arr[i+1]<arr[i] && arr[i]-arr[i+1]>maxi) maxi=arr[i]-arr[i+1];
		}
		J2=valid(maxi);
		printf("Case #%d: %d %d\n",z,J1,J2);
	}
}
