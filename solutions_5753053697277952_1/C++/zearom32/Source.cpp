
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


struct node {
	int num;
	char key;
};

struct cmp {
	int operator()(const node& a, const node& b) const {
		return a.num > b.num;
	}
};

 void solve(ifstream& fin, ofstream& fout) {
	 int N;
	 fin >> N;
	 vector<node> a(N);
	 int sum = 0;
	 for (int i = 0; i < N; i++) {
		 fin >> a[i].num;
		 sum += a[i].num;
		 a[i].key = 'A' + i;
	 }
	 for (int i = 0; i < sum;) {
		 sort(a.begin(), a.end(), cmp());
		 if (a.size() > 2 && a[2].num > 0) {
			 fout << a[0].key;
			 a[0].num--;
			 i++;
		 }
		 else {
			 fout << a[0].key << a[1].key;
			 a[0].num--;
			 a[1].num--;
			 i += 2;
		 }
		 if (i < sum) fout << " ";
	 }
	 fout << endl;
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "c.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;

	for (int cs = 1; cs <= t; cs++) {
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}