#include <iostream>
#include <algorithm>
#include <stdio.h>
#define fi first
#define sc second
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main(){
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	
	int tc;
	scanf("%d",&tc);
	
	for(int w = 0; w < tc; w++){
		
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		
		int bw=1<<(r*c);
		int mini = 9999999;
		
		for(int bm=0; bm < bw; bm++){
			int counter = 0;
			
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(bm&(1<<(i*c+j))){
						counter++;
					}
				}
			}
			
			if(counter != n)continue;
			
			int current=0;
			for (int i = 0; i < r; i++){
				for (int j=0; j < c; j++){
					if (bm&(1<<(i*c+j))){
						for (int k=0;k<4;k++){
							int nx = j+dx[k], ny = i+dy[k];
							if (nx >= 0 && nx < c && ny >= 0 && ny < r){
								if (bm&(1<<(ny*c+nx))){
									current++;
								}
							}
						}
					}
				}
			}
			
			mini = min(mini,current/2);
		}
		
		
		printf("Case #%d: %d\n", w + 1, mini);
	}
}
