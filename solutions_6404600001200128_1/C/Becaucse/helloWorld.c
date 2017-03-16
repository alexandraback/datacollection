#include <stdio.h>

int main() {
	int ts, n, tmp, arr[10005], i, j, k, count, fix, a, b;
	FILE *rfp, *wfp;

	rfp = fopen("A-large.in", "r");
	wfp = fopen("answer.txt", "w");

	fscanf(rfp, "%d", &ts);

	for(i = 0 ; i < ts ; i++) {
		count = 0;
		a = 0;
		b = 0;
		fix = 0;
		fscanf(rfp, "%d", &n);

		for(j = 0 ; j < n ; j++) {
			fscanf(rfp, "%d", &tmp);
			arr[j] = tmp;
		}

		for(j = 0 ; j < n - 1 ; j++) {
			if(arr[j] > arr[j + 1]) {
				a += (arr[j] - arr[j + 1]);
				if(arr[j] - arr[j + 1] > fix)
					fix = arr[j] - arr[j + 1];
			}
		}

		for(j = 0 ; j < n - 1 ; j++) {
			if(fix >= arr[j]) {
				b += arr[j];
			}
			else
				b += fix;
		}

		fprintf(wfp, "Case #%d: %d %d\n", i + 1, a, b);
	}
	fclose(rfp);
	fclose(wfp);
}