#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


class Solver{
public:
	ifstream &in;
	int N;
	vector<char> letters;
	vector<vector<int> > groups;
	bool win;

	Solver(ifstream &input):in(input){
		in>>N;
		letters.reserve(100);
		groups.resize(N);
		win=true;

		for(int i=0;i<N;++i){
			string s;
			in>>s;
			char lastchar='0';
			char c;
			int group=-1;
			groups[i].reserve(s.length());
			for(int j=0;j<s.length();++j){
				c=s[j];
				if(c==lastchar){
					groups[i][group]++;
				} else {
					group++;
					lastchar=c;
					if(i==0){
						letters.push_back(c);
					} else {
						if(group<letters.size() && letters[group]!=c){
							win=false;
							return;
						}
					}

					groups[i].push_back(1);
				}
			}
			if(i!=0){
				if(groups[i].size()!=letters.size()){
					win=false;
					return;
				}
			}
		}
	}

	void print(){
		for(int i=0;i<letters.size();++i)
			cout<<letters[i];
		cout<<"\n";
		for(int i=0;i<N;++i){
			for(int j=0;j<groups[i].size();++j)
				cout<<groups[i][j];
			cout<<"\n";
		}
	}

	int solve(){
		if(!win)
			return -1;
		int turns=0;
		for(int i=0;i<groups[0].size();++i){
			vector<int> v;
			v.resize(N);
			for(int j=0;j<N;++j)
				v[j]=groups[j][i];
			sort(v.begin(),v.end());
			int target=v[(N-1)/2];
			for(int j=0;j<N;++j)
				turns+=abs(v[j]-target);
		}
		return turns;
	}
};


int main(){
	ifstream in;
	ofstream out;
	string fileName = "A-small-attempt1";
	in.open(fileName+".in");
	out.open(fileName+".out");

	int T;
	in>>T;
	for(int i=1;i<=T;++i){
		Solver solver(in);
		int result=solver.solve();
		if(result==-1){
			out << "Case #"<<i<<": "<<"Fegla Won"<<"\n";
			cout << "Case #"<<i<<": "<<"Fegla Won"<<"\n";
		} else {
			out << "Case #"<<i<<": "<<result<<"\n";
			cout << "Case #"<<i<<": "<<result<<"\n";
		}
	}

	return 0;
}

