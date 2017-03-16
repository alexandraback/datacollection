#include <cstdio>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;

int r[2][20];
int v[2];


int main(){
	int cas;
	scanf("%d",&cas);
	fr(u,1,cas+1){
		rep(i,2){
			scanf("%d",&v[i]);
			v[i]--;
			rep(a,4) rep(b,4){				
				int vs;
				scanf("%d",&vs);
				vs--;
				r[i][vs]=a;
			}
		}
		
		int ind=-1,cnt=0;
		rep(j,16){
			if(r[0][j]==v[0] && r[1][j]==v[1]){
				cnt++;
				ind=j+1;
			}
		}
		printf("Case #%d: ",u);
		if(cnt==0) printf("Volunteer cheated!");
		else if(cnt>1) printf("Bad magician!");
		else printf("%d",ind);
		printf("\n");
	}
	return 0;
}
