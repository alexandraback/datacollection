#include <cstdio>
#include <cstdint>
#include <cmath>

const uint32_t MAXDIMENSIONS = 10000;
bool TENNANT_GRID[MAXDIMENSIONS][MAXDIMENSIONS] = { false };

void setCell(uint32_t i, uint32_t r, uint32_t c, bool b) {
	uint32_t row = i / c;
	uint32_t collum = i % c;

	TENNANT_GRID[row][collum] = b;
}

bool getCell(int32_t i, uint32_t r, uint32_t c) {
	uint32_t row = i / c;
	uint32_t collum = i % c;

	return TENNANT_GRID[row][collum];

}

uint32_t getCellUnhappiness(uint32_t i, uint32_t r, uint32_t c) {
	uint32_t unHappy = 0;
	
	uint32_t row = i / c;
	uint32_t collum = i % c;

	if (row != 0) {
		if (TENNANT_GRID[row - 1][collum]) {
			unHappy++;
		}
	}

	if (row != r-1) {
		if (TENNANT_GRID[row + 1][collum]) {
			unHappy++;
		}
	}

	if (collum != 0) {
		if (TENNANT_GRID[row][collum - 1]) {
			unHappy++;
		}
	}

	if (collum != c-1) {
		if (TENNANT_GRID[row][collum + 1]) {
			unHappy++;
		}
	}

	return unHappy;
}

uint32_t fillGridUnhappiness(uint32_t r, uint32_t c, uint32_t n) {
	uint32_t unhappiness = 0;
	uint32_t nCount = n;
	if (nCount == 0) {
		return unhappiness;
	}

	for (uint32_t i = 0; i < MAXDIMENSIONS; i++) {
		for (uint32_t j = 0; j < MAXDIMENSIONS; j++) {
			TENNANT_GRID[i][j] = false;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 0 && !getCell(i,r,c)) {
			setCell(i, r, c, true);
			nCount--;
		}
		if (nCount == 0) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 1 && !getCell(i, r, c)) {
			unhappiness += 1;
			setCell(i, r, c, true);
			nCount--;
		}
		if (nCount == 0) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 2 && !getCell(i, r, c)) {
			unhappiness += 2;
			setCell(i, r, c, true);
			nCount--;
		}
		if (nCount == 0) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 3 && !getCell(i, r, c)) {
			unhappiness += 3;
			setCell(i, r, c, true);
			nCount--;
		}
		if (nCount == 0) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 4 && !getCell(i, r, c)) {
			unhappiness += 4;
			setCell(i, r, c, true);
			nCount--;
		}
		if (nCount == 0) {
			return unhappiness;
		}
	}
	return unhappiness;
}

uint32_t fillGridHappiness(uint32_t r, uint32_t c, uint32_t n) {
	uint32_t unhappiness = ((r - 1)*c) + ((c - 1)*r);
	uint32_t nCount = r*c;
	if (nCount == n) {
		return unhappiness;
	}

	for (uint32_t i = 0; i < MAXDIMENSIONS; i++) {
		for (uint32_t j = 0; j < MAXDIMENSIONS; j++) {
			TENNANT_GRID[i][j] = true;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 4 && getCell(i, r, c)) {
			unhappiness -= 4;
			setCell(i, r, c, false);
			nCount--;
		}
		if (nCount == n) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 3 && getCell(i, r, c)) {
			unhappiness -= 3;
			setCell(i, r, c, false);
			nCount--;
		}
		if (nCount == n) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 2 && getCell(i, r, c)) {
			unhappiness -= 2;
			setCell(i, r, c, false);
			nCount--;
		}
		if (nCount == n) {
			return unhappiness;
		}
	}

	for (uint32_t i = 0; i < r*c; i++) {
		if (getCellUnhappiness(i, r, c) == 1 && getCell(i, r, c)) {
			unhappiness -= 1;
			setCell(i, r, c, false);
			nCount--;
		}
		if (nCount == n) {
			return unhappiness;
		}
	}

	return unhappiness;
}

int main(int argc, char** argv) {
	printf_s("Google Code Jam 2015\n");

	if (argc != 3) {
		printf_s("Please enter the name of the input and output files only.\n");
		return 0;
	}

	FILE *inputFile = NULL, *outputFile = NULL;
	fopen_s(&inputFile, argv[1], "r");
	fopen_s(&outputFile, argv[2], "w");

	if (inputFile == NULL || outputFile == NULL) {
		printf_s("Unable to open the file.\n");
		return 0;
	}

	uint32_t numOfTestCases = 0;
	fscanf_s(inputFile, "%u", &numOfTestCases);
	printf_s("There are %u number of test cases.\n\n", numOfTestCases);


	//Code here
	for (uint32_t i = 0; i < numOfTestCases; i++) {
		uint32_t r, c, n;
		fscanf_s(inputFile, "%lu %lu %lu", &r, &c, &n);

		printf_s("Case %lu: r_%lu c_%lu n_%lu\n", i+1, r, c, n);
		uint32_t unHappyA = fillGridUnhappiness(r, c, n);
		uint32_t unHappyB = fillGridHappiness(r, c, n);
		printf_s("Unhappiness A: %lu\n", unHappyA);
		printf_s("Unhappiness B: %lu\n\n", unHappyB);

		if (unHappyA < unHappyB) {
			fprintf_s(outputFile, "Case #%lu: %lu\n", i + 1, unHappyA);
		}
		else {
			fprintf_s(outputFile, "Case #%lu: %lu\n", i + 1, unHappyB);
		}
	}


	fclose(inputFile);
	fclose(outputFile);
}