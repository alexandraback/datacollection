#include <stdio.h>

int main() {
	int i, j, k, l, m, n, o, p, q, r, t;
	int vet[8];
	
	scanf("%d", &t);
	for (r = 1; r <= t; r++) {
		scanf("%d", &n);
		for (i = 1; i <= 4; i++) {
			for (j = 0; j< 4; j++) {
				if (i == n) {
					scanf("%d", &vet[j]);	
				} else {
					scanf("%d", &k);	
				}  
	  		}	
		}
		
		scanf("%d", &n);
		m = 0;
		p = 0;
		for (i = 1; i <= 4; i++) {
			for (j = 0; j< 4; j++) {
				if (i == n) {
					scanf("%d", &l);
					for (o =0; o < 4; o++) {
						if (vet[o] == l) {
							m++;
							p = l;
							break;	
						}
					}	
				} else {
					scanf("%d", &k);	
				}  
	  		}	
		}
		
		if (m == 0) {
			printf("Case #%d: Volunteer cheated!\n", r);	
		} else if (m == 1) {
			printf("Case #%d: %d\n", r, p);	
		} else {
			printf("Case #%d: Bad magician!\n", r);	
		}
	}	
	
	return 0;	
}
