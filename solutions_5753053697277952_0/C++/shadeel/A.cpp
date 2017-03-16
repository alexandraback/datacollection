#include <cstdio>
#include <algorithm>

using namespace std;

struct PARTY{
	int index, num;
};

PARTY party[26];
int tol;


bool cmp(PARTY a, PARTY b){
	return a.num > b.num;
}

int main(void){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int c, cc=0, n, ans;
	
	scanf("%d", &c);
	while( c-- ){
		scanf("%d", &n);	tol = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &party[i].num);
			tol += party[i].num;
			party[i].index = i;
		}
		printf("Case #%d:", ++cc);
		while( tol ){
			sort(party, party+n, cmp);
			/*for(int i=0; i<n; i++)	printf("%d ", party[i].num);
			putchar('\n');*/
			if( party[0].num>1 ){
				if( party[0].num==party[1].num ){
					printf(" %c%c", 'A'+party[0].index, 'A'+party[1].index);
					party[0].num--;	party[1].num--;	tol-=2;
				} else{
					printf(" %c", 'A'+party[0].index);
					party[0].num--;	tol--;
				}
				continue;
			} else if( tol&1 ){
				printf(" %c", 'A'+party[0].index);
				party[0].num--;	tol--;	continue;
			} else{
				printf(" %c%c", 'A'+party[0].index, 'A'+party[1].index);
				party[0].num--;	party[1].num--;
				tol-=2;	continue;
			}
		}
		putchar('\n');
	}
	
	return 0;
}

