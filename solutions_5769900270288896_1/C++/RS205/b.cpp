#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>
#include<string>
#include<cmath>

int main(){

	std::string readln;
	std::ifstream input;
	std::ofstream output;
	int num_tests;	
	int ans;
	int rows;
	int cols;
	int unhappiness;
	int people;
	int size;

	input.open("B-large.in");
	output.open("output2.txt");

	input >> readln;
	num_tests = std::stoi(readln);

	for (int case_num = 1; case_num <= num_tests; case_num++){

		input>>readln;
		rows = std::stoi(readln);

		input>>readln;
		cols = std::stoi(readln);

		input>>readln;
		people = std::stoi(readln);

		size = rows*cols;
		unhappiness =0;

		if (people>ceil(double(size)/double(2))){
			people-=size/2;
			if (rows%2 == 1 && cols%2 == 1 && people+size/2 - 1 == ceil(double(size)/double(2))){
				unhappiness=3;
				people = 0;
				if (cols == 1 || rows == 1){
					unhappiness=2;
					people = 0;
				}	
			}
			if (people+size/2 == size){
				if (rows == 1 || cols == 1){
				unhappiness=size-1;
				people = 0;
				}
			}
			int corners;
			int edges;
			if (rows%2 == 0 || cols%2 == 0){
				corners= 2;
			}
			else{
				corners=4;
			}

			while(corners>0 && people > 0){
				people--;
				corners--;
				if(rows ==1 ||  cols == 1){
					unhappiness+=1;
				}
				else{
					unhappiness+=2;
				}
			}	

			if (rows%2 ==  cols%2){
				edges= rows/2-1+rows/2-1+cols/2-1+cols/2-1;
			}
			else if (rows%2 == 0){
				edges= rows/2-1+rows/2-1+cols/2-1+ceil(double(cols)/double(2))-1;
			}
			else if (cols%2 == 0){
				edges = cols/2-1+cols/2-1+rows/2-1+ceil(double(rows)/double(2))-1;
			}


			while (edges>0 && people >0){
				people--;
				edges--;
				if(rows == 1 || cols == 1){
					unhappiness+=2;
				}
				else{
					unhappiness+=3;
				}
			}

			while(people>0){
				people--;
				unhappiness+=4;
			}


		}

		output<<"Case #"<<case_num<<": " <<unhappiness<<std::endl;
	}

	input.close();
	output.close();

	return 0;
}
