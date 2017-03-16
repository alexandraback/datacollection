#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		int bmm=1<<(r*c);
		int cmin=9999;
		for(int bm=0;bm<bmm;bm++){
			int cc=0;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(bm&(1<<(i*c+j))){
						cc++;
					}
				}
			}
			if(cc!=n)continue;
			int cv=0;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(bm&(1<<(i*c+j))){
						for(int k=0;k<4;k++){
							int nx=j+dx[k],ny=i+dy[k];
							if(nx>=0&&nx<c&&ny>=0&&ny<r){
								if(bm&(1<<(ny*c+nx))){
									cv++;
								}
							}
						}
					}
				}
			}
			cmin=min(cmin,cv/2);
		}
		printf("Case #%d: %d\n",tcno,cmin);
	}
}
