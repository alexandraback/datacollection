#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void stringToArray(int *data, const std::string &tline, int maxLength){
	int seperatorCount = 0;//count
	size_t seperatorLocation[100];
	seperatorLocation[0] = -1; //seperator location
	const char *lineData = tline.c_str();

	for(int i = 0; i < tline.length(); i ++){
		if(lineData[i] == ' '){
			seperatorCount ++;
			seperatorLocation[seperatorCount] = i;
		}
	}
	seperatorLocation[++seperatorCount] = tline.length();
	if(seperatorCount > maxLength ){
		seperatorCount = maxLength;
	}

	for(int i = 0; i < seperatorCount; i ++){
		data[i] = std::atoi(tline.substr(seperatorLocation[i]+1, seperatorLocation[i+1] - seperatorLocation[i] - 1).c_str());
	}
}

int GetInt(ifstream &fid, string &str) {
	getline(fid, str);
	return atoi(str.c_str());
}

void GetInts(ifstream &fid, string &str, int *r) {
	getline(fid, str);
	stringToArray(r, str, 4);
}

int GetResult(int (*A)[4], int (*B)[4], int RA, int RB) {
	int x[17];
	for(int i = 1; i < 17; i ++) {
		x[i] = 0;
	}
	for(int i = 0; i < 4; i ++) {
		x[A[RA][i]] ++;
	}
	int count = 0, ind;
	for(int i = 0; i < 4; i ++) {
		if(x[B[RB][i]]){
			ind = B[RB][i];
			count++;
		}
	}
	if(count == 1){
		return ind;
	}else if(count == 0) return 0;
	else return -1;
}

int main(int , char* []){
	ifstream fid("F:\\Projects_Cpp\\Tutorial\\A-small-attempt1.in");
	string str;
	int count = GetInt(fid, str);
	vector<int> output(count);
	int A[4][4], B[4][4], temp[4], RA, RB;
	for(int k = 0; k < count; k ++) {
		RA = GetInt(fid, str);
		for(int i = 0; i < 4; i ++) {
			GetInts(fid, str, temp);
			for(int j = 0; j < 4; j ++) {
				A[i][j] = temp[j];
			}
		}

		RB = GetInt(fid, str);
		for(int i = 0; i < 4; i ++) {
			GetInts(fid, str, temp);
			for(int j = 0; j < 4; j ++) {
				B[i][j] = temp[j];
			}
		}

		output[k] = GetResult(A, B, RA-1, RB-1);
	}
	fid.close();

	ofstream fido("f:\\Projects_Cpp\\tutorial\\out.txt");
	for(int i = 0; i < count; i ++) {
		if(output[i] > 0)
			fido<<"Case #"<<i+1<<": "<<output[i]<<endl;
		else if(output[i] == 0) {
			fido<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
		}else fido<<"Case #"<<i+1<<": Bad magician!"<<endl;
	}
	fido.close();
	system("pause");
}