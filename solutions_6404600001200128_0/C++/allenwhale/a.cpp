#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int s[1010];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&s[i]);
		}
		int y=0,z=0;
		for(int i=0;i<N-1;i++){
			if(s[i]>s[i+1]){	
				y+=s[i]-s[i+1];
			}
		}
		int mx=0;
		for(int i=0;i<N-1;i++){
			mx=max(mx,s[i]-s[i+1]);
		}
		for(int i=0;i<N-1;i++){
			z+=min(s[i],mx);
		}
		printf("Case #%d: %d %d\n",t,y,z);
	}
	return 0;
}
