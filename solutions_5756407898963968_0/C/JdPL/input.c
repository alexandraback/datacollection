#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t getNumber(FILE *input, uint16_t NC) {
	uint16_t num;
	char c;
	
	num=0;
	
	c=getc(input);
	while(c!=NC) {
		num = 10*num+c-48;
		c=getc(input);
	}
	return num;
}

int main() {
	FILE *input, *output;
	uint16_t cases, temp, first, second, Possible[4], Possible2[4];
	uint16_t i, j, number, count;
	char c;
	char text[101];
	
	input = fopen ("input.txt", "r");
	output = fopen ("output.txt", "w");
	
	count = 1;
	cases = getNumber(input, 10);
	printf("%d\n",cases);

	while(cases>0) {
		first = getNumber(input, 10);
		printf("%d\n",first);
		if(first == 1) {
			Possible[0] = getNumber(input, 32);
			Possible[1] = getNumber(input, 32);
			Possible[2] = getNumber(input, 32);
			Possible[3] = getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
		}
		if(first == 2) {
			getNumber(input, 10);
			Possible[0] = getNumber(input, 32);
			Possible[1] = getNumber(input, 32);
			Possible[2] = getNumber(input, 32);
			Possible[3] = getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
		}
		if(first == 3) {
			getNumber(input, 10);
			getNumber(input, 10);
			Possible[0] = getNumber(input, 32);
			Possible[1] = getNumber(input, 32);
			Possible[2] = getNumber(input, 32);
			Possible[3] = getNumber(input, 10);
			getNumber(input, 10);
		}
		if(first == 4) {
			getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
			Possible[0] = getNumber(input, 32);
			Possible[1] = getNumber(input, 32);
			Possible[2] = getNumber(input, 32);
			Possible[3] = getNumber(input, 10);
		}
		
		
		second = getNumber(input, 10);
		printf("%d\n",second);
		if(second == 1) {
			Possible2[0] = getNumber(input, 32);
			Possible2[1] = getNumber(input, 32);
			Possible2[2] = getNumber(input, 32);
			Possible2[3] = getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
		}
		if(second == 2) {
			getNumber(input, 10);
			Possible2[0] = getNumber(input, 32);
			Possible2[1] = getNumber(input, 32);
			Possible2[2] = getNumber(input, 32);
			Possible2[3] = getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
		}
		if(second == 3) {
			getNumber(input, 10);
			getNumber(input, 10);
			Possible2[0] = getNumber(input, 32);
			Possible2[1] = getNumber(input, 32);
			Possible2[2] = getNumber(input, 32);
			Possible2[3] = getNumber(input, 10);
			getNumber(input, 10);
		}
		if(second == 4) {
			getNumber(input, 10);
			getNumber(input, 10);
			getNumber(input, 10);
			Possible2[0] = getNumber(input, 32);
			Possible2[1] = getNumber(input, 32);
			Possible2[2] = getNumber(input, 32);
			Possible2[3] = getNumber(input, 10);
		}
		printf("%d,%d,%d,%d\n",Possible[0],Possible[1],Possible[2],Possible[3]);
		printf("%d,%d,%d,%d\n",Possible2[0],Possible2[1],Possible2[2],Possible2[3]);
		i=0;
		j=0;
		number=0;
		
		while(i<4) {
			while(j<4) {
				if(Possible[i] == Possible2[j]) number = 16 * number + Possible[i];
				j++;
			}
			j=0;
			i++;
		}
		
		fprintf (output, "Case #%d: ", count);
		
		
		if(number==0) {
			fprintf (output, "Volunteer cheated!");
		} else {
			if(number>16) {
				fprintf (output, "Bad magician!");
			} else {
				fprintf (output, "%d", number);
			}
		}
		
		
		if(cases!=0) fwrite ("\n", sizeof (char), 1,output);
		count++;
		cases--;
	}
	
	
	
	
	return 0;
}
