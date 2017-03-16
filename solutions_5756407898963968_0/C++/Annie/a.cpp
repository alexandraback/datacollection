#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


//ifstream fin("A.in");
//ofstream fout("A.out");
#define fin cin
#define fout cout

int main()
{
	int nCase, a[8], ar, br, ms;
	fin >> nCase;
	for(int m = 0; m < nCase; ++ m){
		fin >> ar;
		for(int i = 0; i < 4; ++ i){
			for(int j = 0; j < 4; ++ j){
				fin >> ms;
				if(i == (ar-1)) a[j] = ms;
			}
		}
		fin >> br;
		for(int i = 0; i < 4; ++ i){
			for(int j = 0; j < 4; ++ j){
				fin >> ms;
				if(i == (br-1)) a[4+j] = ms;
			}
		}
		sort(a, a+8);
		int rs = -1; bool e = false;
		string sum = "";
		for(int i = 0; i < 7; ++ i){
			if(a[i] == a[i+1]){
				rs = a[i];
				if(!e) e = true;
				else{
					sum = "Bad magician!";
					break;
				}
			}
		}
		fout<<"Case #"<<(m+1)<<": ";
		if(!e) fout<<"Volunteer cheated!"<<endl;
		else if(sum != "") fout<<sum<<endl;
		else fout<<rs<<endl;
	}
	return 0;
}

		

		

