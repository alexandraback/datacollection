#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int cases;
	int i,j,k,l;
	int a[4],b[4];
	int temp;
	int no;
	int cnt;
	ifstream fin;
	ofstream fout;
	fin.open("A-small-attempt4.in");
	fout.open("A-small-attempt4.out");
	
	fin >> cases;
	for(i=1; i<=cases; i++){
		cnt=0;
		fin >> no;
		for(j=1; j<=4; j++){
			if(j!=no){
				fin >> temp >> temp >> temp >> temp;
				continue;
			}
			fin >> a[0] >> a[1] >> a[2] >> a[3];
		}
		fin >> no;
		for(j=1; j<=4; j++){
			if(j!=no){
				fin >> temp >> temp >> temp >> temp;
				continue;
			}
			fin >> b[0] >> b[1] >> b[2] >> b[3];
		}
		for(j=0; j<4; j++){
			for(k=0; k<4; k++){
				if(b[j]==a[k]){
					cnt++;
					temp = b[j];
				}
			}
		}
		fout << "Case #" << i << ": ";
		switch(cnt){
			case 0:
				fout << "Volunteer cheated!";
				break;
			case 1:
				fout << temp;
				break;
			default:
				fout << "Bad magician!";
				break;
		}
		if(i!=cases) fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}