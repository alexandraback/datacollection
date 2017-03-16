// 1BB.cpp 


#include "stdafx.h"
//#include "stdio.h"
//#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;
int T,N,R,C;

int calc(int R, int C, int N){
	if (R > C)return calc(C, R, N);
	if (R == 1){
		if (C == 1){
			return 0;
		}
		if (C == 2){
			if (N == 2)return 1;
		}
		if (C == 3){
			if (N == 3)return 2;
		}
		if (C == 4){
			if (N == 3)return 1;
			if (N == 4)return 3;
		}
	}
	if (R == 2){
		if (C == 2){
			if (N == 3)return 2;
			if (N == 4)return 4;
		}
		if (C == 3){
			if (N == 4)return 2;
			if (N == 5)return 4;
			if (N == 6)return 7;
		}
		if (C == 4){
			
			if (N == 5)return 2;
			if (N == 6)return 4;
			if (N == 7)return 7;
			if (N == 8)return 10;
		}
	}
	if (R == 3){
		
		if (C == 3){
			if (N == 6)return 3;
			if (N == 7)return 6;
			if (N == 8)return 8;
			if (N == 9)return 12;
		}
		if (C == 4){

			
			
			if (N == 7)return 2;
			if (N == 8)return 4;
			if (N == 9)return 7;
			if (N == 10)return 10;
			if (N ==11)return 13;
			if (N == 12)return 17;
		}
	}
	if (R ==4){

		
		if (C == 4){



			
			if (N == 9)return 2;
			if (N == 10)return 4;
			if (N == 11)return 7;
			if (N == 12)return 10;
			if (N == 13)return 13;
			if (N == 14)return 16;
			if (N == 15)return 20;
			if (N == 16)return 24;
		}
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int t, mi;
	//cout << argc << argv;
	ifstream in("L:\\!!GoogleCodeJam\\Debug\\B-small-attempt2.in");
	cout << in.is_open() << endl;
	ofstream out("L:\\!!GoogleCodeJam\\Debug\\b.out");
	//freopen_s("data.txt", "r", stdin);
	//freopen_s("b.txt", "w", stdout);
	//fstream fout("boutput.txt", fstream::out);
	//cin.rdbuf(in.rdbuf());
	//cout.rdbuf(out.rdbuf());
	in >> T;

	for (t = 1; t <= T; t++){
		in >> R>>C>>N;
		
		out << "Case #" << t << ": " << calc(R,C,N) << "\r";

	}
	in.close();
	out.close();
}

