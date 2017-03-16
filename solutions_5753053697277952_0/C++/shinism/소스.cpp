#pragma warning (disable:4996)
#include<fstream>
using namespace std;

void solve();
int n,m,m2;
int p[30];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T,i;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}

void solve()
{
	int i,j,mx,mn,k=0;
	for (i = 0; i < 27; i++) p[i] = 0;
	scanf("%d", &n); m = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		m += p[i];
	}
	int mn2;
	m2 = (m + 2) / 2;
	for (i = 0; i <m; i++) {
		mx = 0; mn2 = -1;
		for (j = 0; j < n; j++) {
			if (mx < p[j]) {
				mx = p[j];
				mn = j;
			}else if(mx==p[j]){
				mn2 = j;
			}
		}
		if (mx == 0) break;
		if ((m-k)%2==0 && (m-k)/2==mx && mn2!=-1 && mx==p[mn2]) {
			p[mn]--; p[mn2]--;
			printf("%c%c ", 'A' + mn, 'A' + mn2);
			k += 2;
		}
		else {
			p[mn]--;
			printf("%c ", 'A' + mn);
			k++;
		}
		m2			= (m - i + 2) / 2;
	}
	printf("\n");
}