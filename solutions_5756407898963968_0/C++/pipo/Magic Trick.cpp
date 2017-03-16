#include <cstdio>
#include <cstring>
#define forn(i,n) for(int i = 0; i < n; i++)
#define forn1(i,n) for(int i = 1; i <= n; i++)
using namespace std;

int T, r1,r2;
int m1[5][5], m2[5][5];
int main(){
	
	scanf("%d", &T);
	forn1(t,T){
		scanf("%d", &r1);
		forn1(i,4)
			forn1(j,4)
				scanf("%d", &m1[i][j]);
		scanf("%d", &r2);
		forn1(i,4)
			forn1(j,4)
				scanf("%d", &m2[i][j]);
		int count = 0;
		int card;
		forn1(i,4)
			forn1(j,4)
				if(m1[r1][i]==m2[r2][j]){
					card = m1[r1][i];
					count++;
				}
		printf("Case #%d: ",t);
		if(count == 1)
			printf("%d\n",card);
		else if(count == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}
	return 0;
}
