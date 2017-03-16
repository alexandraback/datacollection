
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

int ary1[4];
int row1;
int ary2[4];
int row2;



long transfer(){
	int i,j;
	long res;
	
	res=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(ary1[i]==ary2[j]){
				if(res==0){
					res=ary1[i];
				}
				else{
					res=-1;
				}
			}
		}
	}

	return res;
}

int main() {
	int T;
	long res;
	char str[1024];

	fstream fin("A-small-attempt0.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);

	for (int i=0;i<T;i++){
		fin >> row1;
		fin.getline(str,1024);

		for(int j=0;j<4;j++){
			if(j==row1-1){
				fin>>ary1[0];
				fin>>ary1[1];
				fin>>ary1[2];
				fin>>ary1[3];
			}
			fin.getline(str,1024);
		}

		fin >> row2;
		fin.getline(str,1024);

		for(int j=0;j<4;j++){
			if(j==row2-1){
				fin>>ary2[0];
				fin>>ary2[1];
				fin>>ary2[2];
				fin>>ary2[3];
			}
			fin.getline(str,1024);
		}

		res=transfer();
//		fin >> str;
		if(res>0)
			fout << "Case #" << i+1 << ": " << res << endl;
		else if(res==0)
			fout << "Case #" << i+1 << ": " << "Volunteer cheated!" << endl;
		else if(res<0)
			fout << "Case #" << i+1 << ": " << "Bad magician!" << endl;
		else{}

	}



	return 0;
}
