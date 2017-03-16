#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define eps 1e-7
#define inf 0x3f3f3f3f
#define mod 1000000007

using namespace std;

char lista[110][110], comp[110][110];
int qtd[110][110], maxx[110];

int main(){
	int t, caso = 1, n;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		fr(i, 0, n) scanf("%s", lista[i]);
		
		int pos;
		fr(i, 0, n){
			pos = 0;
			qtd[i][0] = 1;
			comp[i][0] = lista[i][0];
			int s = strlen(lista[i]);
			fr(j, 1, s){
				if(lista[i][j] == lista[i][j-1]){
					qtd[i][pos]++;
				}else{
					comp[i][++pos] = lista[i][j];
					qtd[i][pos] = 1;
				}
			}
			comp[i][++pos] = '\0';
		}
		
		int ok = 0;
		fr(i, 1, n){
			if(strcmp(comp[i], comp[i-1]) != 0){
				ok = 1;
				break;
			}
		}
		
		if(ok){
			printf("Case #%d: Fegla Won\n", caso++);
			continue;
		}
		
		int size = strlen(comp[0]);
		
		fr(i, 0, size){
			maxx[i] = 0;
			fr(j, 0, n){
				maxx[i] = max(maxx[i], qtd[j][i]);
			}
		}
		
		int ans = 0;
		
		fr(i, 0, size){
			int temp = 10000000;
			fr(j, 1, maxx[i]+1){
				int cont = 0;
				fr(k, 0, n){
					cont += abs(qtd[k][i] - j);
				}
				temp = min(temp, cont);
			}
			ans += temp;
		}
		
		printf("Case #%d: %d\n", caso++, ans);
	}
	
	return 0;
}

