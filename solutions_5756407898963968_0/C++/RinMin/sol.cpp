#include <iostream>
#include <fstream>
#include <sstream>

#include <cmath>

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#include "pa.h"

void chooseproblem(char p, istream& in, ostream& out){
	if(p == 'A' || p == 'a'){
		pa(in, out);
//	} else if(p == 'B' || p == 'b'){
//		pb(in, out);
//	} else if(p == 'D' || p == 'd'){
//		pd(in, out);
	} else {
		cout << "Unrecognized problem " << p << endl;
	}
}

int main(int argc, char** argv){
	if(argc < 2){
		cout << "Specify problem ABCD" << endl;
		return 0;
	}
	char p = argv[1][0];

	if(argc < 3){
		chooseproblem(p, cin, cout);
	} else {
		ifstream fin;
		ofstream fout;

		string filebase = argv[2];
		string ifile = filebase + ".in";
		string ofile = filebase + ".out";

		fin.open(ifile.c_str());
		if(fin.fail()){
			cout << "Failed to open input file " << ifile << endl;
			fin.close();
			return 0;
		}

		fout.open(ofile.c_str());
		if(fout.fail()){
			cout << "Failed to open output file " << ofile << endl;
			fin.close();
			fout.close();
			return 0;
		}

		chooseproblem(p, fin, fout);

		fin.close();
		fout.close();
	}



}
