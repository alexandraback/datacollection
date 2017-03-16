#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	int a[2][4][4], r[2];
	for(int test=1;test<=T;test++){
		for(int i=0;i<2;i++){
			cin >> r[i]; r[i]--;
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					cin >> a[i][j][k];
		}
		int res = -1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(a[0][r[0]][i] == a[1][r[1]][j]){
					if(res == -1) res = a[0][r[0]][i];
					else if(res > 0) res = -2;
				}
			}
		}
		if(res > 0)
			printf("Case #%d: %d\n", test, res);
		else if(res == -2)
			printf("Case #%d: Bad magician!\n", test);
		else
			printf("Case #%d: Volunteer cheated!\n", test);
	}
}