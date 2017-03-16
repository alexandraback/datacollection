#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#define SQUARESIZE 4
#define BADMAGICIAN 0
#define VOLUNTEERCHEATED -1


void parse_number_of_tests(FILE * file, int * number)
{
	fscanf(file, "%d", number);
}

void parse_half_test(FILE * file, int line[SQUARESIZE])
{
	int lineNo;
	int content[SQUARESIZE][SQUARESIZE];
	fscanf(file, "%d", &lineNo);
	lineNo --;
	int i, j;
	for (i=0; i< SQUARESIZE; i++)
		for(j=0; j< SQUARESIZE; j++)
			fscanf(file, "%d", &content[i][j]);
	for(int i= 0; i< SQUARESIZE; i++)
	{
		line[i] = content[lineNo][i];
	}

}

int contains(int candidate, int array[SQUARESIZE])
{
	for (int i=0; i< SQUARESIZE; i++)
		if(candidate == array[i])
			return 1;
	return 0;
}

int intersect (int fstArray[SQUARESIZE], int otherArray[SQUARESIZE])
{
	int size = 0, which=0;
	for (int i = 0 ; i < SQUARESIZE; i++)
	{
		if (contains(fstArray[i], otherArray))
		{
			which = fstArray[i];
			size++;
		}
	}
	if (size == 0 )
	{
		return VOLUNTEERCHEATED;
	}
	else if (size != 1)
	{
		return BADMAGICIAN;
	}
	else
		return which;

}

void solve_one_test(FILE * inputFile)
{
	int magic, firstLine[SQUARESIZE], secondLine[SQUARESIZE];

	parse_half_test(inputFile, firstLine);
	parse_half_test(inputFile, secondLine);

	magic = intersect (firstLine, secondLine);
	switch(magic)
	{
	case BADMAGICIAN:
		std::cout << "Bad magician!" << std::endl;
		break;
	case VOLUNTEERCHEATED:
		std::cout << "Volunteer cheated!" << std::endl;
		break;
	default:
		std::cout << magic << std::endl;
		break;

	}
}

void solve_input_file()
{
	int numberOfTests;
	FILE * inputFile= fopen ("input.in", "r");
	parse_number_of_tests(inputFile, &numberOfTests);

	for(int i =0; i< numberOfTests; i++)
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_one_test(inputFile);
	}
}

int main(int argc, char * argv[])
{
	solve_input_file();
	return EXIT_SUCCESS;
}