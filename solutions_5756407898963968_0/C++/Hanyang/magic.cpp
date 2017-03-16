#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("No input file\n");
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open("output");
	
	// number of cases
	int caseNum = 0;
	input>>caseNum;
	int counter = 0;
	while(counter < caseNum) {
		int q1, q2;
		int t[4];
		int s[4];
		int a[4];
		input>>q1;
		for(int i = 0; i < 4; i ++) {
			input>>t[0]>>t[1]>>t[2]>>t[3];
			if(i == q1 - 1) {
				for(int j = 0; j < 4; j ++) s[j] = t[j];
			}
		}
		input>>q2;
		for(int i = 0; i < 4; i ++) {
			input>>t[0]>>t[1]>>t[2]>>t[3];
			if(i == q2 - 1) {
				for(int j = 0; j < 4; j ++) a[j] = t[j];
			}
		}
		int found = 0;
		int num = 0;
		for(int i = 0; i < 4; i ++) {
			for(int j = 0; j < 4; j ++) {
				if(s[i] == a[j]) {
					num = s[i];
					found ++;
					break;
				}
			}
		}
		output<<"Case #"<<counter+1<<": ";
		if(found == 0) {
			output<<"Volunteer cheated!"<<endl;
		}
		else if(found == 1) {
			output<<num<<endl;
		}
		else {
			output<<"Bad magician!"<<endl;
		}
		counter ++;
	}
	input.close();
	output.close();
	return 0;
}