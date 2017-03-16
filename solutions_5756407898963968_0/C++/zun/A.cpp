#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin("A.in");
	ofstream fout("A.out");
	int t;
	fin>>t;
	for( int tt=0; tt<t; tt++) {
	  int r,temp;
		vector<int> ans;
		int count=0,answer;
		fin>>r;
		for( int i=0; i<4; i++) {
			for( int j=0; j<4; j++) {
			  fin>>temp;
				if(i+1==r) {
				  ans.push_back(temp);
				}
			}
		}
		fin>>r;
		for( int i=0; i<4; i++) {
			for( int j=0; j<4; j++) {
			  fin>>temp;
				if(i+1==r) {
				  for(int k=0; k<ans.size(); k++) {
					  if(ans[k]==temp) {
							answer = temp;
						  count++;
							break;
						}
					}
				  ans.push_back(temp);
				}
			}
		}
		if(count==0) {
		  fout<<"Case #"<<tt+1<<": Volunteer cheated!"<<endl;
		}
		else if(count==1) {
		  fout<<"Case #"<<tt+1<<": "<<answer<<endl;
		}
		else {
			fout<<"Case #"<<tt+1<<": Bad magician!"<<endl;
		}
	}
}