#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef long long int bignum;

using namespace std;

int main(){
	ifstream fin("A-small.in");
	ofstream fout("A-output.txt");

	int T;
	fin >> T;

	for (int t = 1; t <= T; t++){
		int n;
		fin >> n;

		vector<int> p;

		for (int i = 0; i < n; i++){
			int v;
			fin >> v;
			p.push_back(v);
		}

		vector<string> moves;

		bool done = false;
		while (!done){
			int remaining = 0;
			vector<int> remainingi;
			int maxsize = 0;
			int maxi = -1;
			for (int i = 0; i < p.size(); i++){
				if (p[i] > 0){
					remaining++;
					remainingi.push_back(i);
				}
				if (p[i] > maxsize){
					maxsize = p[i];
					maxi = i;
				}
			}
			if (remaining > 2){
				p[maxi]--;
				string str(1,(char)(maxi + 65));
				moves.push_back(str);
			}
			else if(remaining != 0){
				string str = "";
				for (auto& it : remainingi){
					p[it]--;
					str += string(1, char(it + 65));
				}
				moves.push_back(str);
			}
			else{
				done = true;
			}
		}

		
		fout << "Case #" << t << ":";
		for (auto& it : moves){
			fout << " " << it;
		}
		fout << endl;
	}

	fout.close();
	return 0;
}