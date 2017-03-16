#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, su[1001];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);

	for(int test=1; test<=testt; test++){
		scanf("%d",&n);
		int max=0;
		for(int i=0; i<n; i++){
			scanf("%d",&su[i]);
		}

		int print[2]={0,};
		for(int i=1;i<n;i++){
			if(su[i-1] > su[i]){
				print[0]+=su[i-1]-su[i];
				if(su[i-1]-su[i]>max)
					max = su[i-1] - su[i];
			}
		}

		for(int i=0; i<n-1; i++){
			if(max>su[i])
				print[1]+=su[i];
			else
				print[1]+=max;
		}
		printf("Case #%d: %d %d\n",test,print[0],print[1]);
	}
	return 0;
}
