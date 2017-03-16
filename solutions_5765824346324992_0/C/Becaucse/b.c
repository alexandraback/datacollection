#include<stdio.h>

int main() {
	int ts, b, n, tmp, i, j, k, arr[1001], count, answer, flag;
	long long max;
	FILE *rfp, *wfp;

	rfp = fopen("B-small-attempt0.in", "r");
	wfp = fopen("answer.txt", "w");

	fscanf(rfp, "%d", &ts);

	for(i = 0 ; i < ts ; i++) {
		max = 1;
		count = 0;
		answer = 0;
		flag = 0;
		fscanf(rfp, "%d", &b);
		fscanf(rfp, "%d", &n);

		for(j = 0 ; j < b ; j++) {
			fscanf(rfp, "%d", &tmp);
			arr[j] = tmp;
		}

		for(j = 0 ; j < b ; j++) {
			if(max % arr[j] != 0)
				max *= arr[j];
		}

		for(j = 0 ; j < max ; j++) {
			for(k = 0 ; k < b ; k++) {
				if(j % arr[k] == 0)
					count++;
			}
		}

		answer = n % count;
		if(answer == 0)
			answer = count;

		for(j = 0 ; j < max ; j++) {
			for(k = 0 ; k < b ; k++) {
				if(j % arr[k] == 0) {
					if(answer > 0)
						answer--;
					if(answer == 0) {
						answer = k + 1;
						flag = 1;
						break;
					}
				}
			}
			if(flag == 1)
				break;
		}
		fprintf(wfp, "Case #%d: %d\n", i + 1, answer);
	}

	fclose(rfp);
	fclose(wfp);
	printf("done\n");

	return 0;
}