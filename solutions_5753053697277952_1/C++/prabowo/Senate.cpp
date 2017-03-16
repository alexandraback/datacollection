#include <cstdio>
#include <cstring>

typedef long long LL;

int Main () {
	int n;
	
	scanf ("%d", &n);
	int p[n];
	
	int sum = 0;
	for (int i=0; i<n; i++) scanf ("%d", p + i), sum += p[i];	
	
	while (sum) {
		bool can = 0;		
		if (sum > 1) {
			for (int i=0; i<n; i++) {
				if (p[i] == 0) continue;
				for (int j=0; j<n; j++) {
					if (p[j] == 0) continue;
					if (i == j && p[j] ==  1) continue;
					
					p[i]--; p[j]--;
					sum -= 2;
					
					bool majority = 0;
					for (int k=0; k<n; k++) {
						if (p[k] * 2 > sum) {
							majority = 1;
							break;
						}
					}
					
					if (!majority) {
						printf (" %c%c", i + 'A', j + 'A');
						can = 1;
						break;
					}
					
					p[i]++; p[j]++;
					sum += 2;
					
				}
				
				if (can) break;
			}
		}
		
		if (!can) {
			for (int i=0; i<n; i++) {
				if (p[i] == 0) continue;
				
				p[i]--;
				sum--;
				
				bool majority = 0;
				for (int k=0; k<n; k++) {
					if (p[k] * 2 > sum) {
						majority = 1;
						break;
					}
				}
				
				if (!majority) {
					printf (" %c", i + 'A');
					break;
				}
				
				p[i]++;
				sum++;
			}
		}
	}

	return 0 * printf ("\n");
	
}

int main () {
	freopen ("A-large (1).in", "r", stdin);
	freopen ("A-large (1).out", "w", stdout);

	int t;
	scanf ("%d", &t);
	for (int tc=0; tc<t; tc++) {
		printf ("Case #%d:", tc + 1);
		Main();
	}
	return 0;
}