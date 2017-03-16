#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input");
ofstream out("output");

vector<bool> sol;

int get_val(int R, int C) {
	int unhapp = 0;
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			int idx = C*i + j;
			if(sol[idx] == 1) {
				if(i+1 < R && sol[C*(i+1)+j] == 1)
					unhapp ++;
				if(j+1 < C && sol[C*i+(j+1)] == 1)
					unhapp ++;
			}
		}
	}
	return unhapp;
}

void print_plan(int R, int C) {
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			cout << sol[i*C + j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int _solve(int pos, int max_pos, int tenn, int max_tenn, int R, int C) {
	if(tenn == max_tenn) {
		//print_plan(R,C);
		return get_val(R,C);
	}

	if(pos == max_pos) {
		return 0x7fffffff;
	}

	sol[pos] = 1;
	int val = _solve(pos+1,max_pos,tenn+1, max_tenn, R,C);
	sol[pos] = 0;
	val = min(val,_solve(pos+1,max_pos, tenn, max_tenn,R,C));
	return val;
}

int solve(int R, int C, int N) {
	sol = vector<bool>(R*C,0);
	return _solve(0,R*C,0,N,R,C);
}

int main() {
	int T;

	in >> T;

	for(int t = 1; t <= T; ++t) {
		int R,C,N;
		in >> R >> C >> N;
		out << "Case #" << t << ": " << solve(R,C,N) << '\n';
	}
}