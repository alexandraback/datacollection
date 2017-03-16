/*
 * senate.cc
 *
 *  Created on: May 8, 2016
 *      Author: maciek
 */
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <list>


using namespace std;


int main(int argc,char *argv[]){

	long long T, N;
	string s;
	ifstream fs(argv[1]);
	int count[30];
	int totalN;

	getline(fs, s);
	istringstream(s) >> T;
	for(int i = 0; i < T; i++){
		getline(fs,s);
		istringstream(s) >> N;
		getline(fs,s);
		istringstream is(s);
		totalN = 0;
		for(int j = 0; j < N; j++){
			is >> count[j];
			totalN+=count[j];
		}

		int max;
		int mult;
		int max1pos, max2pos, max3pos;
		cout << "Case #" << i+1 << ": ";
		while(totalN > 0){
			max = 0;
			mult = 0;
			for(int j = 0; j < N; j++){
				if(count[j] > max){
					max = count[j];
					mult = 1;
					max1pos = j;
				} else if(count[j] == max && mult == 1){
					mult++;
					max2pos = j;
				} else if(count[j] == max && mult == 2){
					mult++;
					max3pos = j;
				}
			}

			if(mult == 1){
				cout << (char) ('A' + max1pos) << (char) ('A' + max1pos) << " ";
				count[max1pos]-=2;
				totalN-=2;
			}
			if(mult > 1){
				if(mult == 2){
					cout << (char) ('A' + max1pos) << (char) ('A' + max2pos) << " ";
					count[max1pos]--;
					count[max2pos]--;
					totalN-=2;
				}else{
					cout << (char) ('A' + max1pos) << " ";
					count[max1pos]--;
					totalN--;
				}
			}
		}

		cout << endl;

	}
}
