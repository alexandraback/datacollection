#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int tes,i,j,k,r,c,n,t;
int mem[19][(1<<16)+7][260];

int DP(int row, int bit, int sisa) {
	if (row > r) return 0;
	if (sisa == 0) return 0;
	if (sisa > (r-row) * c) return 999999999;
	if (mem[row][bit][sisa] != -1) return mem[row][bit][sisa];
	
	int i,j;
	int last;
	int tmp_plus;
	int tmp_minus;
	int ans = 999999999;
	
	//printf("%d %d %d\n",row,bit,sisa);
	
	for (i=0 ; i<(1<<c) ; i++) {
		tmp_plus = 0;
		tmp_minus = 0;
		last = 999999999;
		
		for (j=0 ; j<c ; j++) if ((1 << j) & i) {
			tmp_minus++;
			
			if ((1 << j) & bit) tmp_plus++;
			if (last == j-1) tmp_plus++;
			last = j;
		}
		
		//printf("-- %d %d %d\n",i,tmp_plus,tmp_minus);
		
		if (tmp_minus <= sisa) ans = min(ans,tmp_plus + DP(row+1,i,sisa-tmp_minus));
	}
	
	return mem[row][bit][sisa] = ans;
}

int main() {
	scanf("%d",&tes);
	for (t=1 ; t<=tes ; t++) {
	
		for (i=0 ; i<=16 ; i++)
			for (j=0 ; j<=(1<<16) ; j++)
				for (k=0 ; k<=256 ; k++)
					mem[i][j][k] = -1;
	
		scanf("%d%d%d",&r,&c,&n);
		if (n <= (r*c + 1) / 2) printf("Case #%d: %d\n",t,0);
		else printf("Case #%d: %d\n",t,DP(0,0,n));
	}
}