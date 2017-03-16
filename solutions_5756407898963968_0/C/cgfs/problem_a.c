#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MULTI_NUMS 100


int find_num_of_same_value(int c1[], int c2[])
{
	int i,j,k;
	int ret_val = 0;

	for (i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
			if(c1[i] == c2[j]) {
				if (ret_val) {
					return MULTI_NUMS;
				} else {
					ret_val = c1[i];
				}
			}
		}
	}
	return ret_val;
}

int main(void)
{
	int num_set;
	int case_num;
	int answer;
	int dummy[4];
	int c1[4];
	int c2[4];
	int nosv;
	int i;

	scanf("%d", &num_set);

	for (case_num = 1; case_num <= num_set; case_num++) {
		
		scanf("%d", &answer);
		//printf("answer1 %d \n", answer);
		for (i = 1; i <= 4; i++) {
			if (i != answer)
				scanf("%d %d %d %d", &dummy[0], &dummy[1], &dummy[2], &dummy[3]);
			else
				scanf("%d %d %d %d", &c1[0], &c1[1], &c1[2], &c1[3]);
		}

		scanf("%d", &answer);
		//printf("answer2 %d \n", answer);
		for (i = 1; i <= 4; i++) {
			if (i != answer)
				scanf("%d %d %d %d", &dummy[0], &dummy[1], &dummy[2], &dummy[3]);
			else
				scanf("%d %d %d %d", &c2[0], &c2[1], &c2[2], &c2[3]);
		}

		//printf("c1 %d %d %d %d\n", c1[0], c1[1], c1[2], c1[3]);
		//printf("c2 %d %d %d %d\n", c2[0], c2[1], c2[2], c2[3]);
		nosv = find_num_of_same_value(c1, c2);
		//printf("nosv %d\n", nosv);
		switch(nosv) {
			case 0:
				printf("Case #%d: Volunteer cheated!\n", case_num);
				break;
			case MULTI_NUMS:
				printf("Case #%d: Bad magician!\n", case_num);
				break;
			default:
				printf("Case #%d: %d\n", case_num, nosv);
				break;
		}


	}
	return 0;
}	
