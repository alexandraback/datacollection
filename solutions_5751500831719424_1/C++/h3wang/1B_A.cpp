#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(fout.rdbuf());
#endif
}
int T, N,total;
string s, v[100];
struct node{
	char ch;
	int n;
};
vector<node> no[100];
vector<int> tmp;
void process(int i){
	char last = '0';
	int counter = 0;
	for (int j = 0; j < v[i].size(); j++){
		if (v[i][j] != last){
			if (counter != 0){
				node t = { last, counter };
				no[i].push_back(t);
			}
			last = v[i][j];
			counter = 1;
		}
		else{
			counter++;
		}
	}
	node t = { last, counter };
	no[i].push_back(t);
}
int main(){
	redirect();
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> v[j];
			no[j].clear();
			process(j);
		}
		bool found=true;
		for (int i = 1; i < N; i++){
			if (no[0].size() != no[i].size()){
				found = false;
				break;
			}
		}
		if (found){
			for (int i = 0; i < no[0].size()&&found; i++){
				for (int j = 1; j < N; j++){
					if (no[0][i].ch != no[j][i].ch){
						found = false;
						break;
					}
				}
			}
		}
		if (found){
			total = 0;
			for (int i = 0; i < no[0].size(); i++){
				tmp.clear();
				for (int j = 0; j < N; j++){
					tmp.push_back(no[j][i].n);
				}
				sort(tmp.begin(), tmp.end());
				int k;
				if (tmp.size() % 2 == 1)
					k = tmp[(tmp.size() - 1) / 2];
				else
					k = (tmp[(tmp.size() - 1) / 2] + tmp[tmp.size() / 2]) / 2;
				for (int j = 0; j < N; j++){
					total+=abs(k-no[j][i].n);
				}
			}
		}
		cout << "Case #" << t + 1 << ": ";
		if (found)
			cout << total << endl;
		else
			cout << "Fegla Won" << endl;
	}
	return 0;
}