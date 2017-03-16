#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int hav[100];
int tot;
void go(int index){
	hav[index]--;
	tot--;
	putchar(index + 'A');
}

int main(){
	int times, n;
	scanf("%d", &times);
	for (int t=1; t<=times; t++){
		scanf("%d", &n);
		tot = 0;
		for (int i=0; i<n; i++){
			scanf("%d", &hav[i]);
			tot += hav[i];
		}
		printf("Case #%d:", t);
		while (tot > 0){
			putchar(' ');
			int one = 0, maxi = -1, maxj = -1;
			for (int i=0; i<n; i++){
				if (hav[i] == 1){
					one++;
				}
				if (maxi == -1){
					maxi = i;
				}else if (maxj == -1){
					if (hav[maxi] > hav[i]){
						maxj = i;	
					}else{
						maxj = maxi;
						maxi = i;
					}
				}else{
					if (hav[i] > hav[maxj]){
						maxj = i;
					}
					if (hav[maxj] > hav[maxi]){
						int tmp = maxi; maxi = maxj; maxj = tmp;
					}
				}
			}
			if (hav[maxi] > hav[maxj] + 1){
				go(maxi);
				go(maxi);
			}else if (hav[maxi] == hav[maxj] + 1){
				go(maxi);
			}else if (hav[maxi] >= 2){
				go(maxi);
				go(maxj);
			}else if (hav[maxi] == 1){
				if (one > 2){
					go(maxi);
				}else{
					go(maxi);
					go(maxj);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
