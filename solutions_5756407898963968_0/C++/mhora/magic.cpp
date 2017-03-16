// magic.cpp : Defines the entry point for the console application.
//

//#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <cstdio>

using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	FILE * pFile;
	pFile = fopen("input.in", "r");
	FILE * oFile;
	oFile = fopen("output.txt", "w+");
	int t;
	fscanf(pFile, "%d", &t);
	int prvni[4];
	int druhy[4];
	int trash[4];
	int r1, r2;
	int shod;
	int x;
	for(int i = 0; i < t; i++){
		fscanf(pFile, "%d", &r1);
		for (int j = 0; j < 4; j++){
			if (j == r1 - 1){
				fscanf(pFile, "%d %d %d %d", &prvni[0], &prvni[1], &prvni[2], &prvni[3]);
			}
			else{
				fscanf(pFile, "%d %d %d %d", &trash[0], &trash[1], &trash[2], &trash[3]);
			}
		}
		fscanf(pFile, "%d", &r2);
		for (int j = 0; j < 4; j++){
			if (j == r2 - 1){
				fscanf(pFile, "%d %d %d %d", &druhy[0], &druhy[1], &druhy[2], &druhy[3]);
			}
			else{
				fscanf(pFile, "%d %d %d %d", &trash[0], &trash[1], &trash[2], &trash[3]);
			}
		}
		shod = 0;
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				if (prvni[j] == druhy[k]){ 
					shod++;
					if (shod == 1){ x = prvni[j]; }
				}
			}
		}
		if (shod == 1){ fprintf(oFile,"case #%d: %d\n", i+1, x); }
		else if (shod == 0){ fprintf(oFile, "case #%d: Volunteer cheated!\n", i+1); }
		else{ fprintf(oFile, "case #%d: Bad magician!\n", i+1); }
	}
	fclose(pFile);
	fclose(oFile);
	return 0;
}

