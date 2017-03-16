#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int m;
long long n, su[1001];
bool check(long long time){
	long long sum=0;
	for(int i=0; i<m; i++){
		sum+=time/su[i]+1;
	}
	if(sum>=n)
		return true;
	return false;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);

	for(int test=1; test<=testt; test++){
		scanf("%d %lld", &m, &n);
		for(int i=0; i<m; i++)
			scanf("%lld", &su[i]);

		long long low=0, high=n*200000, mid, time;
		while(low<=high){
			mid = (low+high) >> 1;
			if(check(mid)){
				time=mid;
				high=mid-1;
			}
			else
				low=mid+1;
		}

		for(int i=0; i<m; i++){
			n-=(time-1)/su[i]+1;
		}
		int print;
		for(int i=0; i<m; i++){
			if(time%su[i] == 0)
				n--;
			if(n==0){
				print=i+1;
				break;
			}
		}
		printf("Case #%d: %d\n",test,print);
	}
	return 0;
}
