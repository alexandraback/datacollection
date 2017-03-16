#include<cstdio>
using namespace std;
const int MAX = 4 + 10;
int rec[MAX][MAX], arr[MAX][MAX];
int main(){
	int TN;
	scanf("%d", &TN);
	for(int tt = 1 ; tt <= TN ; tt++){
		int n, m;
		scanf("%d", &n);
		n--;
		for(int i = 0 ; i < 4 ; i++)
			for(int j = 0 ; j < 4 ; j++)
				scanf("%d", &rec[i][j]);
		scanf("%d", &m);
		m--;
		for(int i = 0 ; i < 4 ; i++)
			for(int j = 0 ; j < 4 ; j++)
				scanf("%d", &arr[i][j]);
		int ans = -1;
		bool flag = true;
		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				if(rec[n][i]==arr[m][j]){
					if(ans==-1) ans = rec[n][i];
					else flag = false;
				}
			}
		}
		if(!flag)
			printf("Case #%d: Bad magician!\n", tt);
		else if(ans==-1)
			printf("Case #%d: Volunteer cheated!\n", tt);
		else
			printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
