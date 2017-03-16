#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
int main() {
    //ios_base::sync_with_stdio(0);
	int T, matrix[10][10], row;
	bool flag[20];
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%d", &row);
		for(int i=1 ; i<=4 ; i++) {
			for(int k=1 ; k<=4 ; k++) {
				scanf("%d", &matrix[i][k]);
			}
		}
		memset(flag, false, sizeof(flag));
		for(int i=1 ; i<=4 ; i++) flag[matrix[row][i]] = true;
		scanf("%d", &row);
		for(int i=1 ; i<=4 ; i++) {
			for(int k=1 ; k<=4 ; k++) {
				scanf("%d", &matrix[i][k]);
			}
		}
		int cnt = 0, n = -1;
		for(int i=1 ; i<=4 ; i++) if( flag[matrix[row][i]] ) { cnt++; n = matrix[row][i]; }
		if( cnt == 0 ) printf("Case #%d: Volunteer cheated!\n", caso);
		else if( cnt == 1 ) printf("Case #%d: %d\n", caso, n);
		else printf("Case #%d: Bad magician!\n", caso);
	}
    return 0;
}