#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char *argv[]) {
	int nTestCases;
	//auto &input = cin;
	ifstream input("A-large.in");
	ofstream output("A-large.out");
	
	input>>nTestCases;
	
	for(int i = 0; i < nTestCases; i++){
		int nTimes;
		input>>nTimes;
		int minA = 0, minB = 0;
		vector<int> mushrooms(nTimes, 0);
		for(int m=0; m<nTimes; m++){
			input>>mushrooms[m];
		}
		
		for(int m=0; m<nTimes-1; m++){
			int diff = mushrooms[m]-mushrooms[m+1];
			if(diff>0){
				minA += diff;
			}
		}
		
		
		float minRate = 0;
		
		for(int m=0; m<nTimes-1; m++){
			float rate = (mushrooms[m]-mushrooms[m+1]);
			if(mushrooms[m]>=mushrooms[m+1] && rate>minRate){
				minRate = rate;
			}
		}
		
		for(int m=0; m<nTimes-1; m++){{
			if(mushrooms[m]>minRate){
				minB += minRate;
			}else
				minB += mushrooms[m];
			}
		}
		
		output<<"Case #"<<i+1<<": "<<minA<<" "<<minB<<endl;
//		cout<<"===================="<<endl;
		
	}
	
	
	
	return 0;
}

