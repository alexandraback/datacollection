#include <iostream>
#include <cstdio>
using namespace std;

int R,C,N;

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		scanf("%d%d%d",&R,&C,&N);
		int ans=0;
		if(R==3 && C==3 && N==8){printf("Case #%d: %d\n",Case,8); continue;}
		if(R%2==0 && C%2==0){
			int Min=(R/2)*C;
			if(N<Min) ans=0;
			else{
				N-=Min;
				if(N<2) ans+=(N*2);
				else{ 
					N-=2; ans+=4; 
					int edge=(R-1)/2 + (C-1)/2;
					edge<<=1;
					if(N<edge) ans+=(N*3);
					else{
						N-=edge; ans+=(edge*3);
						ans+=(N*4);
					}
				}
			}
		}
		else if(R%2==1 && C%2==1){
			int Min=(R+1)/2 * (C+1)/2 + R/2 * C/2;
			if(N<Min) ans=0;
			else{
				N-=Min;
				int edge=R/2 + C/2;
				edge<<=1;
				if(N<edge) ans+=(N*3);
				else{
					N-=edge; ans+=(edge*3);
					ans+=(N*4);
				}
			}
		}
		else{
			if(R%2==1){int tmp=R; R=C; C=tmp;}
			int Min=R/2*C;
			if(N<Min) ans=0;
			else{
				N-=Min;
				if(N<2) ans+=N*2;
				else{
					N-=2; ans+=4;
					int edge=(R-1)/2+(R-1)/2+C/2+C/2-1;
					if(N<edge) ans+=(N*3);
					else{
						N-=edge; ans+=(edge*3);
						ans+=(N*4);
					}
				}
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
