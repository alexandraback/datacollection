#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


void solve(std::ifstream& input)
{
	int m1[4][4];
	int m2[4][4];
	int s1, s2;

	input >> s1;
	s1= s1-1;
	for(int i =0; i < 4;++i) {
		for(int j =0; j < 4; ++j) {
			input >> m1[i][j];
		}
	}
	input >> s2;
	s2=s2-1;
	for(int i =0; i < 4;++i) {
		for(int j =0; j < 4; ++j) {
			input >> m2[i][j];
		}
	}
	
	int c =0;
	int count = 0;
	for(int i =0; i < 4;++i) {
		for(int j =0; j < 4;++j) {
			if(m1[s1][i] == m2[s2][j]) {
				c = m1[s1][i];
				++count;
			}
		}
	}
	if(count ==0) {
		std::cout << "Volunteer cheated!";
	}
	else if(count ==1) {
		std::cout << c ;
	}
	else {
		std::cout << "Bad magician!";
	}
	std::cout << "\n";
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		printf("Case #%d: ", i);
		solve(in);
	}
	return 0;
}
