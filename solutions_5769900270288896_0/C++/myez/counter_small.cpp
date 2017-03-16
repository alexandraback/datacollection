#include<cstdio>
#define LL long long
#define FI first
#define SC second
#define PB push_back
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
int t,cas,r,c,n,pt,wynik;
int bits[32][32];
int rozloz(int x){
	int score = 0,ile=0;
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j){
			bits[i][j] = x&1;
			if(bits[i][j]==1){
				ile++;
				if(i>0 && bits[i-1][j]==1)
					score++;
				if(j>0 && bits[i][j-1]==1)
					score++;
				}
			x>>=1;
			}
	if(ile==n)
		return score;
	return 1e9;
	}
int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
    scanf("%d",&t);
    while(t--){
		cas++;
		scanf("%d%d%d",&r,&c,&n);
		pt = 1;
		for(int i=0;i<r*c;++i)
			pt*=2;
		wynik = 1e9;
		for(int i=0;i<pt;++i){
			wynik = min(wynik,rozloz(i));
			}
		printf("Case #%d: %d\n",cas,wynik);
		}
	}
