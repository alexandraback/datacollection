#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;

vector< vector<char> > chars;
vector< vector<int> > reps;

void MakeArrays(const vector<string> & strs) {
	chars.resize(strs.size());
	reps.resize(strs.size());
	for(int i=0;i<strs.size();++i) {
		char cur = strs[i][0];
		int tcnt = 1;
		chars[i].resize(0);
		reps[i].resize(0);
		for(int j=1;j<strs[i].size();++j) {
			if (strs[i][j]==cur) tcnt++;
			else {
				chars[i].push_back(cur);
				reps[i].push_back(tcnt);
				tcnt = 0;
				cur = strs[i][j];
			}
		}
		chars[i].push_back(cur);
		reps[i].push_back(tcnt);
	}
}

bool CheckArrays() {
	int tsz = chars[0].size();
	for(int i=0;i<chars.size();++i)
		if (chars[i].size()!=tsz) return 0;
	for(int i=0;i<chars[0].size();++i) {
		char tmp = chars[0][i];
		for(int j=0;j<chars.size();++j) 
			if (tmp!=chars[j][i]) return 0;
	}
	return 1;
}

int Solve() {
	int ret = 0;
	for(int i=0;i<reps[0].size();++i) {
		int tret = 10000000;
		int cmin = reps[0][i], cmax = reps[0][i];
		for(int j=0;j<reps.size();++j) {
			cmin = min(cmin, reps[j][i]);
			cmax = max(cmax, reps[j][i]);
		}
		int twrk = 0;
		for(int val=cmin;val<=cmax;++val) {
			twrk = 0;
			for(int j=0;j<reps.size();++j)
				twrk += abs(val-reps[j][i]);
			tret = min(tret, twrk);
		}
		ret += tret;
	}
	return ret;
}

int main()
{
    fstream fin("A-large.in",ifstream::in);
    fstream fout("A-large.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		int N;
		fin >> N;
		vector<string> strs(N);
		rep(i,N) fin>> strs[i];
		MakeArrays(strs);
		if (!CheckArrays()) {
			cout << "Case #" << tc << ": Fegla Won\n";
			fout << "Case #" << tc << ": Fegla Won\n";
		}
		else {
			int ret = Solve();
			cout << "Case #" << tc << ": " << ret << "\n";
			fout << "Case #" << tc << ": " << ret << "\n";
		}
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
