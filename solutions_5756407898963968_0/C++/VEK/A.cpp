#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

unsigned int tesztDB;
unsigned cards[4][4];
unsigned possibleCards[4];
unsigned correctCard;
unsigned possibleNum;
unsigned rowNum;


int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("A-small-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> rowNum;
		rowNum--;
		for (unsigned j = 0; j < 4; j++) {
			for (unsigned k = 0; k < 4; k++) {
				ifile >> cards[k][j];
				if (j == rowNum) possibleCards[k] = cards[k][j];
			}
		}
		//for (unsigned j = 0; j < 4; j++) printf("%d ", possibleCards[j]);
		//cout << endl;
		ifile >> rowNum;
		rowNum--;
		possibleNum = 0;
		for (unsigned j = 0; j < 4; j++) {
			for (unsigned k = 0; k < 4; k++) {
				ifile >> cards[k][j];
				if (j == rowNum) {
					for (int l = 0; l < 4; l++) {
						if (possibleCards[l] == cards[k][j]) {
							correctCard = possibleCards[l];
							//cout << "|" << cards[k][j] << " " << possibleCards[l] << " " << possibleNum << " " << endl;
							possibleNum++;
							//cout << cards[k][j] << " " << possibleCards[l] << " " << possibleNum << " " << endl;
							break;
						}
					}
				}
			}
		}
		if (possibleNum == 0) fprintf(ofile, "Case #%d: Volunteer cheated!\n", i+1);
		else if (possibleNum > 1) fprintf(ofile, "Case #%d: Bad magician!\n", i+1);
		else fprintf(ofile, "Case #%d: %d\n", i+1, correctCard);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
