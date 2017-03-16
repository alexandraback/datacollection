#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	const string R="RICHARD";
	const string G="GABRIEL";
	for(int q=0; q<qN; ++q){
		int x; inf>>x;
		int m[10010];
		for (int i=0; i<x; ++i)
			inf>>m[i];
		int y=0;
		for (int i=1; i<x; ++i)
			if (m[i]<m[i-1]) y+=m[i-1]-m[i];

		int z=0; int speed=0;
		for (int i=1; i<x; ++i)
			if (m[i-1]-m[i]>speed) 
				speed=m[i-1]-m[i];
		cout<<speed<<endl;
		for (int i=0; i<x-1; ++i){
			z+=min(speed,m[i]);
		}

		of<<"Case #"<<q+1<<": "<<y<<' '<<z<<endl;
	}
}