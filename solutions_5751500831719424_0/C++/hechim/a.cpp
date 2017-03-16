#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

class stringelement {
public:
	char ch;
	int n;
	stringelement(char ch1, int n1) {
		ch=ch1; n=n1;
	}
	void increment() {
		n++;
	}
};

int N;
vector< vector<stringelement> > strs;

vector<stringelement> parseString(string str) {
	vector<stringelement> vec;
	stringelement curr(str[0],1);
	for(int i=1; i<(int)str.size(); i++) {
		if(str[i]==curr.ch)
			curr.increment();
		else {
			vec.push_back(curr);
			curr.ch=str[i];
			curr.n=1;
		}
	}
	vec.push_back(curr);
	return vec;
}

int abs(int n) {
	return (n<0)?-n:n;
}

int getNum(int j) {
	int minCount = 100*100*10;
	for(int n=1; n<=100; n++) {
		int cnt = 0;
		for(int i=0; i<N; i++)
			cnt += abs(strs[i][j].n-n);
		if(cnt<minCount)
			minCount = cnt;
	}
	return minCount;
}

int getNumChanges() {
	int m = (int)strs[0].size();
	for(int i=1; i<N; i++) {
		if(strs[i].size()!=m)
		 	return -1;
		for(int j=0; j<m; j++)
			if(strs[i][j].ch!=strs[0][j].ch)
				return -1;
	}
	int num = 0;
	for(int j=0; j<m; j++)
		num += getNum(j);
	return num;
}

int main() {

	int T; fin>>T;
	for(int t=1; t<=T; t++) {

		strs.clear();

		fin >> N;
		strs.resize(N);
		for(int i=0; i<N; i++) {
			string str;
			fin >> str;
			strs[i] = parseString(str);
		}

		int num = getNumChanges();
		if(num<0)
			fout << "Case #" << t << ": Fegla Won" << endl;
		else
			fout << "Case #" << t << ": " << num << endl;

	}

}







