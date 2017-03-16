#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		int arr[N];
		
		for(int i=0; i<N; i++)
			scanf("%d",&arr[i]);
		
		int ans1 = 0;
		int maxDif=0;
		for(int i=0; i+1<N; i++){
			int diff = arr[i]-arr[i+1];
			if(diff>0){
				ans1 +=diff;
			}
			if(diff>maxDif)
				maxDif = diff;
		}
		int ans2 = 0;
		for(int i=0; i+1<N; i++){
			ans2 += min(arr[i], maxDif);
		}
		
		printf("Case #%d: %d %d\n", t, ans1, ans2);
	}
	return 0;
}