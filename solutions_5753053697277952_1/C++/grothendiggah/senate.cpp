#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>       /* time */
#include <algorithm>
#include <list>
#include <utility>
  

using namespace std;



int main()
{
  ofstream outfile;
  outfile.open ("senate.out");
  std::ifstream infile;
  infile.open ("data.in", std::ifstream::in);
  std::string   line;
  getline(infile, line);
  std::stringstream  lineStream(line);
  int T;
  lineStream>>T;
  string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i=0;i<T;i++){
	int N;
	getline(infile, line);
	std::stringstream  Stream1(line);	
	Stream1>>N;
	vector<int> member;
	getline(infile, line);
	std::stringstream  Stream2(line);
	for(int j=0;j<N;j++){
		int s;			
		Stream2>>s;
		member.push_back(s);
	}
	outfile<<"Case #"<<i+1<<": ";
	while(*max_element(member.begin(),member.end())>0){
		int senators=0;		
		for(int j=0;j<N;j++) senators+=member[j];		
		vector<int>::iterator it1,it2,it3;
		it1 = max_element(member.begin(),member.end());
		it2 = max_element(it1+1,member.end());
		int i1=it1-member.begin();
		int i2=it2-member.begin();
		if(*it1==*it2 && senators!=3){
			outfile<<alphabet[i1]<<alphabet[i2]<<" ";
			member[i1]--;
			member[i2]--;
		}else{
			outfile<<alphabet[i1]<<" ";
			member[i1]--;
		}
	}
	outfile<<endl;
  }		
  infile.close();
  outfile.close();
  return 0;
}


