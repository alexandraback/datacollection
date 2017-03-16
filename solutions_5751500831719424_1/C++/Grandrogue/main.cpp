#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("out.txt");

string s[100];
string exam,ex2;
int sums[100];

int abs(int a) {
	if (a<0) return 0-a;
	return a;
}

int main() {
	int tests, n;
	bool flag=true;
	fin>>tests;
	for(int _t=0;_t<tests;_t++) {
		fin>>n;
		flag=true;
		memset(sums,0,sizeof(sums));
		for(int i=0;i<n;i++)
			fin>>s[i];
		exam="";
		char cur='0';
		for(int i=0;i<s[0].length();i++) {
			if(s[0][i]!=cur) {
				cur=s[0][i];
				exam.push_back(cur);
			}
		}
		for(int i=0;i<n && flag;i++) {
			cur='0';
			ex2="";
			int p=-1;
			for(int j=0;j<s[i].length();j++) {
				if(s[i][j]!=cur) {
					cur=s[i][j];
					ex2.push_back(cur);
					p++;
				}
				sums[p]++;
			}
			if(ex2!=exam) flag=false;
		}
		int best=0;
		for(int i=0;i<n && flag;i++) {
			cur='0';
			int p=-1,cursum[100];
			memset(cursum,0,sizeof(cursum));
			for(int j=0;j<s[i].length();j++) {
				if(s[i][j]!=cur) {
					cur=s[i][j];
					p++;
				}
				cursum[p]++;
			}
			for(int j=0;j<=p;j++)
				best+=abs(cursum[j]-(sums[j]/n));
		}
		if(!flag) fout<<"Case #"<<_t+1<<": Fegla Won"<<endl; else
		fout<<"Case #"<<_t+1<<": "<<best<<endl;
	}
	return 0;
}