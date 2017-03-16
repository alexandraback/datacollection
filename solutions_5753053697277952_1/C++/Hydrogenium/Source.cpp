#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <queue>

using namespace std;

int T;
long long N;



struct pt{
	int l, n;

	bool operator< (pt const &B) const {
		return n < B.n;
	}
};

pt party[27];

priority_queue<pt> q;

ifstream infile;
ofstream outfile;

void reset() {
	return;
}

void proc() {
	for (int i = 1; i <= N; ++i)
		q.push(party[i]);

	pt tmp;
	while (q.size() > 2) {
		tmp = q.top();
		q.pop();
		outfile << ' ' << static_cast<char>('A' - 1 + tmp.l);
		--tmp.n;
		if (tmp.n > 0)
			q.push(tmp);
	}

	pt tmp1 = q.top();
	q.pop();
	pt tmp2 = q.top();
	q.pop();

	int cnt = tmp1.n;
	for (int i = 1; i <= cnt; ++i)
		outfile << " " << static_cast<char>('A' - 1 + tmp1.l) << static_cast<char>('A' - 1 + tmp2.l);
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");


	infile >> T;

	for (int p = 1; p <= T; ++p) {
		reset();

		infile >> N;
		outfile << "Case #" << p << ":";
		for (int i = 1; i <= N; ++i) {
			party[i].l = i;
			infile >> party[i].n;
		}

		proc();

		outfile << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}