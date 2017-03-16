#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#pragma warning(disable: 4996)

#define OUTPUTLOG2(X,Y)\
{\
	char msg[1024];\
	sprintf( msg, X, Y );\
	OutputDebugString(msg);\
}
#define OUTPUTLOG OutputDebugString

#define FOR(r,a,b) for(r=(a); r<(b); r++)
#define REP(r,b) for(r=0; r<(b); r++)
#define TRV(type,cnt,it) for(type::iterator it=(cnt).begin(); it!=(cnt).end(); it++)

void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
	int i,j,k,l,m,n;

	ifstream fin(argv[1]);
	if( fin == NULL ){
		OUTPUTLOG2("cannot open in-file : %s\n", argv[1]);
		return;
	}
	FILE* fout = fopen(argv[2],"w");
	if( fin == NULL ){
		OUTPUTLOG2("cannot open out-file : %s\n", argv[2]);
		return;
	}

/////////////////////////////
	char line[1024];
	int CASE;
	fin >> CASE;
	for( int test_case = 1; test_case <= CASE; test_case++ ){
	/////////////////////////////
		int row;
		fin >> row;
		int card[4][4];
		vector<int> cand(17,0);
		for( int r = 0; r < 4; r++ ){
			for( int c = 0; c < 4; c++ ){
				fin >> card[r][c];
			}
		}
		for( int c = 0; c < 4; c++ ){
			cand[card[row-1][c]]++;
		}

		fin >> row;
		for( int r = 0; r < 4; r++ ){
			for( int c = 0; c < 4; c++ ){
				fin >> card[r][c];
			}
		}
		for( int c = 0; c < 4; c++ ){
			cand[card[row-1][c]]++;
		}

		int ans = -1;
		for( int i = 1; i <= 16; i++ ){
			if( cand[i] == 2 ){
				if( ans != -1 ){
					ans = -2;
					break;
				}
				ans = i;
			}
		}
		if( ans == -2 ){
			fprintf(fout,"Case #%d: Bad magician!\n", test_case );
		}else if( ans == -1 ){
			fprintf(fout,"Case #%d: Volunteer cheated!\n", test_case );
		}else{
			fprintf(fout,"Case #%d: %d\n", test_case, ans );
		}

	/////////////////////////////
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}