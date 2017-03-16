#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int i,j,n,t,tes,len,len_palsu,len_asli,ctr,sum,ans;
int sorted[1000007],a[1007][1007];
char s[1007][1007],asli[1007],palsu[1007];
bool valid;

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%d",&n); gets(s[0]);
		for (i=1 ; i<=n ; i++) gets(s[i]);
		
		len_asli = 0;
		len = strlen(s[1]);
		for (i=0 ; i<len ; i++) {
			if (len_asli == 0 || s[1][i] != asli[len_asli-1]) {
				asli[len_asli] = s[1][i];
				len_asli++;
			}
		}
		
		valid = true;
		for (i=1 ; i<=n && valid; i++) {
			len_palsu = 0;
			len = strlen(s[i]);
			for (j=0 ; j<len ; j++) {
				if (len_palsu == 0 || s[i][j] != asli[len_palsu-1]) {
					palsu[len_palsu] = s[i][j];
					len_palsu++;
				}
			}
			
			if (len_asli != len_palsu) valid = false;
			if (valid) {
				for (j=0 ; j<len_asli ; j++)
					if (asli[j] != palsu[j]) valid = false;
			}
		}
		
		if (!valid) {
			printf("Case #%d: Fegla Won\n",tes);
		} else {
			for (i=1 ; i<=n ; i++) {
				ctr = 0;
				sum = 1;
				len = strlen(s[i]);
				for (j=1 ; j<len ; j++) {
					if (s[i][j] == s[i][j-1]) sum++; else {
						a[i][ctr] = sum;
						ctr++;
						sum = 1;
					}
				}
				
				a[i][ctr] = sum;
				ctr++;
				sum = 1;
			}
			
			ans = 0;
			for (i=0 ; i<ctr ; i++) {
				for (j=0 ; j<n ; j++) sorted[j] = a[j+1][i];
				sort(sorted,sorted+n);
				for (j=0 ; j<n ; j++) ans += abs(sorted[j]-sorted[n/2]);
			}
			
			printf("Case #%d: %d\n",tes,ans);
		}
	}
}