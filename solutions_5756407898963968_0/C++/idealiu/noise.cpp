/** @Image calibration application
 ** @Estimate fundamental or homography matrix
 ** @author Zhe Liu
 **/
/*
Copyright (C) 2011-2013 Zhe Liu.
All rights reserved.

This file is part of the KVLD library and is made available under
the terms of the BSD license (see the COPYING file).
*/
#include<iostream>
#include<vector>
#include <fstream>
using namespace std;

int main(int argc,char*argv[]) {
	cout<<"Hello world"<<endl;
	ifstream input("A-small-attempt0.in");
	if(!input.is_open()) cout<< "problem1"<<endl;
	
	int number;
	input>>number;

	vector<int> result(number+1,0); 


	for(int i=1;i<= number; i++){
		//loading
		vector<int> matrix1(16);
		int ans1;

		input>>ans1;
		ans1--;
		for (int j=0;j<16; j++){
			input>>matrix1[j];
		}
		
		vector<int> matrix2(16);
		int ans2;

		input>>ans2;
		ans2--;
		for (int j=0;j<16; j++){
			input>>matrix2[j];
		}
		//solving 
		for (int id1=ans1*4;id1<ans1*4+4; id1++){
			for (int id2=ans2*4; id2<ans2*4+4;id2++){
				if (matrix1[id1]==matrix2[id2]){ 
					if(result[i]==0){
						result[i]=matrix1[id1];
					}else {
						result[i]=-1;
						break;
					}
				}
			}
		}
	}

	ofstream output("answer.txt");
	for(int i=1;i<=number;i++){
		output<<"Case #"<<i<<": ";
		if (result[i]>0) output<<result[i]<<endl;
		if (result[i]==0) output<<"Volunteer cheated!"<<endl;
		if (result[i]<0) output<<"Bad magician!"<<endl;
	}
	output.close();

	return 0;
}

