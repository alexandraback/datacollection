#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}
int abs(int a) {return (a<0)?(-1*a):a;}

using namespace std;

unsigned int tesztDB;
unsigned strNum;
string *strs;
unsigned** charNum;

int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("A-large.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> strNum;
		strs = new string[strNum];
		getline(ifile, strs[0]);
		for (unsigned j = 0; j< strNum; j++) getline(ifile, strs[j]);
		string singleStr = "";
		char firstChar = '\0';
		for (unsigned j = 0; j < strs[0].length(); j++) {
			if (firstChar != strs[0][j]) {
				firstChar = strs[0][j];
				singleStr += firstChar;
			}
		}
		charNum = new unsigned*[strNum];
		bool failed = false;
		unsigned minSum = 0;
		for (unsigned j = 0; j < strNum; j++) {
			charNum[j] = new unsigned[singleStr.length()];
		}
		for (unsigned j = 0; j < strNum; j++) {
			int place = -1;
			firstChar = '\0';
			for (unsigned k = 0; k < strs[j].length(); k++) {
				if (firstChar != strs[j][k]) {
					firstChar = strs[j][k];
					place++;
					if ((unsigned)place >= singleStr.length() || singleStr[place] != strs[j][k]) {
						failed = true;
						goto end;
					}
					charNum[j][place] = 1;
				} else charNum[j][place]++;
				if (k+1 == strs[j].length() && (unsigned)place+1 < singleStr.length()) {
					failed = true;
					goto end;
				}
			}
		}
		for (unsigned j = 0; j < singleStr.length(); j++) {
			//cout << singleStr[j] << endl;
			unsigned minNum = 10000000;
			for (unsigned goodNum = 1; goodNum <= 100; goodNum++) {
				unsigned potMin = 0;
				for (unsigned k = 0; k < strNum; k++) {
					//cout << charNum[k][j] << endl;
					potMin += abs((int)charNum[k][j]-(int)goodNum);
				}
				minNum = min(potMin, minNum);
			}
			minSum += minNum;
		}
		//cout << endl;
		end:
		if (failed) fprintf(ofile, "Case #%d: Fegla Won\n", i+1);
		else fprintf(ofile, "Case #%d: %d\n", i+1, minSum);
		for (unsigned j = 0; j < strNum; j++) delete[] charNum[j];
		delete[] charNum;
		delete[] strs;
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
